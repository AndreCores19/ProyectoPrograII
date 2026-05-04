
#include "Simulacion.h"

void Simulacion::ejecutarDia(int diaActual) {
    laboratorio->degradarEquipos();
    planificador->planificarDia(laboratorio->getEquipos(), laboratorio->getCantidad());
    laboratorio->setDiaActual(diaActual);
    reporte->genReporteDiario();
}

Simulacion::Simulacion(string rutaEquipos, string rutaIncidencias) {
    totalDias = 30;
    laboratorio = new Laboratorio();
    planificador = new PlanificadorDiario(laboratorio);
    lector = new LectorArchivo(rutaEquipos, rutaIncidencias);
    reporte = new GenerarReporte(laboratorio);
    lector->cargarEquipos(laboratorio);
}

Simulacion::Simulacion() {
    totalDias = 30;
    laboratorio = new Laboratorio();
    planificador = new PlanificadorDiario(laboratorio);
    lector = new LectorArchivo();
    reporte = new GenerarReporte(laboratorio);
}

Simulacion::~Simulacion() {
    delete laboratorio;
    delete planificador;
    delete lector;
    delete reporte;
}

void Simulacion::ejecutarSimulacion() {
    cout << "================== EJECUTANDO SIMULACION ==================" << endl;
    for (int i = 1; i <= totalDias; i++) {
        ejecutarDia(i);
    }
    cout << "================== SIMULACION FINALIZADA ==================" << endl;
    reporte->genReporteFinal();
}

void Simulacion::menu() {
    int opcion;
    do {
        cout << "================== MENU DE SIMULACION ==================" << endl;
        cout << "1. Ejecutar simulacion completa" << endl;
        cout << "2. Submenu de equipos" << endl;
        cout << "3. Submenu de incidencias" << endl;
        cout << "4. Submenu de reportes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            ejecutarSimulacion();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        case 2:
            cout<< endl;
            cout << "================== Submenu de equipos ==================" << endl;
            subMenuEquipos();
            break;
        case 3:
            cout<< endl;
            cout << "================== Submenu de incidencias ==================" << endl;
            subMenuIncidencias();
            break;
        case 4:
            cout<< endl;
            cout << "================== Submenu de reportes ==================" << endl;
            subMenuReportes();
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);
}

void Simulacion::subMenuEquipos() {
    int opcion;
    do {
        cout << "1. Cargar lista de equipos" << endl;
        cout << "2. Agregar un equipo" << endl;
        cout << "3. Ver estado de un equipo" << endl;
        cout << "4. Buscar equipo por ID" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1: {
                string ruta;
                cout<< "Escriba el nombre del archivo a cargar: ";
                cin >> ruta;
                lector->setRutaEquipos(ruta);
                lector->cargarEquipos(laboratorio);
                cout << "Equipos cargados correctamente." << endl;
                cout << endl;
                break;
        }
        case 2: {
                int opt;
                cout <<"Desea agregar un (1) Servidor o (2) Computador: ";
                cin >> opt;
                string id;
                int tiempoInactivo, criticidad;
                float degradacion;
                cout <<"Digite el ID del equipo: ";
                cin >> id;
                cout <<"Digite el tiempo inactivo del equipo: ";
                cin >> tiempoInactivo;
                cout <<"Digite la criticidad del equipo: ";
                cin >> criticidad;
                cout <<"Digite el nivel de degradacion del equipo: ";
                cin >> degradacion;
                if (opt == 1) {
                    laboratorio->agregarEquipo(new Servidor(id, 100, tiempoInactivo, criticidad, 0, degradacion));
                    cout <<"Equipo agregado correctamente. " << endl;
                } else if (opt == 2) {
                    laboratorio->agregarEquipo(new Computador(id, 100, tiempoInactivo, criticidad, 0, degradacion));
                    cout <<"Equipo agregado correctamente. " << endl << endl;
                } else
                    throw OperacionInconsistente("No se pudo anadir el equipo.");

                break;
        }
        case 3: {
                string id;
                cout << "Ingrese el ID del equipo: ";
                cin >> id;
                Equipo* eq = laboratorio->buscarEquipo(id);
                if (eq == nullptr)
                    cout << "Equipo no encontrado." << endl;
                else
                    cout << eq->getEstado() << endl;
                break;
        }
        case 4: {
                string id;
                cout << "Ingrese el ID del equipo: ";
                cin >> id;
                Equipo* eq = laboratorio->buscarEquipo(id);
                if (eq == nullptr)
                    cout << "Equipo no encontrado." << endl;
                else{
                    cout << "Equipo encontrado: " << eq->toString() << endl;
                    Servidor* srv = dynamic_cast<Servidor*>(eq);
                    if (srv != nullptr)
                        cout << "Tipo: Servidor | Degradacion: " << srv->getNivelDegradacion() << endl;

                    Computador* comp = dynamic_cast<Computador*>(eq);
                    if (comp != nullptr)
                        cout << "Tipo: Computador | Degradacion: " << comp->getNivelDegradacion() << endl;
                }
                break;
        }
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

void Simulacion::subMenuReportes() {
    int opcion;
    do {
        cout << "1. Ver reporte de un dia especifico" << endl;
        cout << "2. Generar reporte final" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case 1: {
            int dia;
                cout << "Ingrese el dia (1-30): ";
                cin >> dia;
                if (dia < 1 || dia > 30)
                    cout << "Dia invalido." << endl;
                else
                    reporte->mostrarReporteDia(dia);
                break;
                }
        case 2: {
                reporte->mostrarReporteFinal();
                cout << "Saliendo..." << endl;
                break;
            }
        case 0:
            {
                cout << "Volviendo al menu principal..." << endl;
                break;
            }
        default:
            cout << "Opcion invalida." << endl;
        }


    } while (opcion != 0);
}

void Simulacion::subMenuIncidencias() {
    int opcion;
    do {
        cout << "1. Cargar lista de incidencias" << endl;
        cout << "2. Generar incidencias aleatorias" << endl;
        cout << "3. Ver incidencias activas" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1: {
                    string ruta;
                    cout<< "Escriba el nombre del archivo a cargar: ";
                    cin >> ruta;
                    lector->setRutaIncidencias(ruta);
                    lector->cargarIncidencias(laboratorio);
                    cout << "Incidencias cargadas correctamente." << endl;
                    break;
                }
            case 2: {
                    int total;
                    cout << "Cuantas incidencias desea generar: ";
                    cin >> total;
                    laboratorio->generarIncidenciasAleatorias(total);
                    cout << "Incidencias generadas correctamente." << endl;
                    break;
        }
            case 3: {
                    string id;
                    cout << "Ingrese el ID del equipo: ";
                    cin >> id;
                    Equipo *eq = laboratorio->buscarEquipo(id);
                    if (eq == nullptr)
                        cout << "Equipo no encontrado." << endl;
                    else
                    {
                        cout << "Equipo encontrado: " << eq->getId() << endl;
                        cout << "Incidencias activas: ";
                        cout << eq->toStringIncidencias() << endl;
                    }
                    break;
                }
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}