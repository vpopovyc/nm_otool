/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:52:12 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/11/18 19:52:14 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void nm(t_binary binary)
{
	ft_printf("NM on valid binary: %p\n", binary.content);
}

int main(int ac, char **av)
{
	t_binary	*binary_array;
	char 		**filenames;
	int			number_of_files;
	
	if (ac == 1) {
		filenames = malloc(sizeof(void *));
		*filenames = "a.out";
		number_of_files = 1;
	} else {
		filenames = av + 1;
		number_of_files = ac - 1;
	}
	binary_array = create_execution_array(number_of_files, filenames);
	execute_for_each_valid_binary(nm, binary_array, number_of_files);
	return (0);
}
