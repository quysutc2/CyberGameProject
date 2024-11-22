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
    string name, passWord;
    cout << "Nhap ten khach hang: ";
    cin.ignore(); // Để bỏ qua newline còn lại trong buffer
    getline(cin, name);
    cout << "Nhap mat khau: ";
    cin >> passWord;

    Customer newCustomer(id, name, passWord); // Giả định có constructor phù hợp
    customers.push_back(newCustomer); // Thêm khách hàng vào danh sách
    cout << "Tao tai khoan thanh cong cho khach hang ID: " << id << endl;
}
// Hiển thị danh sách khách hàng
void CustomerManager::displayCustomers() const {
    if (customers.empty()) {
        cout << "Khong co khach hang nao!" << endl;
        return;
    }
    cout << "Danh sach khach hang:" << endl;
    for (const auto& customer : customers) {
        cout << "ID: " << customer.id << ", Name: " << customer.name << endl;
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
bool CustomerManager::loginCustomer(int id, const string& passWord) {
    for (const auto& customer : customers) {
        if (customer.id == id && customer.passWord == passWord) {
            cout << "Login successful for customer ID: " << id << endl;
            return true;
        }
    }
    cout << "Invalid ID or password. Please try again.\n";
    return false;
}

void CustomerManager::registerCustomer(int id, const string& name, const string& password) {
    for (const auto& customer : customers) {
        if (customer.id == id) {
            cout << "Customer ID already exists. Please try again.\n";
            return;
        }
    }
    customers.push_back(Customer(name, id, password));
    cout << "Registration successful for customer: " << name << " (ID: " << id << ")\n";
}
