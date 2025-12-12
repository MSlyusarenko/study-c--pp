#pragma once
#include <iostream>

class Car
{
private:
    bool isEngineOn;
    int currentSpeedKmH;
    int currentGear;
    int fuelLevel;

    static const int kMaxSpeedKmH = 200;
    static const int kMaxFuelLevel = 60;

public:
    Car();

    void printState() const;

    void startEngine();
    void stopEngine();

    void refuel(int fuelAmountToAdd);

    void setGear(int targetGear);

    void accelerate(int speedIncreaseKmH);
    void brake(int speedDecreaseKmH);
};
