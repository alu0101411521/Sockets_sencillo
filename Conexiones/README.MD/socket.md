# Conexión entre ordenadores o procesos

En la siguiente práctica vamos a intentar generar un modelo sencillo capaz de que pueda comunicar dos procesos u ordenadores entre si mediante 
las interfaces de los sockets en un sistema operativo Linux.

## Requisitos

1. Clase Socket:
   1. Atributos:
      * Contendrá el descriptor de archivo de nuestro socket
      * Puerto de conexión
      * Dirección IP

  2. Funciones:
    * Constructor(IP, puerto): Inicializa el socket mediante una ip y puerto
    * Enviar(mensaje, socket_remoto): Envía un mensaje al socket remoto especificado
    * Recibir(mensaje, socket_conectado): Escucha su puerto e IP para recibir mensajes

# Primeros pasos

   * Inicializamos los constructores y los atributos de la clase
   *  