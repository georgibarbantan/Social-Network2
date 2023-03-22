//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_MESAJ_H
#define PROIECT_SDA_MESAJ_H

using namespace std;
#include "iostream"
class Mesaj{
private:
    long mesaj_id;
    string descriere;
    long autor_id;
    long prieten_id;
public:
    Mesaj();

    virtual ~Mesaj();

    string getDescriere() const;

    void setDescriere(string descriere);

    long getAutorId() const;

    void setAutorId(long autorId);

    long getMesajId() const;

    void setMesajId(long  mesajId);


    long getPrietenId() const;

    void setPrietenId(long prietenId);

    Mesaj(long  mesajId, string descriere, long  autorId, long prieten_id);

    bool operator==(const Mesaj &rhs) const;

    bool operator!=(const Mesaj &rhs) const;

    string toString();
};
#endif //PROIECT_SDA_MESAJ_H
