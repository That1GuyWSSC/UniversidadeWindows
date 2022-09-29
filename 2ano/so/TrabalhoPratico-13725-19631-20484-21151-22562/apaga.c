#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int leitura, fd;
    char content[50];
    fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        char* msg = "Ficheiro não existe \n";
        write(STDERR_FILENO, msg , strlen(msg));
        exit(1);
    }
    close(fd);
    remove(argv[1]);
    
    return 0;
}