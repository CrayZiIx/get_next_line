/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:02:30 by jolecomt          #+#    #+#             */
/*   Updated: 2023/08/12 12:09:54 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	*stock;
// 	char		*buf;
// 	char		*tmp;
// 	int			newline_index;
// 	ssize_t		buf_size;

// 	if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	newline_index = get_newline_index(stock);
// 	while (newline_index == -1)
// 	{
// 		buf_size = read(fd, buf, BUFFER_SIZE);
// 		if (buf_size < 0)
// 		{
// 			free(buf);
// 			free(stock);
// 			stock = NULL;
// 			return (NULL);
// 		}
// 		if (buf_size == 0)
// 		{
// 			tmp = stock;
// 			stock = NULL;
// 			free(buf);
// 			return (tmp);
// 		}
// 		buf[buf_size] = '\0';
// 		stock = concatenate_bufer(stock, buf);
// 	}
// 	tmp = stock;
// 	free(buf);
// 	stock = get_stock_after_newline(stock + newline_index + 1);
// 	tmp[newline_index + 1] = '\0';
// 	return (tmp);
// }
char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buf;
	char		*tmp;
	int			newline_index;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newline_index = -1;
	tmp = NULL;
	stock = read_until_nline(buf, stock, &newline_index, fd, tmp);
	if ( stock == NULL)
		return (NULL);
	tmp = stock;
	stock = get_stock_after_newline(stock + newline_index + 1);
	tmp[newline_index + 1] = '\0';
	//printf("%s\n", tmp);
	return (tmp);
}

char    *concatenate_bufer(char *stock, char *buf)
{
	char    *ret;
	int i;
	int y;


	ret = malloc(sizeof(char) * (ft_strlen(stock) + ft_strlen(buf) + 1));
	i = 0;
	if (stock != NULL)
	{
		while (stock[i])
		{
			ret[i] = stock[i];
			i++;
		}
	}
	y = 0;
	while (buf[y])
	{
		ret[i + y] = buf[y];
		y++;
	}
	ret[i + y] = '\0';
	free(stock);
	return (ret);
}

int     get_newline_index(char *stock)
{
	int i;

	i = 0;
	if (stock == NULL)
		return (-1);
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *get_stock_after_newline(char *stock)
{
	char *ret;
	size_t  len;
	int i;

	i = 0;
	len = ft_strlen(stock);
	if (len == 0)
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	while (stock[i] != '\0')
	{
		ret[i] = stock[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}