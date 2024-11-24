#ifndef COMPUTER_MANAGER_H
#define COMPUTER_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Payment.h"
#include "CustomerManager.h"
#include <chrono>
using namespace std;

class Computer {
public:
    string name;
    int id;
    bool isAvailable;
    double usageTime;
    std::chrono::time_point<std::chrono::system_clock> startTime;
    Computer (){
        name="";
        id=0;
        isAvailable=true;
        usageTime=0;

    }
    Computer(string name, int id, bool isAvailable){
        this->name=name;
        this->id=id;
        this->isAvailable=isAvailable;
    }


    
    Computer(string name, int id, bool isAvailable,double usageTime) {
        this->id=id;
        this->name=name;
        this->usageTime=usageTime;
        this->isAvailable=isAvailable;
    }
}
;

class ComputerManager {
private:
    vector<Computer> computers;

public:
    void addComputer(const std::string& name, int id, bool isAvasilable); //Thêm 1 máy tính
    void removeComputer(int id);//Xóa 1 máy tính
    void printDetailComputer(int id);//In dữ liệu 1 máy tính
    void displayComputers();//In toàn bộ máy tính
    Computer* findComputer(int id);//Tìm máy tính theo id
    void updateComputerStatus(int id, bool isAvailable);//Cập nhật trạng thái sử dụng
    void updateUsageTime(int id, double newUsageTime);//Cập nhật thời gian sử dụng
    vector<Computer> getAvailableComputers() const;//In ra những máy tính đang hoạt động
    void displayColoredStatus() const;
    void selectComputerForCustomer(int id, CustomerManager& customerManager);
    double calculateUsageTime(bool isAvailable);
    void runInteractiveClock();
    void returnComputer(int computerId, Payment& payment);
};

#endif
