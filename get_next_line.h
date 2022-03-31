#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdarg.h>

char 	*get_next_line(int fd);
void	ft_realoc2(char *line, char *buff, int i_line, int *buff_size);
void	*ft_realoc(char *line, char *buff, int line_size, int *buff_size);
int		get_size(char *buff);
int		get_size_linha(char *buff);

#endif
