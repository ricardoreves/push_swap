/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/18 17:12:32 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sig;

	nbr = 0;
	sig = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		sig = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			nbr = (nbr * 10) + (*str - 48);
		}
		else
			return (nbr * sig);
		str++;
	}
	return (nbr * sig);
}

void printStack(t_list *stackA, t_list *stackB)
{
	int i;

	i = 1;
	while  (stackA != NULL || stackB != NULL)
	{
		printf("%i		", i);
		if (stackA != NULL)
			printf("%s		", stackA->content);
		else
			printf("		");
		if (stackB != NULL)
			printf("%s\n", stackB->content);
		else
			printf("\n");
		if (stackA != NULL)
			stackA = stackA->next;
		if (stackB != NULL)
			stackB = stackB->next;
		i++;
	}
}

int	check_order(t_list *stack, char c)
{
	int checked;

	if (c == 'i')
	{
		while (stack->next && stack->nbr < stack->next->nbr);
			stack = stack->next;
		if (stack->next = NULL)
			return (0);
		else
			return (1);
	}
	if (c == 'd')
	{
		while (stack->next && stack->nbr > stack->next->nbr);
			stack = stack->next;
		if (stack->next = NULL)
			return (0);
		else
			return (1);
	}
	return (1);
}

void	swap_or_not(t_list **stackA, t_list **stackB)
{
			if ((*stackA*)->nbr > (*stackA)->next->nbr && (*stackB)->nbr < (*stackB)->next->nbr)
			{
				swap(stackA);
				swap(stackB);
				write(1, "ss\n",3);
			}
			else if ((*stackA)->nbr > (*stackA)->next->nbr)
			{
				swap(stackA);
				write(1, "sa\n",3);
			}
			else if ((*stackB)->nbr < (*stackB)->next->nbr)
			{
				swap(stackB);
				write(1, "sb\n",3);
			}
}
int main(int argc, char **argv)
{
	int		i;
	t_list	*stackA;
	t_list	*stackB;

	stackB = NULL;
	i = 1;
	stackA = fill_list(argc, argv);
	if (!stackA)
	{
		printf("il y a eu une erreur de remplissage de la stack :-(");
		return (0);
	}
	printf("la stack s'est bien remplie\n\n");
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	while (check_order(stackA, 'i') && stackB)
	{
		while (check_order(stackA, 'i') && check_order(stackB, 'd'))
		{
			while
		
	
	}
	while (stackA->next)
	{
		stackA->content = NULL;
		stackA->nbr = NULL;
		free (stackA);
		stackA = stackA->next;
	}	
	return (0);
}

/* test des fonctions de manipulation
 *	printf("test de swap\n\n");
	swap(&stackA);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test de push\n\n");
	push(&stackA, &stackB);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test reverse rotate\n\n");
	rev_rotate(&stackA);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test de rotate\n\n");
	rotate(&stackA);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);*/
