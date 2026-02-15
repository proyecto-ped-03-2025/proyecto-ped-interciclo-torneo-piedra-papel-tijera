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

void ListaJugadores::Jugar()
{
    // jugadores < 2
    if (!cabeza || cabeza->siguiente == cabeza)
    {
        cout << "Se necesitan al menos 2 jugadores\n";
        pausar();
        return;
    }

    // Reiniciar puntos cada que se juega un torneo
    Jugador *aux = cabeza;
    do
    {
        aux->puntuacion = 0;
        aux = aux->siguiente;
    } while (aux != cabeza);

    // Cada jugador se enfrenta a todos los demas una vez
    // El jugador1 es la cabeza al empezar
    Jugador *jugador1 = cabeza;
    do
    {
        // El jugador2 empieza desde -> siguiente del jugador1
        Jugador *jugador2 = jugador1->siguiente;
        while (jugador2 != cabeza) // El jugador no puede jugar consigo mismo
        {
            int jugada1, jugada2;

            cout << "\nEnfrentamiento: " << jugador1->nombre << " vs " << jugador2->nombre << endl;
            do
            {
                cout << jugador1->nombre << " (1:Tijera 2:Papel 3:Piedra): ";
                cin >> jugada1;
            } while (jugada1 < 1 || jugada1 > 3); // Evita que pongan otras opciones

            limpiar(); // El oponente no puede ver la respuesta :)

            do
            {
                cout << jugador2->nombre << " (1:Tijera 2:Papel 3:Piedra): ";
                cin >> jugada2;
            } while (jugada2 < 1 || jugada2 > 3); // Evita que pongan otras opciones

            // Determinando ganador
            if (resultado(jugada1, jugada2) == 1)
            {
                jugador1->puntuacion += 3;
                cout << jugador1->nombre << " gana (+3)" << endl;
            }
            else if (resultado(jugada1, jugada2) == -1)
            {
                jugador2->puntuacion += 3;
                cout << jugador2->nombre << " gana (+3)" << endl;
            }
            else
            {
                jugador1->puntuacion++;
                jugador2->puntuacion++;
                cout << "Empate (+1 cada uno)" << endl;
            }

            // El jugador3 (pasa a ser jugador2) como jugador2 -> siguiente y asi sucesivamente hasta que acabe la lista
            jugador2 = jugador2->siguiente;
        }
        // jugador1 -> siguiente (jugador2) pasa a ser jugador1
        jugador1 = jugador1->siguiente;
    } while (jugador1 != cabeza); // Evita que la cabeza juegue 2 veces y se repita

    cout << "Ronda finalizada" << endl;
    pausar();
    cin.get();
    limpiar();
}