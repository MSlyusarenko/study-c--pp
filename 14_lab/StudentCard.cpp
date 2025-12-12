#include "StudentCard.h"
#include <iomanip>

void StudentCard::Show()
{
    // соберЄм УExtraФ в одну строку
    char buf[64];
    sprintf(buf, "Uni: %s, disc=%d%%", University, Discount);

    cout << left
         << setw(10) << "Student"
         << setw(10) << CardId
         << setw(14) << Owner
         << setw(8) << Trips
         << setw(6) << Days
         << setw(10) << fixed << setprecision(2) << GetAvgTrips()
         << setw(24) << buf
         << endl;
}

StudentCard::StudentCard(char *id, char *owner, int trips, int days, char *uni, int disc)
{
    strcpy(CardId, id);
    strcpy(Owner, owner);
    Trips = trips;
    Days = (days > 0) ? days : 1;
    strcpy(University, uni);
    Discount = disc;
}

void StudentCard::SetUniversity(char *u)
{
    strcpy(University, u);
}

void StudentCard::SetDiscount(int d)
{
    Discount = d;
}