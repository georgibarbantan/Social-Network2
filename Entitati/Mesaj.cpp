//
// Created by georg on 20.06.2022.
//


#include <sstream>
#include "Mesaj.h"

Mesaj::Mesaj() {}

string Mesaj::getDescriere() const {
    return descriere;
}

void Mesaj::setDescriere(string descriere) {
    Mesaj::descriere = descriere;
}


Mesaj::~Mesaj() {

}

long Mesaj::getAutorId() const {
    return autor_id;
}

void Mesaj::setAutorId(long autorId) {
    autor_id = autorId;
}

Mesaj::Mesaj(long mesajId, string descriere, long autorId, long prieten_id) : mesaj_id(mesajId),
                                                                              descriere(descriere),
                                                                              autor_id(autorId),
                                                                              prieten_id(prieten_id) {}

bool Mesaj::operator==(const Mesaj &rhs) const {
    return mesaj_id == rhs.mesaj_id &&
           descriere == rhs.descriere &&
           autor_id == rhs.autor_id;
    prieten_id == rhs.prieten_id;
}

bool Mesaj::operator!=(const Mesaj &rhs) const {
    return !(rhs == *this);
}

long Mesaj::getMesajId() const {
    return mesaj_id;
}

void Mesaj::setMesajId(long mesajId) {
    mesaj_id = mesajId;
}

ostream &operator<<(ostream &os, const Mesaj &mesaj) {
    return (os << "Id: " << mesaj.getMesajId() << " Descriere: "
               << mesaj.getDescriere() << " AutorId: " << mesaj.getAutorId()) << " PrietenId: " << mesaj.getPrietenId();
}

string Mesaj::toString() {
    stringstream ss;
    ss << (*this);
    return ss.str();
}

long Mesaj::getPrietenId() const {
    return prieten_id;
}

void Mesaj::setPrietenId(long prietenId) {
    prieten_id = prietenId;
}

