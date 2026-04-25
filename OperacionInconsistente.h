
#ifndef PROYECTOPROGRAII_OPERACIONINCONSISTENTE_H
#define PROYECTOPROGRAII_OPERACIONINCONSISTENTE_H
#include "ErrorBase.h"


class OperacionInconsistente : public ErrorBase {
public:
    OperacionInconsistente(string);
};


#endif //PROYECTOPROGRAII_OPERACIONINCONSISTENTE_H