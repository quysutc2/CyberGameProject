#ifndef COMPUTER_MANAGER_H
#define COMPUTER_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Computer {
public:
    string name; // Tên máy tính
    int id;          // ID máy tính
    bool isAvailable; // Trạng thái máy tính 

    Computer(string name, int id, bool isAvailable)
        : name(name), id(id), isAvailable(isAvailable) {} 
};

class ComputerManager {
private:
    vector<Computer> computers; // Danh sách máy tính

public:
    void addComputer(const std::string& name, int id, bool isAvailable); // Thêm máy tính
    void removeComputer(int id);                                         // Xóa máy tính
    void displayComputers() const;                                       // Hiển thị danh sách máy tính
    Computer* findComputer(int id);                                     // Tìm máy tính theo ID
};

#endif // COMPUTER_MANAGER_H
