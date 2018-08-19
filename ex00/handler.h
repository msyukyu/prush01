/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 03:14:49 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/19 08:25:22 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

struct					s_sudoku_grid
{
	char	sudoku[9][9][11];
};
struct s_sudoku_grid	*ft_initialize_grid(char *lines[]);
struct s_sudoku_grid	*ft_copy_grid(struct s_sudoku_grid *grid);
void					ft_show_grid(struct s_sudoku_grid *grid);
int						ft_check_input(char *lines[]);
#endif
