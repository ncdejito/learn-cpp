#include <iostream>
using namespace std;

class Vehicle {
public:
    int wheels;
    void Start() {
        cout << "The vehicle starts moving." << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        wheels = 4; // Specific to cars
    }
    void Honk() {
        cout << "Honk! Honk!" << endl;
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle() {
        wheels = 2; // Specific to bicycles
    }
    void RingBell() {
        cout << "Ding! Ding!" << endl;
    }
};

int main() {
    Car myCar;
    Bicycle myBike;

    cout << "My car has " << myCar.wheels << " wheels." << endl;
    myCar.Start();
    myCar.Honk();

    cout << "My bicycle has " << myBike.wheels << " wheels." << endl;
    myBike.Start();
    myBike.RingBell();

    return 0;
}
