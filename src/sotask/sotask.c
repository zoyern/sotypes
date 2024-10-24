/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sotask.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 14:51:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	sotask_change_state(t_sotask *sotask, int start, int work, int end)
{
	if (!sotask)
		return ;
	sotask->start = start;
	sotask->work = work;
	sotask->end = end;
}

void	sotask_start(long time, t_sotasks *tasks, void *data)
{
	tasks->starting = time;
	if (tasks->current->callstart)
		tasks->current->callstart(time, tasks->current,
			tasks->current->data, data);
	sotask_change_state(tasks->current, 0, 1, 0);
}

void	sotask_work(long time, t_sotasks *tasks, void *data)
{
	if (tasks->current->callupdate)
		tasks->current->callupdate(time, tasks->current,
			tasks->current->data, data);
	if (time - tasks->starting >= tasks->current->time)
		sotask_change_state(tasks->current, 0, 0, 1);
}

int	sotask_end(long time, t_sotasks *tasks, void *data)
{
	t_sotask	*task;

	if (tasks->current->callquit)
		tasks->current->callquit(time, tasks->current,
			tasks->current->data, data);
	task = tasks->current->next;
	if (task)
	{
		tasks->current = task;
		sotask_change_state(tasks->current, 1, 0, 0);
		sotask_start(time, tasks, data);
		return (0);
	}
	tasks->loop++;
	tasks->current = tasks->first;
	sotask_change_state(tasks->current, 1, 0, 0);
	return (1);
}

int	sotask(long time, t_sotasks *tasks, void *data)
{
	if (!tasks || !tasks->current)
		return (1);
	if (tasks->current->start)
		sotask_start(time, tasks, data);
	if (tasks->current->work)
		sotask_work(time, tasks, data);
	if (tasks->current->end)
		return (sotask_end(time, tasks, data));
	return (0);
}
