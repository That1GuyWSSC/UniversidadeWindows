#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <time.h>

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
    struct stat sb;
    fstat(fd, &sb);
    printf("I-node number: %ld\n", (long)sb.st_ino);

    printf("Mode:  %lo (octal)\n",     (unsigned long)sb.st_mode);

    printf("Link count:               %ld\n", (long)sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
           (long)sb.st_uid, (long)sb.st_gid);

    printf("Preferred I/O block size: %ld bytes\n",
           (long)sb.st_blksize);
    printf("File size:                %lld bytes\n",
           (long long)sb.st_size);
    printf("Blocks allocated:         %lld\n",
           (long long)sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
    return 0;
}