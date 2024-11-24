#include "Computer.h"
#include <iostream>
#define NOMINMAX // Ngăn xung đột định nghĩa min/max của Windows
#define WIN32_LEAN_AND_MEAN // Giảm tải các định nghĩa không cần thiết
#include <windows.h> // Đặt sau các chỉ thị tiền xử lý trên
using namespace std;
#include <chrono>
#include <thread>
#include <iomanip>
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

    // Đảm bảo 10 máy tính ban đầu được hiển thị
    for (int i = 0; i < 10; ++i) {
        cout << "ID: " << (i + 1) << ", Name: Computer" << (i + 1) << ", Status: ";

        // Nếu chưa có dữ liệu về máy tính này, hiển thị màu đỏ
        if (i >= computers.size() || !computers[i].isAvailable) {
            setTextColor(4); // Màu đỏ (chưa sử dụng / không hoạt động)
            cout << "Not Available\n";
        } else {
            setTextColor(2); // Màu xanh (hoạt động)
            cout << "Available\n";
        }
        setTextColor(7); // Reset về màu mặc định


    }
}
void ComputerManager::selectComputerForCustomer(int computerId, CustomerManager& customerManager) {
    if (computerId < 1 || computerId > 10) {
        cout << "Invalid computer ID. Please select an ID between 1 and 10.\n";
        return;
    }

    if (computerId > computers.size()) {
        computers.resize(computerId, Computer("Computer" + to_string(computerId), computerId, false));
    }

    if (computers[computerId - 1].isAvailable) {
        cout << "Computer " << computerId << " is already in use. Please select another computer.\n";
        return;
    }

    int customerId;
    string password;

    cout << "Please log in to use the computer.\n";
    cout << "Enter your customer ID: ";
    cin >> customerId;
    cout << "Enter your password: ";
    cin >> password;

    if (!customerManager.loginCustomer(customerId, password)) {
        cout << "Would you like to create a new account? (yes/no): ";
        string choice;
        cin >> choice;

        if (choice == "yes") {
            customerManager.createAccount(customerId);
            // Kiểm tra dữ liệu đã được thêm
            customerManager.displayCustomers();
        } else {
            cout << "Login failed. Cannot assign computer.\n";
            return;
        }
    }

    computers[computerId - 1].isAvailable = true;
    computers[computerId - 1].startTime = std::chrono::system_clock::now(); // Lưu thời gian bắt đầu

    cout << "Computer " << computerId << " is now assigned to customer ID: " << customerId << ".\n";
}


double ComputerManager::calculateUsageTime(bool isAvailable) {
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
// void  runInteractiveClock() {
//     bool stop(false); // Cờ dừng chương trình
//     auto start = std::chrono::steady_clock::now();

//     // Thread để cập nhật thời gian thực
//     std::thread clockThread([&]() {
//         while (!stop) {
//             auto now = std::chrono::steady_clock::now();
//             auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start);
//             int hours = elapsed.count() / 3600;
//             int minutes = (elapsed.count() % 3600) / 60;
//             int seconds = elapsed.count() % 60;
//             // Di chuyển con trỏ lên đầu và in đè
//             std::cout << "\033[H"; // Di chuyển con trỏ về góc trên cùng
//             std::cout << "|  "
//                   << std::setw(2) << std::setfill('0') << hours << ":"
//                   << std::setw(2) << std::setfill('0') << minutes << ":"
//                   << std::setw(2) << std::setfill('0') << seconds << "  |" << std::endl;
//             std::cout<< "\033[?25l";

//             std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Cập nhật mỗi 0.5 giây
//         }
//     });
//     clockThread.join();
// }
void ComputerManager::returnComputer(int computerId, Payment& payment) {
    if (computerId < 1 || computerId > computers.size()) {
        cout << "ID máy tính không hợp lệ. Vui lòng chọn ID từ 1 đến " << computers.size() << ".\n";
        return;
    }

    Computer& computer = computers[computerId - 1];
    
    if (!computer.isAvailable) {
        cout << "Máy tính này hiện không đang được sử dụng.\n";
        return;
    }

    // Lấy thời gian hiện tại
    auto endTime = std::chrono::system_clock::now();

    // Tính toán thời gian sử dụng
    auto elapsed = std::chrono::duration_cast<std::chrono::minutes>(endTime - computer.startTime).count();
    double usageTime = static_cast<double>(elapsed); // Chuyển đổi sang kiểu double nếu cần

    // Cập nhật trạng thái máy tính
    computer.isAvailable = false;
    setTextColor(4); // Màu đỏ
    cout << "Máy tính ID: " << computerId << " đã được trả lại và chuyển sang trạng thái không có sẵn.\n";

    // Cập nhật thời gian sử dụng cho hóa đơn
    payment.updateUsageTime(static_cast<int>(usageTime)); // Thời gian sử dụng (phút)

    // Tính tổng số tiền
    payment.calculateTotalAmount();

    // Hiển thị hóa đơn
    cout << "Hóa đơn thanh toán:\n";
    payment.displayPaymentDetails();

    // Reset màu
    setTextColor(7);
}