/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 09:11:18 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 01:08:58 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

struct s_sudoku_grid	ft_initialize_grid(char *lines[])
{
	int						l;
	int						c;
	int						d;
	struct s_sudoku_grid	grid;

	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			if (lines[l + 1][c] <= '9' && lines[l + 1][c] >= '1')
				grid.sudoku[l][c][0] = lines[l + 1][c];
			else
			{
				d = -1;
				while (++d < 10)
					grid.sudoku[l][c][d] = d + '0';
				grid.sudoku[l][c][d] = '\0';
			}
		}
	}
	return (grid);
}

struct s_sudoku_grid	ft_copy_grid(struct s_sudoku_grid grid)
{
	int						l;
	int						c;
	int						d;
	struct s_sudoku_grid	newgrid;

	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			d = -1;
			while (++d < 10)
				newgrid.sudoku[l][c][d] = grid.sudoku[l][c][d];
			newgrid.sudoku[l][c][d] = '\0';
		}
	}
	return (newgrid);
}

void					ft_show_grid(struct s_sudoku_grid grid)
{
	int						l;
	int						c;

	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			if (c > 0)
				write(1, " ", 1);
			write(1, &(grid.sudoku[l][c][0]), 1);
			if (c < 9)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int						ft_check_input(char *lines[])
{
	int	l;
	int	c;
	int count;

	l = 0;
	while (++l < 10)
	{
		c = 0;
		count = 0;
		while (lines[l][c] != '\0')
		{
			if (!(lines[l][c] == '.' || (lines[l][c] > '0' &&
							lines[l][c] <= '9')))
				return (0);
			c++;
		}
		if (c != 9)
			return (0);
	}
	return (1);
}

int						main(int argc, char *argv[])
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
