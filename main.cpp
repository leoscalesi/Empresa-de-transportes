#include <iostream>
#include <cstdlib>
using namespace std;
#include "declaraciones.h"
#include "rlutil.h"

int main(){

    system("COLOR 1F");

    bool salir=0;
    int opc;
    bool opcioninvalida=0;

    while(salir==0){

      rlutil::locate(23,3);
      cout << " ---------------------------- " << endl;
      rlutil::locate(30,5);

      cout << " MENU PRINCIPAL " << endl << endl;
      cout << endl << endl << endl << endl << endl;

      rlutil::locate(31,10);
      cout << " 1) CHOFERES " << endl;
      rlutil::locate(32,12);
      cout << " 2) VIAJES " << endl;
      rlutil::locate(31,14);
      cout << " 3) REPORTES " << endl;
      rlutil::locate(29,16);
      cout << " 4) CONFIGURACION " << endl << endl;
      cout  << endl << endl;
      rlutil::locate(27,19);
      cout << " 0) SALIR DEL PROGRAMA " << endl << endl << endl;
      rlutil::locate(23,21);
      cout << " ---------------------------- " << endl;
      rlutil::locate(0,26);

      cout << " INGRESE OPCION: " << " " ;
      cin >> opc;

      while(opcioninvalida==0){


          if(opc<0 || opc>4){

             rlutil::setColor(rlutil::LIGHTRED);
             cout << " OPCION INVALIDA " << endl << endl;
             rlutil::setColor(rlutil::WHITE);
             cout << " INGRESE OPCION: " << " " ;
             cin >> opc;
          }
          else{opcioninvalida=1;}
      }

      system("pause");
      system("cls");

      switch(opc){

      case 1:

        menuChoferes();

      break;

      case 2:

        menuViajes();

      break;

      case 3:

        menuReportes();

      break;

      case 4:

        menuConfiguracion();

      break;


      case 0:

        salir=1;

      break;
      }
    }

    return 0;
}
