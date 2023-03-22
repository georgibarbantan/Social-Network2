//
// Created by georg on 20.06.2022.
//


#include <fstream>
#include "RepositoryFileMesaj.h"

RepositoryFileMesaj::RepositoryFileMesaj() {

}

RepositoryFileMesaj::RepositoryFileMesaj(const char *filename) {
    this->filename = filename;
    std::ifstream f(filename);

    long id;
    string descriere;
    long autor_id;
    long prieten_id;

    while (f >> id >> descriere >> autor_id >> prieten_id) {
        Mesaj Mesaj(id, descriere, autor_id, prieten_id);
        container.add(Mesaj);
    }

    f.close();
}

void RepositoryFileMesaj::addModel(const Mesaj &u) {
    container.add(u);
    save();
}

int RepositoryFileMesaj::deleteModel(const Mesaj &u) {
    if (container.contains(u)) {
        container.remove(u);
        save();
        return 1;
    }
    return 0;
}

int RepositoryFileMesaj::findModel(const Mesaj &u) {
    if (container.contains(u))
        return 1;
    return 0;
}

ArrayList<Mesaj> RepositoryFileMesaj::getAll() {
    return container;
}

int RepositoryFileMesaj::size() {
    return container.getSize();
}

int RepositoryFileMesaj::updateModel(const Mesaj &u, const Mesaj &newU) {
    if (container.contains(u)) {
        container.update(u, newU);
        save();
        return 1;
    }
    return 0;
}

RepositoryFileMesaj::~RepositoryFileMesaj() {

}

void RepositoryFileMesaj::save() {
    std::ofstream f(filename);
    for (auto i = 0; i < container.getSize(); i++) {
        auto m = container.get(i);
        f << m.getMesajId() << " " << m.getDescriere() << " " << m.getAutorId() << " "
          << m.getPrietenId() << std::endl;
    }
    f.close();
}

Mesaj RepositoryFileMesaj::getMesaj(long id) {
    for (auto i = 0; i < container.getSize(); i++)
        if (container.get(i).getMesajId() == id)
            return container.get(i);
    return Mesaj();
}

