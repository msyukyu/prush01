/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrictor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 03:11:39 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 08:00:05 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESTRICTOR_H
# define RESTRICTOR_H

struct s_sudoku_grid	*ft_restrict_stack(struct s_sudoku_grid *grid, int l,
		int c, char ch);
struct s_sudoku_grid	*ft_check_line(struct s_sudoku_grid *grid, int l);
struct s_sudoku_grid	*ft_check_column(struct s_sudoku_grid *grid, int c);
struct s_sudoku_grid	*ft_restrict_subgrid(struct s_sudoku_grid *grid, int ll,
		int cc, char ch);
struct s_sudoku_grid	*ft_check_subgrid(struct s_sudoku_grid *grid, int l,
		int c);
#endif
