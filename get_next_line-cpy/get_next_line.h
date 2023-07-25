/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:57:43 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/24 10:35:18 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_strlcpy(char *dst, const char *src, size_t n);
void	ft_strcat(char *dst, const char *src);

#endif