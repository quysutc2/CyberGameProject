#include "function.h"
#include <iostream>
#define NOMINMAX // Ngăn xung đột định nghĩa min/max của Windows
#define WIN32_LEAN_AND_MEAN // Giảm tải các định nghĩa không cần thiết
#include <windows.h> // Đặt sau các chỉ thị tiền xử lý trên
using namespace std;
#include <chrono>
#include <thread>
#include <iomanip>
#include <atomic>
//Hàm Customer
// Thêm một khách hàng vào danh sách
void CustomerManager::addCustomer(const string& name, int id) {
    customers.push_back(Customer(name, id));
    cout << "Added customer: " << name << " with ID: " << id << endl;
}
// In thông tin khách hàng đang tìm kiếm
void CustomerManager::printCustomerDetails(int id) {
    Customer* customer = findCustomer(id);
    if (customer != nullptr) {
        cout << "Customer Details - ID: " << customer->id
             << ", Name: " << customer->name
             << ", userName: " << customer->userName
             << ", Active: " << (customer->isActive ? "Yes" : "No") << endl;
    } else {
        cout << "Customer with ID: " << id << " not found." << endl;
    }
}
// Tìm kiếm khách hàng theo ID
Customer* CustomerManager::findCustomer(int id) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].id == id) {
            return &customers[i];
        }
    }
    return NULL;
}
// Xóa khách hàng
void CustomerManager::removeCustomer(int id) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->id == id) {
            customers.erase(it);
            cout << "Removed customer with ID: " << id << endl;
            return;
        }
    }
    cout << "Not found customer with ID: " << id << endl;
}
// Tạo tài khoản
void CustomerManager::createAccount(int id) {
     string username;
     string password;
    Customer* customer = findCustomer(id);
    if (customer !=NULL) {
        if (customer->userName.empty() && customer->passWord.empty()) {
                cout << "Enter username: ";
                getline(cin, customer->userName);
                cin.ignore();
                cout << "Enter password: ";
                getline(cin, customer->passWord);
                cin.ignore();
            cout << "Account created for customer ID: " << id << endl;
        } else {
            cout << "Customer ID: " << id << " already has an account." << endl;
        }
    } else {
        cout << "Customer with ID: " << id << " not found. Cannot create account." << endl;
    }
}
// Hiển thị danh sách khách hàng
void CustomerManager::displayCustomers() {
    cout << "List of Customers:" << endl;
    for (const auto& customer : customers) {
        cout << "ID: " << customer.id
             << ", Name: " << customer.name
             << ", userName: " << customer.userName
             << ", Active: " << (customer.isActive ? "Yes" : "No") << endl;
    }
}
//kiểm tra hoạt động của khách hàng
bool CustomerManager::isActiveCustomer(int id){
    Customer* customer=findCustomer(id);
    if(customer!=NULL){
        return customer->isActive;
    }
    else{
            return false;
    }
}
//in ra danh sách khách hàng đang hoạt động
void CustomerManager::printActiveCustomer() {
   cout << "List of Active Customers:" << endl;
    bool foundActive = false;
    for (const auto& customer : customers) {
        if (customer.isActive) {
            cout << "ID: " << customer.id << ", Name: " << customer.name
                      << ", userName: " << customer.userName << endl;
            foundActive = true;
        }
    }
    if (!foundActive) {
       cout << "No active customers found." << endl;
    }
}
bool CustomerManager::loginCustomer(int id, const string& passWord) {
    for (const auto& customer : customers) {
        if (customer.id == id && customer.passWord == passWord) {
            cout << "Login successful for customer ID: " << id << endl;
            return true;
        }
    }
    cout << "Invalid ID or password. Please try again.\n";
    return false;
}

void CustomerManager::registerCustomer(int id, const string& name, const string& password) {
    for (const auto& customer : customers) {
        if (customer.id == id) {
            cout << "Customer ID already exists. Please try again.\n";
            return;
        }
    }
    // customers.push_back(Customer(name, id, passWord));
    // cout << "Registration successful for customer: " << name << " (ID: " << id << ")\n";
}
//end class customer
//begin class computer
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
void ComputerManager::updateUsageTime(int id, double newUsageTime) {
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
// Đổi màu chữ trong console
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Hiển thị trạng thái máy tính với màu
void ComputerManager::displayColoredStatus() const {
    cout << "List of Computers (with status color):" << endl;

    // Duyệt qua danh sách máy tính (đảm bảo hiển thị đủ 10 máy)
    for (int i = 0; i < 10; ++i) {
        cout << "ID: " << (i + 1) << ", Name: Computer" << (i + 1) << ", Status: ";

        // Kiểm tra trạng thái máy tính và thay đổi màu sắc tương ứng
        if (i >= computers.size() || !computers[i].isAvailable) {
            setTextColor(4); // Màu đỏ: không khả dụng
            cout << "Not Available\n";
        } else {
            setTextColor(2); // Màu xanh: khả dụng
            cout << "Available\n";
        }
        setTextColor(7); // Reset về màu mặc định
    }

    // Chạy đồng hồ thời gian thực (chỉ một lần, không cần khởi tạo nhiều thread)
    std::thread clockThread(&ComputerManager::runInteractiveClock, this);
    clockThread.detach(); // Tách thread để nó chạy độc lập
}

void ComputerManager::selectComputerForCustomer(int id, CustomerManager& customerManager) {
    if (id < 1 || id > 10) {
        cout << "Invalid computer ID. Please select an ID between 1 and 10.\n";
        return;
    }

    if (id > computers.size()) {
        // Thêm máy tính mới nếu chưa có
        computers.resize(id, Computer("Computer" + to_string(id), id, false));
    }

    if (computers[id - 1].isAvailable) {
        cout << "Computer " << id << " is already in use. Please select another computer.\n";
        return;
    }

    // Yêu cầu đăng nhập hoặc tạo tài khoản
    cout << "Please log in to use the computer.\n";
    int customerId;
    string password;
    cout << "Enter your customer ID: ";
    cin >> customerId;
    cout << "Enter your password: ";
    cin >> password;

    if (!customerManager.loginCustomer(customerId, password)) {
        cout << "Would you like to create a new account? (yes/no): ";
        string choice;
        cin >> choice;

        if (choice == "yes") {
            string name;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Set a password: ";
            cin >> password;

            customerManager.registerCustomer(customerId, name, password);
        } else {
            cout << "Login failed. Cannot assign computer.\n";
            return;
        }
    }

    // Đăng nhập thành công hoặc đã tạo tài khoản -> Chuyển trạng thái máy tính
    computers[id - 1].isAvailable = true;
    cout << "Computer " << id << " is now assigned to customer ID: " << customerId << ".\n";
}
double calculateUsageTime(bool &isAvailable) {
    auto start = std::chrono::system_clock::now();

    while (isAvailable) {
        auto now = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Tạm dừng 1 giây để giảm tải CPU
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    return elapsed.count();
}
void ComputerManager:: runInteractiveClock() {
    std::atomic<bool> stop(false); // Cờ dừng chương trình
    auto start = std::chrono::steady_clock::now();

    // Thread để cập nhật thời gian thực
    std::thread clockThread([&]() {
        while (!stop) {
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start);
            int hours = elapsed.count() / 3600;
            int minutes = (elapsed.count() % 3600) / 60;
            int seconds = elapsed.count() % 60;
            // Di chuyển con trỏ lên đầu và in đè
            std::cout << "\033[H"; // Di chuyển con trỏ về góc trên cùng
            std::cout << "|  "
                  << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << "  |" << std::endl;
            std::cout<< "\033[?25l";

            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Cập nhật mỗi 0.5 giây
        }
    });
    clockThread.join();
}
//end class Computer
//begin class Payment
// ham khoi tao
Payment :: Payment(int customerId, double ratePerHour, int usageTimeInMinutes)
    : customerId(customerId), ratePerHour(ratePerHour), usageTimeInMinutes(usageTimeInMinutes), isPaid(false), totalAmount(0.0) {}
// tinh tong so tien dua tren thoi gian su dung
void Payment :: calculateTotalAmount() {
    totalAmount = (usageTimeInMinutes / 60.0) * ratePerHour;
}
// xu li thanh toan
void Payment :: processPayment() {
    isPaid = true;
    cout << "Payment complete for customer ID: " << customerId << endl;
}
// hien thi chi tiet thanh toan
void Payment :: displayPaymentDetails() const {
    cout << "Customer ID: " << customerId << endl;
    cout << "Usage time: " << usageTimeInMinutes << " minutes" << endl;
    cout << "Total amount: $" << totalAmount << endl;
    cout << "Payment status: " << (isPaid ? "Completed" : "Pending") << endl;
}
// kiem tra thanh toan da duoc thuc hien chua
bool Payment :: isPaymentComplete() const {
    return isPaid;
}
// cap nhat thoi gian su dung va tinh lai tien
void Payment :: updateUsageTime(int newUsageTime) {
    usageTimeInMinutes = newUsageTime;
    calculateTotalAmount();
}
