// COMSC-210 | Final 2 | Johnathan Perez Baltazar
#include <iostream>
using namespace std;


class CoffeQueue {
private:
    struct Customer {
        string name;
        string order;
        Customer* next;

        Customer(string n, string o) : name(n), order(o), next(nullptr) {}
    };

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

    void display() {
        Customer* temp = front;
        while(temp) {
            cout << "Customer: " << temp->name << ", Order: " << temp->order << endl;
            temp = temp->next;
        }
    }

    ~CoffeQueue() {
        while(front) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    srand(time(0));

    const int ARRAY_SIZE = 10;
    string names[ARRAY_SIZE] = {"Alice", "Bob", "Charlie", "Diana", "Ethan", 
                                "Fiona", "George", "Hannah", "Ian", "Julia"};
    string drinks[ARRAY_SIZE] = {"Latte", "Espresso", "Cappuccino", "Americano", "Mocha", 
                                "Macchiato", "Cold Brew", "Matcha", "Chai Tea", "Frappuccino"};
    return 0;

    CoffeQueue queue;
    for (int i = 0; i < 3; i++){
        queue.enqueue(names[rand() % ARRAY_SIZE], drinks[rand() % ARRAY_SIZE]);
    }
    queue.display();
}