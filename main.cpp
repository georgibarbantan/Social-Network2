//
// Created by georg on 20.06.2022.
//


#include "TAD-uri//ArrayList.h"
#include "UI/UI.h"

using namespace std;

int main() {
    RepositoryFileUtilizator repositoryFileUtilizator("../Data/utilizator.csv");
    RepositoryFileMesaj repositoryFileMesaj("../Data/mesaj.csv");
    RepositoryFilePrietenie repositoryFilePrietenie("../Data/prietenie.csv");
    ServiceUtilizator serviceUtilizator(repositoryFileUtilizator);
    ServiceMesaj serviceMesaj(repositoryFileMesaj);
    ServicePrietenie servicePrietenie(repositoryFilePrietenie);
    ServiceRetea serviceRetea(repositoryFileUtilizator, repositoryFileMesaj, repositoryFilePrietenie);
    Console console(serviceUtilizator, serviceMesaj, servicePrietenie, serviceRetea);
    console.showUI();

    return 0;
}

