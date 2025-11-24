#include <iostream>
#include <fstream>
#include "Juego.h"
using namespace std;

//  JUEGO

Juego::Juego() {}
Juego::~Juego() {}

//  NODO BASE

NodoBase::NodoBase(int id) : id(id), paradoja(false) {}

int NodoBase::getId() {
    return id;
}

bool NodoBase::esParadoja() {
    return paradoja;
}

void NodoBase::setParadoja(bool p) {
    paradoja = p;
}

NodoBase::~NodoBase() {}

//  LISTA NODOS (vacío aún)

NodoLista::NodoLista(int id) {
    this->id = id;
    sig = nullptr;
}

void ListaNodos::agregar(int id) { }
void ListaNodos::mostrar() { }
bool ListaNodos::contiene(int id) { return false; }
bool ListaNodos::vacia() { return true; }
void ListaNodos::eliminar(int id) { }

//  LINEA TEMPORAL

LineaTemporal::LineaTemporal(int id, int estado, int padre) : NodoBase(id) {
    this->estado = estado;
    this->padre = padre;
    _esCheckpoint = false;
    hijos = new ListaNodos();
}

void LineaTemporal::agregarHijo(int idHijo) { }

bool LineaTemporal::verificarParadoja() {
    return paradoja;
}

void LineaTemporal::mostrarInfo() {
    cout << "------Linea Temporal------" << endl;
    cout << "ID: " << id << endl;
    cout << "Estado: " << estado << endl;
    cout << "Padre: " << padre << endl;
    cout << "Es Checkpoint: " << (_esCheckpoint ? "Si" : "No") << endl;
    cout << "Tiene Paradoja: " << (paradoja ? "Si" : "No") << endl;
    cout << "Hijos: ";
    if (hijos->vacia()) {
        cout << "Ninguno" << endl;
    } else {
        hijos->mostrar();
    }
    cout << "-------------------" << endl;
}

void LineaTemporal::setCheckpoint(bool v) { _esCheckpoint = v; }
bool LineaTemporal::esCheckpoint() { return _esCheckpoint; }

//  GRAFO TEMPORAL (vacío)

void GrafoTemporal::agregarLinea(int estado, int padre) { }
LineaTemporal* GrafoTemporal::buscarLinea(int id) { return nullptr; }
void GrafoTemporal::conectar(int origen, int destino) { }
void GrafoTemporal::dfs(int inicio) { }
void GrafoTemporal::mostrarGrafo() { }
void GrafoTemporal::generarParadoja(int id) { }
void GrafoTemporal::propagarParadoja(int id) { }
int GrafoTemporal::getCheckpointCercano(int id) { return -1; }

//  HISTORIAL (vacío)

NodoHistorial::NodoHistorial(int id) {
    this->idLinea = id;
    ant = nullptr;
    esCheckpoint = false;
}

void PilaHistorial::push(int id) { }
void PilaHistorial::push(int id, bool checkpoint) { }
int PilaHistorial::pop() { return -1; }
int PilaHistorial::cima() { return -1; }
bool PilaHistorial::vacia() { return true; }
void PilaHistorial::mostrar() { }
int PilaHistorial::volverCheckpoint() { return -1; }

//  JUGADOR

void Jugador::setDatos(const char* n, int p, int t) {
    int i = 0;
    while (n[i] != '\0' && i < 19) {
        nombre[i] = n[i];
        i++;
    }
    nombre[i] = '\0';
    puntaje = p;
    tiempo = t;
}

void Jugador::mostrar() {
    cout << "Nombre: " << nombre << " | Puntaje: " << puntaje << " | Tiempo: " << tiempo << endl;
}

int Jugador::getPuntaje() { return puntaje; }
const char* Jugador::getNombre() { return nombre; }

//  BASE DE DATOS PUNTAJE

BaseDeDatosPuntaje::BaseDeDatosPuntaje() { total = 0; }

void BaseDeDatosPuntaje::agregar(const Jugador& j) {
    if (total < MAX) {
        jugadores[total] = j;
        total++;
    }
}

void BaseDeDatosPuntaje::mostrarRanking() {
    cout << "------RANKING-----" << endl;
    for (int i = 0; i < total; i++) {
        cout << i+1 << ". ";
        jugadores[i].mostrar();
    }
}

int BaseDeDatosPuntaje::mejorPuntaje() {
    if (total == 0) return 0;

    int mejor = jugadores[0].getPuntaje();
    for (int i = 1; i < total; i++) {
        if (jugadores[i].getPuntaje() > mejor)
            mejor = jugadores[i].getPuntaje();
    }
    return mejor;
}

void BaseDeDatosPuntaje::guardarArchivo() {
    ofstream file("puntajes.dat", ios::binary);

    if (!file) {
        cout << "Error al abrir archivo para guardar.\n";
        return;
    }

    file.write((char*)&total, sizeof(int));
    file.write((char*)jugadores, sizeof(Jugador) * total);

    file.close();
    cout << "Puntajes guardados correctamente.\n";
}

void BaseDeDatosPuntaje::cargarArchivo() {
    ifstream file("puntajes.dat", ios::binary);

    if (!file) {
        cout << "No existe archivo de puntajes.\n";
        return;
    }

    file.read((char*)&total, sizeof(int));
    file.read((char*)jugadores, sizeof(Jugador) * total);

    file.close();
    cout << "Puntajes cargados correctamente.\n";
}

//  JUEGO PRINCIPAL

void JuegoPrincipal::iniciar() {
    db.cargarArchivo();

    cout << "Nombre del jugador: ";
    char nombre[20];
    cin >> nombre;
    jugador.setDatos(nombre, 0, 0);
grafo.agregarLinea(0, -1);
    lineaActual = 0;
    fin = false;

    menu();
}

void JuegoPrincipal::menu() {
    int option;

    while (!fin) {
        cout << "-----MENU-----\n";
        cout << "1. Tomar decision\n";
        cout << "2. Mostrar estado actual\n";
        cout << "3. Salir\n";
        cin >> option;

        switch (option) {
            case 1: procesarDecision(); break;
            case 2: mostrarEstadoActual(); break;
            case 3: fin = true; break;
            default: cout << "Opcion invalida\n";
        }
    }

    guardarPuntaje();
}

void JuegoPrincipal::procesarDecision() {
    cout << "Tomaste una decision.\n";
}

void JuegoPrincipal::mostrarEstadoActual() {
    cout << "Estas en la linea temporal: " << lineaActual << endl;
}

bool JuegoPrincipal::verificarFin() { return false; }

void JuegoPrincipal::guardarPuntaje() {
    db.agregar(jugador);
    db.guardarArchivo();
}