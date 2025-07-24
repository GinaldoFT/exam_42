#include <unistd.h>
#include <errno.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	ft_filter(char *line, char *s)
{
	int	len_s = strlen(s);
	int	i = 0, h = 0, l = 0;

	while (line[i])
	{
		h = 0;
		while (s[h] && line[i + h] == s[h])
			h++;
		if (h == len_s)
		{
			l = 0;
			while (l < len_s)
			{
				write(1, "*", 1);
				l++;
			}
			i += h;
		}
		else 
		{
			write(1, &line[i], 1);
			i++;
		}
	}
}

int	main(int ac, char *av[])
{
	char	line[999999];
	int	r = 1, f = 0;

	if (ac != 2)
		return (1);

	while (r > 0)
	{
		r = read(0, &line[f], BUFFER_SIZE);
		if (r < 0)
		{
			perror("read");
			return (1);
		}
		f += r;
	}
	ft_filter(line, av[1]);
	return (0);
}
