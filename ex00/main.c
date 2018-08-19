/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 03:08:58 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 04:52:16 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "handler.h"
#include "restrictor.h"

void					show_grid_n_stack(struct s_sudoku_grid *grid)
{
	int	l;
	int	c;
	int	p;

	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			p = 0;
			while (++p < 10)
			{
				if (p > 1)
					write(1, " ", 1);
				if (grid->sudoku[l][c][0] != '0' || 
						grid->sudoku[l][c][p] == '\0')
					write(1, ".", 1);
				else
					write(1, &(grid->sudoku[l][c][p]), 1);
			}
		}
		write(1, "\n", 1);
	}
}

int						main(int argc, char *argv[])
{
	struct s_sudoku_grid	grid;
	int l;
	int c;

	if (argc == 10)
	{
		if (ft_check_input(argv) == 1)
		{
			grid = ft_initialize_grid(argv);
			l = -1;
			while (++l < 9)
				grid = *ft_check_line(&grid, l);
			show_grid_n_stack(&grid);
			c = -1;
			while (++c < 9)
				grid = *ft_check_column(&grid, c);
			l = -1;
			show_grid_n_stack(&grid);
			while (++l < 3)
			{
				c = -1;
				while (++c < 3)
				{
					grid = *ft_check_subgrid(&grid, 3 * l, 3 * c);
				}
			}
			ft_show_grid(grid);
			show_grid_n_stack(&grid);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
