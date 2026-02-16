#include "Menu.h"
#include <iostream>
using namespace std;

void MenuJuego(ListaJugadores &lista);
void MenuPrincipal(ListaJugadores &lista);

int main()
{
    ListaJugadores lista;
    MenuPrincipal(lista);
    return 0;
}

void MenuJuego(ListaJugadores &lista)
{
    int opcion;
    string nombre;
    string nombreEliminar;

    do
    {
        limpiar();
        cout << "JUGUEMOS PIEDRA, PAPEL O TIJERA" << endl;
        cout << "==============================" << endl;
        cout << "Menu Juego" << endl;
        cout << "1. Jugar" << endl
             << "2. Insertar Jugador" << endl
             << "3. Eliminar Jugador" << endl
             << "4. Mostrar ganador de la ultima ronda" << endl
             << "5. Mostrar jugadores" << endl
             << "6. Regresar al menu principal" << endl;
        cout << "==============================" << endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            lista.Jugar();
            break;

        case 2:
            cout << "Ingrese nombre: ";
            getline(cin, nombre);
            lista.InsertarJugador(nombre);
            break;

        case 3:
            cout << "Ingrese nombre a eliminar: ";
            getline(cin, nombreEliminar);
            lista.EliminarJugador(nombreEliminar);
            break;

        case 4:
            lista.MostrarGanador();
            break;

        case 5:
            lista.MostrarJugadores();
            break;

        case 6:
            return;

        default:
            cout << "OpciÃ³n no valida" << endl;
            pausar();
            break;
        }
    } while (opcion != 6);
}


void MenuPrincipal(ListaJugadores &lista)
{
    int opcion;
    do
    {
        limpiar();
        cout << "BIENVENIDO AL JUEGO DE PIEDRA, PAPEL O TIJERA" << endl;
        cout << "==============================================" << endl;
        cout << "Menu Principal" << endl
             << "1. Jugar" << endl
             << "2. Ayuda" << endl
             << "3. Creditos" << endl
             << "4. Salir" << endl
             << "==============================================" << endl;
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            MenuJuego(lista);
            break;

        case 2:
            cout << "====================================================================" << endl;
            cout << "Ayuda del juego" << endl;
            cout << "El objetivo del juego es obtener la mayor puntuacion posible" << endl
                 << "debe de haber un minimo de 2 jugadores para poder jugar," << endl
                 << "cada jugador tendra una puntuacion que se actualizara cada vez que juegue," << endl
                 << "el jugador con la mayor puntuacion al final del juego sera el ganador." << endl
                 << "(Se puede ver el ganador en el menu de juego)" << endl;
            cout << "====================================================================" << endl;
            pausar();
            break;

        case 3:
            cout << "=============================================================================" << endl;
            cout << "\tCreditos:\t" << endl
                 << "\t Nombre: Anderson Alejandro Lopez Valle    Carnet: 00140023\t" << endl
                 << "\t Nombre: Daniel Andres Hernandez Barahona  Carnet: 00036225\t" << endl
                 << "\t Nombre: Elias Samuel Rubio Hernandez      Carnet: 00052524\t" << endl;
            cout << "=============================================================================" << endl;
            pausar();
            break;

        case 4:
            cout << "Saliendo...";
            break;

        default:
            cout << "Opcion no valida" << endl;
            pausar();
            break;
        }
    } while (opcion != 4);
}
