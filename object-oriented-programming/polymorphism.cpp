#include <iostream>
using namespace std;

class Shape {
public:
    virtual double calculateArea() {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        return 3.14159265359 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() override {
        return width * height;
    }
};

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    // Create an array of Shape pointers
    Shape* shapes[] = { &myCircle, &myRectangle };

    for (Shape* shape : shapes) {
        cout << "Area: " << shape->calculateArea() << endl;
    }

    return 0;
}
