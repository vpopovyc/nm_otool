/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:15:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/11/18 14:15:17 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHARED_H
# define __SHARED_H

/*
** To make life harder
*/
# include <libft.h>
/*
** Indicates, that binary mapped successfully
*/
# define MMAP_MACH_O_SUCCESS 0
/*
** For error handling errno used
 */
# include <errno.h>

typedef struct  s_binary
{
	void 		*content;
}               t_binary;

t_binary mmap_mach_o(char *bin_name, int *error);

t_binary *create_execution_array(int number_of_elements, char **filenames);

typedef void	(*t_func)(t_binary);

void execute_for_each_valid_binary(t_func exec, t_binary *array, int array_size);

#endif

