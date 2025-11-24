#include <iostream>
#include<fstream>
#include "Juego.h"
using namespace std;

int main() {
    Juego juego("datos.txt");

    string nombre;
    int puntaje;

    cout << "Nombre del jugador: ";
    cin >> nombre;

    cout << "Puntaje: ";
    cin >> puntaje;

    // Guarda
    juego.guardarArchivo(nombre, puntaje);

    // Carga
    juego.cargarArchivo();

    return 0;
}
