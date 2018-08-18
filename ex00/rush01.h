/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 20:17:59 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 00:17:43 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

struct					s_sudoku_grid
{
	char	sudoku[9][9][11];
};
struct s_sudoku_grid	ft_initialize_grid(char *lines[]);
struct s_sudoku_grid	ft_copy_grid(struct s_sudoku_grid grid);
void					ft_show_grid(struct s_sudoku_grid grid);
int						ft_check_input(char *lines[]);
#endif
