/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwinky <dwinky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:59:52 by dwinky            #+#    #+#             */
/*   Updated: 2021/03/21 22:44:00 by dwinky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t number, size_t size);

int		ft_error(char **str, char *str2);

void	ft_clear_tail(char **s_tail);

size_t	ft_strlen(const char *str);

char	*ft_strchr(char *str, int c);

char	*ft_strdup(const char *str);

char	*ft_strjoin_to_new_line_and_free(char **s1, char *s2);

int		check_tail(char **line, char **s_tail, char **find_end);

int		set_line(char **array, char **s_tail, char **find_end);

int		get_next_line(int fd, char **line);

#endif
