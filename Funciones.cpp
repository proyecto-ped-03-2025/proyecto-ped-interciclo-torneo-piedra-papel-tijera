#include "Funciones.h"

void pausar()
{
    cout << "Presione Enter para continuar...";
    cin.get();
}
void limpiar()
{
    system("cls");
}

ListaJugadores::ListaJugadores()
{
    cabeza = nullptr;
}

// Agregar destructor
ListaJugadores::~ListaJugadores()
{
    if (!cabeza)
        return;

    Jugador *actual = cabeza->siguiente;

    while (actual != cabeza)
    {
        Jugador *temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    delete cabeza;
}

bool ListaJugadores::existeJugador(string nombre)
{
    // El jugador no es la cabeza
    if (!cabeza)
        return false;

    Jugador *temp = cabeza;

    do
    {
        if (temp->nombre == nombre)
            return true; // Jugador encontrado
        temp = temp->siguiente;
    } while (temp != cabeza);

    // Jugador no encontrado
    return false;
}

void ListaJugadores::InsertarJugador(string nombre)
{
    if (existeJugador(nombre))
    {
        cout << "El jugador ya existe" << endl;
        pausar();
        return;
    }

    // Contruye un nuevo nodo Jugador y le asigna los datos
    Jugador *nuevo = new Jugador{nombre, 0, nullptr};

    // Verifica si la lista esta vacia, lo ingresa al principio
    if (cabeza == nullptr)
    {
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
    }
    // Si no esta vacia, lo ingresa al final de la lista
    else
    {
        Jugador *temp = cabeza;
        while (temp->siguiente != cabeza)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = cabeza;
    }
    cout << "Jugador insertado: " << nombre << endl;
    pausar();
    limpiar();
    
    
}

// Funcion para calcular el resultado de cada partida
int resultado(int jugador1, int jugador2)
{
    // Los jugadores eligen la misma opcion
    if (jugador1 == jugador2)
        return 0; // empate

    // Se usa operador logico AND comparando las 2 jugadas, y OR para comparar cada caso que gana el jugador 1
    if ((jugador1 == 1 && jugador2 == 2) || // tijera gana papel
        (jugador1 == 2 && jugador2 == 3) || // papel gana piedra
        (jugador1 == 3 && jugador2 == 1))   // piedra gana tijera
        return 1;                           // gana jugador 1

    return -1; // gana jugador 2
}
