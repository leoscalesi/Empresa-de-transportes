#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "declaraciones.h"
#include "rlutil.h"


void menuConfiguracion(){

    bool salir=0;
    int opc;
    bool opcioninvalida=0;
    bool backupexitoso,restauradatosexitoso;
    bool cargainiciochofer=0;
    bool cargochofer;
    bool guardachoferini;
    bool guardochoferdat;
    bool cargainicioviaje=0;
    bool cargoviaje,guardaviajeini,guardoviajedat;
    string respuesta;

    struct Chofer cho;
    struct Viaje via;

    while(salir==0){

       rlutil::locate(25,3);
       cout << " ---------------------------- " << endl;
       rlutil::locate(30,5);
       cout << " MENU CONFIGURACION " << endl << endl;
       cout << endl << endl << endl << endl << endl;
       rlutil::locate(30,10);
       cout << " 1) REALIZAR BACKUP " << endl;
       rlutil::locate(30,12);
       cout << " 2) RESTAURAR BACKUP " << endl;
       rlutil::locate(24,14);
       cout << " 3) CARGAR DATOS DE INICIO CHOFERES " << endl;
       rlutil::locate(25,16);
       cout << " 4) CARGAR DATOS DE INICIO VIAJES " << endl;
       rlutil::locate(27,20);
       cout << " 0) VOLVER AL MENU PRINCIPAL " << endl << endl << endl;
       rlutil::locate(26,23);
       cout << " ---------------------------- " << endl;
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

      system("pause");
      system("cls");

      switch(opc){

      case 1:

        backupexitoso=Backup();

        if(backupexitoso==false){

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " NO SE PUDO REALIZAR EL BACKUP " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
            return;
        }

        else{

            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << " EL BACKUP SE REALIZO CON EXITO " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
        }

      break;

      case 2:

        restauradatosexitoso=restauraBackup();

        if(restauradatosexitoso==false){

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " NO SE PUDO RESTAURAR EL BACKUP " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
            return;

        }

        else{

            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << " EL BACKUP SE RESTAURO CON EXITO " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");
        }

      break;

      case 3:


        while(cargainiciochofer==0){

        cargochofer=cargarNuevoChofer(&cho);

        if(cargochofer==true){

            guardachoferini=guardarNuevoChoferArchivoIni(cho);

            if(guardachoferini==true){

                rlutil::setColor(rlutil::LIGHTGREEN);

                cout << " SE GUARDO EL REGISTRO DE CHOFER EXITOSAMENTE " << endl;
                rlutil::setColor(rlutil::WHITE);
                cout << endl << endl;
                cout << " DESEA CARGAR EN EL ARCHIVO CHOFERES ESTE REGISTRO DE INICIO? (S/N) " << "  ";
                cin >> respuesta;

                if(respuesta=="s" || respuesta=="S"){

                     guardochoferdat=guardarNuevoChoferArchivo(cho);

                     if(guardochoferdat==true){

                        rlutil::setColor(rlutil::LIGHTGREEN);
                        cout << " SE GUARDO EL REGISTRO DE CHOFER EXITOSAMENTE " << endl;
                        rlutil::setColor(rlutil::WHITE);

                     }

                     else{

                        rlutil::setColor(rlutil::LIGHTRED);
                        cout << " NO SE PUDO GUARDAR EL REGISTRO " << endl;
                        rlutil::setColor(rlutil::WHITE);
                     }

                }
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

        cout << endl << endl;
        cout << " DESEA CARGAR OTRO REGISTRO? (S/N) " << "   ";
        cin >> respuesta;

        system("pause");
        system("cls");

        if(respuesta=="n" || respuesta=="N"){

            cargainiciochofer=1;
            system("pause");
            system("cls");
        }

        }

      break;


      case 4:

        while(cargainicioviaje==0){

        cargoviaje=cargarNuevoViaje(&via);

        if(cargoviaje==true){

            guardaviajeini=guardarNuevoViajeArchivoIni(via);

            if(guardaviajeini==true){

                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << " SE GUARDO EL REGISTRO DE VIAJE EXITOSAMENTE " << endl;
                rlutil::setColor(rlutil::WHITE);
                cout << endl << endl;
                cout << " DESEA CARGAR EN EL ARCHIVO VIAJES ESTE REGISTRO DE INICIO? (S/N) " << "  ";
                cin >> respuesta;

                if(respuesta=="s" || respuesta=="S"){

                     guardoviajedat=guardarNuevoViajeArchivo(via);

                     if(guardoviajedat==true){

                        rlutil::setColor(rlutil::LIGHTGREEN);
                        cout << " SE GUARDO EL REGISTRO DE VIAJE EXITOSAMENTE " << endl;
                        rlutil::setColor(rlutil::WHITE);

                     }

                     else{

                        rlutil::setColor(rlutil::LIGHTRED);
                        cout << " NO SE PUDO GUARDAR EL REGISTRO " << endl;
                        rlutil::setColor(rlutil::WHITE);
                     }

                }
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

        cout << endl << endl;
        cout << " DESEA CARGAR OTRO REGISTRO? (S/N) " << "   ";
        cin >> respuesta;

        system("pause");
        system("cls");

        if(respuesta=="n" || respuesta=="N"){

            cargainicioviaje=1;
            system("pause");
            system("cls");
        }

        }


      break;



      case 0:

        salir=1;

      break;
      }
    }
}



bool Backup(){

    int cantregistroschoferes;
    int cantregistrosviajes;
    bool backupchofer,backupviaje;
    string respuesta;

    Chofer (*vCho);
    Viaje (*vVia);

    cantregistroschoferes=cantRegistrosArchivoChoferes();
    cantregistrosviajes=cantRegistrosArchivoViajes();

    if(cantregistroschoferes>0){

    vCho=(Chofer *)malloc(cantregistroschoferes*sizeof(Chofer));

    if(vCho==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO HAY MEMORIA DISPONIBLE " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }
    }
    else{return false;}

    guardoVectorChoferes(vCho,cantregistroschoferes);

    cout << endl << endl << endl;

    if (cantregistrosviajes>0){

    vVia=(Viaje *)malloc(cantregistrosviajes*sizeof(Viaje));

    if(vVia==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO HAY MEMORIA DISPONIBLE " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }
    }
    else{
        return false;
    }

    guardoVectorViajes(vVia,cantregistrosviajes);


    cout << endl << endl;
    cout << " CONFIRMA BACKUP? (S/N) " << endl;
    cin >> respuesta;

    if (respuesta=="s" || respuesta=="S"){

       backupchofer=realizaBackupChofer(vCho,cantregistroschoferes);
       backupviaje=realizaBackupViaje(vVia,cantregistrosviajes);


       if(backupchofer==false || backupviaje==false){return false;}
    }

    else{return false;}

    cout << endl << endl << endl;

    free(vCho);
    free(vVia);

    return true;
}



void guardoVectorChoferes(struct Chofer * vCho,int cant){

    FILE *p;
    int i;
    struct Chofer cho;

    p=fopen("choferes.dat","rb");

    if (p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return;
    }

    for(i=0;i<cant;i++){

        fread(&cho,sizeof(Chofer),1,p);

        vCho[i]=cho;
    }

    fclose(p);
}


void listarVector(struct Chofer * vCho, int cant){

    int i;

    for(i=0;i<cant;i++){listarChofer(vCho[i]);}
}


bool realizaBackupChofer(struct Chofer * vCho,int cant){

    FILE *p;
    struct Chofer cho;
    int i;

    p=fopen("choferes.bkp","wb");

    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    for(i=0;i<cant;i++){

        cho=vCho[i];
        fwrite(&cho,sizeof(Chofer),1,p);
    }

    fclose(p);

    return true;

}


void listarChoferesBkp(){

    FILE *p;
    struct Chofer cho;
    p=fopen("choferes.bkp","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return ;
    }
    while(fread(&cho,sizeof(Chofer),1,p)==1){listarChofer(cho);}

    system("pause");
    system("cls");
    fclose(p);

}

void listarViajesBkp(){

    FILE *p;
    struct Viaje via;
    p=fopen("viajes.bkp","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return ;
    }
    while(fread(&via,sizeof(Viaje),1,p)==1){listarViaje(via);}

    system("pause");
    system("cls");
    fclose(p);

}

void guardoVectorViajes(struct Viaje * vVia,int cant){

    FILE *p;
    int i;
    struct Viaje via;

    p=fopen("viajes.dat","rb");

    if (p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return;
    }

    for(i=0;i<cant;i++){

        fread(&via,sizeof(Viaje),1,p);
        vVia[i]=via;
    }

    fclose(p);
}


bool realizaBackupViaje(struct Viaje * vVia,int cant){

    FILE *p;
    struct Viaje via;
    int i;

    p=fopen("viajes.bkp","wb");

    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    for(i=0;i<cant;i++){

        via=vVia[i];
        fwrite(&via,sizeof(Viaje),1,p);

    }

    fclose(p);

    return true;
}


bool restauraBackup(){

    int cantregistroschoferesbkp;
    int cantregistrosviajesbkp;
    bool restaurabackupchofer,restaurabackupviaje;
    string respuesta;


    Chofer (*vCho);
    Viaje (*vVia);

    cantregistroschoferesbkp=cantRegistrosArchivoChoferesBkp();
    cantregistrosviajesbkp=cantRegistrosArchivoViajesBkp();

    vCho=(Chofer *)malloc(cantregistroschoferesbkp*sizeof(Chofer));

    if(vCho==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO HAY MEMORIA DISPONIBLE " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    guardoVectorChoferesBkp(vCho,cantregistroschoferesbkp);

    vVia=(Viaje *)malloc(cantregistrosviajesbkp*sizeof(Viaje));

    if(vVia==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO HAY MEMORIA DISPONIBLE " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
}

    guardoVectorViajesBkp(vVia,cantregistrosviajesbkp);

    cout << endl << endl;
    cout << " CONFIRMA RESTAURADO DEL BACKUP? (S/N) " << endl;
    cin >> respuesta;


    if (respuesta=="s" || respuesta=="S"){

       restaurabackupchofer=restauraBackupChofer(vCho,cantregistroschoferesbkp);
       restaurabackupviaje=restauraBackupViaje(vVia,cantregistrosviajesbkp);


       if(restaurabackupchofer==false || restaurabackupviaje==false){

          return false;
       }
    }

    else{return false;}

    free(vCho);
    free(vVia);

    return true;
}


int cantRegistrosArchivoChoferesBkp(){

    FILE *p;
    int bytes,cantregistros;

    p=fopen("choferes.bkp","rb");

    if(p==NULL){return -1;}

    fseek(p,0,SEEK_END);
    bytes=ftell(p);

    cantregistros=bytes/sizeof(Chofer);

    fclose(p);
    return cantregistros;
}


int cantRegistrosArchivoViajesBkp(){

    FILE *p;
    int bytes,cantregistros;

    p=fopen("viajes.bkp","rb");

    if(p==NULL){return -1;}
    fseek(p,0,SEEK_END);
    bytes=ftell(p);

    cantregistros=bytes/sizeof(Viaje);

    fclose(p);
    return cantregistros;
}


void guardoVectorChoferesBkp(struct Chofer * vCho, int cant){

    FILE *p;
    int i;
    struct Chofer cho;

    p=fopen("choferes.bkp","rb");

    if (p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return;
    }

    for(i=0;i<cant;i++){

        fread(&cho,sizeof(Chofer),1,p);
        vCho[i]=cho;
    }

    fclose(p);
}


void guardoVectorViajesBkp(struct Viaje * vVia,int cant){

    FILE *p;
    int i;
    struct Viaje via;

    p=fopen("viajes.bkp","rb");

    if (p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return;
    }

    for(i=0;i<cant;i++){

        fread(&via,sizeof(Viaje),1,p);
        vVia[i]=via;
    }

    fclose(p);
}


bool restauraBackupChofer(struct Chofer * vCho,int cant){

    FILE *p;
    struct Chofer cho;
    int i;

    p=fopen("choferes.dat","wb");

    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    for(i=0;i<cant;i++){

        cho=vCho[i];
        fwrite(&cho,sizeof(Chofer),1,p);
    }

    fclose(p);

    return true;

}

bool restauraBackupViaje(struct Viaje * vVia,int cant){

    FILE *p;
    struct Viaje via;
    int i;

    p=fopen("viajes.dat","wb");

    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    for(i=0;i<cant;i++){

        via=vVia[i];
        fwrite(&via,sizeof(Viaje),1,p);
    }

    fclose(p);

    return true;
}


bool guardarNuevoChoferArchivoIni(struct Chofer cho){

    FILE *p;
    bool escribio;
    p=fopen("choferes.ini","ab");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    escribio=fwrite(&cho,sizeof(Chofer),1,p);

    fclose(p);
    return escribio;
}


void listarChoferesIni(){

    FILE *p;
    struct Chofer cho;
    p=fopen("choferes.ini","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return ;
    }

    while(fread(&cho,sizeof(Chofer),1,p)==1){listarChofer(cho);}

    cout << endl << endl;
    system("pause");
    system("cls");
    fclose(p);
}


bool guardarNuevoViajeArchivoIni(struct Viaje via){

    FILE *p;
    bool escribio;
    p=fopen("viajes.ini","ab");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    escribio=fwrite(&via,sizeof(Viaje),1,p);

    fclose(p);
    return escribio;
}










