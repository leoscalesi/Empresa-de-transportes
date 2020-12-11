# Empresa-de-transportes
Proyecto de empresa de transportes usando C/C++

Este es mi segundo proyecto usando C/C++. En esta ocasion, trabaje realizando ABM de archivos, utilizando structs y asignacion dinamica de memoria.

El proyecto consta de 4 partes bien diferenciadas, a saber:

1) Un archivo en el que se registran los datos de los choferes de la empresa.
2) Un archivo en el que se registran los datos de los viajes de la empresa.
3) Un archivo para hacer el Backup de la informacion, y otro para restaurar dicho Backup.
4) La creacion de nuevos archivos en base a reportes requeridos por la empresa.


REQUERIMIENTOS Y CONSTRUCCION DEL PROYECTO

Para los choferes se debera definir un archivo con los campos que se describen a continuación:

Campo Tipo
DNI Cadena de 10 caracteres
Apellido Cadena de 50 caracteres
Nombre Cadena de 50 caracteres
Fecha de ingreso Fecha
CUIT Cadena de 20 caracteres
Tipo de registro Número entero
Fecha de vencimiento del registro Fecha
Teléfono Cadena de 15 caracteres
Propietario de auto Bool
Estado Bool

Restricciones

- El DNI no debe aceptar una cadena vacía.
- El DNI debe ser un valor único. No puede repetirse en el archivo de choferes.
- El apellido no debe aceptar una cadena vacía.
- El nombre no debe aceptar una cadena vacía.
- La fecha de ingreso debe ser una fecha menor o igual a la fecha actual.
- El CUIT no debe aceptar una cadena vacía.
- EL CUIT debe ser un valor único. No puede repetirse en el archivo de choferes.
- El Tipo de registro puede ser un número entero entre 1 y 3.
- La fecha de vencimiento del registro debe ser mayor a la fecha del sistema.


Menúes

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


Aclaraciones:
- La opción Nuevo Chofer deberá permitir ingresar de a un registro de Chofer nuevo por vez.
- La opción Modificar Chofer deberá solicitar el DNI de Chofer y permitir modificar la fecha
de vencimiento de la licencia.
- La opción Listar Chofer por DNI deberá solicitar el DNI de Chofer y listar todos los campos
del registro si este existe.
- La opción Listar todos los Choferes deberá listar todos los campos de todos los registros
de Chofer.
- La opción Eliminar Chofer deberá solicitar el DNI de Chofer y realizar la baja lógica.
Página
