
#include "GenerarReporte.h"




GenerarReporte::GenerarReporte(Laboratorio* laboratorio) {
    this->laboratorio = laboratorio;
}

GenerarReporte::~GenerarReporte()
{
    delete laboratorio;
}

void GenerarReporte::genReporteDiario() {
    reporte.open("reporte_diario.txt", ios::app);
    if (!reporte.is_open())
    {
        throw ArchivoInvalido("No se pudo abrir el archivo de reporte.");
    }
    else {

    }
}
