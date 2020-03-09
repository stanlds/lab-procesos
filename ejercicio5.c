#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int wc;

    if (rc == 0)
    {
        wc = wait(NULL);
        printf("Soy el hijo, y wait retorna en el hijo %d\n", wc);
    }else{
        wc = wait(NULL);
        printf("Soy el padre, el pid del hijo es %d y wait retorna %d\n", rc, wc);
    }
    return 0;
}
