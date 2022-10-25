/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 13:21:33 by nicky         #+#    #+#                 */
/*   Updated: 2021/12/15 18:40:13 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	loop_ft_is(int (*func)(), int i, char *str)
{
	while (func(str[i]) == 1)
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
		n++;
	return (n);
}

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	min;
	int	answer;

	min = 1;
	answer = 0;
	while (ft_isspace(str[0]))
		str++;
	if (str[0] == 45)
		min = min * -1;
	if ((str[0] == 45) || (str[0] == 43))
		str++;
	while (ft_isdigit(str[0]))
	{
		answer = answer * 10 + str[0] - '0';
		str++;
	}
	return (answer * min);
}
