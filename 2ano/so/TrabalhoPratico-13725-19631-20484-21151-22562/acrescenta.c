#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int leitura, fd, fd_append;
    char content[50];
    fd = open(argv[1], O_RDONLY);
    fd_append = open(argv[2], O_RDWR | O_APPEND ,00666);
    if (fd == -1)
    {
        char* msg = "Ficheiro origem não existe \n";
        write(STDERR_FILENO, msg , strlen(msg));
        exit(1);
    }
    if (fd == -1)
    {
        char* msg = "Ficheiro origem não existe \n";
        write(STDERR_FILENO, msg , strlen(msg));
        exit(1);
    }
    int byte_count =0;
    do{
        leitura = read(fd, content, sizeof(content));
        int bytes = write(fd_append, content, leitura);
        byte_count+=bytes;
        if(bytes ==-1)
        {   
            char* msg = "Erro ao escrever ficheiro\n";
            write(STDERR_FILENO, msg , strlen(msg));
            exit(0);
        }
    }while(leitura!=0);
    
    printf("wrote %d bytes to the file: %s \n", byte_count, argv[2]);
    close(fd_append);
    return 0;
}