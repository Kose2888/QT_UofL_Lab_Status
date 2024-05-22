#include "lab.h"

Lab::Lab(){
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(test()));
    timer->start(1000); //time specified in ms
}

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

    std::cout << "File Content: " << std::endl;
    int lineNumber = 0;
    while (std::getline(file, line)) {
        //std::cout << line << std::endl; // Print the current line


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


        //bool check = false;

        // Find Machine Name
        for(long unsigned int i = col1End; i < line.size(); i++){
            if(line[i] == ':')
                break;

            //if(line[i] == '3' && line[i+1] == '6' && line[i+2] == '2')
            //    check = true;
            if(line[i] != ' ')
                temp += line[i];

        }
        machineName.push_back(temp);

        lineNumber += 1;
    }
    for(long unsigned int i = 0; i < accountName.size(); i++){
        std::cout << "Account Name: " << accountName[i] << std::endl;
        std::cout << "Machine Name: " << machineName[i] << "\n" << std::endl;
    }

    // Close the file
    file.close();
}

void Lab::updateLoggedIn(){
    std::cout << "Update func" << std::endl;
    extract_rwho();

    for(long unsigned int i = 0; i < machineName.size(); i++){
        for(long unsigned int j = 0; j < machine.size(); j++){
            QString temp = "362" + machine[j]->objectName();
            if(temp.toStdString() == machineName[i])
                machine[j]->setStyleSheet(IN_USE);
        }
    }
}
