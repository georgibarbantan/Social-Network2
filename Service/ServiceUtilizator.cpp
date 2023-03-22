//
// Created by georg on 20.06.2022.
//


#include "ServiceUtilizator.h"
#include "../ExceptionHandler/CustomException.h"

ServiceUtilizator::~ServiceUtilizator() {

}

void ServiceUtilizator::addU(long id, string nume, string prenume, int varsta, string gen) {
    try {
        if (findU(id))
            throw CustomException("User id already exists!\n");
        this->repositoryFileUtilizator.addModel(Utilizator(id, nume, prenume, varsta, gen));
    } catch (
            CustomException &exception) {
        std::cout << exception.getMessage();
    }
}

int ServiceUtilizator::deleteU(long id) {
    return this->repositoryFileUtilizator.deleteModel(this->repositoryFileUtilizator.getUtilizator(id));
}

int ServiceUtilizator::findU(long id) {
    return this->repositoryFileUtilizator.findModel(this->repositoryFileUtilizator.getUtilizator(id));
}

int ServiceUtilizator::updateU(long id, string nume, string prenume, int varsta, string gen) {
    return this->repositoryFileUtilizator.updateModel(this->repositoryFileUtilizator.getUtilizator(id),
                                                      Utilizator(id, nume, prenume, varsta, gen));
}

ArrayList<Utilizator> ServiceUtilizator::getAll() {
    return this->repositoryFileUtilizator.getAll();
}

ServiceUtilizator::ServiceUtilizator() {

}

ServiceUtilizator::ServiceUtilizator(const RepositoryFileUtilizator &repositoryFileUtilizator)
        : repositoryFileUtilizator(repositoryFileUtilizator) {}

