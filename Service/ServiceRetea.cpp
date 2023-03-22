//
// Created by georg on 20.06.2022.
//


#include "ServiceRetea.h"

ServiceRetea::ServiceRetea(const RepositoryFileUtilizator &repositoryFileUtilizator,
                           const RepositoryFileMesaj &repositoryFileMesaj,
                           const RepositoryFilePrietenie &repositoryFilePrietenie) : repositoryFileUtilizator(
        repositoryFileUtilizator), repositoryFileMesaj(repositoryFileMesaj), repositoryFilePrietenie(
        repositoryFilePrietenie) {}

ServiceRetea::~ServiceRetea() {

}

Dictionary<long, vector<Utilizator>> ServiceRetea::getFriendList(long userId) {
    try {
        if (!this->repositoryFileUtilizator.findModel(this->repositoryFileUtilizator.getUtilizator(userId)))
            throw CustomException("User doesn't exist!\n");
        vector<Utilizator> lista;
        Dictionary<long, vector<Utilizator>> friendList;
        auto relatii = this->repositoryFilePrietenie.getAll();
        for (auto i = 0; i < relatii.getSize(); i++) {
            if (relatii.get(i).getUtilizator1() == userId) {
                lista.push_back(this->repositoryFileUtilizator.getUtilizator(relatii.get(i).getUtilizator2()));
            } else if (relatii.get(i).getUtilizator2() == userId) {
                lista.push_back(this->repositoryFileUtilizator.getUtilizator(relatii.get(i).getUtilizator1()));
            }
        }

        friendList.add(userId, lista);
        return friendList;
    } catch (CustomException &exception) {
        cout << exception.getMessage();
        return {};
    }
}


vector<Utilizator> ServiceRetea::getPeopleByName(string nume, string prenume) {
    vector<Utilizator> response;
    auto usersList = this->repositoryFileUtilizator.getAll();

    for (int i = 0; i < usersList.getSize(); ++i) {
        if (usersList.get(i).getNume() == nume && usersList.get(i).getPrenume() == prenume) {
            response.push_back(usersList.get(i));
        }
    }

    return response;
}

Dictionary<long, vector<Mesaj>> ServiceRetea::getUserMessages(long userId) {
    try {
        if (!this->repositoryFileUtilizator.findModel(this->repositoryFileUtilizator.getUtilizator(userId)))
            throw CustomException("User doesn't exist!\n");
        Dictionary<long, vector<Mesaj>> messageList;
        vector<Mesaj> lista;
        auto mesaje = this->repositoryFileMesaj.getAll();
        for (int i = 0; i < mesaje.getSize(); ++i) {
            if (mesaje.get(i).getAutorId() == userId || mesaje.get(i).getPrietenId() == userId)
                lista.push_back(mesaje.get(i));
        }

        messageList.add(userId, lista);
        return messageList;
    } catch (CustomException &exception) {
        std::cout << exception.getMessage();
        return {};
    }
}

ServiceRetea::ServiceRetea() {

}

