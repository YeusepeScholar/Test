#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "empleados.h" 

int main (int argc, char **argv)
{
  int fd, pid, n, bytes, creado=0, i=0,pidRecibido;
  int flag= 0,contador=0;
  tproducto elproducto;
  
  
  mode_t fifo_mode = S_IRUSR | S_IWUSR;
  unlink(argv[1]); // por si ya existe

  if (mkfifo (argv[1], fifo_mode) == -1) {
     perror("mkfifo");
     exit(1);
  }

 
  // De esta forma se puede iniciar cualquiera de los dos procesos 
  // primero y funciona. 
   do {
    printf ("Abrio el pipe\n");     
    fd = open (argv[1], O_RDONLY);
     if (fd == -1) {
         perror("pipe");
         printf(" Se volvera a intentar despues\n");
         sleep(5);
     } else creado = 1;
  } while (creado == 0);

  //hecho en taller
  
  // read(fd,&pidRecibido,sizeof(int));
  // printf("PID del mesero: %d \n", pidRecibido);
  // printf("Info de los empleados:\n");
  do {
      n=read(fd,&elproducto,sizeof(elproducto));
      if (n == -1) {
        perror("proceso lector:");
        exit(1);
      }
      if(elproducto.cantidad> 0 )
      {
            printf("%s %d %f \n",em.nombre,em.edad,em.salario);
	    sleep(elproducto.cantidad);
      }
      }
    } while(elproducto.cantidad == -1);
  
if(flag==1){
	printf("----------------------------------------------------------\n");        
	printf("Nombre del proceso: %s \n", argv[0]);
	printf("Mi PID es: %d \n", getpid());
	printf("Fin del procesamiento\n");
	// Va a matar a la instancia del proceso con pid PidRecibido (es decir la agencia)	
	kill (pidRecibido,SIGKILL);
}
    printf ("Lei el pipe \n");
  exit(0);
}
