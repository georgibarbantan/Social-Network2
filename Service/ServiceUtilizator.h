//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_SERVICEUTILIZATOR_H
#define PROIECT_SDA_SERVICEUTILIZATOR_H


#include "../Repository/RepositoryFileUtilizator.h"

class ServiceUtilizator {
private:
    RepositoryFileUtilizator repositoryFileUtilizator;
public:
    void addU(long id, string nume, string prenume, int varsta, string gen);

    int deleteU(long id);

    int findU(long id);

    int updateU(long id, string nume, string prenume,
                int varsta, string gen);

    ArrayList<Utilizator> getAll();

    ServiceUtilizator();

    ServiceUtilizator(const RepositoryFileUtilizator &repositoryFileUtilizator);

    virtual ~ServiceUtilizator();

};

#endif //PROIECT_SDA_SERVICEUTILIZATOR_H
