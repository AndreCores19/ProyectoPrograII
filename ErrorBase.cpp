//
// Created by andre on 24/4/2026.
//

#include "ErrorBase.h"

ErrorBase::ErrorBase(string mensaje) {
    this->mensaje = mensaje;
}

ErrorBase::ErrorBase() {
    mensaje = "Operacion Invalida";
}

string ErrorBase::getMensaje() {
    return mensaje;
}

const char* ErrorBase::what() const noexcept {
    return mensaje.c_str();
}
