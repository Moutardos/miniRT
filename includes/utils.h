/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:43:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/01 10:44:44 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_quadratic_roots
{
	int	nb;
	union
	{
		double	*none;
		double	single[1];
		double	distincts[2];
	};
}	t_quadratic_roots;

double				get_min_positive_root(t_quadratic_roots *roots);
t_quadratic_roots	solve_quadratic_equation(double a, double b, double c);

bool				are_doubles_equals(double x, double y);
double				ft_dabs(double a);
double				ft_dmin(double a, double b);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
int					ft_isdigit(char c);
unsigned int		ft_strlen(const char *s);
int					ft_putstr_fd(char *s, int fd);
bool				is_same_first_word(const char *s1, const char *s2);
int					ft_strcmp(const char *str1, const char *str2);

/* get_next_line */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 35
# endif

int					get_next_line(char **line_p, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_strchri(const char *str, char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_substrrange(char *buffer,
						unsigned int start_index, unsigned int end_index);

#endif