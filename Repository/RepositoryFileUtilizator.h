//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_REPOSITORYFILEUTILIZATOR_H
#define PROIECT_SDA_REPOSITORYFILEUTILIZATOR_H


#include "../Entitati/Utilizator.h"
#include "../TAD-uri/ArrayList.h"

class RepositoryFileUtilizator {
private:
    const char *filename;
    ArrayList<Utilizator> container;
public:
    RepositoryFileUtilizator();

    RepositoryFileUtilizator(const char *filename);

    void addModel(const Utilizator &);

    int deleteModel(const Utilizator &);

    int findModel(const Utilizator &);

    ArrayList<Utilizator> getAll();

    int size();

    int updateModel(const Utilizator &, const Utilizator &);

    Utilizator getUtilizator(int id);

    ~RepositoryFileUtilizator();

    void save();
};

#endif //PROIECT_SDA_REPOSITORYFILEUTILIZATOR_H
