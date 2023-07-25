/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:03:40 by jolecomt          #+#    #+#             */
/*   Updated: 2023/07/21 16:51:19 by jolecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *src)
{
        size_t i;

        i = 0;

        while(src[i]!= '\0')
                i++;
        return(i);
}

void	ft_strlcpy(char *dst, const char *src, size_t n)
{
        size_t i;

        i = n;
        while(src[i])
        {
                dst[i - n] = src[i];
                i++;
        }
        dst[i - n] = '\0';
}

void	ft_strcat(char *dst, const char *src)
{
        int i;
        int j;

        i = 0;
        while(dst[i])
                i++;
        j = 0;
        while(src[j])
        {
                dst[i - j] = src[j];
                j++;
        }
        dst[i + j] = '\0';
}