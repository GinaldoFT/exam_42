#include <unistd.h>
#include <stdlib.h>

void ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void ft_sort(char *str, int len)
{
	int i = 0;
	while (i < len - 1)
	{
		int j = 0;
		while (j < len - i - 1)
		{
			if (str[j] > str[j + 1])
				ft_swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

void permute(char *str, int start, int end)
{
	if (start == end)
	{
		ft_putstr(str);
		return;
	}
	int i = start;
	while (i <= end)
	{
		ft_swap(&str[start], &str[i]);
		permute(str, start + 1, end);
		ft_swap(&str[start], &str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	char *str = argv[1];
	int len = 0;
	while (str[len])
		len++;

	ft_sort(str, len);
	permute(str, 0, len - 1);
	return 0;
}

