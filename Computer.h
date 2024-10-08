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
    void addComputer(const std::string& name, int id, bool isAvailable); 
    void removeComputer(int id);                                         
    void displayComputers() const;                                       
    Computer* findComputer(int id);  
    void updateComputerStatus(int id, bool isAvailable);
    void updateUsageTime(int id, int newUsageTime);
    vector<Computer> getAvailableComputers() const;
    void clearAllComputers();                                   // Tìm máy tính theo ID
};

#endif // COMPUTER_MANAGER_H
