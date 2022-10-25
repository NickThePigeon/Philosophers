/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils_two.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 18:36:12 by nduijf        #+#    #+#                 */
/*   Updated: 2021/12/15 18:42:21 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	putnbr_ull(long long nbr)
{
	if (nbr / 10 > 0)
		putnbr_ull(nbr / 10);
	ft_putchar_fd(nbr % 10 + '0', 1);
}
