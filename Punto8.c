#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("Pipe error while creation\n");
        exit(EXIT_FAILURE);
    }
    int pid_c1 = fork();
    if(pid_c1 < 0) {
        perror("Fork error while creation\n");
        exit(EXIT_FAILURE);
    } else if (pid_c1 == 0) { //Hijo 1
        char *message = "Carta de amor a Henry, leeme\n";
        close(pipefd[0]); // Cerrando lectura sin usar
        printf("El proceso %d escribe: %s\n", (int) getpid(), message);
        write(pipefd[1], message, (strlen(message) + 1));
    } else { // Padre
        int pid_c2 = fork();
        if(pid_c2 < 0) {
            perror("Fork error while creation\n");
            exit(EXIT_FAILURE);
        } else if (pid_c2 == 0) { // Hijo 2
            close(pipefd[1]); // Cerrando escritura sin usar
            read(pipefd[0], buffer, sizeof(buffer));
            printf("El proceso %d recibió: %s\n", (int) getpid(), buffer);
        } else { // Padre
            printf("Yo solo superviso a los niños \n");
        }
    }

    return 0;
}
