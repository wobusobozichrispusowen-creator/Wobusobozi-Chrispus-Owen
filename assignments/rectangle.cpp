/*Take-home
Design a class called Rectangle with private members width and length.
The class should have public member functions for getting and setting the width and length, 
as well as functions for calculating the area and perimeter.
In the main function, create suitable examples that demonstrate creating Rectangle objects, 
setting and retrieving their dimensions, and calculating their area and perimeter.
*/
#include <iostream>

class Rectangle {
private:
    double width;
    double length;

public:
    // Setter functions
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            width = 0;
            std::cout << "Width must be positive. Set to 0.\n";
        }
    }

    void setLength(double l) {
        if (l > 0) {
            length = l;
        } else {
            length = 0;
            std::cout << "Length must be positive. Set to 0.\n";
        }
    }

    // Getter functions
    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }

    // Calculation functions
    double calculateArea() const {
        return width * length;
    }

    double calculatePerimeter() const {
        return 2 * (width + length);
    }
};

int main() {
    // Create a Rectangle object
    Rectangle rect;

    // Set dimensions 
    rect.setWidth(5.5);
    rect.setLength(10.0);

    // Retrieve and display dimensions 
    std::cout << " Rectangle Details \n";
    std::cout << "Width: " << rect.getWidth() << "\n";
    std::cout << "Length: " << rect.getLength() << "\n";

    // Calculate and display area and perimeter
    std::cout << "Area: " << rect.calculateArea() << "\n";
    std::cout << "Perimeter: " << rect.calculatePerimeter() << "\n";

    return 0;
}