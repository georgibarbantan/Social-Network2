//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_UI_H
#define PROIECT_SDA_UI_H


#include "../Service/ServicePrietenie.h"
#include "../Service/ServiceMesaj.h"
#include "../Service/ServiceUtilizator.h"
#include "../Service/ServiceRetea.h"

class Console {
private:
    ServiceUtilizator serviceUtilizator;
    ServiceMesaj serviceMesaj;
    ServicePrietenie servicePrietenie;
    ServiceRetea serviceRetea;

    void addUtilizator();

    void delUtilizator();

    void updateUtilizator();

    void findUtilizator();

    void addMesaj();

    void delMesaj();

    void updateMesaj();

    void findMesaj();

    void addPrietenie();

    void delPrietenie();

    void updatePrietenie();

    void findPrietenie();

    void showAllU();

    void showAllM();

    void showAllP();

    void getUserFriendList();

    void getPeopleByName();

    void getUserMessageList();

public:
    Console();

    Console(const ServiceUtilizator &serviceUtilizator, const ServiceMesaj &serviceMesaj,
            const ServicePrietenie &servicePrietenie, const ServiceRetea &serviceRetea);

    void showMenu();

    void showUI();

    virtual ~Console();
};

#endif //PROIECT_SDA_UI_H
