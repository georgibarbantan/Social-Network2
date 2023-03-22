//
// Created by georg on 20.06.2022.
//


#include <sstream>
#include "Utilizator.h"

string Utilizator::getNume() const {
    return nume;
}

void Utilizator::setNume(string nume) {
    Utilizator::nume = nume;
}

string Utilizator::getPrenume() const {
    return prenume;
}

void Utilizator::setPrenume(string prenume) {
    Utilizator::prenume = prenume;
}

int Utilizator::getVarsta() const {
    return varsta;
}

void Utilizator::setVarsta(int varsta) {
    Utilizator::varsta = varsta;
}

string Utilizator::getGen() const {
    return gen;
}

void Utilizator::setGen(string gen) {
    Utilizator::gen = gen;
}

Utilizator::~Utilizator() {

}

bool Utilizator::operator==(const Utilizator &rhs) const {
    return nume == rhs.nume &&
           prenume == rhs.prenume &&
           varsta == rhs.varsta &&
           gen == rhs.gen;
}

bool Utilizator::operator!=(const Utilizator &rhs) const {
    return !(rhs == *this);
}

Utilizator::Utilizator() {}

long Utilizator::getId() const {
    return id;
}

void Utilizator::setId(long id) {
    Utilizator::id = id;
}

Utilizator::Utilizator(long id, string nume, string prenume, int varsta, string gen) : id(id), nume(nume),
                                                                                       prenume(prenume),
                                                                                       varsta(varsta), gen(gen) {}

ostream &operator<<(ostream &os, const Utilizator &utilizator) {
    return (os << "Id: " << utilizator.getId() << " Nume: " << utilizator.getNume() << " Prenume: "
               << utilizator.getPrenume() << " Varsta: " << utilizator.getVarsta() << " Gen: " << utilizator.getGen());
}

string Utilizator::toString() {
    stringstream ss;
    ss << (*this);
    return ss.str();
}

