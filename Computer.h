#ifndef COMPUTER_MANAGER_H
#define COMPUTER_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Computer {
public:
    string name; 
    int id;          
    bool isAvailable; 
    int usageTime;
    Computer(string name, int id, bool isAvailable)
        : name(name), id(id), isAvailable(isAvailable) {} 
};

class ComputerManager {
private:
    vector<Computer> computers; 

public:
    void addComputer(const std::string& name, int id, bool isAvailable); //Thêm 1 máy tính
    void removeComputer(int id);//Xóa 1 máy tính                                         
    void displayComputers() const;//In toàn bộ máy tính                                       
    Computer* findComputer(int id);//Tìm máy tính theo id  
    void updateComputerStatus(int id, bool isAvailable);//Cập nhật trạng thái sử dụng
    void updateUsageTime(int id, int newUsageTime);//Cập nhật thời gian sử dụng
    vector<Computer> getAvailableComputers() const;//In ra những máy tính đang hoạt động                            
};

#endif 
