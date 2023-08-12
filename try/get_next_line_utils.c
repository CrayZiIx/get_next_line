/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:02:25 by jolecomt          #+#    #+#             */
/*   Updated: 2023/08/12 12:04:55 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*read_until_nline(char *buf, char *stock, int newline_index, int fd, char *tmp)
{
	ssize_t		buf_size;
	
	newline_index = get_newline_index(stock);
	while (newline_index == -1)
	{
		buf_size = read(fd, buf, BUFFER_SIZE);
		if (buf_size < 0)
		{
			free(buf);
			free(stock);
			stock = NULL;
			return (NULL);
		}
		if (buf_size == 0)
		{
			tmp = stock;
			stock = NULL;
			free(buf);
			return (tmp);
		}
		buf[buf_size] = '\0';
		stock = concatenate_bufer(stock, buf);
	}
	return (NULL);
}



// char	*get_next_line(int fd)
// {
// 	static char	*stock;
// 	char		*buf;
// 	char		*tmp;
// 	char		*nline;
// 	int			newline_index;

// 	if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	nline = read_until_nline(buf, stock, newline_index, fd, tmp);
// 	if (nline == NULL)
// 		return (NULL);
// 	// newline_index = get_newline_index(stock);
// 	// while (newline_index == -1)
// 	// {
// 	// 	buf_size = read(fd, buf, BUFFER_SIZE);
// 	// 	if (buf_size < 0)
// 	// 	{
// 	// 		free(buf);
// 	// 		free(stock);
// 	// 		stock = NULL;
// 	// 		return (NULL);
// 	// 	}
// 	// 	if (buf_size == 0)
// 	// 	{
// 	// 		tmp = stock;
// 	// 		stock = NULL;
// 	// 		free(buf);
// 	// 		return (tmp);
// 	// 	}
// 	// 	buf[buf_size] = '\0';
// 	// 	stock = concatenate_bufer(stock, buf);
// 	// }
// 	tmp = stock;
// 	free(buf);
// 	stock = get_stock_after_newline(stock + newline_index + 1);
// 	tmp[newline_index + 1] = '\0';
// 	return (tmp);
// }