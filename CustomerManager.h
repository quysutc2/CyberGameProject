#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Customer{
    public:
        string name;
        int id;
        bool isActive;
        string userName;
        string passWord;
        //khoi tao mặc định
        Customer(){
        name="";
        id=0;
        isActive=true;
        userName="";
        passWord="";
        }
        //khởi tạo có tham số
      Customer(string name, int id, bool isActive = true, string userName = "", string passWord = "") {
        this->name = name;
        this->id = id;
        this->isActive = isActive;
        this->userName = userName;
        this->passWord = passWord;
    }

};
class CustomerManager{
    private:
        vector<Customer> customers;
    public:
        //tạo tài khoản cho khách hàng
        void createAccount(int id);
        //them khách hàng vào danh sách
        void addCustomer(const string &name, int id);
        //xóa khách hàng ra khởi danh sách
        void removeCustomer(int id);
        //hiển thị thông tin khách hàng
        void displayCustomers();
        // tìm kiếm khách hàng theo id
        Customer *findCustomer(int id);
        //kiểm tra trạng thái hoạt động của khách hàng theo id
        bool isActiveCustomer(int id);
        //in ra danh sách khách hàng đang hoạt động
        void printActiveCustomer();
        //in ra thông tin chi tiết của một khách hàng theo id
        void printCustomerDetails(int id);
        bool loginCustomer(int id, const string& password);
        void registerCustomer(int id, const string& name, const string& password);
};
#endif
