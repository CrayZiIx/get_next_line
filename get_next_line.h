/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:30:54 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/08 11:55:41 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // REMOVE FOR PUSH

char    *fct_strjoin(char *buf, char *stash);
int	fct_strlen(char *buf);
int	fct_strlen_line(char *buf);
char	*fct_strjoin_line(char  *bufr, char    *stash);
char	*fct_stash_clean(char   *stash);
int	gnl_check(char *stash);
char    *get_next_line(int fd);

#endif