#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "empleados.h"

//Funcion modificada en el taller
void EnviarPipe(prod *miproducto, int cuantos, char pipe[]) {

  int i, creado, fd, mipid;
   do{
   fd = open(pipe, O_WRONLY);
   
    if (fd == -1) {
    perror("pipe");
    sleep(1);
    }
}while (fd==-1);
   
   //Obtiene el pid y se lo manda a central por el pipe	
   
   /*
   mipid= getpid();
   write(fd, &mipid, sizeof(int));
   */
   
  

    //printf ("%d \n",i);
	
    // Usar un write para escribir en el pipe
	
    sleep(2);
    printf("Escribi el producto #%d \n",i);
  

    
    close (fd);
  
}

/* asignar
   inserta un nuevo producto en la estructura de producto
*/
void asignar(prod *unproducto, char *nombre )
{
  unproducto.cantidad = lacantidad;
  strcpy(unproducto.nombre, nombre);
}

/* imprimir
   imprime los primeros cuantos productos del arreglo
*/
void  imprimir(losproductos *)
{
  int i;

    printf("Productos:\n");

       printf("%s %d \n",  losproductos[i].nombre, losproductos[i].cantidad);
}


int main(int argc, char *argv[]) 
{
  tproducto mipedido[MAX];
  char line[MAXLIN], alimento[MAXNOMBRE];
  FILE *fp;
  int i, cantidadp=0;

  
  fp = fopen(argv[1], "r");
  i = 0;

  while (!feof(fp))  {
    fscanf(fp, "%s %d \n", alimento,&cantidad );
    /* printf("valid: %s\n", line); */
    /* printf("%s, %d \n", alimento, cantidad ); */
    asignar(mipedido, alimento, cantidad, i++);
	
	  // Enviar por el pipe
  EnviarPipe(mipedido,i,argv[2]);
  
  // Ver cuando parar
  }


  fclose(fp); 
}
