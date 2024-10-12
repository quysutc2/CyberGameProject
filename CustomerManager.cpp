#include "CustomerManager.h"

// Thêm một khách hàng vào danh sách
void CustomerManager::addCustomer(const string& name, int id) {
    customers.push_back(Customer(name, id));
    cout << "Added customer: " << name << " with ID: " << id << endl;
}
// In thông tin khách hàng đang tìm kiếm
void CustomerManager::printCustomerDetails(int id) {
    Customer* customer = findCustomer(id);
    if (customer != nullptr) {
        cout << "Customer Details - ID: " << customer->id
             << ", Name: " << customer->name
             << ", userName: " << customer->userName
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
}
// Tạo tài khoản
void CustomerManager::createAccount(int id) {
     string username;
     string password;
    Customer* customer = findCustomer(id);
    if (customer !=NULL) {
        if (customer->userName.empty() && customer->passWord.empty()) {
                cout << "Enter username: ";
                getline(cin, username);
                cin.ignore();
                cout << "Enter password: ";
                getline(cin, password);
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
             << ", userName: " << customer.userName
             << ", Active: " << (customer.isActive ? "Yes" : "No") << endl;
    }
}
//kiểm tra hoạt động của khách hàng
bool CustomerManager::isActiveCustomer(int id){
    Customer* customer=findCustomer(id);
    if(customer!=NULL){
        return customer->isActive;
    }
    else{
            return false;
    }
}
//in ra danh sách khách hàng đang hoạt động
void CustomerManager::printActiveCustomer() {
   cout << "List of Active Customers:" << endl;
    bool foundActive = false;
    for (const auto& customer : customers) {
        if (customer.isActive) {
            cout << "ID: " << customer.id << ", Name: " << customer.name
                      << ", userName: " << customer.userName << endl;
            foundActive = true;
        }
    }
    if (!foundActive) {
       cout << "No active customers found." << endl;
    }
}
