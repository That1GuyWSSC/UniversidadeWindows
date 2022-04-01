#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char readbuffer[100];
     int fd, leitura;
    fd = open("teste.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("occorreu um erro no ficheiro");
        exit(1);
    }
    write(1,"Digite o sue texto aqui:", 24);
    leitura = read(0, readbuffer, sizeof(readbuffer));
    write(fd,readbuffer,leitura);
    close(fd);


};
