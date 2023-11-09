/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:46:08 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/10/30 10:52:56 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *string)
{
	int	counter;

	counter = 0;
	while (string && string[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*return_string;
	char	*return_string_start;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	return_string = ft_calloc(sizeof(char), lens1 + lens2 + 1);
	if (!return_string)
		return (NULL);
	return_string_start = return_string;
	while (s1 != NULL && *s1)
		*(return_string++) = *(s1++);
	while (s2 != NULL && *s2)
		*(return_string++) = *(s2++);
	*return_string = '\0';
	return (return_string_start);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;
	size_t	amount;
	size_t	index;

	amount = num * size;
	index = 0;
	array = malloc(amount);
	if (array == NULL)
		return (NULL);
	while (amount-- > 0)
		((unsigned char *)array)[index++] = 0;
	return (array);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*substring;
	char	*substring_start;
	size_t	remaining_len;

	if (ft_strlen(s) < start)
		start = ft_strlen(s);
	remaining_len = ft_strlen(s) - start;
	if (remaining_len < len)
		substring = ft_calloc(remaining_len + 1, sizeof(char));
	else
		substring = ft_calloc(len + 1, sizeof(char));
	if (substring == NULL || s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		*substring = '\0';
		return (substring);
	}
	substring_start = substring;
	while (len-- > 0 && s[start])
		*(substring++) = s[start++];
	*substring = '\0';
	return (substring_start);
}

char	*ft_strchr(const char *str, int character)
{
	while (str && *str != '\0')
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (str && *str == (char)character)
		return ((char *)str);
	return (NULL);
}
