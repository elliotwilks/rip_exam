#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int		min_to_remove(char *str)
{
	int		i;
	int		open;
	int		close;

	i = 0;
	open = 0;
	close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')' && open > 0)
			open--;
		else if (str[i] == ')')
			close++;
		i++;
	}
	return (open + close);
}

void	solve(int idx, int total, int removed, char *str)
{
	char	temp;

	if (idx == ft_strlen(str))
	{
		if (removed == total && min_to_remove(str) == 0)
			ft_putstr(str);
		return ;
	}

	if (str[idx] == '(' || str[idx] == ')')
	{
		temp = str[idx];
		str[idx] = ' ';
		solve(idx + 1, total, removed + 1, str);
		str[idx] = temp;
	}
	solve(idx + 1, total, removed, str);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	
	solve(0, min_to_remove(argv[1]), 0, argv[1]);
	return (0);
}