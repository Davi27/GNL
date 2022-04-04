#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*statchar;
	char		*line;

	statchar = NULL;
	line = NULL;
	if ((fd < 0 || fd > 2023) || BUFFER_SIZE <= 0)
		return (0);
	statchar = form_line(fd, statchar);
	line = complete_line(statchar);
	statchar = handle_leftovers(statchar);
	return (line);
}

char	*form_line(int fd, char *statchar)
{
	char	*buffer;
	int		read_num;

	read_num = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_num != 0 && !ft_strchr(buffer, '/n'))  // Function strchr
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_num] = '\0';
		statchar = ft_strjoin(statchar, buffer); // Function join
	}
	free(buffer);
	return (statchar);
}

char	*complete_line(char *statchar)
{
	int i;

	i = 0;
	while (statchar && statchar[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	return (line);
}

char	*handle_leftovers(char *statchar)
{
	char	*str;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (statchar && statchar[i] != '\n')
		i++;
	if (statchar[i] == '\n')
	{
		i++;
		while (statchar)
		{
			str[j++] = statchar[i++];
		}
	}
	return (str);
}

// int	main(void)
// {
// 	int	i;
// 	int	fd1;

// 	fd1 = open("file1.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%s", get_next_line(fd1));
// 		i++;
// 	}
// 	return (0);
// }


char	*get_next_line(int fd)
{
	static char	*staticchar;
	char		*line;

	if ((fd < 0 || fd > 1023) || BUFFER_SIZE <= 0)
		return (0);
	staticchar = form_line(fd, staticchar);
	if (!staticchar)
		return (NULL);
	line = complete_line(staticchar);
	staticchar = handle_leftovers(staticchar);
	return (line);
}

char	*form_line(int fd, char *staticchar)
{
	char	*buffer;
	int		read_num;

	read_num = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_num != 0 && !ft_strchr(staticchar, '\n'))
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_num] = '\0';
		staticchar = ft_strjoin(staticchar, buffer);
	}
	free(buffer);
	return (staticchar);
}

char	*complete_line(char *staticchar)
{
	int		i;
	char	*line;

	i = 0;
	if (!staticchar[i])
		return (NULL);
	while (staticchar[i] && staticchar[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (staticchar[i] && staticchar[i] != '\n')
	{		
		line[i] = staticchar[i];
		i++;
	}
	if (staticchar[i] == '\n')
	{
		line[i] = staticchar[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*handle_leftovers(char *staticchar)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (staticchar[i] && staticchar[i] != '\n')
		i++;
	if (!staticchar[i])
	{
		free(staticchar);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(staticchar) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (staticchar[i])
		str[j++] = staticchar[i++];
	str[j] = '\0';
	free(staticchar);
	return (str);
}
