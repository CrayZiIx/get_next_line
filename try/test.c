#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
    char    *line;
    int fd;

    fd = open("blabla.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("%s", line);
    return (0);
}
