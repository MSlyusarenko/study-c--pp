#include "MetroCard.h"
#include <iomanip>

void MetroCard::Show()
{
    cout << left
         << setw(10) << "Metro"
         << setw(10) << CardId
         << setw(14) << Owner
         << setw(8) << Trips
         << setw(6) << Days
         << setw(10) << fixed << setprecision(2) << GetAvgTrips()
         << setw(24) << (string("Tariff: ") + Tariff)
         << endl;
}

MetroCard::MetroCard(char *id, char *owner, int trips, int days, char *tariff)
{
    strcpy(CardId, id);
    strcpy(Owner, owner);
    Trips = trips;
    Days = (days > 0) ? days : 1;
    strcpy(Tariff, tariff);
}

void MetroCard::SetTariff(char *t)
{
    strcpy(Tariff, t);
}