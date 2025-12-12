#ifndef MAGNETICCARD_H
#define MAGNETICCARD_H

#include <iostream>
#include <string.h>

using namespace std;

class MagneticCard
{
public:
    MagneticCard();

    // getters
    int GetTrips();
    int GetDays();
    double GetAvgTrips();

    // virtual show
    virtual void Show();

    // setters
    void SetCardId(char *id);
    void SetOwner(char *owner);
    void SetTrips(int t);
    void SetDays(int d);

protected:
    char CardId[30];
    char Owner[30];
    int Trips;
    int Days;

private:
};

#endif
