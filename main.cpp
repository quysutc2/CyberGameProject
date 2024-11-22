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
int main(){
    Manager mng1(123,123, "Alex");
    CustomerManager customerManager;
    cout << "Vui long dang nhap de tiep tuc!"<<endl;
    if (mng1.signIn() == 1)
    {
        cout << "Chao mung " << mng1.name << "!" << " Chuc mot ngay lam viec tot lanh :)" << endl;
        int choice;
        bool thoat = false;
        while (!thoat) {
            // cout << "1. Quan li khach hang." << endl;
            cout << "1. Quan li may tinh." << endl;
            cout << "2. Quan li thanh toan." << endl;
            cout << "3. Thoat." << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice){
                case 1:{
                    CustomerManager customerManager; // Tạo đối tượng quản lý khách hàng
                    ComputerManager manager;         // Tạo đối tượng quản lý máy tính
                    int choice2;
                    do {
                        cout << "\n--- Computer Manager Menu ---" << endl;
                        cout << "1. Tao tai khoan" << endl;
                        cout << "2. Hien thi chi tiet khach hang" << endl;
                        cout << "3. Danh sach khach hang" << endl;
                        cout << "4. Hien thi may tinh co san" << endl;
                        cout << "5. Hien thi trang thai may tinh voi mau sac" << endl;
                        cout << "6. Chon may tinh cho khach hang" << endl;
                        cout << "7. Thoat" << endl;
                        cout << "Moi ban nhap lua chon cua ban: ";
                        cin >> choice2;
                        switch (choice2) {
                            case 1: {
                            int id;
                            string username, password;
                            cout << "Nhap id khach hang de tao tai khoan: ";
                            cin >> id;
                            customerManager.createAccount(id);
                            break;
                        }
                            case 2: {
                                int id;
                                cout << "Nhap id khach hang de hien thi thong tin: ";
                                cin >> id;
                                customerManager.printCustomerDetails(id);
                                break;
                            }
                            case 3: {
                                customerManager.displayCustomers();
                                break;
                            }
                            case 4: {
                                vector<Computer> availableComputers = manager.getAvailableComputers();
                                cout << "May tinh kha dung:" << endl;
                                for (const auto& computer : availableComputers) {
                                    cout << "ID: " << computer.id << ", Ten: " << computer.name
                                        << ", Thoi gian su dung: " << computer.usageTime << " gio" << endl;
                                }
                                break;
                            }
                            case 5: { // Menu hiển thị trạng thái với màu sắc
                                cout << "\n--- Display Computer Status with Color ---" << endl;
                                manager.displayColoredStatus();
                                break;
                            }
                            case 6: {
                                int id;
                                cout << "Enter computer ID (1-10) to assign to customer: ";
                                cin >> id;
                                manager.selectComputerForCustomer(id, customerManager); // Sử dụng customerManager chính
                                break;
                            }
                            case 7:{
                                cout << "Thoat chuong trinh thanh cong" << endl;
                                break;
                            }
                            default:
                                cout << "Khong co lua chon nay! Vui long nhap lai." << endl;
                                break;
                        }
                    } while (choice2 != 10);
                    break;
                }
                case 2:{
                    Payment payment(0, 0.0, 0);  // Khởi tạo đối tượng Payment, sau này sẽ cập nhật giá trị thật
                    int choice3;
                    do {
                        cout << "\n--- Payment Manager Menu ---" << endl;
                        cout << "1. Tinh tong so tien" << endl;
                        cout << "2. Xu ly thanh toan" << endl;
                        cout << "3. Hien thi chi tiet thanh toan" << endl;
                        cout << "4. Cap nhat thoi gian su dung" << endl;
                        cout << "5. Kiem tra trang thai thanh toan" << endl;
                        cout << "6. Thoat" << endl;
                        cout << "Moi nhap lua chon: ";
                        cin >> choice3;

                        switch (choice3) {
                            case 1: {
                                int id;
                                double rate;
                                int usageTime;
                                cout << "Nhap ID khach hang: ";
                                cin >> id;
                                cout << "Nhap gia tien theo gio (USD): ";
                                cin >> rate;
                                cout << "Nhap thoi gian su dung may (phut): ";
                                cin >> usageTime;
                                payment = Payment(id, rate, usageTime);
                                payment.calculateTotalAmount();
                                cout << "Tong so tien da duoc tinh toan!" << endl;
                                break;
                            }
                            case 2: {
                                payment.processPayment();
                                break;
                            }
                            case 3: {
                                payment.displayPaymentDetails();
                                break;
                            }
                            case 4: {
                                int newUsageTime;
                                cout << "Nhap thoi gian su dung moi (phut): ";
                                cin >> newUsageTime;
                                payment.updateUsageTime(newUsageTime);
                                cout << "Thoi gian su dung va tong so tien da duoc cap nhat!" << endl;
                                break;
                            }
                            case 5: {
                                bool isComplete = payment.isPaymentComplete();
                                cout << "Trang thai thanh toan: " << (isComplete ? "Da thanh toan" : "Chua thanh toan") << endl;
                                break;
                            }
                            case 6:
                                cout << "Thoat chuong trinh quan ly thanh toan." << endl;
                                break;
                            default:
                                cout << "Lua chon khong hop le! Vui long nhap lai!" << endl;
                                break;
                        }
                    } while (choice3 != 6);
                    break;
                }
                case 3:{
                    cout << "Cam on da su dung chuong trinh!";
                    thoat = true;
                    break;
                }
                default: 
                    cout << "Chuong trinh khong co phuong an lua chon nay! Vui long nhap lai!" << endl;
            }
        }
    }
    return 0;
}