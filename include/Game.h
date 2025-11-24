#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "DataStructures.h"
#include "TwoSAT.h"
#include "Personaje.h"
using namespace std;

class Nivel
{
    public:
        Nivel(int n);
        void agregarDefensor(int npc);
        void agregarAtacante(int npc);
        void agregarNPC(int npc);

        Vec getDefensores() const;
        Vec getAtacantes() const;
        Vec getPresentes() const;
        virtual ~Nivel();

    protected:

    private:
        int numero;
        Vec defensores;
        Vec atacantes;
        Vec presentes;
};

class Juego
{
    private:
        Jugador jugador;
        NPC* npcs;
        Nivel* niveles;
        int totalNPC;
        int totalNiveles;

        Mapa mapa;

        TwoSAT construirTwoSATActual();

    public:
        Juego(int cantNPC, int cantNiveles);

        void inicializarNPCs();
        void inicializarNiveles();

        void mostrarMapaNivel(int n);
        void guardarCheckpoint();
        void jugarNivel(int n);

        ~Juego();
};


class Mapa
{
    private:
        const int ALT;
        const int ANC;

        char grid[ALT][ANC];

    public:
        Mapa();
        void limpiar();
        void dibujar() const;
        void colocarJugador(int x, int y);
        void colocarNPC(int x, int y, char simbolo);
        int getAltura() const;
        int getAncho() const;

        ~Mapa();
};

#endif // GAME_H
