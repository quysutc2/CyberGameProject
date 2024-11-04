#include <iostream>
#include "CustomerManager.cpp"
#include "CustomerManager.h"
#include "Computer.cpp"
#include "Computer.h"
#include "Payment.cpp"
#include "Payment.h"
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
    Manager(string name){
        this->name = name;
    }
    Manager(int id, int password, string name) : AuthenticatedManager(){
        this->id = id;  
        this->password = password;
        this->name = name;
    }
    bool signIn() override { // ghi de
        int idManager;
        int passWord;
        int a = 0;
        do {
            cout << "Tai khoan: ";
            cin >> idManager;
            cout << "Mat khau: ";
            cin >> passWord;
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
    cout << "Vui long dang nhap de tiep tuc!"<<endl;
    if (mng1.signIn() == 1)
    {
        cout << "Chao mung " << mng1.name << "!" << " Chuc mot ngay lam viec tot lanh :)" << endl;
        int choice;
        bool thoat = false;
        while (!thoat) {
            cout << "1. Quan li khach hang." << endl;
            cout << "2. Quan li may tinh." << endl;
            cout << "3. Quan li thanh toan." << endl;
            cout << "4. Thoat." << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice){
                case 1:{
                    int choice1;
                    CustomerManager customerManager;
                    do {
                    cout << "\n--- Customer Manager Menu ---" << endl;
                    cout << "1. Them khach hang." << endl;
                    cout << "2. Hien thi chi tiet khach hang." << endl;
                    cout << "3. Xoa khach hang." << endl;
                    cout << "4. Tao tai khoan." << endl;
                    cout << "5. Kiem tra tai khoan co hoat dong khong." << endl;
                    cout << "6. Hien thi tai khoan dang hoat dong." << endl;
                    cout << "7. Hien thi danh sach khach hang." << endl;
                    cout << "8. Thoat." << endl;
                    cout << "Moi nhap lua chon: ";
                    cin >> choice1;
                    switch (choice1) {
                        case 1: {
                            string name;
                            int id;
                            cout << "Nhap ten: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "Nhap id: ";
                            cin >> id;
                            customerManager.addCustomer(name, id);
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
                            int id;
                            cout << "Nhap id khach hang de xoa: ";
                            cin >> id;
                            customerManager.removeCustomer(id);
                            break;
                        }
                        case 4: {
                            int id;
                            string username, password;
                            cout << "Nhap id khach hang de tao tai khoan: ";
                            cin >> id;
                            customerManager.createAccount(id);
                            break;
                        }
                        case 5: {
                            int id;
                            cout << "Kiem tra tai khoan hoat dong: ";
                            cin>>id;
                            bool isActive = customerManager.isActiveCustomer(id);
                            cout<<"Customer with ID " << id << (isActive ? "is active" : "not active") << endl;
                            break;
                        }
                        case 6: {
                            customerManager.printActiveCustomer();
                            break;
                        }
                        case 7: {
                            customerManager.displayCustomers();
                            break;
                        }
                        case 8:
                            cout << "Thoat chuong trinh thanh cong." << endl;
                            break;
                        default:
                            cout << "Khong co lua chon nay! Vui long nhap lai!" << endl;
                            break;
                        }
                    } while (choice1 != 8);
                    break;
                }
                case 2:{
                    ComputerManager manager;
                    int choice2;
                    do {
                        cout << "\n--- Computer Manager Menu ---" << endl;
                        cout << "1. Them may tinh moi" << endl;
                        cout << "2. Xoa may tinh" << endl;
                        cout << "3. Hien thi chi tiet may tinh" << endl;
                        cout << "4. Hien thi tat ca may tinh" << endl;
                        cout << "5. Cap nhat trang thai may tinh" << endl;
                        cout << "6. Cap nhat thoi gian su dung" << endl;
                        cout << "7. Hien thi may tinh co san" << endl;
                        cout << "8. Thoat" << endl;
                        cout << "Moi ban nhap lua chon cua ban: ";
                        cin >> choice2;
                        switch (choice2) {
                            case 1: {
                                string name;
                                int id;
                                bool isAvailable;
                                cout << "Nhap ten may tinh: ";
                                cin >> name;
                                cout << "Nhap id may tinh: ";
                                cin >> id;
                                cout << "May tinh co kha dung khong (1 la co, 0 la khong): ";
                                cin >> isAvailable;
                                manager.addComputer(name, id, isAvailable);
                                break;
                            }
                            case 2: {
                                int id;
                                cout << "Nhap id may tinh de xoa: ";
                                cin >> id;
                                manager.removeComputer(id);
                                break;
                            }
                            case 3: {
                                int id;
                                cout << "Nhap id cua may tinh de in chi tiet: ";
                                cin >> id;
                                manager.printDetailComputer(id);
                                break;
                            }
                            case 4: {
                                manager.displayComputers();
                                break;
                            }
                            case 5: {
                                int id;
                                bool isAvailable;
                                cout << "Nhap id cua may tinh de cap nhat trang thai: ";
                                cin >> id;
                                cout << "May tinh co san khong: (1 cho co, 0 cho khong)";
                                cin >> isAvailable;
                                manager.updateComputerStatus(id, isAvailable);
                                break;
                            }
                            case 6: {
                                int id, newUsageTime;
                                cout << "Nhap id cua may tinh de cap nhat thoi gian su dung: ";
                                cin >> id;
                                cout << "Nhap thoi gian su dung moi (theo gio): ";
                                cin >> newUsageTime;
                                manager.updateUsageTime(id, newUsageTime);
                                break;
                            }
                            case 7: {
                                vector<Computer> availableComputers = manager.getAvailableComputers();
                                cout << "May tinh kha dung:" << endl;
                                for (const auto& computer : availableComputers) {
                                    cout << "ID: " << computer.id << ", Ten: " << computer.name
                                        << ", Thoi gian su dung: " << computer.usageTime << " gio" << endl;
                                }
                                break;
                            }
                            case 8:
                                cout << "Thoat chuong trinh thanh cong" << endl;
                                break;
                            default:
                                cout << "Khong co lua chon nay! Vui long nhap lai." << endl;
                                break;
                        }
                    } while (choice2 != 8);
                    break;
                }
                case 3:{
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
                case 4:{
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