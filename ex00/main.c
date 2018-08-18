/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 20:05:53 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 00:58:13 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

int		main(int argc, char *argv[])
{
	struct s_sudoku_grid	grid;

	if (argc == 10)
	{
		if (ft_check_input(argv) == 1)
		{
			grid = ft_initialize_grid(argv);
			ft_show_grid(grid);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
