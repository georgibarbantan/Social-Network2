//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_CUSTOMEXCEPTION_H
#define PROIECT_SDA_CUSTOMEXCEPTION_H


#include "iostream"

class CustomException {
private:
    std::string message;
public:
    CustomException();

    CustomException(const std::string &message);

    virtual ~CustomException();

    const std::string &getMessage() const;

    void setMessage(const std::string &message);
};

#endif //PROIECT_SDA_CUSTOMEXCEPTION_H
