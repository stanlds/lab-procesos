#include <stdio.h>
#include <unistd.h>

int main (void){

  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Codigo hijo
     printf("Hello \n");
    
   }
   else {
     // Codigo padre
     sleep(4);
     printf("GoodBye \n");
   }
   // Codijo ejecutado por ambos (para el caso)
   printf("Finalizando proceso %d\n", getpid());
   return 0;
}
