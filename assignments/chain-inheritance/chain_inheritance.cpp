#include <iostream>
#include <string>

// Class 1 parent class
class Device {
protected:
    std::string brand;

public:
    Device(const std::string& b) : brand(b) {}

    void powerOn() {
        std::cout << "[" << brand << "] Device powering on..." << std::endl;
    }
};

// Class 2 Intermediate Class inherits from device
class Computer : public Device {
protected:
    int ramGB;

public:
    Computer(const std::string& b, int ram) : Device(b), ramGB(ram) {}

    void runCalculations() {
        std::cout << "Processing data using " << ramGB << "GB RAM." << std::endl;
    }
};

// Class 3 Inherits from Computer
class Laptop : public Computer {
private:
    int batteryLevel;

public:
    Laptop(const std::string& b, int ram, int battery) 
        : Computer(b, ram), batteryLevel(battery) {}

    void checkStatus() {
        std::cout << "\n Laptop Specs Info  " << std::endl;
        std::cout << "Brand: " << brand << " (Grandparent Property)" << std::endl;
        std::cout << "Memory: " << ramGB << "GB (Parent Property)" << std::endl;
        std::cout << "Battery: " << batteryLevel << "% (Local Property)" << std::endl;
    }

    void togglePowerSaving() {
        std::cout << "Power saving mode activated at " << batteryLevel << "% charge." << std::endl;
    }
};

int main() {
    // Creating the ultimate child object
    Laptop myLaptop("Apple", 16, 85);

    // 1. Calling grandparent function
    myLaptop.powerOn();

    // 2. Calling parent function
    myLaptop.runCalculations();

    // 3. Calling local functions
    myLaptop.togglePowerSaving();
    myLaptop.checkStatus();

    return 0;
}
