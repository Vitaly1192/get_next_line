/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwinky <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:59:52 by dwinky            #+#    #+#             */
/*   Updated: 2020/11/12 21:59:53 by dwinky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
int			get_next_line(int fd, char **line);

void		*ft_calloc(size_t number, size_t size);

size_t		ft_strlen(const char *str);

char		*ft_strchr(char *str, int c);

char		*ft_strrchr(const char *str, int c);

char		*ft_strdup(const char *str);

char		*ft_strjoin_to_endline_and_free(char **s1, char *s2);

#endif
