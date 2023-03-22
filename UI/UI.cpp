//
// Created by georg on 20.06.2022.
//


#include "UI.h"
#include "iostream"

using namespace std;

Console::~Console() {

}

void showMenuUtilizator() {
    cout << "<<<<<MENIU>>>>>\n";
    cout << "1.Adauga utilizator \n";
    cout << "2.Sterge utilizator \n";
    cout << "3.Actualizeaza utilizator \n";
    cout << "4.Gaseste utilizator \n";
    cout << "5.Afisare utilizatori \n";
    cout << "0. Meniul principal\n";

}

void Console::addUtilizator() {
    long id;
    string nume;
    string prenume;
    int varsta;
    string gen;
    cout << "Scrie id-ul utilizatorului:\n";
    cin >> id;
    cout << "Scrie numele utilizatorului:\n";
    cin >> nume;
    cout << "Scrie prenumele utilizatorului:\n";
    cin >> prenume;
    cout << "Scrie varsta utilizatorului:\n";
    cin >> varsta;
    cout << "Scrie gen-ul utilizatorului(barbat/femeie):\n";
    cin >> gen;
    this->serviceUtilizator.addU(id, nume, prenume, varsta, gen);

}

void Console::delUtilizator() {
    long id;

    cout << "Scrie id-ul utilizatorului:\n";
    cin >> id;

    if (this->serviceUtilizator.deleteU(id))
        cout << "User deleted!\n";
    else
        cout << "User not found!\n";
}

void Console::updateUtilizator() {
    long id;
    string nnume;
    string nprenume;
    int nvarsta;
    string ngen;
    cout << "Scrie id-ul utilizatorului vechi:\n";
    cin >> id;
    cout << "Scrie numele utilizatorului nou:\n";
    cin >> nnume;
    cout << "Scrie prenumele utilizatorului nou:\n";
    cin >> nprenume;
    cout << "Scrie varsta utilizatorului nou:\n";
    cin >> nvarsta;
    cout << "Scrie gen-ul utilizatorului(barbat/femeie) nou:\n";
    cin >> ngen;

    if (this->serviceUtilizator.updateU(id, nnume, nprenume, nvarsta, ngen))
        cout << "User updated!\n";
    else
        cout << "User not found";
}

void Console::findUtilizator() {
    long id;

    cout << "Scrie id-ul utilizatorului:\n";
    cin >> id;
    if (this->serviceUtilizator.findU(id))
        cout << "User found!\n";
    else
        cout << "User not found!\n";

}

void showMenuMesaj() {
    cout << "<<<<<MENIU>>>>>\n";
    cout << "1.Adauga mesaj \n";
    cout << "2.Sterge mesaj \n";
    cout << "3.Actualizeaza mesaj \n";
    cout << "4.Gaseste mesaj \n";
    cout << "5.Afisare mesaj \n";
    cout << "0. Meniul principal\n";

}

void Console::addMesaj() {
    try {
        long mesaj_id;
        string descriere;
        long autor_id;
        long prieten_id;
        cout << "Scrie id-ul mesajului:\n";
        cin >> mesaj_id;
        cout << "Scrie descrierea mesajului:\n";
        cin >> descriere;
        cout << "Scrie id-ul autorului mesajului:\n";
        cin >> autor_id;
        cout << "Scrie id-ul prietenului care primeste mesajul:\n";
        cin >> prieten_id;
        if (!this->serviceUtilizator.findU(autor_id))
            throw CustomException("User doesn't exist!\n");
        if (!this->serviceUtilizator.findU(prieten_id))
            throw CustomException("Friend doesn't exist!\n");
        this->serviceMesaj.addM(mesaj_id, descriere, autor_id, prieten_id);
    } catch (CustomException &exception) {
        cout << exception.getMessage();
    }
}

void Console::delMesaj() {
    long mesaj_id;

    cout << "Scrie id-ul mesajului:\n";
    cin >> mesaj_id;

    if (this->serviceMesaj.deleteM(mesaj_id))
        cout << "Message deleted!\n";
    else
        cout << "Message not found!\n";

}

void Console::updateMesaj() {
    try {
        long mesaj_id;
        string descriere;
        long autor_id;
        long prieten_id;
        cout << "Scrie id-ul mesajului:\n";
        cin >> mesaj_id;
        cout << "Scrie descrierea mesajului:\n";
        cin >> descriere;
        cout << "Scrie id-ul autorului mesajului:\n";
        cin >> autor_id;
        cout << "Scrie id-ul prietenului care primeste mesajul:\n";
        cin >> prieten_id;
        if (!this->serviceUtilizator.findU(autor_id))
            throw CustomException("User doesn't exist!\n");
        if (!this->serviceUtilizator.findU(prieten_id))
            throw CustomException("Friend doesn't exist!\n");
        if (autor_id == prieten_id) {
            throw CustomException("Author's id and Friend's id cannot be the same!\n");
        }
        if (this->serviceMesaj.updateM(mesaj_id, descriere, autor_id, prieten_id))
            cout << "Message updated!\n";
        else
            cout << "Message not found!\n";
    } catch (CustomException &exception) {
        cout << exception.getMessage();
    }
}

void Console::findMesaj() {
    long mesaj_id;
    cout << "Scrie id-ul mesajului:\n";
    cin >> mesaj_id;
    if (this->serviceMesaj.findM(mesaj_id))
        cout << "Message found!\n";
    else
        cout << "Message not found!\n";
}

void showMenuPrietenie() {
    cout << "<<<<<MENIU>>>>>\n";
    cout << "1.Adauga prietenie \n";
    cout << "2.Sterge prietenie \n";
    cout << "3.Actualizeaza prietenie \n";
    cout << "4.Gaseste prietenie \n";
    cout << "5.Afisare prietenie \n";
    cout << "0. Meniul principal\n";

}

void Console::addPrietenie() {
    try {
        long id;
        long utilizator_1;
        long utilizator_2;

        cout << "Scrie id-ul relatiei de prietenie:\n";
        cin >> id;
        cout << "Scrie id-ul primului uitlizator:\n";
        cin >> utilizator_1;
        cout << "Scrie id-ul celui de-al doilea utilizator:\n";
        cin >> utilizator_2;
        if (!this->serviceUtilizator.findU(utilizator_1) || !this->serviceUtilizator.findU(utilizator_2))
            throw CustomException("Users id's must exist!\n");
        if (utilizator_1 == utilizator_2)
            throw CustomException("A user cannot be friend with himself!\n");
        this->servicePrietenie.addP(id, utilizator_1, utilizator_2);
    } catch (CustomException &exception) {
        std::cout << exception.getMessage();
    }
}

void Console::delPrietenie() {
    long id;
    cout << "Scrie id-ul prieteniei:\n";
    cin >> id;
    if (this->servicePrietenie.deleteP(id))
        cout << "Friendship deleted!\n";
    else
        cout << "Friendship not found!\n";
}

void Console::updatePrietenie() {
    try {
        long id;
        long utilizator_1;
        long utilizator_2;
        cout << "Scrie id-ul relatiei de prietenie:\n";
        cin >> id;
        cout << "Scrie id-ul primului uitlizator nou:\n";
        cin >> utilizator_1;
        cout << "Scrie id-ul celui de-al doilea utilizator nou:\n";
        cin >> utilizator_2;
        if (!this->serviceUtilizator.findU(utilizator_1) || !this->serviceUtilizator.findU(utilizator_2))
            throw CustomException("Users id's must exist!\n");
        if (utilizator_1 == utilizator_2)
            throw CustomException("A user cannot be friend with himself!\n");
        if (this->servicePrietenie.updateP(id, utilizator_1, utilizator_2))
            cout << "Friendship updated!\n";
        else
            cout << "Friendship not found!\n";
    } catch (CustomException &exception) {
        cout << exception.getMessage();
    }
}

void Console::findPrietenie() {
    long id;
    cout << "Scrie id-ul relatiei de prietenie:\n";
    cin >> id;
    if (this->servicePrietenie.findP(id))
        cout << "Friendship found!\n";
    else
        cout << "Friendship not found!\n";
}

void Console::showAllU() {
    auto lista = serviceUtilizator.getAll();
    if (lista.getSize() < 1)
        cout << "No users in network!\n";
    for (auto i = 0; i < lista.getSize(); i++)
        cout << lista.get(i).toString() << "\n";
}

void Console::showAllM() {
    auto lista = serviceMesaj.getAll();
    if (lista.getSize() < 1)
        cout << "No messages in network!\n";
    for (auto i = 0; i < lista.getSize(); i++)
        cout << lista.get(i).toString() << "\n";
}

void Console::showAllP() {
    auto lista = servicePrietenie.getAll();
    if (lista.getSize() < 1)
        cout << "No friendship in network!\n";
    for (int i = 0; i < lista.getSize(); ++i) {
        cout << lista.get(i).toString() << "\n";
    }
}

void showMenuRetea() {
    cout << "<<<<<<MENIU>>>>>>\n";
    cout << "1.Afisare lista de prieteni pentru un user\n";
    cout << "2.Afisare lista de utilizatori cu un nume dat\n";
    cout << "3.Afisare lista cu mesajele unui utilizator\n";
    cout << "0.Meniul principal\n";
}

void Console::getUserFriendList() {
    long userId;
    cout << "Scrie id-ul utilizatorului:\n";
    cin >> userId;
    auto friendList = this->serviceRetea.getFriendList(userId);

    if (friendList.getSize() < 1) {
        cout << "Empty Friends List!\n";
    } else {
        cout << "User: " << userId << "\nFriends List:\n";
        auto list = friendList.get(userId);
        for (auto user: list) {
            cout << user.toString() << "\n";
        }
    }
}

void Console::getPeopleByName() {
    string nume;
    string prenume;
    cout << "Scrie numele utilizatorului:\n";
    cin >> nume;
    cout << "Scrie prenumele utilizatorului:\n";
    cin >> prenume;
    auto list = this->serviceRetea.getPeopleByName(nume, prenume);
    if (list.size() < 1) {
        cout << "No user found with name: " << nume << " " << prenume << endl;
    } else {
        cout << "Users with name: " << nume << " " << prenume << endl;
        for (auto user: list) {
            cout << user.toString() << "\n";
        }
    }
}

void Console::getUserMessageList() {
    try {
        long userId;
        cout << "Scrie id-ul utilizatorului:\n";
        cin >> userId;
        auto messageList = this->serviceRetea.getUserMessages(userId);
        if (messageList.getSize() < 1)
            cout << "The user doesn't have any messages sent!\n";
        else {
            cout << "UserId: " << userId << "\nMessage List:\n";
            for (auto message: messageList.get(userId)) {
                cout << message.toString() << "\n";
            }
        }
    } catch (CustomException &exception) {
        cout << exception.getMessage();
    }

}

void Console::showMenu() {
    cout << "*******MENIU*******\n";
    cout << "1. Meniu utilizator.\n";
    cout << "2. Meniu prietenie.\n";
    cout << "3. Meniu mesaj.\n";
    cout << "4. Meniu retea.\n";
    cout << "0. inchide program.\n";
}

void Console::showUI() {
    int optiune = 1;
    while (optiune) {
        showMenu();
        cout << "Scrie optiunea:\n";
        cin >> optiune;
        switch (optiune) {
            case 1: {
                while (optiune) {
                    showMenuUtilizator();
                    cout << "Scrie optiunea:\n";
                    cin >> optiune;
                    switch (optiune) {
                        case 1: {
                            addUtilizator();
                            break;
                        }
                        case 2: {
                            delUtilizator();
                            break;
                        }
                        case 3: {
                            updateUtilizator();
                            break;
                        }
                        case 4: {
                            findUtilizator();
                            break;
                        }
                        case 5: {
                            showAllU();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Optiune inexistenta!\n";
                    }
                }
                optiune = 1;
                break;
            }
            case 2: {while (optiune) {
                    showMenuPrietenie();
                    cout << "Scrie optiunea:\n";
                    cin >> optiune;
                    switch (optiune) {
                        case 1: {
                            addPrietenie();
                            break;
                        }
                        case 2: {
                            delPrietenie();
                            break;
                        }
                        case 3: {
                            updatePrietenie();
                            break;
                        }
                        case 4: {
                            findPrietenie();
                            break;
                        }
                        case 5: {
                            showAllP();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Optiune inexistenta!\n";
                    }
                }
                optiune = 1;
                break;
            }
            case 3: {
                while (optiune) {
                    showMenuMesaj();
                    cout << "Scrie optiunea:\n";
                    cin >> optiune;
                    switch (optiune) {
                        case 1: {
                            addMesaj();
                            break;
                        }
                        case 2: {
                            delMesaj();
                            break;
                        }
                        case 3: {
                            updateMesaj();
                            break;
                        }
                        case 4: {
                            findMesaj();
                            break;
                        }
                        case 5: {
                            showAllM();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Optiune inexistenta!\n";
                    }
                }
                optiune = 1;
                break;
            }
            case 4: {
                while (optiune) {
                    showMenuRetea();
                    cout << "Scrie optiunea:\n";
                    cin >> optiune;
                    switch (optiune) {
                        case 1: {
                            getUserFriendList();
                            break;
                        }
                        case 2: {
                            getPeopleByName();
                            break;
                        }
                        case 3: {
                            getUserMessageList();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Optiune inexistenta!\n";
                    }
                }
                optiune = 1;
                break;

            }
        }
    }

}

Console::Console(
        const ServiceUtilizator &serviceUtilizator,
        const ServiceMesaj &serviceMesaj,
        const ServicePrietenie &servicePrietenie,
        const ServiceRetea &serviceRetea) : serviceUtilizator(serviceUtilizator), serviceMesaj(
        serviceMesaj), servicePrietenie(servicePrietenie), serviceRetea(serviceRetea) {}


Console::Console() {

}