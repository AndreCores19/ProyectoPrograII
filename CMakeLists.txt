cmake_minimum_required(VERSION 4.1)
project(ProyectoPrograII)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPrograII main.cpp
        Equipo.cpp
        Equipo.h
        Computador.cpp
        Computador.h
        Servidor.cpp
        Servidor.h
        Laboratorio.cpp
        Laboratorio.h
        LectorArchivo.h
        LectorArchivo.cpp
        ErrorBase.cpp
        ErrorBase.h
        ArchivoInvalido.cpp
        ArchivoInvalido.h
        OperacionInconsistente.cpp
        OperacionInconsistente.h
        FormatoInvalido.cpp
        FormatoInvalido.h
        GenerarReporte.cpp
        GenerarReporte.h
        Ordenamiento.cpp
        Ordenamiento.h
        Incidencia.h
        PlanificadorDiario.cpp
        PlanificadorDiario.h
        Incidencia.cpp
)
