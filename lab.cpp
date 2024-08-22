#include "lab.h"


Lab::Lab(std::vector<QWidget *> v, QString f, QString f2) {
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

    qDebug() << "Reading rwho File...";
    while (!stream.atEnd()) {
        QString line = stream.readLine();

        //qDebug() << line;

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

    std::cout << "Checking Account & Machine Names:" << std::endl;

    for(int i = 0; i < machineName.size(); i++) {
        qDebug() << accountName[i] << "\t" << machineName[i];
    }

}

void Lab::checkLoggedIn(){
    extract_rwho();
    std::cout << "Looking for changes" << std::endl;

    for(long unsigned int i = 0; i < machine.size(); i++){
        for(int j = 0; j < machineName.size(); j++){
            QString temp = "362" + machine[i]->objectName();
            qDebug() << "temp = " << temp;
            if(temp == machineName[j]) {
                qDebug() << accountName[j] << " is logged into "
                          << machineName[j] << "\n";
                machine[i]->setStyleSheet(IN_USE);  // Machine in-use if found in rwho file
                break;
            }
        }
    }
}

void Lab::checkOffline(){

    /*
    std::ifstream file(machineHealthFileName);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    std::string line; // stores each line

    while (std::getline(file, line)) {
        std::string name = "";
        int col1End = 0;

        // Get Machine Name
        for(long unsigned int i = 0; i < line.size(); i++){
            if(line[i] == ' ') // Stops before second column
                break;
            else
                name += line[i];
            col1End++;
        }

        std::string status = "";
        // Get Machine Status
        for(long unsigned int i = col1End; i < line.size(); i++){
            if(line[i] == ':')
                break;
            if(line[i] != ' ')
                status += line[i];
        }

        // Set Status
        for(long unsigned int i = 0; i < machine.size(); i++){
            QString temp = "362" + machine[i]->objectName();
            if(temp.toStdString() == name) {
                if(status == "online") {
                    machine[i]->setStyleSheet(ONLINE);
                }
                else if(status == "offline") {
                    machine[i]->setStyleSheet(OFFLINE);
                    std::cout << name << " Is offline" << std::endl;
                }
                else {
                    machine[i]->setStyleSheet(UNKNOWN);
                    std::cout << "Error: checkOffline function fault" << std::endl;
                }
                break;
            }
        }
    }

    // Close the file
    file.close();
    */
}

void Lab::updateStatus(){
    checkOffline();
    checkLoggedIn();
    std::cout << std::endl;
}
