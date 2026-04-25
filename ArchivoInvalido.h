
#ifndef PROYECTOPROGRAII_ARCHIVOINVALIDO_H
#define PROYECTOPROGRAII_ARCHIVOINVALIDO_H
#include "ErrorBase.h"


class ArchivoInvalido : public ErrorBase {
public:
    ArchivoInvalido(string);
};


#endif //PROYECTOPROGRAII_ARCHIVOINVALIDO_H