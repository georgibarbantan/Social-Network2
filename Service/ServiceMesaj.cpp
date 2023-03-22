//
// Created by georg on 20.06.2022.
//


#include "ServiceMesaj.h"
#include "../ExceptionHandler/CustomException.h"
#include "iostream"

void ServiceMesaj::addM(long id, string descriere, long autor_id, long prieten_id) {
    try {
        if (findM(id))
            throw CustomException("Message id already exists!\n");
        this->repositoryFileMesaj.addModel(Mesaj(id, descriere, autor_id, prieten_id));
    } catch (CustomException &exception) { std::cout << exception.getMessage(); }
}

int ServiceMesaj::deleteM(long id) {
    return this->repositoryFileMesaj.deleteModel(this->repositoryFileMesaj.getMesaj(id));
}

int ServiceMesaj::findM(long id) {
    return this->repositoryFileMesaj.findModel(this->repositoryFileMesaj.getMesaj(id));
}

int
ServiceMesaj::updateM(long id, string descriere,
                      long autor_id, long prieten_id) {

    return this->repositoryFileMesaj.updateModel(this->repositoryFileMesaj.getMesaj(id),
                                                 Mesaj(id, descriere, autor_id, prieten_id));
}

ArrayList<Mesaj> ServiceMesaj::getAll() {
    return this->repositoryFileMesaj.getAll();
}

ServiceMesaj::ServiceMesaj() {

}

ServiceMesaj::ServiceMesaj(const RepositoryFileMesaj &repositoryFileMesaj) : repositoryFileMesaj(repositoryFileMesaj) {

}

ServiceMesaj::~ServiceMesaj() {

}

