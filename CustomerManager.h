#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include<iostream>
#include<string>
class Customer{
    public:
        string name;
        int id;
        bool isActive;
        string userName;
        string passWord;
        //khoi tao mặc định
        Customer();
        //khởi tạo có tham số
        Customer(string name, int id, bool isActive = true, string userName, string passWord);


};
class CustomerManager{
    private:
        vector<Customer> customers;
    public:
        //tạo tài khoản cho khách hàng
        void createAccount(string userName, string passWord, int id);
        //them khách hàng vào danh sách
        void addCustomer();
        //xóa khách hàng ra khởi danh sách
        void removeCustomer(int id);
        //hiển thị thông tin khách hàng
        void displayCustomer(int id);
        // tìm kiếm khách hàng theo id
        void findCustmer(int id);
        //kiểm tra trạng thái hoạt động của khách hàng theo id
        bool isActiveCustomer(int id);
        //in ra danh sách khách hàng đang hoạt động
        void printActiveCustomer();
};
#endif
