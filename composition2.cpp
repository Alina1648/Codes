#include <iostream>
class Engine {
public:
    void start() {
        std::cout << "Engine is starting..." << std::endl;
    }
};
class Car {
private:
    Engine engine;  // Car has an Engine
public:
    void startCar() {
        engine.start();  // Using the engine to start the car
        std::cout << "Car is starting..." << std::endl;
    }
};
int main() {
    Car myCar;
    myCar.startCar();
    return 0;
}
