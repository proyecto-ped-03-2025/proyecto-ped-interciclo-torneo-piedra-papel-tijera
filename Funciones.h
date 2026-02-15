#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
using namespace std;

// Struct Jugador
struct Jugador
{
    string nombre;
    int puntuacion;
    Jugador *siguiente;
};

// Clase ListaJugadores
class ListaJugadores
{
private:
    Jugador *cabeza;

public:
    ListaJugadores();

    //Funciones
    bool existeJugador(string nombre);
    void InsertarJugador(string nombre);
};
#endif