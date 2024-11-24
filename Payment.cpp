#include "Payment.h"
using namespace std;
// ham khoi tao
Payment :: Payment(int customerId, double ratePerMinute, int usageTimeInMinutes)
    : customerId(customerId), ratePerMinute(ratePerMinute), usageTimeInMinutes(usageTimeInMinutes), isPaid(false), totalAmount(0.0) {}
// tinh tong so tien dua tren thoi gian su dung
void Payment :: calculateTotalAmount() {
    totalAmount = (usageTimeInMinutes / 60.0) * ratePerMinute;
}
// xu li thanh toan
void Payment :: processPayment() {
    isPaid = true;
    cout << "Payment complete for customer ID: " << customerId << endl;
}
// hien thi chi tiet thanh toan
void Payment :: displayPaymentDetails() const {
    cout << "Usage time: " << usageTimeInMinutes << " minutes" << endl;
    cout << "Total amount: $" << totalAmount << endl;
    cout << "Payment status: " << (isPaid ? "Completed" : "Pending") << endl;
}
// kiem tra thanh toan da duoc thuc hien chua
bool Payment :: isPaymentComplete() const {
    return isPaid;
}
// cap nhat thoi gian su dung va tinh lai tien 
void Payment :: updateUsageTime(int newUsageTime) {
    usageTimeInMinutes = newUsageTime;
    calculateTotalAmount();
}