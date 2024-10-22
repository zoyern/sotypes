/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sotask_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:05 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 14:52:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sotypes/all.h>

t_sotask	*sonew_task(t_solib *solib, char *time, int (*callback)(), void *data)
{
	t_sotask	*task;

	task = somalloc(solib, sizeof(t_sotask));
	task->id = 0;
	task->time = solib_atoi(time);
	task->start = 0;
	task->work = 0;
	task->end = 0;
	task->callback = callback;
	task->data = data;
	task->next = NULL;
	return (task);
}

t_sotasks	*sotask_list(t_solib *solib)
{
	t_sotasks	*list;

	list = somalloc(solib, sizeof(t_sotasks));
	list->loop = 0;
	list->count = 0;
	list->starting = 0;
	list->current = NULL;
	list->first = NULL;
	return (list);
}

void	sotask_add(t_sotasks *list, unsigned long id, t_sotask *task)
{
	t_sotask	*current;

	if (!task || !list)
		return ;
	current = list->current;
	if (!current)
		return ((void)(task->id = id, task->start = 1 ,
			list->count++, list->current = task, list->first = task));
	while (current->next)
		current = current->next;
	task->id = id;
	list->count++;
	current->next = task;
}

