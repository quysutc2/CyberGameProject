#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <vector>
#include <iostream>

class Payment {
private:
    int customerId;            // ID của khách hàng thực hiện thanh toán
    double ratePerMinute;        // Giá tiền tính theo giờ
    double totalAmount;        // Tổng số tiền cần thanh toán
    int usageTimeInMinutes;    // Thời gian sử dụng (phút)
    bool isPaid;               // Trạng thái thanh toán (đã thanh toán hay chưa)

public:
    Payment(int customerId, double ratePerHour, int usageTimeInMinutes); // ham khoi tao
    void calculateTotalAmount(); // tinh tien dua tren thoi gian su dung
    void processPayment(); // thanh toan 
    void displayPaymentDetails() const; // hien thi chi tiet thanh toan
    bool isPaymentComplete() const; // kiem tra thanh toan da duoc thuc hien chua
    void updateUsageTime(int newUsageTime); // cap nhat thoi gian su dung de tinh lai tien
};
#endif 