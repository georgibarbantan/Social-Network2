//
// Created by georg on 20.06.2022.
//

#include "RepositoryFilePrietenie.h"
#include <fstream>

RepositoryFilePrietenie::RepositoryFilePrietenie() {

}

RepositoryFilePrietenie::RepositoryFilePrietenie(const char *filename) {
    this->filename = filename;
    std::ifstream f(filename);

    long id;
    long autor_1;
    long autor_2;

    while (f >> id >> autor_1 >> autor_2) {
        Prietenie Prietenie(id, autor_1, autor_2);
        container.add(Prietenie);

    }

    f.close();
}

void RepositoryFilePrietenie::addModel(const Prietenie &u) {
    container.add(u);
    save();
}

int RepositoryFilePrietenie::deleteModel(const Prietenie &u) {
    if (container.contains(u)) {
        container.remove(u);
        save();
        return 1;

    }
    return 0;
}

int RepositoryFilePrietenie::findModel(const Prietenie &u) {
    if (container.contains(u))
        return 1;
    return 0;
}

ArrayList<Prietenie> RepositoryFilePrietenie::getAll() {
    return container;
}

int RepositoryFilePrietenie::size() {
    return container.getSize();
}

int RepositoryFilePrietenie::updateModel(const Prietenie &u, const Prietenie &newU) {
    if (container.contains(u)) {
        container.update(u, newU);
        save();
        return 1;
    }
    return 0;
}

RepositoryFilePrietenie::~RepositoryFilePrietenie() {

}

void RepositoryFilePrietenie::save() {
    std::ofstream f(filename);
    for (auto i = 0; i < container.getSize(); i++) {
        auto m = container.get(i);
        f << m.getId() << " " << m.getUtilizator1() << " " << m.getUtilizator2() << std::endl;
    }
    f.close();
}

Prietenie RepositoryFilePrietenie::getPrietenie(long id) {
    for (auto i = 0; i < container.getSize(); i++)
        if (container.get(i).getId() == id)
            return container.get(i);
    return {};
}

