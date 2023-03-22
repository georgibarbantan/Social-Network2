//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_UTILIZATOR_H
#define PROIECT_SDA_UTILIZATOR_H

#include "iostream"

using namespace std;

class Utilizator {
private:
    long id;
    string nume;
    string prenume;
    int varsta;
    string gen;
public:

    Utilizator();

    Utilizator(long id, string nume, string prenume, int varsta, string gen);

    long getId() const;

    void setId(long id);

    string getNume() const;

    void setNume(string nume);

    string getPrenume() const;

    void setPrenume(string prenume);

    int getVarsta() const;

    void setVarsta(int varsta);

    string getGen() const;

    void setGen(string gen);

    virtual ~Utilizator();


    bool operator==(const Utilizator &rhs) const;

    bool operator!=(const Utilizator &rhs) const;

    string toString();

};

#endif //PROIECT_SDA_UTILIZATOR_H
