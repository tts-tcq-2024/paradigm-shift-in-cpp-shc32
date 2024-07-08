#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>
 
bool batteryIsOk(float temperature, float soc, float chargeRate);
 
std::unordered_map<std::string, bool> checkMeasure(const std::string& measureName, float measureValue, float lowerLimit, float upperLimit) {
    std::unordered_map<std::string, bool> results;
    bool status = true;
    if (measureValue < lowerLimit) {
        std::cout << measureName << " is too low!" << std::endl;
        status = false;
    } else if (measureValue > upperLimit) {
        std::cout << measureName << " is too high!" << std::endl;
        status = false;
    }
    results["status"] = status;
    return results;
}
 
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    auto tempResults = checkMeasure("Temperature", temperature, 0, 45);
    auto socResults = checkMeasure("State of Charge", soc, 20, 80);
    auto chargeResults = checkMeasure("Charge Rate", chargeRate, 0, 0.8f);
    return tempResults["status"] && socResults["status"] && chargeResults["status"];
}
 
int main() {
    // Test cases
    assert(batteryIsOk(25, 70, 0.7f) == true);
    assert(batteryIsOk(50, 85, 0.0f) == false);
    assert(batteryIsOk(-1, 70, 0.7f) == false);
    assert(batteryIsOk(25, 10, 0.7f) == false);
    assert(batteryIsOk(25, 70, 0.9f) == false);
    std::cout << "Some more tests needed" << std::endl;
    return 0;
}
