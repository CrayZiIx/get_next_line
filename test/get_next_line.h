/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:19:25 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/15 17:17:56 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // REMOVE FOR PUSH


char    *get_next_line(int fd);
char    *fct_addbuftobufr(char *buf, char *bufr); // l(SRC) -> r(DEST)
char    *fct_addresttostash(char *stash, char *bufr);
char *fct_addresttobufr(char *stash, char *bufr);
int fct_strlen(char *buf);
int fct_checkifline(char *bufr);
int fct_checkifrest(char *bufr);
int fct_checkifeof(char *bufr);


#endif