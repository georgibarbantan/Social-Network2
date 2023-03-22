//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_REPOSITORYFILEPRIETENIE_H
#define PROIECT_SDA_REPOSITORYFILEPRIETENIE_H

#include "../Entitati//Prietenie.h"
#include "../TAD-uri//ArrayList.h"

class RepositoryFilePrietenie {
private:
    const char *filename;
    ArrayList<Prietenie> container;
public:
    RepositoryFilePrietenie();

    RepositoryFilePrietenie(const char *filename);

    void addModel(const Prietenie &);

    int deleteModel(const Prietenie &);

    int findModel(const Prietenie &);

    ArrayList<Prietenie> getAll();

    int size();

    int updateModel(const Prietenie &, const Prietenie &);

    Prietenie getPrietenie(long id);

    ~RepositoryFilePrietenie();

    void save();
};

#endif //PROIECT_SDA_REPOSITORYFILEPRIETENIE_H
