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
