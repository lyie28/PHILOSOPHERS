/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:32:15 by lyie              #+#    #+#             */
/*   Updated: 2021/10/28 16:39:55 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_freelist(t_node *head)
{
	t_node	*go;
	t_node	*temp;

	go = head;
	while (go != NULL)
	{
		temp = go;
		go = go->next;
		free(temp);
	}
	return (-1);
}

void	ft_lstadd_back(t_list *start, t_node *node)
{
	t_node	*current;

	if (start->head == NULL)
	{
		start->head = node;
		return ;
	}
	current = start->head;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	return ;
}

t_node	*ft_newnode(void)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!(new))
		return (NULL);
	new->next = NULL;
	return (new);
}
