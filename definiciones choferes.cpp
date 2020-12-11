#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#include "declaraciones.h"
#include "rlutil.h"

void menuChoferes(){

    bool salir=0;
    int opc;
    bool opcioninvalida=0;
    struct Chofer cho;
    struct Fecha fech;
    bool cargochofer,guardachofer;
    bool modificachofer;
    bool bajalogica;


    while(salir==0){

      rlutil::locate(23,3);
      cout << " ---------------------------- " << endl;
      rlutil::locate(30,5);
      cout << " MENU CHOFERES " << endl << endl;
      cout  << endl << endl << endl << endl << endl;
      rlutil::locate(29,10);
      cout << " 1) NUEVO CHOFER " << endl;
      rlutil::locate(27,12);
      cout << " 2) MODIFICAR CHOFER " << endl;
      rlutil::locate(25,14);
      cout << " 3) LISTAR CHOFER POR DNI " << endl;
      rlutil::locate(23,16);
      cout << " 4) LISTAR TODOS LOS CHOFERES " << endl;
      rlutil::locate(27,18);
      cout << " 5) ELIMINAR CHOFER " << endl << endl;
      cout << endl << endl;
      rlutil::locate(23,21);
      cout << " 0) VOLVER AL MENU PRINCIPAL " << endl << endl << endl;
      rlutil::locate(23,23);
      cout << " ---------------------------- " << endl;
      rlutil::locate(0,29);

      cout << " INGRESE OPCION: " << " " ;
      cin >> opc;

      while(opcioninvalida==0){

         if(opc<0 || opc>5){

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

        cargochofer=cargarNuevoChofer(&cho);

        if(cargochofer==true){

            guardachofer=guardarNuevoChoferArchivo(cho);

            if(guardachofer==true){

                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << " SE GUARDO EL REGISTRO DE CHOFER EXITOSAMENTE " << endl;
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

        modificachofer=modificarChofer();

        if(modificachofer==true){

            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << " LA FECHA DE VENCIMIENTO DE LA LICENCIA FUE MODIFICADA CORRECTAMENTE " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl << endl;
            system("pause");
            system("cls");
        }

        else{

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " LA FECHA DE VENCIMIENTO DE LA LICENCIA NO PUDO MODIFICARSE " << endl;
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl << endl;
            system("pause");
            system("cls");
        }

      break;

      case 3:

        listarChoferPorDni();

      break;

      case 4:

        listarChoferes();

      break;

      case 5:

        bajalogica=eliminarChofer();

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

bool cargarNuevoChofer(struct Chofer *cho){

    bool dnivalido;
    bool apellidovalido;
    bool nombrevalido;
    bool fechavalida,numregvalido;
    bool fechamenoroigual,fechamayoroigual;
    bool cuitvalido,numtelvalido;
    bool fechavencimientovalida;
    int cant;
    bool dnirepetido,cuitrepetido;

    cout << " INGRESE DNI SIN ESPACIOS " << endl;
    cout << " (MINIMO 7 DIGITOS,NO SE ACEPTAN LETRAS NI CADENAS VACIAS): ";

    cargarCadena(cho->dni,10);

    cant=tamanioArchivoChoferes();

    if(cant>0){

       dnirepetido=buscaDniRepetido(cho->dni);

       if (dnirepetido==false){

          rlutil::setColor(rlutil::LIGHTRED);
          cout << " DNI YA EXISTENTE " << endl;
          rlutil::setColor(rlutil::WHITE);

          return false;
       }
    }

    dnivalido=validaDni(cho->dni);

    if(dnivalido==false){
        system("pause");
        system("cls");
        return false;
    }

    cout << endl << endl << endl;
    cout << " INGRESE APELLIDO: " << endl;
    cout << " SE ADMITE SOLO UN ESPACIO ENTRE CARACTERES " <<endl;
    cout <<" NO SE ADMITEN DIGITOS NI CADENAS VACIAS:   " ;

    cargarCadena(cho->apellido,50);

    apellidovalido=validaNombreApellido(cho->apellido);

    if(apellidovalido==false){

        system("pause");
        system("cls");
        return false;
    }

    cout << endl << endl << endl;
    cout << " INGRESE NOMBRE: " << endl;
    cout << " SE ADMITE SOLO UN ESPACIO ENTRE CARACTERES " <<endl;
    cout <<" NO SE ADMITEN DIGITOS NI CADENAS VACIAS:   " ;


    cargarCadena(cho->nombre,50);

    nombrevalido=validaNombreApellido(cho->nombre);

    if(nombrevalido==false){

        system("pause");
        system("cls");
        return false;
    }

    cout << endl << endl << endl;

    cout << " FECHA DE INGRESO " << endl << endl;
    cout << " INGRESE DIA DE INGRESO: " << "     ";
    cin >> cho->fechaingreso.dia;
    cout << " INGRESE MES DE INGRESO: " << "     ";
    cin >> cho->fechaingreso.mes;
    cout << " INGRESE ANIO DE INGRESO: " << "     ";
    cin >> cho->fechaingreso.anio;


    fechavalida=validaFecha(cho->fechaingreso.dia,cho->fechaingreso.mes,cho->fechaingreso.anio);

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

        fechamenoroigual=verificaFechaMenorIgualSistema(cho->fechaingreso.dia,cho->fechaingreso.mes,cho->fechaingreso.anio);

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
    cout << " INGRESE CUIT SIN ESPACIOS: " << endl ;
    cout << " (MINIMO 10 DIGITOS,NO SE ACEPTAN LETRAS NI CADENAS VACIAS): ";


    cargarCadena(cho->cuit,20);

    if(cant>0){

        cuitrepetido=buscaCuitRepetido(cho->cuit);

       if (cuitrepetido==false){

          rlutil::setColor(rlutil::LIGHTRED);
          cout << " CUIT YA EXISTENTE " << endl;
          rlutil::setColor(rlutil::WHITE);

          return false;
       }

    }

    cuitvalido=validaCuit(cho->cuit);

    if(cuitvalido==false){

        system("pause");
        system("cls");

        return false;
    }

    cout << " FECHA DE VENCIMIENTO DEL REGISTRO " << endl << endl;
    cout << " INGRESE DIA DE VENCIMIENTO DEL REGISTRO: " << "     ";
    cin >> cho->fechavencimientoregistro.dia;
    cout << " INGRESE MES DE DE VENCIMIENTO DEL REGISTRO: " << "     ";
    cin >> cho->fechavencimientoregistro.mes;
    cout << " INGRESE ANIO DE VENCIMIENTO DEL REGISTRO: " << "     ";
    cin >> cho->fechavencimientoregistro.anio;


    fechavencimientovalida=validaFecha(cho->fechavencimientoregistro.dia,cho->fechavencimientoregistro.mes,cho->fechavencimientoregistro.anio);

    if(fechavencimientovalida==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout<< " DATOS INVALIDOS DE DIA, MES O ANIO ";
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");

        return false;
    }
    else{

        fechamayoroigual=verificaFechaMayorIgualSistema(cho->fechavencimientoregistro.dia,cho->fechavencimientoregistro.mes,cho->fechavencimientoregistro.anio);

        if(fechamayoroigual==false){

            rlutil::setColor(rlutil::LIGHTRED);

            cout << " LA FECHA DE VENCIMIENTO INGRESADA DEBE SER  MAYOR A LA FECHA ACTUAL ";
            rlutil::setColor(rlutil::WHITE);
            cout << endl << endl;
            system("pause");
            system("cls");

            return false;
        }
    }

    cout << endl << endl << endl;

    cout << " INGRESE TIPO DE REGISTRO (1 A 3): " << "    ";
    cin.ignore();
    cin >> cho->tiporegistro;

    numregvalido=validaNumeroRegistro(cho->tiporegistro);


    if(numregvalido==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NUMERO DE REGISTRO INVALIDO " << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl << endl;
        system("pause");
        system("cls");

        return false;

    }

    cout << endl << endl << endl;


    cout << " INGRESE NUMERO DE TELEFONO (11 DIGITOS O MAS): " << "    ";

    cargarCadena(cho->telefono,15);

    numtelvalido=validaNumeroTelefono(cho->telefono);

    if(numtelvalido==false){

        system("pause");
        system("cls");

        return false;

    }

    cout << endl << endl << endl;

    cout << " ES PROPIETARIO? (1: SI, 0: NO) " << "   ";
    cin >> cho->propietarioauto;

    cho->estado=true;

    system("pause");
    system("cls");

    return true;
}


bool validaDni(char *cadena){

    bool cadenavacia;
    bool tieneletras;
    bool menosdesietedigitos;


    ////BUSCO EN EL ARCHIVO SI EXISTE EL DNI SIEMPRE Y CUANDO HAYA AL MENOS UN REGISTRO
    // AL USAR cin.getline ME CORTA EN LOS PRIMEROS 10 CARACTERES, SI ME DEJA INGRESAR MENOS CARACTERES
    /// POR ESO LO VOY A CONDICIONAR ENTRE 8 Y 10.
    /// PRIMER FUNCION VERIFICA QUE EL DNI NO SE REPITA EN EL ARCHIVO CHOFERES
    /// LA HAGO AL FINAL
    /// FUNCION QUE NO PERMITE QUE LA CADENA ESTE VACIA
    cadenavacia=verificaCadenaVacia(cadena);

    if (cadenavacia==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITEN CADENAS VACIAS O ESPACIOS " ;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    /// FUNCION QUE NO PERMITE QUE EL DNI CONTENGA LETRAS
    /// TAMPOCO SE ADMITEN ESPACIOS VACIOS

    tieneletras=buscaLetras(cadena);

    if(tieneletras==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITEN CARACTERES O ESPACIOS EN ESTE CAMPO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    menosdesietedigitos=cuentaMasDeSeis(cadena);

    /// ESTABLEZCO QUE EL DNI NO PUEDA TENER MENOS DE OCHO DIGITOS

    if(menosdesietedigitos==false){return false;}

    return true;

}


bool verificaCadenaVacia(char *cadena){

    int i;
    int cont=0;
    int contespacios=0;

    while(cadena[cont]!='\0'){

        if(cadena[cont]==' '){contespacios++;}

        cont ++;
    }

    if(contespacios>1){return false;}

    return true;
}



bool cuentaMasDeSeis(char * cadena){

    int esdigito;
    int cont=0;
    int contdigitos=0;

    while(cadena[cont] != '\0'){

        esdigito=isdigit(cadena[cont]);

        if(esdigito==1){contdigitos ++;}

        cont++;
    }

    if(contdigitos<7){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << "  NO SE ADMITEN MENOS DE 7 DIGITOS ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    return true;
}



bool buscaLetras(char * cadena){

    int esdigito;
    int cont=0;
    int contletras=0;

    while(cadena[cont] != '\0'){

        esdigito=isdigit(cadena[cont]);

        if(esdigito==0){contletras ++;}

        cont++;
    }

    if(contletras>0){return false;}

    return true;
}


bool validaNombreApellido(char *cadena){

    bool cadenavacia;
    bool tienenumero;
    bool menosdoscaracteres;

    /// AL MENOS DOS CARACTERES DEBEN INGRESARSE
    menosdoscaracteres=verificaMenosDosCaracteres(cadena);

    if (menosdoscaracteres==false){return false;}

    /// SE PERMITE SOLO UN ESPACIO VACIO
    cadenavacia=verificaCadenaVacia(cadena);

    if (cadenavacia==false){return false;}

    /// VERIFICA QUE EN DONDE HAYA QUE ESCRIBIR LETRAS SOLO HAYA LETRAS

    tienenumero=buscaDigito(cadena);

    if (tienenumero==false){return false;}

    return true;
}


bool buscaDigito(char * cadena){

    int esdigito;
    int cont=0;
    int contdigitos=0;

    while(cadena[cont] != '\0'){

        esdigito=isdigit(cadena[cont]);

        if(esdigito==1){contdigitos ++;}

        cont++;
    }

    if(contdigitos>0){return false;}

    return true;
}


bool validaFecha(int dia,int mes, int anio){

    if(dia<1 || dia >31){return false;}

    if(mes<1 || mes>12){return false;}

    /// VALIDACION PERSONAL YA QUE NO SE ACLARABA NADA AL RESPECTO EN EL TP

    if(anio<1900){return false;}

    return true;

}


bool verificaFechaMenorIgualSistema(int dia,int mes,int anio){

    int vDiaMesAnio[3]={0};  /// v[0] dia   v[1] mes     v[2]  anio

    calculaFechaSistema(vDiaMesAnio);

    if(anio>vDiaMesAnio[2]){return false;}

    if(anio==vDiaMesAnio[2]){

        if(mes>vDiaMesAnio[1]){return false;}
    }

    if(anio==vDiaMesAnio[2]){

        if(mes==vDiaMesAnio[1]){

                if(dia>vDiaMesAnio[0]){return false;}
        }
    }

    return true;

}


void calculaFechaSistema(int * vDiaMesAnio){


  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  /*printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
  strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
  printf("\n\n%s", cad);*/

  vDiaMesAnio[0]=tmPtr->tm_mday;
  vDiaMesAnio[1]=tmPtr->tm_mon+1;
  vDiaMesAnio[2]=1900+tmPtr->tm_year;
}

bool validaCuit(char  *cadena){

    bool cadenavacia;
    bool tieneletras;
    bool diezomasdigitos;

    cadenavacia=verificaCadenaVacia(cadena);

    if (cadenavacia==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITE CUIT VACIO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    tieneletras=buscaLetras(cadena);

    if(tieneletras==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITEN LETRAS O ESPACIOS EN ESTE CAMPO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

     /// SOLO PERMITO QUE EL CUIT TENGA ONCE DIGITOS, VALIDACION PERSONAL
     diezomasdigitos=cuentaMasDeDiez(cadena);

     if(diezomasdigitos==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " SE ADMITEN SOLO CANTIDADES MAYORES O IGUALES A 11 DIGITOS ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    return true;
}


bool cuentaMasDeOnce(char *cadena){

    int esdigito;
    int cont=0;
    int contdigitos=0;

    while(cadena[cont] != '\0'){

        esdigito=isdigit(cadena[cont]);

        if(esdigito==1){contdigitos ++;}

        cont++;
    }

    if(contdigitos<11){return false;}

    return true;
}


bool cuentaMasDeDiez(char * cadena){

    int esdigito;
    int cont=0;
    int contdigitos=0;

    while(cadena[cont] != '\0'){

        esdigito=isdigit(cadena[cont]);

        if(esdigito==1){contdigitos ++;}

        cont++;
    }

    if(contdigitos<10){return false;}

    return true;
}


bool verificaFechaMayorIgualSistema(int dia,int mes,int anio){

    int vDiaMesAnio[3]={0};  //// v[0] dia   v[1] mes     v[2]  anio

    calculaFechaSistema(vDiaMesAnio);

    if(anio<vDiaMesAnio[2]){return false;}

    if(anio==vDiaMesAnio[2]){

        if(mes<vDiaMesAnio[1]){return false;}
    }

    if(anio==vDiaMesAnio[2]){

        if(mes==vDiaMesAnio[1]){

                if(dia<=vDiaMesAnio[0]){return false;}
        }
    }

    return true;
}

bool validaNumeroRegistro(int n){

    if(n<1 || n>3){return false;}

    return true;
}

bool validaNumeroTelefono(char * cadena){


    bool cadenavacia;
    bool tieneletras;
    bool onceomasdigitos;

    cadenavacia=verificaCadenaVacia(cadena);

    if (cadenavacia==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITEN CADENAS VACIAS" ;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    /// FUNCION QUE NO PERMITE QUE EL DNI CONTENGA LETRAS
    /// TAMPOCO SE ADMITEN ESPACIOS VACIOS

    tieneletras=buscaLetras(cadena);

    if(tieneletras==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ADMITEN LETRAS O ESPACIOS EN ESTE CAMPO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    onceomasdigitos=cuentaMasDeOnce(cadena);

    if(onceomasdigitos==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " SE ADMITEN SOLO CANTIDADES MAYORES O IGUALES A 11 DIGITOS AL CARGAR EL TELEFONO ";
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    return true;
}


int tamanioArchivoChoferes(){

    FILE *p;
    int cant;

    p=fopen("choferes.dat","rb");

    if(p==NULL){return -1;}

    fseek(p,0,SEEK_END);
    cant=ftell(p);

    fclose(p);
    return cant;
}

bool guardarNuevoChoferArchivo(struct Chofer cho){

    FILE *p;
    bool escribio;
    p=fopen("choferes.dat","ab");
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

void listarChofer(struct Chofer cho){


    cout << endl << endl << endl << endl;

    if(cho.estado==true){
    cout << " DNI: " << "         " << cho.dni << endl << endl;
    cout << " APELLIDO: " << "    " << cho.apellido << endl << endl;
    cout << " NOMBRE: " << "      " << cho.nombre << endl << endl;
    cout << " FECHA DE INGRESO: " << endl << endl;
    cout << " DIA: " << "    " << cho.fechaingreso.dia << endl;
    cout << " MES: " << "    " << cho.fechaingreso.mes << endl;
    cout << " ANIO: " << "   " << cho.fechaingreso.anio << endl << endl;
    cout << " CUIT: " << "   " << cho.cuit << endl << endl;
    cout << " TIPO DE REGISTRO: " << cho.tiporegistro << endl << endl;
    cout << " FECHA DE VENCIMIENTO DEL REGISTRO "  << endl << endl;
    cout << " DIA: " << "     " << cho.fechavencimientoregistro.dia << endl;
    cout << " MES: " << "     " << cho.fechavencimientoregistro.mes << endl;
    cout << " ANIO: " << "    " << cho.fechavencimientoregistro.anio << endl<<endl;
    cout << " TELEFONO: " << cho.telefono << endl << endl;
    cout << " PROPIETARIO: " << cho.propietarioauto << endl << endl;
    cout << " -------------------------------------------------------";

    }
}


void listarChoferes(){

    FILE *p;
    struct Chofer cho;
    p=fopen("choferes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return;
    }

    while(fread(&cho,sizeof(Chofer),1,p)==1){listarChofer(cho);}

    cout << endl << endl;
    system("pause");
    system("cls");
    fclose(p);
}


void cargarCadena(char *pal, int tam){

  int i;

  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


bool buscaDniRepetido(char * cadena){

    FILE *p;
    struct Chofer cho;
    p=fopen("choferes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return false ;
    }

    while(fread(&cho,sizeof(Chofer),1,p)==1){

        if(strcmp(cadena,cho.dni)==0){return false;}
    }

    fclose(p);

    return true;
}


bool buscaCuitRepetido(char * cadena){

    FILE *p;
    struct Chofer cho;
    p=fopen("choferes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return false ;
    }

    while(fread(&cho,sizeof(Chofer),1,p)==1){

        if(strcmp(cadena,cho.cuit)==0){return false;}
    }

    fclose(p);

    return true;
}


bool modificarChofer(){

    struct Chofer cho;
    int pos;
    bool fechavencimientovalida;
    bool fechamayoroigual;
    string respuesta;
    bool sobreescribio;

    cout << " INGRESE DNI DEL CHOFER: " << endl;
    cargarCadena(cho.dni,10);
    system("cls");

    /// BUSCO QUE EXISTA EL DNI EN EL ARCHIVO Y TRAIGO LA POSICION

    pos=buscaDni(cho.dni);

    if(pos<0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ENCONTRO EL DNI " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    /// BUSCO EL REGISTRO QUE OCUPA ESA POSICION

    cho=buscaChofer(pos);

    if(cho.tiporegistro<0){return false;}

    cout << endl << endl << endl;

    if(cho.estado==true){

    cout << " USTED QUIERE MODIFICAR EL SIGUIENTE REGISTRO: " ;

    listarChofer(cho);

    cout << endl << endl;

    cout << " CONFIRMA?  (S/N): " << "   ";
    cin >> respuesta;

    if(respuesta=="s"||respuesta=="S"){

      system("cls");
      cout << " NUEVA FECHA DE VENCIMIENTO DEL REGISTRO " << endl << endl;
      cout << " INGRESE DIA DE VENCIMIENTO DEL REGISTRO: " << "     ";
      cin >> cho.fechavencimientoregistro.dia;
      cout << " INGRESE MES DE DE VENCIMIENTO DEL REGISTRO: " << "     ";
      cin >> cho.fechavencimientoregistro.mes;
      cout << " INGRESE ANIO DE VENCIMIENTO DEL REGISTRO: " << "     ";
      cin >> cho.fechavencimientoregistro.anio;


      fechavencimientovalida=validaFecha(cho.fechavencimientoregistro.dia,cho.fechavencimientoregistro.mes,cho.fechavencimientoregistro.anio);

      if(fechavencimientovalida==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout<< " DATOS INVALIDOS DE DIA, MES O ANIO ";
        rlutil::setColor(rlutil::WHITE);

        cout << endl << endl;
        system("pause");
        system("cls");

        return false;
      }
      else{

        fechamayoroigual=verificaFechaMayorIgualSistema(cho.fechavencimientoregistro.dia,cho.fechavencimientoregistro.mes,cho.fechavencimientoregistro.anio);

        if(fechamayoroigual==false){

            rlutil::setColor(rlutil::LIGHTRED);
            cout << " LA FECHA DE VENCIMIENTO INGRESADA DEBE SER  MAYOR A LA FECHA ACTUAL ";
            rlutil::setColor(rlutil::WHITE);

            cout << endl << endl;
            system("pause");
            system("cls");

            return false;
        }
      }

      sobreescribio=sobreescribirArchivo(cho,pos);

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

    else{

        return false;
    }

}



int buscaDni(char * cadena){

    FILE *p;
    struct Chofer cho;
    int pos=0;
    p=fopen("choferes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO ";
        rlutil::setColor(rlutil::WHITE);

        return -1 ;
    }

    while(fread(&cho,sizeof(Chofer),1,p)==1){

        if(cho.estado==true){

           if(strcmp(cadena,cho.dni)==0){

            fclose(p);
            return pos;
           }
        }

        pos++;
    }

    fclose(p);
    return -2;
}


Chofer buscaChofer(int pos){

    FILE *p;
    struct Chofer cho;

    p=fopen("choferes.dat","rb");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        cho.tiporegistro=-1111;
        return cho;
    }

    fseek(p,pos*sizeof(Chofer),0);
    fread(&cho,sizeof(Chofer),1,p);

    fclose(p);

    return cho;
}


bool sobreescribirArchivo(struct Chofer cho,int pos){

    FILE *p;

    p=fopen("choferes.dat","rb+");
    if(p==NULL){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE PUDO LEER EL ARCHIVO " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    fseek(p,pos*sizeof(Chofer),0);
    fwrite(&cho,sizeof(Chofer),1,p);

    fclose(p);

    return true;
}


void listarChoferPorDni(){

    struct Chofer cho;
    int pos;

    cout << " INGRESE DNI DEL CHOFER: " << endl;
    cargarCadena(cho.dni,10);
    system("cls");

    cout << endl << endl << endl << endl;
    /// BUSCO QUE EXISTA EL DNI EN EL ARCHIVO Y TRAIGO LA POSICION

    pos=buscaDni(cho.dni);

    if(pos<0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ENCONTRO EL DNI " << endl;
        rlutil::setColor(rlutil::WHITE);

        cout << endl << endl;
        system("pause");
        system("cls");
        return ;
    }

    /// BUSCO EL REGISTRO QUE OCUPA ESA POSICION

    cho=buscaChofer(pos);

    if(cho.tiporegistro<0){return ;}

    if(cho.estado==false){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ENCONTRO AL CHOFER " << endl;
        rlutil::setColor(rlutil::WHITE);

        cout << endl << endl;
        system("pause");
        system("cls");

        return;
    }

    cout << " LOS DATOS DEL CHOFER QUE CORRESPONDEN AL DNI INGRESADO SON: " << endl;

    listarChofer(cho);
    cout << endl << endl;
    system("pause");
    system("cls");
}

bool eliminarChofer(){

    struct Chofer cho;
    int pos;
    string respuesta;
    bool sobreescribio;

    cout << " INGRESE DNI DEL CHOFER: " << endl;
    cargarCadena(cho.dni,10);
    system("cls");

    /// BUSCO QUE EXISTA EL DNI EN EL ARCHIVO Y TRAIGO LA POSICION

    pos=buscaDni(cho.dni);

    if(pos<0){

        rlutil::setColor(rlutil::LIGHTRED);
        cout << " NO SE ENCONTRO EL DNI " << endl;
        rlutil::setColor(rlutil::WHITE);

        return false;
    }

    /// BUSCO EL REGISTRO QUE OCUPA ESA POSICION

    cho=buscaChofer(pos);

    if(cho.tiporegistro<0){return false;}

    if(cho.estado==false){return false;}

    cout << endl << endl << endl;
    cout << " USTED QUIERE DAR DE BAJA AL SIGUIENTE REGISTRO: " ;

    listarChofer(cho);

    cout << endl << endl;

    cout << " CONFIRMA?  (S/N): " << "   ";
    cin >> respuesta;

    if(respuesta=="s"||respuesta=="S"){

      cho.estado=false;

      sobreescribio=sobreescribirArchivo(cho,pos);

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



bool verificaMenosDosCaracteres(char * cadena){

    int longitud;

    longitud=strlen(cadena);

    if(longitud<2){return false;}

    return true;
}

int cantRegistrosArchivoChoferes(){

    FILE *p;
    int bytes,cantregistros;

    p=fopen("choferes.dat","rb");

    if(p==NULL){return 0;}
    fseek(p,0,SEEK_END);
    bytes=ftell(p);

    cantregistros=bytes/sizeof(Chofer);

    fclose(p);
    return cantregistros;
}











