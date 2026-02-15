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

#endif