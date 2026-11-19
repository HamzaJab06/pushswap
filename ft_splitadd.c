int	size_num(char *argv, int *j)
{
	int	size;

	size = 0;
	while((argv[*j] >= 9 && argv[*j] <= 13) || argv[*j] == 32)
		(*j)++;
	while(argv[*j] && ((argv[*j] >= 9 && argv[*j] <= 13) || argv[*j] == 32))
	{
		size++;
		(*j)++;
	}
	return (size);
}

void	copy_word(char *new, char *argv, int size)
{
	new[size] = '\0';
	while (size--)
	{
		argv--;
		new[size] = *argv;
	}	
}

void	ft_splitadd(char **list, int argc, int ind, char *argv[])
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (ind < argc)
	{
		j = 0;
		while (argv[j])
		{
			size = size_num(&argv[j], &j);
			list[i] = malloc((size + 1) * sizeof(char));
			copy_word(list[i++], &argv[j], size);
		}
		argv++;
		ind++;
	}
}