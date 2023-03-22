//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_REPOSITORYFILEMESAJ_H
#define PROIECT_SDA_REPOSITORYFILEMESAJ_H


#include "../Entitati//Mesaj.h"
#include "../TAD-uri//ArrayList.h"

class RepositoryFileMesaj {
private:
    const char *filename;
    ArrayList<Mesaj> container;
public:
    RepositoryFileMesaj();

    RepositoryFileMesaj(const char *filename);

    void addModel(const Mesaj &);

    int deleteModel(const Mesaj &);

    int findModel(const Mesaj &);

    ArrayList<Mesaj> getAll();

    int size();

    int updateModel(const Mesaj &, const Mesaj &);

    Mesaj getMesaj(long id);

    ~RepositoryFileMesaj();

    void save();
};

#endif //PROIECT_SDA_REPOSITORYFILEMESAJ_H
