// COMSC-210 | Final 2 | Johnathan Perez Baltazar
#include <iostream>
#include <deque>
#include <vector>
#include <list>
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

struct IceCreamOrder {
    string name;
    string flavor;
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
    string flavors[ARRAY_SIZE] = {"Vanilla", "Chocolate", "Strawberry", "Mint", 
                                "Cookie Dough", "Rocky Road", "Pistachio", "Coffee",
                                "Mango", "Butter Pecan"};

    CoffeQueue line;
    deque<MuffinOrder> muffinOrders;
    vector<BracaletOrder> bracaletOrders;
    list<IceCreamOrder> iceCreamOrders;

    for (int i = 0; i < 3; i++){
        line.enqueue(names[rand() % ARRAY_SIZE], drinks[rand() % ARRAY_SIZE]);

        MuffinOrder order = {names[rand() % ARRAY_SIZE], 
                                "Muffin " + to_string(rand() % 5 + 1)};
        muffinOrders.push_back(order);
        
        BracaletOrder bOrder = {names[rand() % ARRAY_SIZE], 
                                colors[rand() % ARRAY_SIZE]};
        bracaletOrders.push_back(bOrder);

        IceCreamOrder iOrder = {names[rand() % ARRAY_SIZE], 
                                flavors[rand() % ARRAY_SIZE]};
        iceCreamOrders.push_back(iOrder);
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

    for (const auto& order : iceCreamOrders) {
        cout << "\n   Ice Cream Customer: " << order.name << ", Flavor: " 
                << order.flavor;
    }

    for (int round = 0; round <= 10; round++){
        line.dequeue();

        if (!muffinOrders.empty()) {
            muffinOrders.pop_front();
        }

        if (!bracaletOrders.empty()) {
            bracaletOrders.erase(bracaletOrders.begin());
        }

        if (!iceCreamOrders.empty()) {
            iceCreamOrders.pop_front();
        }

        if (rand() % 2 == 0) {
            line.enqueue(names[rand() % ARRAY_SIZE], drinks[rand() % ARRAY_SIZE]);
        }
        
        if (rand() % 2 == 0) {
            MuffinOrder m_Order = {names[rand() % ARRAY_SIZE], 
                "Muffin " + to_string(rand() % 5 + 1)};
            muffinOrders.push_back(m_Order);
        }
            
        if (rand() % 2 == 0) {
            BracaletOrder b_Order = {names[rand() % ARRAY_SIZE], 
                                    colors[rand() % ARRAY_SIZE]};
            bracaletOrders.push_back(b_Order);
        }

        if (rand() % 2 == 0) {
            IceCreamOrder i_Order = {names[rand() % ARRAY_SIZE], 
                                    flavors[rand() % ARRAY_SIZE]};
            iceCreamOrders.push_back(i_Order);
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

        if (bracaletOrders.empty()) {
            cout << "   Bracalet queue is empty!" << endl;
        } else {
            for (const auto& customer : bracaletOrders) {
                cout << "\n   Bracalet Customer: " << customer.name << ", Color: " 
                        << customer.bracalet;
            }
            cout << endl;
        }

        if (iceCreamOrders.empty()) {
            cout << "   Ice Cream queue is empty!" << endl;
        } else {
            for (const auto& customer : iceCreamOrders) {
                cout << "\n   Ice Cream Customer: " << customer.name << ", Flavor: " 
                        << customer.flavor;
            }
            cout << endl;
        }
    }

    return 0;
}