/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 08:24:34 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 18:24:23 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

int						ft_check_fullness(struct s_sudoku_grid *grid);
struct s_sudoku_grid	*ft_place_min_stack(struct s_sudoku_grid *grid,
		int count);
#endif
