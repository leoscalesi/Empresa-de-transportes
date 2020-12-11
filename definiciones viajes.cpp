#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#include "declaraciones.h"
#include "rlutil.h"


void menuViajes(){

    bool salir=0;
    int opc;
    bool opcioninvalida=0;
    struct Viaje via;
    ///struct Fecha fech;
    bool cargoviaje,guardaviaje;
    bool bajalogica;

    while(salir==0){

      rlutil::locate(23,3);
      cout << " ---------------------------- " << endl;
      rlutil::locate(30,5);
      cout << " MENU VIAJES " << endl << endl;
      cout << endl << endl << endl << endl << endl;
      rlutil::locate(29,10);
      cout << " 1) NUEVO VIAJE " << endl;
      rlutil::locate(23,12);
      cout << " 2) LISTAR VIAJE POR IDVIAJE " << endl;
      rlutil::locate(24,14);
      cout << " 3) LISTAR TODOS LOS VIAJES " << endl;
      rlutil::locate(28,16);
      cout << " 4) ELIMINAR VIAJE " << endl << endl;
      cout  << endl << endl;
      rlutil::locate(23,19);
      cout << " 0) VOLVER AL MENU PRINCIPAL " << endl << endl << endl;
      rlutil::locate(23,22);
      cout << " ---------------------------- " << endl;
      rlutil::locate(0,28);

      cout << " INGRESE OPCION: " << " " ;
      cin >> opc;

      while(opcioninvalida==0){

         if(opc<0 || opc>4){

             rlutil::setColor(rlutil::LIGHTRED);
             cout << " OPCION INVALIDA " << endl << endl;
             rlutil::setColor(rlutil::WHITE);
             cout << " INGRESE OPCION: " << "       " ;
             cin >> opc;
          }

          else{opcioninvalida=1;}
      }

      //// PROBLEMAS AL VALIDAR SI INGRESA LETRAS WHILE INFINITO
      system("pause");
      system("cls");

      switch(opc){

      case 1:

        cargoviaje=cargarNuevoViaje(&via);

        if(cargoviaje==true){

            guardaviaje=guardarNuevoViajeArchivo(via);

            if(guardaviaje==true){

                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << " SE GUARDO EL REGISTRO DE VIAJE EXITOSAMENTE " << endl;
                rlutil::setColor(rlutil::WHITE);
                cout << endl << endl;
                system("pause");
                system("cls");
            }
            else{

                rlutil::setColor(rlutil::LIGHTRED);
                cout << " PROBLEMAS AL GUARDAR EN EL REGISTRO EN EL ARCHIVO " << endl;
                rlutil::setColor(rlutil::WHITE);
                cout << endl << endl;
                system("pause");
                system("cls");
            }
        }
        else{

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " PROBLEMAS AL CARGAR EL REGISTRO " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
        }

      break;

      case 2:

          listarViajePorId();

      break;

      case 3:

        listarViajes();

      break;


      case 4:

        bajalogica=eliminarViaje();

        if(bajalogica==false){

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " NO SE PUDO REALIZAR LA BAJA LOGICA " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
        }
        else{

            rlutil::setColor(rlutil::LIGHTGREEN);
            cout<< " LA BAJA LOGICA SE REALIZO CON EXITO " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
        }

      break;

      case 0:

        salir=1;

      break;
      }
    }
}


bool cargarNuevoViaje(struct Viaje * via){

    int id,cant,existedni;
    bool dnivalido;
    bool fechavalida,fechamenoroigual;
    /*bool patentevacia;*/
    bool patentevalida;

    id=generaIdAutomatico();

    via->idviaje=id;

    /*cout << " EL ID GENERADO AUTOMATICAMENTE ES: " << id;*/

    cout << endl << endl << endl;
    cout << " INGRESE DNI SIN ESPACIOS " <<endl;
    cout << " (MINIMO 7 DIGITOS,NO SE ACEPTAN CARACTERES NI CADENAS VACIAS): ";

    cargarCadena(via->dnichofer,10);

    cant=tamanioArchivoViajes();

   /// VERIFICAR QUE EL DNI EXISTA EN EL ARCHIVO CHOFERES
    /// NO ES NECESARIO TODAS LAS VALIDACIONES QUE HICE PARA CHOFERES PORQUE SI PONGO CUALQUIER COSA NO LA
    /// VA A ENCONTRAR EN EL ARCHIVO CHOFERES, DEBIDO A TODAS LAS VALIDACIONES QUE DEBE PASAR EL DNI AL INGRESAR
    /// UN NUEVO CHOFER
    /// LOS DNIS CON BAJA LOGICA SERAN CONSIDERADOS TAMBIEN, SI SE PONE UN DNI CON BAJA LOGICA, NO DEJARA
    /// SEGUIR CARGANDO, SOLO CONSIDERAMOS LOS DNI QUE NO ESTEN DADOS DE BAJA

    existedni=buscaDni(via->dnichofer);

    if(existedni<0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " EL DNI INGRESADO NO EXISTE EN EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
    }

    /*cout << " EL DNI EXISTE " << endl;*/

    cout << endl << endl << endl;
    cout << " INGRESE ID DEL CLIENTE: (NUMEROS MAYORES A 0):    ";
    cin >> via->idcliente;

    if(via->idcliente <= 0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITEN ID CLIENTE MENORES QUE 1 ";
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
    }

    cout << endl << endl << endl;

    cout << " INGRESE FECHA DEL VIAJE " << endl;
    cout << " DEBE SER MENOR O IGUAL A LA FECHA ACTUAL " << endl;

    cout << endl << endl;

    cout << " INGRESE DIA DEL VIAJE: " << "     ";
    cin >> via->fechaviaje.dia;
    cout << " INGRESE MES DEL VIAJE: " << "     ";
    cin >> via->fechaviaje.mes;
    cout << " INGRESE ANIO DEL VIAJE: " << "     ";
    cin >> via->fechaviaje.anio;

    fechavalida=validaFecha(via->fechaviaje.dia,via->fechaviaje.mes,via->fechaviaje.anio);

    if(fechavalida==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout<< " DATOS INVALIDOS DE DIA, MES O ANIO ";
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");

        return false;
    }
    else{

        fechamenoroigual=verificaFechaMenorIgualSistema(via->fechaviaje.dia,via->fechaviaje.mes,via->fechaviaje.anio);

        if(fechamenoroigual==false){

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " LA FECHA INGRESADA DEBE SER IGUAL O MENOR A LA FECHA ACTUAL ";
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");

            return false;
        }
    }

    cout << endl << endl << endl;

    cout << " INGRESE HORA DE SALIDA  (ENTRE O Y 23): " << "  ";
    cin >> via->horasalida;

     if(via->horasalida < 0 || via->horasalida > 23){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " HORA INVALIDA " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
     }

     cout << endl << endl << endl;

     cout << " INGRESE KILOMETRAJE DEL VIAJE: " << "  ";
     cin >> via->kilometraje;

      if(via->kilometraje <= 0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " KILOMETRAJE INVALIDO ";
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
     }


    cout << endl << endl << endl;

    cout << " INGRESE IMPORTE DEL VIAJE: " << "  ";
    cin >> via->importe;

    if(via->importe <= 0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " IMPORTE INVALIDO ";
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
    }

    cout << endl << endl << endl;

    cout << " INGRESE PATENTE " << endl;
    cout << " SOLO SE ADMITE UN ESPACIO Y NO MENOS DE SEIS CARACTERES ENTRE LETRAS Y NUMEROS " << endl;

    cargarCadena(via->patente,10);

    patentevalida=validaPatente(via->patente);
    /*patentevacia=verificaCadenaVacia(via->patente);*/

    if(patentevalida==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " PROBLEMAS AL CARGAR LA PATENTE " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
    }

    cout << endl << endl << endl;

    cout << " INGRESE CALIFICACION(ENTRE 0 Y 5): " << "  " << endl;
    cin >> via->calificacion;

    if(via->calificacion < 0 || via->calificacion > 5 ){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " CALIFICACION INVALIDA " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return false;
    }

    via->estadoviaje=true;

    system("pause");
    system("cls");
    return true;
}


int generaIdAutomatico(){

    /// CUENTO REGISTROS ARCHIVO Y LE SUMO 1 A ESE VALOR PARA GENERAR EL AUTONUMERICO
    int cant;
    cant=cantRegistrosArchivoViajes();
    cant=cant+1;

    return cant;
}


int cantRegistrosArchivoViajes(){

    FILE *p;
    int bytes,cantregistros;

    p=fopen("viajes.dat","rb");

    if(p==NULL){return 0;}
    fseek(p,0,SEEK_END);
    bytes=ftell(p);

    cantregistros=bytes/sizeof(Viaje);

    fclose(p);
    return cantregistros;

}

int tamanioArchivoViajes(){

    FILE *p;
    int cant;

    p=fopen("viajes.dat","rb");

    if(p==NULL){return -1;}

    fseek(p,0,SEEK_END);
    cant=ftell(p);

    fclose(p);
    return cant;
}

bool guardarNuevoViajeArchivo(struct Viaje via){

    FILE *p;

    p=fopen("viajes.dat","ab");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    fwrite(&via,sizeof(Viaje),1,p);
    fclose(p);

    return true;
}


void listarViaje(struct Viaje via){


    cout << endl << endl << endl << endl;

    if(via.estadoviaje==true){
    cout << " ID VIAJE: " << "    " << via.idviaje << endl << endl;
    cout << " DNI CHOFER: " << "  " << via.dnichofer << endl << endl;
    cout << " ID CLIENTE: " << "  " << via.idcliente << endl << endl;
    cout << " FECHA DEL VIAJE " << endl << endl;
    cout << " DIA: " << "    " << via.fechaviaje.dia << endl;
    cout << " MES: " << "    " << via.fechaviaje.mes << endl;
    cout << " ANIO: " << "   " << via.fechaviaje.anio << endl << endl;
    cout << " HORA DE SALIDA: " << "  " << via.horasalida << endl << endl;
    cout << " KILOMETRAJE: " << via.kilometraje << endl << endl;
    cout << " IMPORTE: " << "    " << via.importe << endl << endl;
    cout << " PATENTE: " << "    " << via.patente << endl << endl;
    cout << " CALIFICACION: " << "    " << via.calificacion<< endl << endl;

    cout << " -------------------------------------------------------";

    }
}


void listarViajes(){

    FILE *p;
    struct Viaje via;
    p=fopen("viajes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return;
    }

    while(fread(&via,sizeof(Viaje),1,p)==1){listarViaje(via);}

    cout << endl << endl;
    system("pause");
    system("cls");
    fclose(p);

}


void listarViajePorId(){

    struct Viaje via;
    struct Viaje viajeid;
    int posid;

    cout << " INGRESE EL ID DE VIAJE: " << "  " << endl;
    cin >> via.idviaje;
    system("pause");
    system("cls");

    posid=buscaIdViaje(via.idviaje);

    if(posid < 0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " EL ID DE VIAJE NO EXISTE EN EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");
        return;
    }

    viajeid=buscaViaje(posid);

    if(via.idviaje<0){return;}

    listarViaje(viajeid);
    system("pause");
    system("cls");
}



int buscaIdViaje(int id){

    FILE *p;
    int pos=0;
    struct Viaje via;
    p=fopen("viajes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return -1;
    }

    while(fread(&via,sizeof(Viaje),1,p)==1){

        if(id==via.idviaje){

            fclose(p);
            return pos;
        }
        pos ++;
    }

    fclose(p);
    pos=-2;

    return pos;
}



Viaje buscaViaje(int pos){

    FILE *p;
    struct Viaje via;

    p=fopen("viajes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        via.idviaje=-1111;
        return via;
    }

    fseek(p,pos*sizeof(Viaje),0);
    fread(&via,sizeof(Viaje),1,p);

    fclose(p);

    return via;

}


bool eliminarViaje(){

    struct Viaje via;
    int pos;
    string respuesta;
    bool sobreescribio;

    cout << " INGRESE ID DE VIAJE A DAR DE BAJA: " << endl;
    cin >> via.idviaje;
    system("cls");

    /// BUSCO QUE EXISTA EL DNI EN EL ARCHIVO Y TRAIGO LA POSICION

    pos=buscaIdViaje(via.idviaje);

    if(pos<0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO EXISTE EL ID DE VIAJE " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    /// BUSCO EL REGISTRO QUE OCUPA ESA POSICION

    via=buscaViaje(pos);

    if(via.idviaje<0){return false;}

    if(via.estadoviaje==false){return false;}

    cout << endl << endl << endl;
    cout << " USTED QUIERE DAR DE BAJA AL SIGUIENTE REGISTRO: " ;

    listarViaje(via);

    cout << endl << endl;

    cout << " CONFIRMA?  (S/N): " << "   ";
    cin >> respuesta;

    if(respuesta=="s"||respuesta=="S"){

      via.estadoviaje=false;

      sobreescribio=sobreescribirArchivoViajes(via,pos);

      if(sobreescribio==false){

         return false;
      }
      else{

         return true;
      }

    }
    else{

        return false;
    }
}


bool sobreescribirArchivoViajes(struct Viaje via, int pos){

    FILE *p;

    p=fopen("viajes.dat","rb+");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    fseek(p,pos*sizeof(Viaje),0);
    fwrite(&via,sizeof(Viaje),1,p);

    fclose(p);

    return true;
}


bool verificaMenosSieteCaracteres(char * cadena){

    int longitud;

    longitud=strlen(cadena);

    if(longitud<7){return false;}

    return true;

}


bool validaPatente(char * cadena){

    bool vacia;
    bool menosdesiete;

    vacia=verificaCadenaVacia(cadena);

    if(vacia==false){return false;}

    menosdesiete=verificaMenosSieteCaracteres(cadena);

    if (menosdesiete==false){return false;}

    return true;
}



