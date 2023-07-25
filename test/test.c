#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
    char    *line;
    int fd;

    fd = open("blabla.txt", O_RDONLY);
    printf("%d\n", fd);
    line = get_next_line(fd);

    while((line != NULL))
    {    
        //printf("-----------\n");
        printf("-<try - %s>-\n", line);
        line = get_next_line(fd);
    }
    return (0);
}
