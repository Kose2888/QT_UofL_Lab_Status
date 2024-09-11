#include "lab.h"


Lab::Lab(std::vector<QWidget *> v, QString f, QString f2) {
    name = "Lab";

    fileName = f;
    machineHealthFileName = f2;
    machine = v;
    changeColourAll(UNKNOWN);

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    timer->start(30000); //time specified in ms (Every 30 seconds)
}

Lab::~Lab() {
}

void Lab::setName(QString n) {name = n;}

QString Lab::getName() {return name;}

void Lab::displayLab() {
    qDebug() << "\t\t\t" << name;
}

void Lab::changeColourAll(QString colour){
    for(unsigned long i = 0; i < machine.size(); i++) {
        machine[i]->setStyleSheet(colour);
    }
}

void Lab::extract_rwho(){


    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Error opening file" << std::endl;
    }

    QTextStream stream(&file);

    accountName.clear();
    machineName.clear();

    while (!stream.atEnd()) {
        QString line = stream.readLine();

        QString temp = "";
        int col1End = 0;

        // Find Account Name
        for(int i = 0; i < line.size(); i++){
            if(line[i] == QChar(' ')) // Stops before second column
                break;
            else
                temp += line[i];
            col1End++;
        }
        accountName.push_back(temp);
        temp = "";


        // Find Machine Name
        for(int i = col1End; i < line.size(); i++){
            if(line[i] == ':')
                break;
            if(line[i] != ' ')
                temp += line[i];
        }
        machineName.push_back(temp);

    }
    file.close();
}

void Lab::checkLoggedIn(){
    extract_rwho();

    for(long unsigned int i = 0; i < machine.size(); i++){
        for(int j = 0; j < machineName.size(); j++){
            QString temp = "362" + machine[i]->objectName();
            //qDebug() << "temp = " << temp;
            if(temp == machineName[j]) {
                qDebug() << accountName[j] << "\t is logged into" << "\t"
                          << machineName[j];
                machine[i]->setStyleSheet(IN_USE);  // Machine in-use if found in rwho file
                break;
            }
        }
    }
    qDebug() << "\n";
}

void Lab::checkOffline(){

    QFile file(machineHealthFileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Error opening file" << std::endl;
    }

    QTextStream stream(&file);

    while (!stream.atEnd()) {
        QString line = stream.readLine();

        QString name = "";
        int col1End = 0;

        // Get Machine Name
        for(int i = 0; i < line.size(); i++){
            if(line[i] == ' ') // Stops before second column
                break;
            else
                name += line[i];
            col1End++;
        }

        QString status = "";
        // Get Machine Status
        for(int i = col1End; i < line.size(); i++){
            if(line[i] == ':')
                break;
            if(line[i] != ' ')
                status += line[i];
        }

        // Set Status
        for(long unsigned int i = 0; i < machine.size(); i++){
            QString temp = "362" + machine[i]->objectName();
            if(temp == name) {
                if(status == "online") {
                    machine[i]->setStyleSheet(ONLINE);
                }
                else if(status == "offline") {
                    machine[i]->setStyleSheet(OFFLINE);
                    qDebug() << name << " Is offline" << "\n";
                }
                else {
                    machine[i]->setStyleSheet(UNKNOWN);
                    qDebug() << "Error: checkOffline function fault" << "\n";
                }
                break;
            }
        }
    }
    file.close();
}

void Lab::updateStatus(){
    displayLab();
    checkOffline();
    checkLoggedIn();
    std::cout << std::endl;
}
