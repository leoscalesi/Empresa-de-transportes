#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED


struct Fecha{

    int dia,mes,anio;

};

struct Chofer{

    char dni[10];
    char apellido[50];
    char nombre[50];
    Fecha fechaingreso;
    char cuit[20];
    int tiporegistro;
    Fecha fechavencimientoregistro;
    char telefono[15];
    bool propietarioauto;
    bool estado;

};


struct Viaje {

    int idviaje;
    char dnichofer[10];
    int idcliente;
    Fecha fechaviaje;
    int horasalida;
    float kilometraje;
    float importe;
    char patente[10];
    int calificacion;
    bool estadoviaje;

};

struct Reporte3{

    char dni[10];
    char nombre[50];
    char apellido[50];
    int cant;

};


//// CHOFERES

void menuChoferes();

bool cargarNuevoChofer(struct Chofer *cho);

bool validaDni(char *);

bool verificaCadenaVacia(char *);

bool cuentaMasDeSeis(char *);

bool buscaLetras(char *);

bool validaNombreApellido(char *);

bool buscaDigito(char * );

bool validaFecha(int,int,int );

bool verificaFechaMenorIgualSistema(int,int,int);

void calculaFechaSistema(int *);

bool validaCuit(char *);

bool cuentaMasDeOnce(char *);

bool cuentaMasDeDiez(char *);

bool verificaFechaMayorIgualSistema(int ,int ,int );

bool validaNumeroRegistro(int);

bool validaNumeroTelefono(char *);

int tamanioArchivoChoferes();

bool guardarNuevoChoferArchivo(struct Chofer cho);

void listarChofer(struct Chofer cho);

void listarChoferes();

void cargarCadena(char *pal, int tam);

bool buscaDniRepetido(char *);

bool buscaCuitRepetido(char *);

bool modificarChofer();

int buscaDni(char *);

Chofer buscaChofer(int);

bool sobreescribirArchivo(struct Chofer cho,int);

void listarChoferPorDni();

bool eliminarChofer();

bool verificaMenosDosCaracteres(char *);

int cantRegistrosArchivoChoferes();


///// VIAJES

void menuViajes();

bool cargarNuevoViaje(struct Viaje *);

int generaIdAutomatico();

int cantRegistrosArchivoViajes();

int tamanioArchivoViajes();

bool guardarNuevoViajeArchivo(struct Viaje via);

void listarViaje(struct Viaje via);

void listarViajes();

void listarViajePorId();

int buscaIdViaje(int);

Viaje buscaViaje(int);

bool eliminarViaje();

bool sobreescribirArchivoViajes(struct Viaje via, int);

bool verificaMenosSieteCaracteres(char * cadena);

bool validaPatente(char *);


//// REPORTES

void menuReportes();

void reporte1();

void cargaVectorMayo(int *);

void listarVector(int *);

void reporte2();

void reporte3();

void cargarVectorChoferes(struct Chofer *, int);

void cargarVectorViajes(struct Viaje *, int);

void buscaIdClienteYGuardaNuevoArchivo(struct Chofer *,int,struct Viaje *,int);

void guardoRegistroNuevoArchivo(struct Reporte3);

/*void listarRegistros();

void listarRegistro(struct Reporte3);*/


//// CONFIGURACION

void menuConfiguracion();

bool Backup();

void guardoVectorChoferes(struct Chofer *,int);

void listarVector(struct Chofer *, int);

bool realizaBackupChofer(struct Chofer *,int);

bool realizaBackupViaje(struct Viaje *,int);

void listarChoferesBkp();

void listarViajesBkp();

void guardoVectorViajes(struct Viaje *,int);

bool restauraBackup();

int cantRegistrosArchivoChoferesBkp();

int cantRegistrosArchivoViajesBkp();

void guardoVectorChoferesBkp(struct Chofer *, int);

void guardoVectorViajesBkp(struct Viaje *,int);

bool restauraBackupChofer(struct Chofer *,int);

bool restauraBackupViaje(struct Viaje *,int);

bool guardarNuevoChoferArchivoIni(struct Chofer);

void listarChoferesIni();

bool guardarNuevoViajeArchivoIni(struct Viaje);



#endif // DECLARACIONES_H_INCLUDED
