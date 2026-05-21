// COMSC-210 | Final 2 | Johnathan Perez Baltazar
#include <iostream>
using namespace std;

struct Customer {
    string name;
    string order;
    Customer* next;

    Customer(string n, string o) : name(n), order(o), next(nullptr) {}
};

class CoffeQueue {
private:
    Customer* front;
    Customer* rear;

public:
    CoffeQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(string name, string order) {
        Customer* newCustomer = new Customer(name, order);

        if(!rear) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
    }

    void dequeue() {
        if(!front) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Customer* temp = front;
        front = front->next;

        if(!front) {
            rear = nullptr;
        }

        delete temp;
    }
};

int main() {
    return 0;
}