#include <iostream>
#include "CustomerManager.cpp"
#include "CustomerManager.h"
#include "Computer.cpp"
#include "Computer.h"
#include "Payment.cpp"
#include "Payment.h"
using namespace std;

class Manager{
    private:
        int id; int password;
    public:
        Manager();
        Manager(int id, int password);
        bool signIn();
};
Manager :: Manager()
{
    id = 1;
    password = 123;
}
Manager :: Manager(int id, int password)
{
    this->id = id;
    this->password = password;
}
bool Manager :: signIn()
{
    int idManager;
    int passWord;
    int a = 0;
    do{
        cout << "Tai khoan: "; cin >> idManager;
        cout << "Mat khau: "; cin >> passWord;
        if (this->id == idManager && this->password == passWord)
        {
            cout << "Dang nhap thanh cong!" << endl;
            a = 1;
        }
        else
            cout << "Tai khoan hoac mat khau sai! Vui long dang nhap lai!" << endl; 
    } while (a == 0);
    return 1;  
}
int main(){
    Manager mng1(123,123);
    cout << "Vui long dang nhap de tiep tuc!"<<endl;
    if (mng1.signIn() == 1)
    {
        int choice;
        bool thoat = false;
        while (!thoat) {
            cout << "\n--- Customer Manager Menu ---" << endl;
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
                    cout << "1. Them khach ham." << endl;
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

                    break;
                }
                case 3:{

                    break;
                }
                case 4:{
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