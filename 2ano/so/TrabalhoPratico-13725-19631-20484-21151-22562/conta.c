#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int leitura, fd;
    char content[1];
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        char* msg = "Ficheiro não existe \n";
        write(STDERR_FILENO, msg , strlen(msg));
        exit(1);
    }
    int lines = 1;
    do{
        leitura = read(fd, content, sizeof(content));
        if(content[0]=='\n')
        {
            lines+=1;
        }
    }while(leitura!=0);
    
    printf("Este ficheiro tem %d linhas", lines);
    return 0;
}