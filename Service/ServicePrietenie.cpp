//
// Created by georg on 20.06.2022.
//

#include "ServicePrietenie.h"
#include "../ExceptionHandler/CustomException.h"

void ServicePrietenie::addP(long id, long utilizator_1, long utilizator_2) {
    try {
        if (findP(id))
            throw CustomException("Friendship id already exists!\n");
        this->repositoryFilePrietenie.addModel(Prietenie(id, utilizator_1, utilizator_2));
    } catch (CustomException &exception) {
        std::cout << exception.getMessage();
    }
}

int ServicePrietenie::deleteP(long id) {
    return this->repositoryFilePrietenie.deleteModel(this->repositoryFilePrietenie.getPrietenie(id));
}

int ServicePrietenie::findP(long id) {
    return this->repositoryFilePrietenie.findModel(this->repositoryFilePrietenie.getPrietenie(id));
}

int ServicePrietenie::updateP(long id, long utilizator_1,
                              long utilizator_2) {
    return this->repositoryFilePrietenie.updateModel(this->repositoryFilePrietenie.getPrietenie(id),
                                                     Prietenie(id, utilizator_1, utilizator_2));
}

ArrayList<Prietenie> ServicePrietenie::getAll() {
    return repositoryFilePrietenie.getAll();
}

ServicePrietenie::ServicePrietenie() {

}


ServicePrietenie::~ServicePrietenie() {

}

ServicePrietenie::ServicePrietenie(const RepositoryFilePrietenie &repositoryFilePrietenie
) : repositoryFilePrietenie(
        repositoryFilePrietenie) {}
