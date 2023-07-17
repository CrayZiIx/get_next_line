/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:44:25 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/15 17:45:16 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int fct_strlen(char *buf)
{
    int i;
    
    i = 0;
    while (buf[i] != '\0'){}
    return(i - 1);
}

char    *fct_addbuftobufr(char *buf, char *bufr)
{
    char    *nbufr;
    int i;

    i = 0;
    nbufr = (char *)malloc(sizeof(char) * (fct_strlen(buf) + fct_strlen(bufr) + 1));
    while (bufr[i++] != '\0')
        nbufr[i - 1] = bufr[i - 1];
    i = 0;
    while (buf[i++] != '\0')
        nbufr[i + fct_strlen(bufr) - 1] = buf[i - 1];
    nbufr[i - 1] = '\0';
    free(bufr);
    return(nbufr);
}

char    *fct_addresttostash(char *stash, char *bufr)
{
    int i;
    int y;

    i = 0;
    y = 0;
    if (!stash)
        stash = malloc(sizeof(char) * 100000);// c'est pas bo !!
    while (bufr[i++] != '\n'){}
    while (bufr[i++] != '\0')
        stash[y++] = bufr[i - 1];
    stash[y] = '\0';
    return(stash);
}

char *fct_addresttobufr(char *stash, char *bufr)
{
    char    *nbufr;
    int i;

    i = 0;
    nbufr = (char *)malloc(sizeof(char) * (fct_strlen(stash) + fct_strlen(bufr) + 1));
    while (stash[i++] != '\0')
        nbufr[i- 1] = stash[i - 1];
    nbufr[i - 1] = '\0';
    free(bufr);
    return(nbufr);
}
int fct_checkifline(char *bufr)
{
    int i;

    i = 0;
    while(bufr[i++] != '\0')
        if(bufr[i] == '\n')
            return (1);
    return (0);
}

int fct_checkifrest(char *bufr)
{
    int i;
    int y;
    
    i = 0;
    y = 0;
    while ( bufr[i++] != '\0')
        y++;
    if (y != 0)
        return (1);
    return (0);
}
int fct_checkifeof(char *bufr)
{
    int i;

    i = 0;
    while(i++ < fct_strlen(bufr))
    {
        if (bufr[i - 1] == '\0')
            return (1);
    }
    return (0);
}