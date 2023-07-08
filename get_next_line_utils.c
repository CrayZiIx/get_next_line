/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:43:50 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/08 12:08:56 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *fct_strjoin(char *buf, char *stash)
{
	int i;
	int y;
	int len;

	i = 0;
	y = fct_strlen(stash);
	len = fct_strlen(buf) + fct_strlen(stash);
	while(i <= len)
	{
		stash[y] =  buf[i];
		i++;
		y++;
	}
	stash[i] = '\0';
	return (stash);
}

char	*fct_strjoin_line(char	*bufr ,char	*stash)
{
	int i;

	i = 0;
	while(stash[i] != '\n')
	{
		bufr[i] = stash[i];
		i++;
	}
	bufr[i] = '\0';
	return (bufr);
}
int	fct_strlen(char *buf)
{
	int i;

	i = 0;
	if(!buf)
		return (i);
	while (buf[i] != '\0')
		i++;
	return (i);
}

int	fct_strlen_line(char *buf)
{
	int i;

	i = 0;
	if(!buf)
		return (i);
	while (buf[i] != '\n')
		i++;
	return (i);
}

char	*fct_stash_clean(char	*stash)
{
	char	*buf;
	int	i;
	int	y;
	
	y = 0;
	i = fct_strlen_line(stash);
	buf = malloc(sizeof(char) * (-i + fct_strlen(stash)));
	while (stash[i] != '\0')
	{
		buf[y] = stash[i];
		i++;
		y++;
	}
	buf[i] = '\0';
	i = 0;
	while (buf[i] != '\0')
	{
		stash[i] = buf[i];
		i++;
	}
	while (stash[i] != '\0')
	{
		stash[i] = 'I';
		i++;
	}
	// NORMALEMENT IL RESTE JUSTE A REECRIRE LA RESTE DANS LE STATIC AU DEBUT DE CELUI-CI EST C'EST GOOD !
	free(buf);
	return (stash);	
}