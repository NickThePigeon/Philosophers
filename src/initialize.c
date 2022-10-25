/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 18:47:58 by nduijf        #+#    #+#                 */
/*   Updated: 2021/12/15 18:48:43 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosophers(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->persons)
	{
		info->member[i].l_fork = i;
		info->member[i].r_fork = (i + 1) % info->persons;
		info->member[i].id = i;
		info->member[i].eat = 0;
		info->member[i].died = 0;
		info->member[i].info = info;
		info->member[i].info->mutex_print = info->mutex_print;
		i++;
	}
}

int	init(t_info *info)
{
	if (info->persons == 1)
		one_philo(info);
	else
	{
		init_philosophers(info);
		if (!init_mutex(info))
			return (2);
		if (!create_thread(info))
			return (3);
		if (!join_thread(info))
			return (4);
		if (!destroy_mutex(info))
			return (5);
	}
	free(info->member);
	free(info->mutex_fork);
	return (0);
}

int	check_input_atoi(const char *str)
{
	int	i;
	int	ret;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
		else if (!ft_isdigit(str[i]))
			return (0);
		else
			i++;
	}
	ret = atoi(str);
	return (ret);
}

int	check_range_args(t_info *info)
{
	if (info->persons <= 0 || info->time_to_die <= 0 || info->time_to_eat <= 0
		|| info->time_to_sleep <= 0 || info->times_of_eating < 0)
		return (7);
	return (0);
}

int	get_args(int argc, char **argv, t_info *info)
{
	info->persons = check_input_atoi(argv[1]);
	info->time_to_die = check_input_atoi(argv[2]);
	info->time_to_eat = check_input_atoi(argv[3]);
	info->time_to_sleep = check_input_atoi(argv[4]);
	if (argc == 6)
		info->times_of_eating = check_input_atoi(argv[5]);
	else
		info->times_of_eating = 0;
	if (check_range_args(info))
		return (7);
	info->all_eat = 0;
	info->dieded = 0;
	info->member = malloc(sizeof(t_member) * info->persons);
	if (!info->member)
		return (1);
	info->mutex_fork = malloc(sizeof(pthread_mutex_t) * info->persons);
	if (!info->mutex_fork)
		return (1);
	return (0);
}
