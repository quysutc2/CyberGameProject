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
// Hàm vẽ khung menu
void drawMenuFrame() {
    const int frameWidth = 40;
    setColor(15, 1); // Màu chữ trắng, nền xanh
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║          CHUONG TRINH QUAN LY          ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;
    cout << "║  1. Quan li may tinh                   ║" << endl;
    cout << "║  2. Thoat                              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    setColor(15, 0); // Khôi phục màu nền đen
}
void drawComputerMenuFrame() {
    setColor(14, 1); // Màu chữ vàng, nền xanh
    cout << "+----------------------------------------+" << endl; // 40 ký tự
    cout << "|         COMPUTER MANAGER MENU          |" << endl; // 40 ký tự
    cout << "+----------------------------------------+" << endl;
    setColor(15, 1); // Màu chữ trắng, nền xanh
    cout << "|  1. Tao tai khoan                      |" << endl; // 40 ký tự
    cout << "|  2. Hien thi chi tiet khach hang       |" << endl;
    cout << "|  3. Danh sach khach hang               |" << endl;
    cout << "|  4. Hien thi may tinh co san           |" << endl;
    cout << "|  5. Hien thi trang thai may tinh voi   |" << endl;
    cout << "|     mau sac                            |" << endl; // Tách dòng để vừa khung
    cout << "|  6. Chon may tinh cho khach hang       |" << endl;
    cout << "|  7. Tra may va thuc hien thanh toan    |" << endl;
    cout << "|  8. Thoat                              |" << endl;
    setColor(14, 1); // Màu chữ vàng, nền xanh
    cout << "+----------------------------------------+" << endl;
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
        cout << "Chao mung " << mng1.name << "!" << " Chuc mot ngay lam viec tot lanh :)" << endl;
        int choice;
        bool thoat = false;

        while (!thoat) {
            system("cls"); // Xóa màn hình console
            drawMenuFrame(); // Hi?n th? khung menu
            cout << "Moi nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice) {
                case 1:{
                    CustomerManager customerManager; // T?o d?i tu?ng qu?n lý khách hàng
                    ComputerManager manager;         // T?o d?i tu?ng qu?n lý máy tính
                    Payment payment(0, 2000, 0);
                    int choice2;
                    do {
                        system("cls"); // Xóa màn hình để hiển thị menu mới
                        drawComputerMenuFrame(); // Gọi hàm vẽ menu khung
                        cout << "Moi ban nhap lua chon cua ban: ";
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
                            case 4: {
                                vector<Computer> availableComputers = manager.getAvailableComputers();
                                cout << "May tinh kha dung:" << endl;
                                for (const auto& computer : availableComputers) {
                                    cout << "ID: " << computer.id << ", Ten: " << computer.name
                                        << ", Thoi gian su dung: " << computer.usageTime << " gio" << endl;
                                }
                                cout << "\nNhan phim bat ky de tiep tuc...";
                                _getch();
                                break;
                            }
                            case 5: { // Menu hi?n th? tr?ng thái v?i màu s?c
                                cout << "\n--- Display Computer Status with Color ---" << endl;
                                manager.displayColoredStatus();
                                cout << "\nNhan phim bat ky de tiep tuc...";
                                _getch();
                                break;
                            }
                            case 6: {
                                int id;
                                cout << "Enter computer ID (1-10) to assign to customer: ";
                                cin >> id;
                                manager.selectComputerForCustomer(id, customerManager); // S? d?ng customerManager chính
                                cout << "\nNhan phim bat ky de tiep tuc...";
                                _getch();
                                break;
                            }
                            case 7: {
                                int computerId;
                                cout << "Nhập ID máy tính bạn muốn trả: ";
                                cin >> computerId;

                                // Gọi hàm trả máy tính
                                manager.returnComputer(computerId, payment, customerManager);
                                cout << "\nNhan phim bat ky de tiep tuc...";
                                _getch(); 
                                break;
                            }
                            case 8:{
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
                    } while (choice2 != 8);
                    break;
                }
                case 2:
                    cout << "Cam on da su dung chuong trinh!";
                    thoat = true;
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long nhap lai!" << endl;
            }
            if (!thoat) {
                cout << "\nNhan phim bat ky de tiep tuc...";
                _getch();
            }
        }
    }
    return 0;
}
