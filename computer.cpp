#include "Computer.h"
#include <iostream>
using namespace std;
//Thêm một máy tính mới vào hệ thống
void ComputerManager::addComputer(const string& name, int id, bool isAvailable) {
    computers.push_back(Computer(name,id,isAvailable));
    cout << "Added computer: " << name << " with ID: " << id << endl;
}
//Loại bỏ 1 máy tính khỏi hệ thống thông qua id
void ComputerManager::removeComputer(int id) {
    for (auto it = computers.begin(); it != computers.end(); ++it) {
        if (it->id == id) {
            computers.erase(it);
            cout << "Removed computer with ID: " << id << endl;
            return;
        }
    }
    std::cout << "Computer with ID: " << id << " not found." << endl;
}
//In ra dữ liệu 1 máy tính
void ComputerManager::printDetailComputer(int id){
    Computer* c = findComputer(id);
    if(c!=NULL){
        cout<<"ID"<<c->id<<", Name: "<<c->id
        <<", Available:" << (c->isAvailable ? "Yes" : "No")<<", Usage time:"<<c->usageTime<<endl;;
    }
    else
        cout<<"ID not found"<<endl;

}

//In ra danh sách các máy tính
void ComputerManager::displayComputers() const {
    cout << "List of Computers:" << endl;
    for (const auto& computer : computers) {
        cout << "ID: " << computer.id << ", Name: " << computer.name
                  << ", Available: " << (computer.isAvailable ? "Yes" : "No") <<"Usage time:"<<computer.usageTime<< endl;
    }
}

//Tìm máy tính theo id
Computer* ComputerManager::findComputer(int id) {
    for (int i = 0; i < computers.size(); i++) {
        if (computers[i].id == id) {
            return &computers[i];
        }
    }
    return NULL;
}
//Cập nhật trạng thái của máy tính
void ComputerManager::updateComputerStatus(int id, bool isAvailable) {
    Computer* computer = findComputer(id);
    if (computer) {
        computer->isAvailable = isAvailable;
        cout << "Computer with ID " << id << " status updated.\n";
    } else {
        cout << "Computer with ID " << id << " not found.\n";
    }
}
//cập nhật thời gian  sử dụng của máy đang sử dụng
void ComputerManager::updateUsageTime(int id, int newUsageTime) {
    Computer* computer = findComputer(id);
    if (computer) {
        computer->usageTime = newUsageTime;
        cout << "Computer with ID " << id << " usage time updated.\n";
    } else {
        cout << "Computer with ID " << id << " not found.\n";
    }
}


vector<Computer> ComputerManager::getAvailableComputers() const {
    vector<Computer> availableComputers;
    for (const auto& computer : computers) {
        if (computer.isAvailable) {
            availableComputers.push_back(computer);
        }
    }
    return availableComputers;
}