//
// Created by andre on 24/4/2026.
//

#ifndef PROYECTOPROGRAII_ERRORBASE_H
#define PROYECTOPROGRAII_ERRORBASE_H
#include <iostream>
#include <exception>
using namespace std;

class ErrorBase : public exception {
protected:
    string mensaje;
public:
    ErrorBase(string);
    ErrorBase();
    string getMensaje();
    const char* what() const noexcept override;
};


#endif //PROYECTOPROGRAII_ERRORBASE_H