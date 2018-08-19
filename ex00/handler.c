/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 03:09:16 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 18:21:44 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "handler.h"

struct s_sudoku_grid	*ft_initialize_grid(char *lines[])
{
	int						l;
	int						c;
	int						d;
	struct s_sudoku_grid	*grid;

	grid = malloc(sizeof(struct s_sudoku_grid) + 9 * 9 * 11);
	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			if (lines[l + 1][c] <= '9' && lines[l + 1][c] >= '1')
				grid->sudoku[l][c][0] = lines[l + 1][c];
			else
			{
				d = -1;
				while (++d < 10)
					grid->sudoku[l][c][d] = d + '0';
				grid->sudoku[l][c][d] = '\0';
			}
		}
	}
	return (grid);
}

struct s_sudoku_grid	*ft_copy_grid(struct s_sudoku_grid *grid)
{
	int						l;
	int						c;
	int						d;
	struct s_sudoku_grid	*newgrid;

	newgrid = malloc(sizeof(struct s_sudoku_grid) + 9 * 9 * 11);
	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			d = 0;
			if (grid->sudoku[l][c][0] == '0')
			{
				while (grid->sudoku[l][c][d] != '\0' && d++ < 10)
					newgrid->sudoku[l][c][d - 1] = grid->sudoku[l][c][d - 1];
				newgrid->sudoku[l][c][d] = '\0';
			}
			else
				newgrid->sudoku[l][c][0] = grid->sudoku[l][c][0];
		}
	}
	return (newgrid);
}

void					ft_show_grid(struct s_sudoku_grid *grid)
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
			write(1, &(grid->sudoku[l][c][0]), 1);
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
