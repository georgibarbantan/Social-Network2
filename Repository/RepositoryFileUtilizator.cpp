//
// Created by georg on 20.06.2022.
//


#include <fstream>
#include "RepositoryFileUtilizator.h"

RepositoryFileUtilizator::RepositoryFileUtilizator() {

}

RepositoryFileUtilizator::RepositoryFileUtilizator(const char *filename) {
    this->filename = filename;
    std::ifstream f(filename);

    long id;
    string nume;
    string prenume;
    int varsta;
    string gen;

    while (f >> id >> nume >> prenume >> varsta >> gen) {
        Utilizator utilizator(id, nume, prenume, varsta, gen);
        container.add(utilizator);
    }

    f.close();
}

void RepositoryFileUtilizator::addModel(const Utilizator &u) {

    container.add(u);
    save();
}

int RepositoryFileUtilizator::deleteModel(const Utilizator &u) {
    if (container.contains(u)) {
        container.remove(u);
        save();
        return 1;
    }
    return 0;
}

int RepositoryFileUtilizator::findModel(const Utilizator &u) {
    if (container.contains(u))
        return 1;
    return 0;
}

ArrayList<Utilizator> RepositoryFileUtilizator::getAll() {
    return container;
}

int RepositoryFileUtilizator::size() {
    return container.getSize();
}

int RepositoryFileUtilizator::updateModel(const Utilizator &u, const Utilizator &newU) {
    if (container.contains(u)) {
        container.update(u, newU);
        save();
        return 1;
    }
    return 0;
}

RepositoryFileUtilizator::~RepositoryFileUtilizator() {

}

void RepositoryFileUtilizator::save() {
    std::ofstream f(filename);
    for (auto i = 0; i < container.getSize(); i++) {
        auto m = container.get(i);
        f << m.getId() << " " << m.getNume() << " " << m.getPrenume() << " " << m.getVarsta() << " " << m.getGen()
          << std::endl;
    }
    f.close();
}

Utilizator RepositoryFileUtilizator::getUtilizator(int id) {
    for (auto i = 0; i < container.getSize(); i++)
        if (container.get(i).getId() == id)
            return container.get(i);
    return Utilizator();
}
