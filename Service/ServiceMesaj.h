//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_SERVICEMESAJ_H
#define PROIECT_SDA_SERVICEMESAJ_H


#include "../Repository/RepositoryFileMesaj.h"

class ServiceMesaj {
private:
    RepositoryFileMesaj repositoryFileMesaj;
public:
    void addM(long id, string descriere, long autor_id, long prieten_id);

    int deleteM(long id);

    int findM(long id);

    int updateM(long id, string descriere, long autor_id, long prieten_id);

    ArrayList<Mesaj> getAll();

    ServiceMesaj();

    ServiceMesaj(const RepositoryFileMesaj &repositoryFileMesaj);

    virtual ~ServiceMesaj();

};

#endif //PROIECT_SDA_SERVICEMESAJ_H
