#include <iostream>
#include <string>
using namespace std;

class Address; // Forward declaration

class Person {
private:
    string name;
    Address* address;  // Pointer to Address
public:
    Person(string n) : name(n), address(nullptr) {}

    void setAddress(Address* addr) {
        address = addr;
    }

    void showAddress();
};

class Address {
private:
    string city;
public:
    Address(string c) : city(c) {}

    string getCity() {
        return city;
    }
};

void Person::showAddress() {
    if (address != nullptr) {
        cout << name << " lives in " << address->getCity() << endl;
    } else {
        cout << name << " has no address set." << endl;
    }
}

int main() {
    Person person("John");
    Address address("New York");

    person.setAddress(&address);  // Set bidirectional association
    person.showAddress();

    return 0;
}
