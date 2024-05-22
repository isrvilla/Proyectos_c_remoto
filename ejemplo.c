#include <stdio.h>
#include <string.h>
struct{
char nombreFich[41]; /* Nombre del fichero */
unsigned long tamanio; /* El tamanio en bytes */
} fichas[1000];
int numeroFichas=0; /* Nzmero de fichas que ya tenemos */
int i; /* Para bucles */
int opcion; /* La opcion del menu que elija el usuario */
char textoTemporal[40]; /* Para cuando preguntemos al usuario */
unsigned long numeroTemporal;
main()
{
do {
/* Menu principal */
printf("Escoja una opcion:\n");
printf("1.- Aniadir datos de un nuevo fichero\n");
printf("2.- Mostrar los nombres de todos los ficheros\n");
printf("3.- Mostrar ficheros que sean de mas de un cierto tamanio\n");
printf("4.- Ver datos de un fichero\n");
printf("5.- Salir\n");
/* Para evitar problemas con datos mal introducidos,
leemos con "gets" y luego lo filtramos con "sscanf" */
gets (textoTemporal);
sscanf(textoTemporal, "%d", &opcion);
/* Hacemos una cosa u otra segun la opcion escogida */
switch(opcion){
case 1: /* Aniadir un dato nuevo */
if (numeroFichas < 1000) { /* Si queda hueco */
printf("Introduce el nombre del fichero: ");
gets(fichas[numeroFichas].nombreFich);
printf("Introduce el tamanio en KB: ");
gets(textoTemporal);
sscanf(textoTemporal,"%ld",&fichas[numeroFichas].tamanio);
/* Y ya tenemos una ficha mas */
numeroFichas++;
} else /* Si no hay hueco para mas fichas, avisamos */
printf("Maximo de fichas alcanzado (1000)!\n");
break;
case 2: /* Mostrar todos */
for (i=0; i<numeroFichas; i++)
printf("Nombre: %s; Tamanio: %ld Kb\n",
fichas[i].nombreFich, fichas[i].tamanio);
break;
case 3: /* Mostrar segzn el tamaqo */
printf("?A partir de que tamaqo quieres que te muestre?");
gets(textoTemporal);
sscanf(textoTemporal, "%ld", &numeroTemporal);
for (i=0; i<numeroFichas; i++)
if (fichas[i].tamanio >= numeroTemporal)
printf("Nombre: %s; Tamanio: %ld Kb\n",
fichas[i].nombreFich, fichas[i].tamanio);
break;
case 4: /* Ver todos los datos (pocos) de un fichero */
printf("?De qui fichero quieres ver todos los datos?");
gets(textoTemporal);
for (i=0; i<numeroFichas; i++)
if (strcmp(fichas[i].nombreFich, textoTemporal) == 0)
printf("Nombre: %s; Tamaqo: %ld Kb\n",
fichas[i].nombreFich, fichas[i].tamanio);
break;
case 5: /* Salir: avisamos de que salimos */
printf("Fin del programa\n");
break;
default: /* Otra opcion: no valida */
printf("Opcisn desconocida!\n");
break;
}
} while (opcion != 5); /* Si la opcion es 5, terminamos */
}
