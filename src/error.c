/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 18:19:49 by nduijf        #+#    #+#                 */
/*   Updated: 2022/02/03 14:40:14 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_msg(int error)
{
	if (error == 1)
		write(2, "Error:\nMalloc failed\n", 21);
	else if (error == 2)
		write(2, "Error:\nMutex init failed\n", 25);
	else if (error == 3)
		write(2, "Error:\nCreating thread failed\n", 30);
	else if (error == 4)
		write(2, "Error:\nJoining thread failed\n", 29);
	else if (error == 5)
		write(2, "Error:\nMutex destroy failed\n", 28);
	else if (error == 6)
		write(2, "Error:\nInvalid number of aguments\n", 34);
	else if (error == 7)
		write(2, "Error:\nArgument less || == to zero\n", 35);
	return (error);
}
