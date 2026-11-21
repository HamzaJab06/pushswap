#include "push_swap.h"

int	size_num(char *argv, int *k)
{
	int	size;

	size = 0;
	while((argv[*k] >= 9 && argv[*k] <= 13) || argv[*k] == 32)
		(*k)++;
	while(argv[*k] && !((argv[*k] >= 9 && argv[*k] <= 13) || argv[*k] == 32))
	{
		size++;
		(*k)++;
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
	//int	j;
	int k;
	int	size;

	i = 0;
	//j = 0;
	k = 0;
	while (ind < argc)
	{
		k = 0;
		while (argv[0][k])
		{
			size = size_num(*argv, &k);
			if (!size)
				break;
			list[i] = malloc((size + 1) * sizeof(char));
			copy_word(list[i++], &((*argv)[k]), size);
		}
		argv++;
		ind++;
	}
	list[i] = NULL;
}