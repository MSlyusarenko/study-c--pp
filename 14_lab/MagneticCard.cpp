#include "MagneticCard.h"
#include <iomanip>

double MagneticCard::GetAvgTrips()
{
    return (Days > 0) ? (double)Trips / Days : 0.0;
}

void MagneticCard::Show()
{
    cout << left
         << setw(10) << "Base"
         << setw(10) << CardId
         << setw(14) << Owner
         << setw(8) << Trips
         << setw(6) << Days
         << setw(10) << fixed << setprecision(2) << GetAvgTrips()
         << setw(24) << "-"
         << endl;
}

MagneticCard::MagneticCard()
{
    strcpy(CardId, "N/A");
    strcpy(Owner, "Noname");
    Trips = 0;
    Days = 1;
}

int MagneticCard::GetTrips()
{
    return Trips;
}

int MagneticCard::GetDays()
{
    return Days;
}

void MagneticCard::SetCardId(char *id)
{
    strcpy(CardId, id);
}

void MagneticCard::SetOwner(char *owner)
{
    strcpy(Owner, owner);
}

void MagneticCard::SetTrips(int t)
{
    Trips = t;
}

void MagneticCard::SetDays(int d)
{
    Days = (d > 0) ? d : 1;
}
