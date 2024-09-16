#include <iostream>
class Heart {
public:
    void beat() {
        std::cout << "Heart is beating..." << std::endl;
    }
};
class Human {
private:
    Heart heart;  // Human has a Heart
public:
    void live() {
        heart.beat();  // Heart beating as the human lives
        std::cout << "Human is living..." << std::endl;
    }
};

int main() {
    Human person;
    person.live();
    return 0;
}
