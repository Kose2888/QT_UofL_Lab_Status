#include "lab.h"


Lab::Lab(std::string f, std::vector<QWidget *> v) {
    fileName = f;
    machine = v;
    changeColourAll(ONLINE);

    std::string test = "Test";
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateLoggedIn()));
    timer->start(5000); //time specified in ms
}

Lab::~Lab() {
}

void Lab::changeColourAll(QString colour){
    for(unsigned long i = 0; i < machine.size(); i++) {
        machine[i]->setStyleSheet(colour);
    }
}

void Lab::extract_rwho(){
    std::ifstream file(fileName);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    std::string line; // stores each line

    int lineNumber = 0;
    while (std::getline(file, line)) {

        std::string temp = "";
        int col1End = 0;

        // Find Account Name
        for(long unsigned int i = 0; i < line.size(); i++){
            if(line[i] == ' ') // Stops before second column
                break;
            else
                temp += line[i];
            col1End++;
        }
        accountName.push_back(temp);
        temp = "";


        // Find Machine Name
        for(long unsigned int i = col1End; i < line.size(); i++){
            if(line[i] == ':')
                break;
            if(line[i] != ' ')
                temp += line[i];
        }
        machineName.push_back(temp);

        lineNumber += 1;
    }

    // Close the file
    file.close();
}

void Lab::updateLoggedIn(){
    std::cout << "Reading rwho File... Updating Machine Status" << std::endl;
    extract_rwho();

    for(long unsigned int i = 0; i < machineName.size(); i++){
        for(long unsigned int j = 0; j < machine.size(); j++){
            QString temp = "362" + machine[j]->objectName();
            if(temp.toStdString() == machineName[i]) {
                machine[j]->setStyleSheet(IN_USE);
                //std::cout << "Modifying: " << temp << std::endl;
            }
        }
    }
}
