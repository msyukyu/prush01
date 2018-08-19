/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:45:50 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 19:49:37 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "handler.h"
#include "restrictor.h"
#include "solver.h"

int						ft_check_fullness(struct s_sudoku_grid *grid)
{
	int	l;
	int	c;

	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			if (grid->sudoku[l][c][0] == '0')
				return (0);
		}
	}
	return (1);
}

void					ft_min_stack(struct s_sudoku_grid *grid, int var[])
{
	int l;
	int c;

	var[1] = 11;
	l = -1;
	while (++l < 9)
	{
		c = -1;
		while (++c < 9)
		{
			if (grid->sudoku[l][c][0] == '0')
			{
				var[0] = 1;
				while (grid->sudoku[l][c][var[0]] != '\0')
					var[0]++;
				if (var[0] < var[1])
				{
					var[1] = var[0];
					var[2] = l;
					var[3] = c;
				}
			}
		}
	}
}

struct s_sudoku_grid	*ft_place_number(struct s_sudoku_grid *grid,
		int count, int var[], int l)
{
	struct s_sudoku_grid	*safeguard;
	struct s_sudoku_grid	*newgrid;

	newgrid = ft_copy_grid(grid);
	safeguard = newgrid;
	newgrid->sudoku[var[2]][var[3]][0] = newgrid->sudoku[var[2]][var[3]][l];
	newgrid = ft_check_line(newgrid, var[2]);
	if (newgrid != (void*)0)
	{
		newgrid = ft_check_column(newgrid, var[3]);
		if (newgrid != (void*)0)
		{
			newgrid = ft_check_subgrid(newgrid, var[2], var[3]);
			if (newgrid != (void*)0)
			{
				count += ft_check_fullness(newgrid);
				if (count == 1)
					return (newgrid);
				newgrid = ft_place_min_stack(newgrid, count);
				if (newgrid == (void*)0)
					free(safeguard);
			}
		}
	}
	return (newgrid);
}

struct s_sudoku_grid	*ft_place_min_stack(struct s_sudoku_grid *grid,
		int count)
{
	int						var[4];
	int						l;
	struct s_sudoku_grid	*newgrid;

	ft_min_stack(grid, var);
	if (var[1] == 0)
		return ((void*)0);
	else
	{
		l = 0;
		while (++l < var[1])
			newgrid = ft_place_number(grid, count, var, l);
	}
	return (newgrid);
}
