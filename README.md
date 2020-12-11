# Empresa-de-transportes
Proyecto de empresa de transportes usando C/C++

Este es mi segundo proyecto usando C/C++. En esta ocasion, trabaje realizando ABM de archivos, utilizando structs y asignacion dinamica de memoria.

El proyecto consta de 4 partes bien diferenciadas, a saber:

1) Un archivo en el que se registran los datos de los choferes de la empresa.
2) Un archivo en el que se registran los datos de los viajes de la empresa.
3) Un archivo para hacer el Backup de la informacion, y otro para restaurar dicho Backup.
4) La creacion de nuevos archivos en base a reportes requeridos por la empresa.

Ademas, se adjuntara un archivo excel en donde se muestran los registros que tiene precargados el sistema, de forma de poder hacr los reportes.
Obviamente el sistema permitira agregar mas registros, eliminarlos,etc.

REQUERIMIENTOS Y CONSTRUCCION DEL PROYECTO

CHOFERES

Para los choferes se debera definir un archivo con los campos que se describen a continuación:

DNI: 
Cadena de 10 caracteres

Apellido: 
Cadena de 50 caracteres

Nombre: 
Cadena de 50 caracteres

Fecha de ingreso:
Fecha

CUIT:
Cadena de 20 caracteres

Tipo de registro:
Número entero

Fecha de vencimiento del registro:
Fecha

Teléfono:
Cadena de 15 caracteres

Propietario de auto:
Bool

Estado:
Bool

RESTRICCIONES

- El DNI no debe aceptar una cadena vacía.
- El DNI debe ser un valor único. No puede repetirse en el archivo de choferes.
- El apellido no debe aceptar una cadena vacía.
- El nombre no debe aceptar una cadena vacía.
- La fecha de ingreso debe ser una fecha menor o igual a la fecha actual.
- El CUIT no debe aceptar una cadena vacía.
- EL CUIT debe ser un valor único. No puede repetirse en el archivo de choferes.
- El Tipo de registro puede ser un número entero entre 1 y 3.
- La fecha de vencimiento del registro debe ser mayor a la fecha del sistema.


MENUES

El programa debe contener un Menú Principal con las siguientes opciones:

MENÚ PRINCIPAL
--------------
1) CHOFERES
2) VIAJES
3) REPORTES
4) CONFIGURACION
----------------------
0) SALIR DEL PROGRAMA


A su vez, el submenú de choferes debe contener las siguientes opciones:

MENÚ CHOFERES
------------------
1) NUEVO CHOFER
2) MODIFICAR CHOFER
3) LISTAR CHOFER POR DNI
4) LISTAR TODOS LOS CHOFERES
5) ELIMINAR CHOFER
--------------------------------
0) VOLVER AL MENÚ PRINCIPAL


ACLARACIONES:

- La opción Nuevo Chofer deberá permitir ingresar de a un registro de Chofer nuevo por vez.
- La opción Modificar Chofer deberá solicitar el DNI de Chofer y permitir modificar la fecha
de vencimiento de la licencia.
- La opción Listar Chofer por DNI deberá solicitar el DNI de Chofer y listar todos los campos
del registro si este existe.
- La opción Listar todos los Choferes deberá listar todos los campos de todos los registros
de Chofer.
- La opción Eliminar Chofer deberá solicitar el DNI de Chofer y realizar la baja lógica.
Página


VIAJES

Para gestionar los viajes se definió un archivo con los campos que se describen a continuación:

Campo Tipo
IDViaje Número autonumérico
DNI Chofer Cadena de 10 caracteres
IDCliente Número entero
Fecha del viaje Fecha
Hora salida Número entero
Kilometraje Float
Importe Float
Patente Cadena de 10 caracteres
Calificación Número entero
Estado Bool


RESTRICCIONES

- El DNI debe existir en el archivo de Choferes.
- La Fecha del viaje debe ser una fecha anterior o igual a la fecha del sistema.
- La Hora de salida debe ser un número entre 0 y 23.
- El Kilometraje debe ser un número mayor a 0.
- El Importe debe ser un número mayor a 0.
- La Patente no puede contener una cadena vacía.
- La Calificación del viaje debe ser un número entero entre 0 y 5. Es el puntaje que el usuario
le pone al chofer.


MENUES

El submenú de Viajes debe contener las siguientes opciones:

MENÚ VIAJES
------------------
1) NUEVO VIAJE
2) LISTAR VIAJE POR IDVIAJE
3) LISTAR TODOS LOS VIAJES
4) ELIMINAR VIAJE
--------------------------------
0) VOLVER AL MENÚ PRINCIPAL


ACLARACIONES:

- La opción Nuevo Viaje deberá permitir ingresar de a un registro de Viaje nuevo por vez.
- La opción Listar Viaje por IDViaje deberá solicitar el IDViaje y listar todos los campos del
registro si éste existe.
- La opción Listar todos los Viajes deberá listar todos los campos de todos los registros de
Viajes.
- La opción Eliminar Viaje deberá solicitar el IDViaje y realizar la baja lógica.

En el menú de Reportes se colocarán tres reportes requeridos por la empresa, comentados directo sobre el codigo en el archivo reportes.cpp. Debe tener una opción
para volver al menú principal.

MENÚ

MENÚ REPORTES
------------------
1) REPORTE 1
2) REPORTE 2
3) REPORTE 3
--------------------------------
0) VOLVER AL MENÚ PRINCIPAL


CONFIGURACION

A traves de este menu se podran gestionar los Backups y la Restauracion de archivos.

El menú de Configuración debe contener las siguientes opciones.

MENÚ CONFIGURACION
------------------
1) REALIZAR BACKUP
2) RESTAURAR BACKUP
3) CARGAR DATOS DE INICIO
--------------------------------
0) VOLVER AL MENÚ PRINCIPAL


ACLARACIONES:

- La opción Realizar Backup, previa confirmación del usuario, deberá generar archivos de
copia de seguridad (con extensión bkp) de cada uno de los archivos de datos del sistema.
Los archivos de backup deberán contener los mismos registros que los archivos de datos
incluyendo los registros eliminados en baja lógica.
choferes.dat → choferes.bkp
viajes.dat → viajes.bkp

- La opción Restaurar Backup, previa confirmación del usuario, deberá restaurar los archivos
de backup sobre los archivos de datos del sistema. Este proceso eliminará todos los datos
de los archivos de datos con la información que previamente se haya respaldado en los
archivos de copia de seguridad.
choferes.bkp → choferes.dat
viajes.bkp → viajes.dat


RESTRICCION GENERAL DEL SISTEMA

En todos los casos, un registro que se encuentre en baja lógica deberá ser ignorado por el sistema.
Por ejemplo, un chofer dado de baja no puede realizar un viaje.


