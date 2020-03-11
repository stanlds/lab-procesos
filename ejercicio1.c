#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int texto;
    char *c;
    int fd = open("archivo.txt", O_WRONLY | O_CREAT | O_TRUNC, 644);
    int f = fork();

    if (f == 0){
        char a[] = "Soy el hijo\n\0";
        texto = write(fd, a, strlen(a));
        c = "Fin hijo\n\0";
    }else{
        char b[] = "Soy el padre\n\0";
        texto = write(fd, b, strlen(b));
        c = "Fin padre\n\0";
    }
    
    texto = write(fd, c, strlen(c));
    printf("Finalizando proceso. (File descriptor %d)\n", fd);

    return 0;
}
