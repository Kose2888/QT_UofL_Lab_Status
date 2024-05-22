#include "lab.h"


Lab::Lab(std::string f, std::vector<QWidget *> v) {
    fileName = f;
    machine = v;
    changeColourAll(ONLINE);

    std::string test = "Test";
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateLoggedIn()));
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
    std::ifstream file(fileName);

    accountName.clear();
    machineName.clear();

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }

    std::string line; // stores each line

    std::cout << "Reading rwho File...";

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
    extract_rwho();
    std::cout << "Looking for changes" << std::endl;

    for(long unsigned int i = 0; i < machine.size(); i++){
        for(long unsigned int j = 0; j < machineName.size(); j++){
            QString temp = "362" + machine[i]->objectName();
            if(temp.toStdString() == machineName[j]) {
                std::cout << accountName[j] << " is logged into "
                          << machineName[j] << std::endl;
                machine[i]->setStyleSheet(IN_USE);  // Machine in-use if found in rwho file
                break;
            }
            else {
                machine[i]->setStyleSheet(ONLINE);  // Go back to online if no longer in rhwo file
            }
        }
    }
    std::cout << std::endl;
}
