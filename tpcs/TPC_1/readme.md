#Informática II R2053
##Trabajo Práctico de Clase N°1

---

1.- Se tiene una serie de procesos corriendo sobre una plataforma Linux, cuyas acciones deben estar
identificadas por un número secuencial único para toda la plataforma. Cada vez que el proceso
ejecuta una acción determinada, debe marcar esa acción con este número.
Su tarea es generar los recursos y herramientas necesarias para que los procesos puedan acceder a
este número auto-incremental.

El número esta conforma por 14 dígitos hexadecimales, más 2 dígitos de verificación.
Cada vez que un proceso obtiene un número, el mismo debe ser autoincrementado de manera que el
próximo proceso obtenga el número secuencial siguiente.

Los dígitos de verificación se forman con los dos dígitos menos significativos de la suma de todos
los dígitos del número, más 0x89.

Para realizar las pruebas de funcionamiento, debe implementar procesos ficticios que consuman el
número, lo verifiquen y dejen un registro en archivo de los valores obtenidos. Es recomendable que
también analicen la secuencia del número obtenido.

---
#### Proyecto: TPC.1

#### Código con QT Creator:

1.a. - Secuenciador básico
Se utilizará como recurso secuenciador, un archivo de texto de dos líneas. La primera línea
conformada por el número secuencial auto-incremental y la segunda por los dígitos de
verificación.
Cada proceso debe acceder al archivo, obtener los datos y resguardar el archivo con el valor
incrementados y los dígitos verificadores.

> ¿Con que inconvenientes se encuentra al momento de realizar esta implementación?
Justifique

>> * Cuando se corren 2 o mas programas intentando tomar el mismo recurso al mismo tiempo. La solución mas simple realizada en la implementación fue cerrar el archivo apenas se obtienen los datos. 

>> *  Esto no significa que el conflicto se haya resuelto, sin embargo la probabilidad de que ocurra teniendo en cuenta que el tamaño del dato es muy pequeño, lo hace insignificante.

#### Proyecto: TPC.1.B

1.b. - Secuenciador en Memoria Compartida
Modificar el sistema anterior de manera que el número secuencial se almacene en memoria
compartida. Sea en formato texto o binario.
Genere además, una herramienta que permita visualizar y/o modificar desde consola el
número secuenciador.

> ¿Qué diferencias/coincidencias encuentra con el sistema anterior?

>> * Los datos persisten hasta que la memoria compartida sea destruida

> ¿Qué ocurre con el número de secuencia si se apaga el equipo? ¿Cómo lo solucionaría?

>> * Se pierde

>> * Podría almacenarlo en un archivo dentro del sistema

#### Proyecto: TPC.1.C

1.c. - Secuenciador mediante cola de mensajes
Implementar una aplicación que satisfaga la necesidad de los procesos mediante una cola de
mensajes.
Genere además, una herramienta que permita visualizar y/o modificar desde consola el
número secuenciador.

> ¿Qué opina de esta implementación y del uso de cola de mensajes para satisfacer esta
necesidad?

>> * Es mucho mas controlada aunque tiene la limitación de que solo puede existir 1 cliente escuchando la aplicación

> ¿Qué ocurre si la aplicación de cola de mensajes se cae? ¿Cómo asegura que este
siempre (o casi siempre) disponible?

>> * No hay problemas siempre y cuando se este utilizando la misma llave o identificador.

>> * Cuando el aplicativo trasmisor se cae, el receptor puede seguir escuchando hasta que vuelva a recibir algun mensaje.

---

##2.- Agregamos a la solución el uso de semáforos

#### Proyecto: TPC.2.A

2.a. - Secuenciador básico +
Modificar el punto 1.a. de manera que utilice un semáforo al momento de acceder al recurso
Número secuencial.

> ¿Con que inconvenientes se encuentra al momento de realizar esta implementación? Justifique

>> * El identificador o key, que si es el recurso mismo que se va a utilizar, debe existir en un embiente público y todos los clientes deben tener permisos para modificarlo

--- 
#### Código sin QT Creator:

#### Proyecto: TPC.2.B
2.b. - Secuenciador en Memoria Compartida +
Modificar el punto 1.b. de manera que utilice un semáforo al momento de acceder al recurso
Número secuencial.

> ¿Qué inconvenientes solucionó respecto de las versiones anteriores?

>> * No voy a encontrar problemas con múltiples clientes conectandose a un mismo servidor

> ¿Se le ocurre alguna otra opción para proveer este servicio? Descríbala.

>> * ...
