#include <iostream>
#include <stdlib.h>
#include "Pelicula.h"
#include "ListaPeliculas.h"

using namespace std;


void menu() {
    ListaPeliculas* lista = new ListaPeliculas();
    Pelicula* peli = new Pelicula();

    int opc = -1;

    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar pelicula" << endl;
        cout << "(2) Retirar pelicula" << endl;
        cout << "(3) Consultar pelicula" << endl;
        cout << "(4) Modificar pelicula" << endl;
        cout << "(5) Desplegar lista" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1:
            break;

        case 2:
            int cod = 0;
            cout << "Ingrese el codigo de la pelicula: " << endl;
            cin >> cod;
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            lista->desplegarLista();
            break;

        case 0:
            cout << "Finalizando el programa...";
            break;

        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }
}

Pelicula formularioPelicula() {
    int codPelicula;
    std::string nombre;
    int anno;
    std::string director;
    int cantSolicitudes;


    cout << "Digite el codigo de la pelicula:" << endl;
    cin >> codPelicula;

    cout << "Digite el nombre de la pelicula:" << endl;
    cin >> nombre;

    cout << "Digite el año de la pelicula:" << endl;
    cin >> anno;

    cout << "Digite el nombre del director:" << endl;
    cin >> director;

    cout << "Digite la cantidad de solicitudes:" << endl;
    cin >> cantSolicitudes;
}

int main() {
    menu();
}