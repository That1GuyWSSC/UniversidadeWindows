#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int leitura, fd;
    char content[50];
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir");
        exit(1);
    }
    do{
        leitura = read(fd, content, sizeof(content));
        write(STDOUT_FILENO, content, leitura);
    }while(leitura!=0);
    
    printf("\n\n%d", leitura);
    return 0;
}