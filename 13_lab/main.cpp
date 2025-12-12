#include <iostream>
#include <limits>
#include <Windows.h>
#include "Car.h"

int readIntegerFromUser(const char *promptText)
{
    while (true)
    {
        std::cout << promptText;

        int enteredValue = 0;
        std::cin >> enteredValue;

        if (std::cin)
        {
            std::cin.ignore(1000, '\n');
            return enteredValue;
        }

        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Ошибка: введите целое число.\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car car;
    bool isProgramRunning = true;

    while (isProgramRunning)
    {
        std::cout << "\n--- МЕНЮ ---\n";
        std::cout << "1. Показать состояние\n";
        std::cout << "2. Завести двигатель\n";
        std::cout << "3. Заглушить двигатель\n";
        std::cout << "4. Заправить\n";
        std::cout << "5. Установить передачу\n";
        std::cout << "6. Ускориться\n";
        std::cout << "7. Тормозить\n";
        std::cout << "0. Выход\n";

        int menuCommand = readIntegerFromUser("Команда -> ");

        switch (menuCommand)
        {
        case 1:
            car.printState();
            break;
        case 2:
            car.startEngine();
            break;
        case 3:
            car.stopEngine();
            break;
        case 4:
        {
            int fuelAmountToAdd = readIntegerFromUser("Сколько заправить? ");
            car.refuel(fuelAmountToAdd);
            break;
        }
        case 5:
        {
            int targetGear = readIntegerFromUser("Передача (0..5): ");
            car.setGear(targetGear);
            break;
        }
        case 6:
        {
            int speedIncreaseKmH = readIntegerFromUser("Увеличить скорость на: ");
            car.accelerate(speedIncreaseKmH);
            break;
        }
        case 7:
        {
            int speedDecreaseKmH = readIntegerFromUser("Уменьшить скорость на: ");
            car.brake(speedDecreaseKmH);
            break;
        }
        case 0:
            isProgramRunning = false;
            break;
        default:
            std::cout << "Неизвестная команда.\n";
        }
    }

    return 0;
}
