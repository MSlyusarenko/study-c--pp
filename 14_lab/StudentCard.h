#ifndef STUDENTCARD_H
#define STUDENTCARD_H

#include "MagneticCard.h"

class StudentCard : public MagneticCard
{
public:
    StudentCard(char *id, char *owner, int trips, int days, char *uni, int disc);

    void SetUniversity(char *u);
    void SetDiscount(int d);
    void Show();

protected:
private:
    char University[30];
    int Discount;
};

#endif
