#include "Simulacion.h"

int main() {
    try {
        Simulacion simulacion("equipos_100.txt", " ");
        simulacion.menu();

    } catch (ArchivoInvalido& e) {
        cout << "[ERROR] " << e.getMensaje() << endl;

    } catch (FormatoInvalido& e) {
        cout << "[ERROR] " << e.getMensaje() << endl;

    } catch (OperacionInconsistente& e) {
        cout << "[ERROR] " << e.getMensaje() << endl;

    } catch (exception& e) {
        cout << "[ERROR inesperado] " << e.what() << endl;
    }

    return 0;
}