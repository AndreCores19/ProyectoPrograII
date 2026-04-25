//
// Created by andre on 24/4/2026.
//

#ifndef PROYECTOPROGRAII_ERRORBASE_H
#define PROYECTOPROGRAII_ERRORBASE_H
#include <iostream>
#include <exception>
using namespace std;

class ErrorBase {
protected:
    string mensaje;
public:
    ErrorBase(string);
    ErrorBase();
    string getMensaje();
};


#endif //PROYECTOPROGRAII_ERRORBASE_H