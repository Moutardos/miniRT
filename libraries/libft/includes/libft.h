/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:48:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/04/20 14:14:28 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>

# define EPSILON 0.00001

bool				are_doubles_equals(double x, double y);
double				ft_dabs(double a);
double				ft_dmin(double a, double b);
double				ft_dmax(double a, double b);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
int					ft_isdigit(char c);
bool				ft_iswhitespace(char c);
unsigned int		ft_strlen(const char *s);
int					ft_putstr_fd(char *s, int fd);
bool				is_same_first_word(const char *s1, const char *s2);
int					ft_strcmp(const char *str1, const char *str2);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_strchri(const char *str, char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_substrrange(char *buffer,
						unsigned int start_index, unsigned int end_index);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 35
# endif

int					get_next_line(char **line_p, int fd);

#endif
