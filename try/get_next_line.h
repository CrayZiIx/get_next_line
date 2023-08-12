/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:02:32 by jolecomt          #+#    #+#             */
/*   Updated: 2023/08/12 12:02:23 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/**main functions**/
char	*get_next_line(int fd);
char	*concatenate_bufer(char *stock, char *buf);
char	*get_stock_after_newline(char *stock);
int		get_newline_index(char *stock);
/**utils functions**/
ssize_t	ft_strlen(char *str);
char	*read_until_nline(char *buf, char *stock, int *newline_index, int fd, char *tmp);
#endif