/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:05:56 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/08 12:12:16 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_check(char *stash)
{
	int i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	if (stash[i] != '\0')
		return (2);
	return (0);
}
char    *get_next_line(int fd)
{
    static char	*stash; // Dynamic Array 
    char	*buf;
    char	*bufr;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	stash = malloc(sizeof(char) * (BUFFER_SIZE * 1000));
	if (fd <= 0)
		return (NULL);
	while (1)
	{
		// printf("tqtq");
		read(fd, buf, BUFFER_SIZE);
		// printf("stash = %s\n", stash);
		stash = fct_strjoin(buf, stash);
		if (gnl_check(stash) ==  1)
		{
			bufr = malloc(sizeof(char) * (fct_strlen_line(stash) + 1));
			bufr = fct_strjoin_line(bufr, stash);
			stash = fct_stash_clean(stash);
			free(buf);
			return (bufr);
		}
		else if (gnl_check(stash) == 2)
		{
			free(buf);
			return (stash);
		}
		if (read(fd, buf, BUFFER_SIZE) <= 0) // buf avec 5 char dedans si BUFFER_SIZE 5
			return (0);
	}
}
