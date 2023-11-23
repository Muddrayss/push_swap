#include "push_swap.h"

typedef struct s_operations
{
	int rx;
	int rrx;
} t_operations;

typedef struct s_total_operations
{
	int ra;
	int rra;
	int rb;
	int rrb;
} t_total_operations;

static int count_rx(t_list **stack, int num)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = *stack;
	while (tmp && tmp->next && tmp->value != num)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static int count_rrx(t_list **stack, int num)
{
	int count;
	t_list *tmp;

	count = 0;
	tmp = *stack;
	while (tmp && tmp->next && tmp->value != num)
	{
		tmp = tmp->next;
	}
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static int count_rr(int *ra_count, int *rb_count)
{
	int count;

	count = 0;
	while (*ra_count > 0 && *rb_count > 0)
	{
		count++;
		(*ra_count)--;
		(*rb_count)--;
	}
	return (count);
}

static int count_rrr(int *rra_count, int *rrb_count)
{
	int count;

	count = 0;
	while (*rra_count > 0 && *rrb_count > 0)
	{
		count++;
		(*rra_count)--;
		(*rrb_count)--;
	}
	return (count);
}

static int find_min(t_list **stack)
{
	t_list *tmp;
	int min;

	tmp = *stack;
	min = tmp->value;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value < min)
			min = tmp->value;
	}
	return (min);
}

static t_operations count_stack_operations(t_list **stack, int num)
{
	t_operations operations;

	operations.rx = count_rx(stack, num);
	operations.rrx = count_rrx(stack, num);

	return (operations);
}

static int find_best_num(t_list **stack, int num)
{
	int best_num;
	int best_sum;
	int i;
	t_list *tmp;

	best_num = 0;
	best_sum = 0;
	i = ft_lstsize(*stack);
	tmp = *stack;
	while (i > 0)
	{
		if ((best_sum == 0 && (num - tmp->value) > 0) || (num - tmp->value > 0 && (num - tmp->value) < best_sum))
		{
			best_sum = (num - tmp->value);
			best_num = tmp->value;
		}
		tmp = tmp->next;
		i--;
	}
	return (best_num);
}

static int sum_operations(t_operations ops_a, t_operations ops_b)
{
	int sum;

	sum = 0;
	if (ops_b.rx <= ops_b.rrx)
	{
		if (ops_a.rx <= ops_a.rrx)
			sum = count_rr(&ops_a.rx, &ops_b.rx) + ops_a.rx + ops_b.rx;
		else
			sum = ops_b.rx + ops_a.rrx;
	}
	else
	{
		if (ops_a.rx <= ops_a.rrx)
			sum = ops_b.rrx + ops_a.rx;
		else
			sum = count_rrr(&ops_a.rrx, &ops_b.rrx) + ops_a.rrx + ops_b.rrx;
	}
	return (sum);
}

static t_total_operations get_total_operations(t_operations ops_a, t_operations ops_b)
{
	t_total_operations total_operations;

	if (ops_b.rx <= ops_b.rrx)
	{
		if (ops_a.rx <= ops_a.rrx)
		{
			total_operations.ra = ops_a.rx;
			total_operations.rb = ops_b.rx;
			total_operations.rra = 0;
			total_operations.rrb = 0;
		}
		else
		{
			total_operations.ra = 0;
			total_operations.rb = ops_b.rx;
			total_operations.rra = ops_a.rrx;
			total_operations.rrb = 0;
		}
	}
	else
	{
		if (ops_a.rx <= ops_a.rrx)
		{
			total_operations.ra = ops_a.rx;
			total_operations.rb = 0;
			total_operations.rra = 0;
			total_operations.rrb = ops_b.rrx;
		}
		else
		{
			total_operations.ra = 0;
			total_operations.rb = 0;
			total_operations.rra = ops_a.rrx;
			total_operations.rrb = ops_b.rrx;
		}
	}
	return (total_operations);
}

static int count_operations(t_list **stack_a, t_list **stack_b, int num)
{
	t_operations operations_a;
	t_operations operations_b;

	operations_a = count_stack_operations(stack_a, num);
	operations_a.rrx += 1;
	if (num < find_min(stack_b))
	{
		operations_b = count_stack_operations(stack_b, find_min(stack_b));
		operations_b.rx += 1;
	}
	else
	{
		operations_b = count_stack_operations(stack_b, find_best_num(stack_b, num));
		operations_b.rrx += 1;
	}
	return (sum_operations(operations_a, operations_b) + 1);
}

static void perform_operations(t_list **stack_a, t_list **stack_b, int num)
{
	t_total_operations total_operations;
	t_operations operations_a;
	t_operations operations_b;
	int is_min;

	is_min = 0;
	operations_a = count_stack_operations(stack_a, num);
	operations_a.rrx += 1;
	// printf("\nnum: %d\n", num);
	// printf("Initial stack_b:\n");
	// printList(*stack_b);
	if (num < find_min(stack_b))
	{
		// printf("min: %d\n", find_min(stack_b));
		operations_b = count_stack_operations(stack_b, find_min(stack_b));
		operations_b.rx += 1;
		is_min = 1;
	}
	else
	{
		// printf("best_num: %d\n", find_best_num(stack_b, num));
		operations_b = count_stack_operations(stack_b, find_best_num(stack_b, num));
		operations_b.rrx += 1;
	}
	// printList(*stack_b);
	// printf("operations_a: %d %d\n", operations_a.rx, operations_a.rrx);
	// printf("operations_b: %d %d\n", operations_b.rx, operations_b.rrx);
	total_operations = get_total_operations(operations_a, operations_b);
	// printf("total_operations: %d %d %d %d\n", total_operations.ra, total_operations.rb, total_operations.rra, total_operations.rrb);
	while (total_operations.ra > 0 && total_operations.rb > 0)
	{
		perform_operation("rr", stack_a, stack_b);
		total_operations.ra--;
		total_operations.rb--;
	}
	while (total_operations.rra > 0 && total_operations.rrb > 0)
	{
		perform_operation("rrr", stack_a, stack_b);
		total_operations.rra--;
		total_operations.rrb--;
	}
	while (total_operations.ra > 0)
	{
		perform_operation("ra", stack_a, stack_b);
		total_operations.ra--;
	}
	while (total_operations.rb > 0)
	{
		perform_operation("rb", stack_a, stack_b);
		total_operations.rb--;
	}
	while (total_operations.rra > 0)
	{
		perform_operation("rra", stack_a, stack_b);
		total_operations.rra--;
	}
	while (total_operations.rrb > 0)
	{
		perform_operation("rrb", stack_a, stack_b);
		total_operations.rrb--;
	}
	// printf("Ending stack_b:\n");
	// printList(*stack_b);
	perform_operation("pb", stack_a, stack_b);
	if (is_min)
		perform_operation("rb", stack_a, stack_b);
}

void sort_lists(t_list **stack_a, t_list **stack_b)
{
	int i;
	int j;
	int min_operations;
	int min_num;
	int curr_operations;
	t_list *tmp;

	i = ft_lstsize(*stack_a);
	perform_operation("pb", stack_a, stack_b);
	perform_operation("pb", stack_a, stack_b);
	while (i > 0)
	{
		min_operations = 0;
		min_num = 0;
		tmp = *stack_a;
		j = i;
		while (j > 0 && tmp)
		{
			curr_operations = count_operations(stack_a, stack_b, tmp->value);
			if (min_operations == 0 || curr_operations < min_operations)
			{
				min_operations = curr_operations;
				min_num = tmp->value;
			}
			tmp = tmp->next;
			j--;
		}
		perform_operations(stack_a, stack_b, min_num);
		i = ft_lstsize(*stack_a);
	}
}