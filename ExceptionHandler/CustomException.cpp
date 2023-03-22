//
// Created by georg on 20.06.2022.
//


#include "CustomException.h"

CustomException::CustomException(const std::string &message) : message(message) {}

const std::string &CustomException::getMessage() const {
    return message;
}

void CustomException::setMessage(const std::string &message) {
    CustomException::message = message;
}

CustomException::~CustomException() {

}

