#include "Car.h"
#include <algorithm> // std::min, std::max

Car::Car()
    : isEngineOn(false),
      currentSpeedKmH(0),
      currentGear(0),
      fuelLevel(10)
{
}

void Car::printState() const
{
    std::cout << "Ч —осто€ние автомобил€:\n";
    std::cout << "Ч ƒвигатель: " << (isEngineOn ? "¬ Ћ" : "¬џ Ћ") << "\n";
    std::cout << "Ч ѕередача: " << currentGear << "\n";
    std::cout << "Ч —корость: " << currentSpeedKmH << " км/ч\n";
    std::cout << "Ч “опливо: " << fuelLevel << "\n";
}

void Car::startEngine()
{
    if (isEngineOn)
    {
        std::cout << "Ч ƒвигатель уже запущен.\n";
        return;
    }
    if (fuelLevel <= 0)
    {
        std::cout << "Ч Ќет топлива.\n";
        return;
    }
    if (currentSpeedKmH != 0)
    {
        std::cout << "Ч Ќельз€ заводить на ходу.\n";
        return;
    }

    isEngineOn = true;
    std::cout << "Ч ƒвигатель запущен.\n";
}

void Car::stopEngine()
{
    if (!isEngineOn)
    {
        std::cout << "Ч ƒвигатель уже остановлен.\n";
        return;
    }
    if (currentSpeedKmH != 0)
    {
        std::cout << "Ч —начала остановитесь (скорость = 0).\n";
        return;
    }

    isEngineOn = false;
    currentGear = 0;
    std::cout << "Ч ƒвигатель остановлен.\n";
}

void Car::refuel(int fuelAmountToAdd)
{
    if (fuelAmountToAdd <= 0)
    {
        std::cout << "Ч Ќекорректное значение.\n";
        return;
    }

    fuelLevel = std::min(kMaxFuelLevel, fuelLevel + fuelAmountToAdd);
    std::cout << "Ч «аправка выполнена.\n";
}

void Car::setGear(int targetGear)
{
    if (targetGear < 0 || targetGear > 5)
    {
        std::cout << "Ч ѕередача должна быть 0..5.\n";
        return;
    }
    if (!isEngineOn && targetGear != 0)
    {
        std::cout << "Ч ƒвигатель выключен.\n";
        return;
    }
    if (targetGear == 0 && currentSpeedKmH > 0)
    {
        std::cout << "Ч Ќейтраль на ходу запрещена.\n";
        return;
    }

    currentGear = targetGear;
    std::cout << "Ч ѕередача установлена: " << currentGear << "\n";
}

void Car::accelerate(int speedIncreaseKmH)
{
    if (speedIncreaseKmH <= 0)
    {
        std::cout << "Ч ”величение скорости должно быть > 0.\n";
        return;
    }
    if (!isEngineOn)
    {
        std::cout << "Ч —начала запустите двигатель.\n";
        return;
    }
    if (currentGear == 0)
    {
        std::cout << "Ч ¬ключите передачу.\n";
        return;
    }
    if (fuelLevel <= 0)
    {
        std::cout << "Ч Ќет топлива.\n";
        return;
    }

    int targetSpeedKmH = std::min(kMaxSpeedKmH, currentSpeedKmH + speedIncreaseKmH);
    int fuelSpent = std::max(1, (targetSpeedKmH - currentSpeedKmH) / 10); // условный расход

    if (fuelSpent > fuelLevel)
    {
        std::cout << "Ч Ќе хватает топлива дл€ ускорени€.\n";
        return;
    }

    fuelLevel -= fuelSpent;
    currentSpeedKmH = targetSpeedKmH;
    std::cout << "Ч ”скорение выполнено.\n";
}

void Car::brake(int speedDecreaseKmH)
{
    if (speedDecreaseKmH <= 0)
    {
        std::cout << "Ч ”меньшение скорости должно быть > 0.\n";
        return;
    }

    currentSpeedKmH = std::max(0, currentSpeedKmH - speedDecreaseKmH);
    if (currentSpeedKmH == 0 && isEngineOn)
        currentGear = 0;

    std::cout << "Ч “орможение выполнено.\n";
}
