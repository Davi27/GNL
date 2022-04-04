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


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char 	*get_next_line(int fd);
char	*form_line(int fd, char *staticchar);
char	*complete_line(char *staticchar);
char	*handle_leftovers(char *staticchar);
size_t	ft_strlen(char *string);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
