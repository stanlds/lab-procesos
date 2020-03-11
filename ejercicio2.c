
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    fd[0] = open("file.txt", O_RDWR);

    if (fd[0] == -1)
    {
        
        printf("Error Number\n");
    }

    for (int i=0; i<=100; i++)
    {
        if (fork() == 0)
        {
            printf("Empezando proceso hijo %d\n", getpid());
            write(fd[0], "Escribiendo desde el hijo\n", strlen("Escribiendo desde el hijo\n"));
        }
        else
        {

            printf("Empezando proceso padre %d\n", getpid());

            write(fd[0], "Escribiendo desde el padre\n", strlen("Escribiendo desde el padre\n"));
        }

        close(fd[0]);
    }
    return 0;
}
