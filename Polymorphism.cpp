#include <iostream>
#include <vector>

class PaymentMethod {
public:
virtual void processPayment(double amount) {
std::cout << "Processing a generic payment of $" << amount << std::endl;
    }

virtual ~PaymentMethod() {} 
};

class CreditCard : public PaymentMethod {
public:
void processPayment(double amount) override {
std::cout << "Processing credit card payment of $" << amount << " via Gateway." << std::endl;
    }
};

class PayPal : public PaymentMethod {
public:
void processPayment(double amount) override {
std::cout << "Redirecting to PayPal to complete payment of $" << amount << "." << std::endl;
    }
};

int main() {
std::vector<PaymentMethod*> payments;   
payments.push_back(new CreditCard());
payments.push_back(new PayPal());

std::cout << "--- Executing Polymorphic Calls ---" << std::endl;
for (PaymentMethod* method : payments) {
method->processPayment(150.00); // Calls the specific overridden function dynamically
    }

for (PaymentMethod* method : payments) {
delete method;
    }

    return 0;
}
