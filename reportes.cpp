#include <iostream>
#include <cstdlib>
using namespace std;
#include "declaraciones.h"
#include "rlutil.h"


void menuReportes(){

    bool salir=0;
    int opc;
    bool opcioninvalida=0;

    while(salir==0){

      rlutil::locate(23,3);

      cout << " ---------------------------- " << endl;

      rlutil::locate(30,5);

      cout << " MENU REPORTES " << endl << endl;
      cout << endl << endl << endl << endl << endl;
      rlutil::locate(31,10);
      cout << " 1) REPORTE 1 " << endl;
      rlutil::locate(31,12);
      cout << " 2) REPORTE 2 " << endl;
      rlutil::locate(31,14);
      cout << " 3) REPORTE 3 " << endl;
      rlutil::locate(23,17);
      cout << " 0) VOLVER AL MENU PRINCIPAL " << endl << endl << endl;
      rlutil::locate(23,19);
      cout << " ---------------------------- " << endl;
      cout << " INGRESE OPCION: " << " " ;
      cin >> opc;

      while(opcioninvalida==0){


          if(opc<0 || opc>3){

             rlutil::setColor(rlutil::LIGHTRED);
             cout << " OPCION INVALIDA " << endl << endl;
             rlutil::setColor(rlutil::WHITE);
             cout << " INGRESE OPCION: " << "       " ;
             cin >> opc;
          }
          else{
            opcioninvalida=1;
          }
      }

      system("pause");
      system("cls");

      switch(opc){

      case 1:

        reporte1();

      break;

      case 2:

        reporte2();

      break;

      case 3:

        reporte3();

      break;



      case 0:

        salir=1;

      break;


      }

    }


}


/*Informar la cantidad de viajes realizados en cada uno de los días de mayo del año actual con
más de 10 km de kilometraje*/



void reporte1(){

    int vMayo[31]={0};

    cargaVectorMayo(vMayo);

    listarVector(vMayo);

    system("pause");
    system("cls");
}



void cargaVectorMayo(int * v){

    FILE *p;
    struct Viaje via;

    p=fopen("viajes.dat","rb");
    if(p==NULL){

        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        return;
    }

    while(fread(&via,sizeof(Viaje),1,p)==1){

        if(via.fechaviaje.mes==5 && via.fechaviaje.anio==2020 && via.kilometraje > 10){

            v[via.fechaviaje.dia-1]++;
        }
    }

    fclose(p);

}


void listarVector(int * v){

    int i;

    for(i=0;i<31;i++){

        cout << " DIA: " << i+1 << "    " << v[i] << endl;
    }

}


/*Informar la cantidad de choferes que tienen registro de categoría 1*/


void reporte2(){

    FILE *p;
    struct Chofer cho;
    int cant=0;

    p=fopen("choferes.dat","rb");

    if(p==NULL){

        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        return;
    }

    while(fread(&cho,sizeof(Chofer),1,p)==1){

        if(cho.tiporegistro==1){

            cant ++;
        }
    }

    fclose(p);

    cout << endl << endl << endl;

    cout << " LA CANTIDAD DE CHOFERES CON REGISTRO DE CATEGORIA 1 ES DE " << cant << endl;

    system("pause");
    system("cls");


}




/*Generar un archivo con los choferes que hayan realizado viajes con el cliente de ID 14879, en agosto de este año,
con el siguiente formato:

DNI, nombre, apellido, y cantidad de viajes con el cliente de ID 14879.

En el archivo no deben repetirse los choferes.*/


void reporte3(){

     int cantregcho,cantregvia;

     Chofer *vCho;
     Viaje *vVia;

     cantregcho=cantRegistrosArchivoChoferes();
     cantregvia=cantRegistrosArchivoViajes();

     vCho=(Chofer*)malloc(cantregcho*sizeof(Chofer));
     vVia=(Viaje*)malloc(cantregvia*sizeof(Viaje));

     if(vCho==NULL){

        cout << " NO HAY MEMORIA DISPONIBLE " << endl;
        return;
     }


      if(vVia==NULL){

        cout << " NO HAY MEMORIA DISPONIBLE " << endl;
        return;
     }


      cargarVectorChoferes(vCho,cantregcho);
      cargarVectorViajes(vVia,cantregvia);

      /*listaChofer(vCho,cantregcho,vVia,cantregvia);*/


      buscaIdClienteYGuardaNuevoArchivo(vCho,cantregcho,vVia,cantregvia);

      /*listarRegistros();*/


      free(vCho);
      free (vVia);

      cout << endl << endl << endl;
      system("pause");
      system("cls");

}

void cargarVectorChoferes(struct Chofer * vCho, int cant){

    FILE *p;
    int i;
    struct Chofer cho;
    p=fopen("choferes.dat","rb");
    if(p==NULL){

        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        system("pause");
        system("cls");
        return;
    }
    for(i=0;i<cant;i++){

        fread(&cho,sizeof(Chofer),1,p);
        vCho[i]=cho;
    }
    fclose(p);

}


void cargarVectorViajes(struct Viaje * vVia, int cant){

    FILE *p;
    int i;
    struct Viaje via;
    p=fopen("viajes.dat","rb");
    if(p==NULL){

        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        system("pause");
        system("cls");
        return;
    }
    for(i=0;i<cant;i++){

        fread(&via,sizeof(Viaje),1,p);
        vVia[i]=via;
    }
    fclose(p);

}



void buscaIdClienteYGuardaNuevoArchivo(struct Chofer * vCho,int cantcho,struct Viaje * vVia,int cantvia){

      int i,j;
      int cant;
      struct Reporte3 repo;

      for(i=0;i<cantcho;i++){

            cant=0;

            for(j=0;j<cantvia;j++){

              //// NO PUSE j EN vVia EN EL PARCIAL  Y POR ESO DABA MAL

              if(strcmp(vCho[i].dni,vVia[j].dnichofer)==0){

                if(vVia[j].idcliente==51 && vVia[j].fechaviaje.mes==8 && vVia[j].fechaviaje.anio==2020){

                    cant ++;
                }
              }
            }

            strcpy(repo.apellido,vCho[i].apellido);
            strcpy(repo.nombre,vCho[i].nombre);
            strcpy(repo.dni,vCho[i].dni);
            repo.cant=cant;

            guardoRegistroNuevoArchivo(repo);


        }

}


void guardoRegistroNuevoArchivo(struct Reporte3 repo){

    FILE *p;

    p=fopen("nuevoarchivo.dat","ab");
    if(p==NULL){

        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        return;
    }

    fwrite(&repo,sizeof(Reporte3),1,p);

    fclose(p);

}


/*void listarRegistros(){

    FILE *p;
    struct Reporte3 repo;

    p=fopen("nuevoarchivo.dat","rb");
    if(p==NULL){

        cout << " NO SE PUDO ABRIR EL ARCHIVO " << endl;
        return;
    }

    while(fread(&repo,sizeof(Reporte3),1,p)==1){

        listarRegistro(repo);
    }

    fclose(p);

}


void listarRegistro(struct Reporte3 repo){

    cout << endl << endl << endl;

    cout << " DNI " << "    " << repo.dni << endl;
    cout << " NOMBRE " << "    " << repo.nombre << endl;
    cout << " APELLIDO " << "    " << repo.apellido << endl;
    cout << " CANTIDAD DE VIAJES CON EL CLIENTE ESPECIFICADO " << "    " << repo.cant << endl;

}*/































































































































