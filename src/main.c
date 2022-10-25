/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/06 13:40:18 by nicky         #+#    #+#                 */
/*   Updated: 2022/02/03 19:21:03 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	if (argc == 5 || argc == 6)
	{
		ret = get_args(argc, argv, &info);
		if (ret)
			return (error_msg(ret));
		ret = init(&info);
		if (ret)
			return (error_msg(ret));
	}
	else
		return (error_msg(6));
	return (0);
}
