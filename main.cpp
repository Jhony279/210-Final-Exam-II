// COMSC-210 | Final 2 | Johnathan Perez Baltazar
#include <iostream>
#include <deque>
#include <vector>
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
            cout << "   Coffee Queue is empty!" << endl;
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
            cout << "\n   Coffee Customer: " << temp->name << ", Order: " 
                    << temp->order;
            temp = temp->next;
        }
        cout << endl;
    }

    ~CoffeQueue() {
        while(front) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

struct MuffinOrder {
    string name;
    string muffin;
};

struct BracaletOrder {
    string name;
    string bracalet;
};

int main() {
    srand(time(0));

    const int ARRAY_SIZE = 10;
    string names[ARRAY_SIZE] = {"Alice", "Bob", "Charlie", "Diana", "Ethan", 
                                "Fiona", "George", "Hannah", "Ian", "Julia"};
    string drinks[ARRAY_SIZE] = {"Latte", "Espresso", "Cappuccino", "Americano", 
                                "Mocha", "Macchiato", "Cold Brew", "Matcha", 
                                "Chai Tea", "Frappuccino"};
    string colors[ARRAY_SIZE] = {"Red", "Blue", "Green", "Yellow", "Purple", 
                                "Pink", "Orange", "Black", "White", "Rainbow"};

    CoffeQueue line;
    deque<MuffinOrder> muffinOrders;
    deque<BracaletOrder> bracaletOrders;

    for (int i = 0; i < 3; i++){
        line.enqueue(names[rand() % ARRAY_SIZE], drinks[rand() % ARRAY_SIZE]);

        MuffinOrder order = {names[rand() % ARRAY_SIZE], 
                                "Muffin " + to_string(rand() % 5 + 1)};
        muffinOrders.push_back(order);
        
        BracaletOrder bOrder = {names[rand() % ARRAY_SIZE], 
                                colors[rand() % ARRAY_SIZE]};
        bracaletOrders.push_back(bOrder);
    }

    cout << "\nInitial Queue:";
    line.display();

    for (const auto& order : muffinOrders) {
        cout << "\n   Muffin Customer: " << order.name << ", Muffin: " 
                << order.muffin;
    }

    for (const auto& order : bracaletOrders) {
        cout << "\n   Bracalet Customer: " << order.name << ", Bracalet: " 
                << order.bracalet;
    }

    for (int round = 0; round <= 10; round++){
        line.dequeue();

        if (!muffinOrders.empty()) {
            muffinOrders.pop_front();
        }

        if (!bracaletOrders.empty()) {
            bracaletOrders.pop_front();
        }

        if (rand() % 2 == 0) {
            line.enqueue(names[rand() % ARRAY_SIZE], drinks[rand() % ARRAY_SIZE]);
        }

        if (rand() % 2 == 0) {
            MuffinOrder order = {names[rand() % ARRAY_SIZE], 
                                    "Muffin " + to_string(rand() % 5 + 1)};
            muffinOrders.push_back(order);
        }

        cout << "\nRound " << round + 1 << ":";
        line.display();

        if (muffinOrders.empty()) {
            cout << "   Muffin queue is empty!" << endl;
        } else {
            for (const auto& customer : muffinOrders) {
                cout << "\n   Muffin Customer: " << customer.name << ", Order: " 
                        << customer.muffin;
            }
            cout << endl;
        }
    }

    return 0;
}