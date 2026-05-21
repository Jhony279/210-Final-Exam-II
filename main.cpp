// COMSC-210 | Final 2 | Johnathan Perez Baltazar
#include <iostream>
using namespace std;

struct Customer {
    string name;
    string order;
    Customer* next;

    Customer(string n, string o) : name(n), order(o), next(nullptr) {}
};

int main() {
    return 0;
}