#include <iostream>
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
    return 0;
}