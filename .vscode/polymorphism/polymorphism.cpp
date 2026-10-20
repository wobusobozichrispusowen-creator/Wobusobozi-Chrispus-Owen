#include <iostream>
#include <string>
#include <vector>

// 1. Parent Class
class SmartDevice {
protected:
    std::string deviceName;

public:
    // Constructor 
    SmartDevice(const std::string& name) : deviceName(name) {}
    
    
    virtual ~SmartDevice() = default;

    // The virtual function for polymorphism
    virtual void activate() {
        std::cout << "Activating generic smart device: " << deviceName << std::endl;
    }
};

// 2. First Derived Class
class SmartLight : public SmartDevice {
private:
    int brightnessPercentage;

public:
    SmartLight(const std::string& name, int brightness) 
        : SmartDevice(name), brightnessPercentage(brightness) {}

    void activate() override {
        std::cout << "[LIGHT] " << deviceName << " is turning ON. Brightness adjusted to " 
                  << brightnessPercentage << "%." << std::endl;
    }
};

// 3. Second Derived Class
class SmartThermostat : public SmartDevice {
private:
    double targetTemperature;

public:
    SmartThermostat(const std::string& name, double temp) 
        : SmartDevice(name), targetTemperature(temp) {}

    void activate() override {
        std::cout << "[THERMOSTAT] " << deviceName << " is initializing. Setting room climate to " 
                  << targetTemperature << "°C." << std::endl;
    }
};

int main() {
    std::cout << " Setting Up Smart Home Hub " << std::endl;

    SmartLight livingRoomLight("Living Room Lightbulb", 80);
    SmartThermostat hallwayThermostat("Hallway Nest Thermostat", 22.5);

    std::vector<SmartDevice*> smartHub;
    smartHub.push_back(&livingRoomLight);
    smartHub.push_back(&hallwayThermostat);

    std::cout << "\n Running Hub Automated Routine  " << std::endl;
    for (SmartDevice* devicePtr : smartHub) {
        devicePtr->activate(); 
    }

    return 0;
}
