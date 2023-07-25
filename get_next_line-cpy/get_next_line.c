/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:57:07 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/25 15:29:45 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd)
{
	char	*line;
	int		size;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	size = read(fd, line, BUFFER_SIZE);
	if (size <= 0)
	{
		free(line);
		return (NULL);
	}
	line[size] = '\0';
	return (line);
}

static int	is_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	write_line(char *content, char *prev_content)
{
	ft_strlcpy(prev_content, content, is_newline(content) + 1);
	content[is_newline(content) + 1] = '\0';
}

static int	get_line(int fd, char *content, char *prev_content)
{
        char	*newline;

	while (is_newline(content) == -1)
	{
		newline = read_line(fd);
		if (newline != NULL)
		{
			ft_strcat(content, newline);
			free(newline);
		}
		else
			break ;
	}
	if (!*content)
	{
		free(content);
		return (0);
	}
	else if (is_newline(content) >= 0)
		write_line(content, prev_content);
	else
		prev_content[0] = '\0';
	return (1);
}
char    *get_next_line(int fd)
{
        char    *content;
        static char *prev_content = NULL;

        if (fd < 0)
                return (NULL);
        if (prev_content == NULL) // INIT
        {
                prev_content = malloc(214748364);
                prev_content[0] = '\0';
        }
        content =  malloc(214748364);
        content[0] = '\0';
        if (ft_strlen(prev_content) > 0)
		ft_strlcpy(content, prev_content, 0);
        if (!get_line(fd, content, prev_content))
	{
		if (prev_content)
		{
			free(prev_content);
			prev_content = NULL;
		}
		return (NULL);
	}
        return (content);
}