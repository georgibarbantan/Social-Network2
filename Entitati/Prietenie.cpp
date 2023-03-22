//
// Created by georg on 20.06.2022.
//


#include <sstream>
#include "Prietenie.h"

using namespace std;

long Prietenie::getUtilizator1() const {
    return utilizator_1;
}

void Prietenie::setUtilizator1(long utilizator1) {
    utilizator_1 = utilizator1;
}

long Prietenie::getUtilizator2() const {
    return utilizator_2;
}

void Prietenie::setUtilizator2(long utilizator2) {
    utilizator_2 = utilizator2;
}

Prietenie::~Prietenie() {

}


Prietenie::Prietenie() {}

long Prietenie::getId() const {
    return id;
}

void Prietenie::setId(long id) {
    Prietenie::id = id;
}

bool Prietenie::operator==(const Prietenie &rhs) const {
    return id == rhs.id &&
           utilizator_1 == rhs.utilizator_1 &&
           utilizator_2 == rhs.utilizator_2;
}

bool Prietenie::operator!=(const Prietenie &rhs) const {
    return !(rhs == *this);
}

Prietenie::Prietenie(long id, long utilizator1, long utilizator2) : id(id), utilizator_1(
        utilizator1), utilizator_2(utilizator2) {}

ostream &operator<<(ostream &os, const Prietenie &prietenie) {
    return (os << "Id: " << prietenie.getId() << " Utilizator1: " << prietenie.getUtilizator1() << " Utilizator2: "
               << prietenie.getUtilizator2());
}

string Prietenie::toString() {
    stringstream ss;
    ss << (*this);
    return ss.str();
}
