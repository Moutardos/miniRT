/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:43:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/03/06 22:40:38 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>

int				ft_isdigit(char c);
unsigned int	ft_strlen(const char *s);
int				ft_putstr_fd(char *s, int fd);

/* get_next_line */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 35
# endif

int				get_next_line(char **line_p, int fd);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_strchri(const char *str, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substrrange(char *buffer,
					unsigned int start_index, unsigned int end_index);

#endif