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
