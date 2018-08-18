/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 09:11:18 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/18 10:28:31 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct					s_sudoku_grid
{
	char	sudoku[11][11][11];
};

struct s_sudoku_grid	ft_initialize_grid(void)
{
	int						l;
	int						c;
	int						d;
	struct s_sudoku_grid	grid;

	l = -1;
	while (++l < 10)
	{
		c = -1;
		while (++c < 10)
		{
			d = -1;
			while (++d < 10)
				grid.sudoku[l][c][d] = d + '0';
			grid.sudoku[l][c][d] = '\0';
		}
		grid.sudoku[l][c] = NULL;
	}
	grid.sudoku[l] = NULL;
	return (grid);
}

struct s_sudoku_grid	ft_copy_grid(struct s_sudoku_grid grid)
{
	int						l;
	int						c;
	int						d;
	struct s_sudoku_grid	newgrid;

	l = -1;
	while (++l < 10)
	{
		c = -1;
		while (++c < 10)
		{
			d = -1;
			while (++d < 10)
				newgrid.sudoku[l][c][d] = grid.sudoku[l][c][d];
			newgrid.sudoku[l][c][d] = '\0';
		}
		newgrid.sudoku[l][c] = NULL;
	}
	newgrid.sudoku[l] = NULL;
	return (newgrid);
}

void					ft_show_grid(struct s_sudoku_grid grid)
{
	int						l;
	int						c;
	int						d;

	l = -1;
	while (++l < 10)
	{
		c = -1;
		while (++c < 10)
		{
			d = -1;
			while (++d < 10)
			{
				if (d > 0)
					write(1, " ", 1);
				write(1, &(grid.sudoku[l][c][d]), 1);
				if (d < 9)
					write(1, " ", 1);
			}
			write(1, "\n", 1);
		}
	}
}
