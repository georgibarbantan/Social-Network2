//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_SERVICERETEA_H
#define PROIECT_SDA_SERVICERETEA_H


#include <vector>
#include "../Repository/RepositoryFileUtilizator.h"
#include "../Repository/RepositoryFilePrietenie.h"
#include "../Repository/RepositoryFileMesaj.h"
#include "../TAD-uri//LinkedListDictionary.h"

class ServiceRetea {
private:
    RepositoryFileUtilizator repositoryFileUtilizator;
    RepositoryFileMesaj repositoryFileMesaj;
    RepositoryFilePrietenie repositoryFilePrietenie;
public:
    ServiceRetea();

    ServiceRetea(const RepositoryFileUtilizator &repositoryFileUtilizator,
                 const RepositoryFileMesaj &repositoryFileMesaj,
                 const RepositoryFilePrietenie &repositoryFilePrietenie);

    Dictionary<long, vector<Utilizator>> getFriendList(long userId);

    vector<Utilizator> getPeopleByName(string nume, string prenume);

    Dictionary<long, vector<Mesaj>> getUserMessages(long userId);

    virtual ~ServiceRetea();
};

#endif //PROIECT_SDA_SERVICERETEA_H
