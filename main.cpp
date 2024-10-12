#include <iostream>
#include <CustomerManager.h>
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
    bool a = false;
    do{
        cout << "Account: "; cin >> idManager; cout << endl;
        cout << "Password: "; cin >> passWord; cout << endl;
        if (this->id == idManager && this->password == passWord)
        {
            cout << "Login succes!";
            a = true;
        }
        else
            cout << "Tai khoan hoac mat khau sai! Vui long dang nhap lai!"; 
    } while (a != true);
    return 1;  
}
int main(){
    Manager mng1(123,123);
    cout << "Vui long dang nhap de tiep tuc!"<<endl;
    mng1.signIn();
    if (mng1.signIn() == 1)
    {
        int choice;
        bool thoat = false;
        while (thoat) {
            cout << "1. Quan li khach hang." << endl;
            cout << "2. Quan li may tinh." << endl;
            cout << "3. Quan li thanh toan." << endl;
            cout << "4. Thoat." << endl;
            cout << "Moi nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice){
                case 1:{

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