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
    ~ListaJugadores();

    //Funciones
    bool existeJugador(string nombre);
    void InsertarJugador(string nombre);
    void Jugar();
    void EliminarJugador(string nombre);
    void MostrarGanador();
};

// Funciones para limpiar la pantalla y pausar el programa
void pausar();
void limpiar();


#endif