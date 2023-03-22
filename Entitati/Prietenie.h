//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_PRIETENIE_H
#define PROIECT_SDA_PRIETENIE_H

#include "iostream"
class Prietenie{
private:
    long  id;
    long  utilizator_1;
    long  utilizator_2;
public:
    long  getUtilizator1() const;

    void setUtilizator1(long  utilizator1);

    long  getUtilizator2() const;

    void setUtilizator2(long  utilizator2);

    virtual ~Prietenie();

    long  getId() const;

    void setId(long  id);

    bool operator==(const Prietenie &rhs) const;

    Prietenie(long  id, long  utilizator1, long  utilizator2);

    bool operator!=(const Prietenie &rhs) const;

    std::string toString();
    Prietenie();
};
#endif //PROIECT_SDA_PRIETENIE_H
