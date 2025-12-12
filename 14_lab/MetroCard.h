#ifndef METROCARD_H
#define METROCARD_H

#include "MagneticCard.h"

class MetroCard : public MagneticCard
{
public:
    MetroCard(char *id, char *owner, int trips, int days, char *tariff);

    void SetTariff(char *t);
    void Show();

protected:
private:
    char Tariff[30];
};

#endif
