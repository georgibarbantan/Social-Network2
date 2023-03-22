//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_SERVICEPRIETENIE_H
#define PROIECT_SDA_SERVICEPRIETENIE_H


#include "../Repository/RepositoryFilePrietenie.h"
#include "../Repository/RepositoryFileUtilizator.h"

class ServicePrietenie {
private:
    RepositoryFilePrietenie repositoryFilePrietenie;
    RepositoryFileUtilizator repositoryFileUtilizator;
public:
    void addP(long id, long utilizator_1, long utilizator_2);

    int deleteP(long id);

    int findP(long id);

    int updateP(long id, long utilizator_1, long utilizator_2);

    ArrayList<Prietenie> getAll();

    ServicePrietenie();

    ServicePrietenie(const RepositoryFilePrietenie &repositoryFilePrietenie);

    virtual ~ServicePrietenie();
};


#endif //PROIECT_SDA_SERVICEPRIETENIE_H
