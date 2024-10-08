#include "CustomerManager.h"
#include <iostream>
#include <vector>
using namespace std;

// Thêm một khách hàng vào danh sách
void CustomerManager::addCustomer(const std::string& name, int id) {
    customers.push_back(Customer(name, id));
    cout << "Added customer: " << name << " with ID: " << id << endl;
}
// In thông tin khách hàng đang tìm kiếm
void CustomerManager::printCustomerDetails(int id) {
    Customer* customer = findCustomer(id);
    if (customer != nullptr) {
        cout << "Customer Details - ID: " << customer->id
             << ", Name: " << customer->name
             << ", userName: " << customer->username
             << ", Active: " << (customer->isActive ? "Yes" : "No") << endl;
    } else {
        cout << "Customer with ID: " << id << " not found." << endl;
    }
}
// Tìm kiếm khách hàng theo ID
Customer* CustomerManager::findCustomer(int id) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].id == id) {
            return &customers[i];
        }
    }
    return NULL;
}
// Xóa khách hàng
void CustomerManager::removeCustomer(int id) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->id == id) {
            customers.erase(it);
            cout << "Removed customer with ID: " << id << endl;
            return;
        }
    }
    cout << "Not found customer with ID: " << id << endl;
// Tạo tài khoản
void CustomerManager::createAccount(int id, const string& username, const string& password) {
    Customer* customer = findCustomer(id);
    if (customer !=NULL) {
        if (customer->username.empty() && customer->password.empty()) {
            customer->username = username;
            customer->password = password;
            cout << "Account created for customer ID: " << id << endl;
        } else {
            cout << "Customer ID: " << id << " already has an account." << endl;
        }
    } else {
        cout << "Customer with ID: " << id << " not found. Cannot create account." << endl;
    }
}
// Hiển thị danh sách khách hàng
void CustomerManager::displayCustomers() {
    cout << "List of Customers:" << endl;
    for (const auto& customer : customers) {
        cout << "ID: " << customer.id
             << ", Name: " << customer.name
             << ", userName: " << customer.username
             << ", Active: " << (customer.isActive ? "Yes" : "No") << endl;
    }
}
