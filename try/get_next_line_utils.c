/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:02:25 by jolecomt          #+#    #+#             */
/*   Updated: 2023/08/07 15:57:57 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t ft_strlen(char *str)
{
        ssize_t i;
        
        i = 0;
        if (str == NULL)
                return (0);
        while (str[i] != '\0')
                i++;
        return (i);

}