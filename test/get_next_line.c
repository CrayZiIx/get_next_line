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
    
    bufr = malloc(1);
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    // if ( fd <= 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) <= 0)
    //     return (NULL);
    while(1)
    {
        if (!stash)
            fct_addresttobufr(stash, bufr);
        nb = read(fd, buf, BUFFER_SIZE);
        buf[nb] = '\0';
        bufr = fct_addbuftobufr(buf, bufr);
        if ( fct_checkifline(bufr) == 1)
        {
            if (fct_checkifrest(bufr) == 1)
                stash = fct_addresttostash(stash, bufr);
            break;
        }
        if (fct_checkifeof(bufr) == 1)
        {
            free(stash);
            stash = NULL;
            break;
        }
    }
    free(buf);
    return (bufr);
}


