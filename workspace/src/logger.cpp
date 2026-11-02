#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char **argv) {
    int fd;
    char buffer[1024];
    int leidos;

    // borrar FIFO por si existiera previamente
    unlink("/tmp/FIFO_LOGGER");

    /* crear el FIFO */
    if (mkfifo("/tmp/FIFO_LOGGER",0666)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    fd = open("/tmp/FIFO_LOGGER", O_RDONLY);
    if (fd<0) {
        perror("No puede abrirse el FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while ((leidos = read(fd, buffer, sizeof(buffer)-1)) > 0) {
	printf("%s", buffer);
        fflush(stdout);
    }
    close(fd);
    unlink("/tmp/FIFO_LOGGER");
    return(0);
}


