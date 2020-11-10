#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);

void		*ft_calloc(size_t number, size_t size);

size_t		ft_strlen(const char *str);

char		*ft_strchr(char *str, int c);

char		*ft_strrchr(const char *str, int c);

char		*ft_strdup(const char *str);

char	*ft_strjoin_to_endline_and_free(char *s1, char *s2);

#endif
