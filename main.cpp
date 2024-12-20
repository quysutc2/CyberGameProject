#include <iostream>
#include <conio.h>
#include <string>
#include "CustomerManager.cpp"
#include "CustomerManager.h"
#include "Computer.cpp"
#include "Computer.h"
#include "Payment.cpp"
#include "Payment.h"
#include <thread>
#define NOMINMAX // Ngăn xung đột định nghĩa min/max của Windows
#define WIN32_LEAN_AND_MEAN // Giảm tải các định nghĩa không cần thiết
#include <windows.h> // Đặt sau các chỉ thị tiền xử lý trên
using namespace std;

// Hàm đổi màu văn bản
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
void printTitle() {
    setColor(12, 0); // Màu chữ đỏ (12), nền đen (0)
    cout << "Cypher Gaming" << endl;
    setColor(15, 0); // Khôi phục màu chữ mặc định (trắng)
}
void drawComputerMenuFrame() {
    setColor(15, 0); // Reset về màu mặc định trước khi in
    setColor(14, 1); // Màu chữ vàng, nền xanh
    std::cout << "+----------------------------------------+" << std::endl;
    std::cout << "|         COMPUTER MANAGER MENU          |" << std::endl;
    std::cout << "+----------------------------------------+" << std::endl;
    setColor(15, 1); // Màu chữ trắng, nền xanh
    std::cout << "|  1. Tao tai khoan                      |" << std::endl;
    std::cout << "|  2. Hien thi chi tiet khach hang       |" << std::endl;
    std::cout << "|  3. Danh sach khach hang               |" << std::endl;
    std::cout << "|  4. Hien thi trang thai may tinh       |" << std::endl;
    std::cout << "|  5. Chon may tinh cho khach hang       |" << std::endl;
    std::cout << "|  6. Tra may va thuc hien thanh toan    |" << std::endl;
    std::cout << "|  7. Thoat                              |" << std::endl;
    setColor(14, 1); // Màu chữ vàng, nền xanh
    std::cout << "+----------------------------------------+" << std::endl;
    setColor(15, 0); // Khôi phục màu nền đen
}


void enableUTF8Console() {
    SetConsoleOutputCP(CP_UTF8); // Đặt mã hóa UTF-8 cho console
    SetConsoleCP(CP_UTF8);       // Đặt mã hóa UTF-8 cho đầu vào
}
class AuthenticatedManager {
protected:
    bool isLoggedIn = false;
    int id;
    int password;

public:
    virtual bool signIn() = 0; //ham ao
    bool isAuthenticated() const { return isLoggedIn; }
};

class Manager : public AuthenticatedManager {
private:
public:
    string name;
    Manager() {}
    Manager(string name) {
        this->name = name;
    }
    Manager(int id, int password, string name) : AuthenticatedManager() {
        this->id = id;
        this->password = password;
        this->name = name;
    }
    bool signIn() override { // ghi de
        int idManager;
        string passWordInput;
        int a = 0;
        do {
            cout << "Tai khoan: ";
            cin >> idManager;

            // Nhập mật khẩu dạng *
            cout << "Mat khau: ";
            passWordInput.clear();
            char ch;
            while ((ch = _getch()) != '\r') { // Nhấn Enter để kết thúc
                if (ch == '\b') { // Xử lý phím Backspace
                    if (!passWordInput.empty()) {
                        passWordInput.pop_back();
                        cout << "\b \b"; // Xóa ký tự trên màn hình
                    }
                } else {
                    passWordInput += ch;
                    cout << '*'; // Hiển thị dấu *
                }
            }
            cout << endl;

            // Chuyển chuỗi mật khẩu thành số nguyên
            int passWord = stoi(passWordInput);

            if (this->id == idManager && this->password == passWord) {
                cout << "Dang nhap thanh cong!" << endl;
                isLoggedIn = true;
                a = 1;
            } else {
                cout << "Tai khoan hoac mat khau sai! Vui long dang nhap lai!" << endl;
            }
        } while (a == 0);
        return isLoggedIn;
    }
    // Toán tử gán
    Manager& operator=(const Manager& other) {
        if (this != &other) { // Kiểm tra tự gán
            this->id = other.id;
            this->password = other.password;
            this->isLoggedIn = other.isLoggedIn;
        }
        return *this;
    }

    // Toán tử so sánh ==
    bool operator==(const Manager& other) const {
        return this->id == other.id && this->password == other.password;
    }

    // Toán tử so sánh !=
    bool operator!=(const Manager& other) const {
        return !(*this == other);
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& os, const Manager& manager) {
        os << "Manager ID: " << manager.id << ", Status: "
           << (manager.isLoggedIn ? "Logged in" : "Not logged in");
        return os;
    }
};
int main() {
    enableUTF8Console();
    printTitle();
    Manager mng1(123, 123, "Alex");
    cout << "Vui long dang nhap de tiep tuc!" << endl;

    if (mng1.signIn() == 1) {
        cout<<"Hi "<<mng1.name<<"!!"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        CustomerManager customerManager; // T?o d?i tu?ng qu?n lý khách hàng
        ComputerManager manager;         // T?o d?i tu?ng qu?n lý máy tính
        Payment payment(0, 2000, 0);
        int choice2;
        do {
            system("cls"); // Xóa màn hình để hiển thị menu mới
            manager.displayColoredStatus();
            drawComputerMenuFrame(); // Gọi hàm vẽ menu khung

            cout << "\nMoi ban nhap lua chon cua ban: ";
            cin >> choice2;
            switch (choice2) {
                case 1: {
                    int id;
                    string username, password;
                    cout << "Nhap id khach hang de tao tai khoan: ";
                    cin >> id;
                    customerManager.createAccount(id);
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
                case 2: {
                    int id;
                    cout << "Nhap id khach hang de hien thi thong tin: ";
                    cin >> id;
                    customerManager.printCustomerDetails(id);
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
                case 3: {
                    customerManager.displayCustomers();
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
                case 4: { // Menu hi?n th? tr?ng thái v?i màu s?c
                    cout << "\n--- Display Computer Status with Color ---" << endl;
                    manager.displayColoredStatus();
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
                case 5: {
                    int id;
                    cout << "Enter computer ID (1-10) to assign to customer: ";
                    cin >> id;
                    manager.selectComputerForCustomer(id, customerManager); // S? d?ng customerManager chính
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
                case 6: {
                    int computerId;
                    cout << "Nhập ID máy tính bạn muốn trả: ";
                    cin >> computerId;

                    // Gọi hàm trả máy tính
                    manager.returnComputer(computerId, payment, customerManager);
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    _getch();
                    break;
                }
                case 7:{
                    cout << "Thoat chuong trinh thanh cong" << endl;
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
                default:
                {
                    cout << "Khong co lua chon nay! Vui long nhap lai." << endl;
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    _getch();
                    break;
                }
            }
        } while (choice2 != 7);
    }
    return 0;
}
