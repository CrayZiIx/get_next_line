/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:19:12 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/15 17:34:09 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buf;// warning stack
    char    *bufr;
    int nb;
    static char *stash = NULL;
    int i = 0; // remove
    
    bufr = malloc(1);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if ( fd <= 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
        return (NULL);
    while(1)
    {
        if (stash)
            bufr = fct_addresttobufr(stash, bufr);
        nb = read(fd, buf, BUFFER_SIZE);
        buf[nb] = '\0';
        if (nb < BUFFER_SIZE )
        {
            printf("\nBUF |%s|",buf);
            printf("\nBUFR |%s|",bufr);
            printf("\nSTASH |%s|",stash);
            free(stash);
            stash = NULL;
            free(buf);
            usleep(100000);
            if (fct_strlen(bufr))
                return (bufr);
            free(bufr);
            return (NULL);
        }
        bufr = fct_addbuftobufr(buf, bufr);
        
        if ( fct_checkifline(bufr) == 1)
        {
            if (fct_checkifrest(bufr) == 1)
            {
                stash = fct_addresttostash(stash, bufr);
                bufr = fct_clearrest(bufr);
            }
            break;
        }
        // if (nb == 0)
        // {
        //     usleep(1000000);
        //     printf("|%s|", bufr);
        //     free(stash);
        //     stash = NULL;
        //     free(buf);
        //     return (NULL);
        // }
    }
    free(buf);
    return (bufr);
}


