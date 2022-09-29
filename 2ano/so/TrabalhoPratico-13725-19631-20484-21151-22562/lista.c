#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <string.h>

#define BUF_SIZE 1024
int main(int argc, char *argv[])
{
       
       char *buf;
       DIR *dir = opendir(argv[1]);
       struct dirent *d;
       while ((d = readdir(dir)) != NULL)
       {
              char type[1];
              switch (d->d_type)
              {
              case DT_REG:
                     write(STDOUT_FILENO, "File      ", 10);
                     break;
              case DT_DIR:
                     write(STDOUT_FILENO, "Directory ", 10);
                     break;
              case DT_FIFO:
                     write(STDOUT_FILENO, "File      ", 10);
                     break;
              case DT_SOCK:
                     write(STDOUT_FILENO, "socket    ", 10);
                     break;
              case DT_LNK:
                     write(STDOUT_FILENO, "symlink   ", 10);
                     break;
              case DT_BLK:
                     write(STDOUT_FILENO, "block dev ", 10);
                     break;
              case DT_CHR:
                     write(STDOUT_FILENO, "char dev  ", 10);
                     break;
              }
              
              write(STDOUT_FILENO, " ", 1);
              write(STDOUT_FILENO, d->d_name, strlen(d->d_name));
              write(STDOUT_FILENO, "\n", 1);
       }
       closedir(dir);
       return 0;
}