/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrictor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 03:11:49 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 15:10:44 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"

struct s_sudoku_grid	*ft_restrict_stack(struct s_sudoku_grid *grid, int l,
		int c, char ch)
{
	int p;
	int	d;

	p = 0;
	d = 0;
	while (grid->sudoku[l][c][p] != '\0')
	{
		if (d == 0 && grid->sudoku[l][c][p] == ch)
			d++;
		if (d == 1)
			grid->sudoku[l][c][p] = grid->sudoku[l][c][p + d];
		p++;
	}
	return (grid);
}

struct s_sudoku_grid	*ft_check_line(struct s_sudoku_grid *grid, int l)
{
	int	c;
	int	sub_c;

	c = -1;
	while (++c < 9)
	{
		if (grid->sudoku[l][c][0] != '0')
		{
			sub_c = -1;
			while (++sub_c < 9)
			{
				if (grid->sudoku[l][sub_c][0] == '0')
					grid = ft_restrict_stack(grid, l, sub_c,
							grid->sudoku[l][c][0]);
				else if (sub_c != c &&
						grid->sudoku[l][c][0] == grid->sudoku[l][sub_c][0])
					return ((void*)0);
			}
		}
	}
	return (grid);
}

struct s_sudoku_grid	*ft_check_column(struct s_sudoku_grid *grid, int c)
{
	int l;
	int sub_l;

	l = -1;
	while (++l < 9)
	{
		if (grid->sudoku[l][c][0] != '0')
		{
			sub_l = -1;
			while (++sub_l < 9)
			{
				if (grid->sudoku[sub_l][c][0] == '0')
					grid = ft_restrict_stack(grid, sub_l, c,
							grid->sudoku[l][c][0]);
				else if (sub_l != l &&
						grid->sudoku[l][c][0] == grid->sudoku[sub_l][c][0])
					return ((void*)0);
			}
		}
	}
	return (grid);
}

struct s_sudoku_grid	*ft_restrict_subgrid(struct s_sudoku_grid *grid, int l,
		int c)
{
	int sub_l;
	int sub_c;
	int ll;
	int cc;

	ll = (l / 3) * 3;
	cc = (c / 3) * 3;
	sub_l = ll - 1;
	while (++sub_l < ll + 3)
	{
		sub_c = cc - 1;
		while (++sub_c < cc + 3)
		{
			if (grid->sudoku[sub_l][sub_c][0] == '0')
				grid = ft_restrict_stack(grid, sub_l, sub_c,
						grid->sudoku[l][c][0]);
			else if (l != sub_l && c != sub_c &&
					grid->sudoku[l][c][0] == grid->sudoku[sub_l][sub_c][0])
				return ((void*)0);
		}
	}
	return (grid);
}

struct s_sudoku_grid	*ft_check_subgrid(struct s_sudoku_grid *grid, int l,
		int c)
{
	int cc;
	int ll;

	ll = (l / 3) * 3;
	cc = (c / 3) * 3;
	l = ll - 1;
	while (++l < ll + 3)
	{
		c = cc - 1;
		while (++c < cc + 3)
		{
			if (grid->sudoku[l][c][0] != '0')
			{
				grid = ft_restrict_subgrid(grid, l, c);
				if (grid == (void*)0)
					return (grid);
			}
		}
	}
	return (grid);
}
