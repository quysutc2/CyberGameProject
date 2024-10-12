#include "Computer.h"

void ComputerManager::addComputer(const string& name, int id, bool isAvailable) {
    cout << "Added computer: " << name << " with ID: " << id << endl;
}

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


void ComputerManager::displayComputers() const {
    cout << "List of Computers:" << endl;
    for (const auto& computer : computers) {
        cout << "ID: " << computer.id << ", Name: " << computer.name
                  << ", Available: " << (computer.isAvailable ? "Yes" : "No") << endl;
    }
}


Computer* ComputerManager::findComputer(int id) {
    for (auto& computer : computers) {
        if (computer.id == id) {
            return &computer;
        }
    }
    return nullptr; // Không tìm thấy
}
