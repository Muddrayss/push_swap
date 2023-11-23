#include "push_swap.h"

static int check_duplicates(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// static int check_duplicates(int argc, char **argv)
// {
// 	int i;
// 	int *arr;

// 	i = 0;
// 	arr = (int *)ft_calloc(argc, sizeof(int));
// 	while (i < argc)
// 	{
// 		if (arr[ft_atoi(argv[i])] == 1)
// 		{
// 			free(arr);
// 			return (1);
// 		}
// 		arr[ft_atoi(argv[i])] = 1;
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }

static t_list *process(int argc, char **argv)
{
	t_list *a;
	t_list *new;
	int i;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&a, new);
		i++;
	}

	return (a);
}

t_list *create_stack(int argc, char **argv)
{
	if (check_duplicates(argc, argv))
		return (NULL);
	if (argc == 2)
		return (process(argc, ft_split(argv[1], ' ')));
	else
		return (process(argc, argv));
}