#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0){
        printf("falló el fork\n");
    }else if (rc == 0){
        printf("proceso del hijo %d\n", (int)getpid());
        close(STDOUT_FILENO);
        printf("se cerró la salida\n");
    }else{
        printf("proceso del padre %d\n", (int)getpid());
    }
    return 0;
}
