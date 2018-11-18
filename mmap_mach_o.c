/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_mach_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:10:02 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/11/18 16:10:04 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shared.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

extern int errno;

void execute_for_each_valid_binary(t_func exec, t_binary *array, int array_size)
{
	int			i;
	t_binary	*binary;
	
	i = 0;
	while (i < array_size)
	{
		binary = array + i;
		if (binary->content != MAP_FAILED)
			exec(*binary);
		i++;
	}
}

t_binary *create_execution_array(int number_of_elements, char **filenames)
{
	t_binary	*binary_array;
	int			error;
	int			i;
	
	binary_array = malloc(sizeof(t_binary) * number_of_elements);
	i = 0;
	while (i < number_of_elements)
	{
		error = 0;
		binary_array[i] = mmap_mach_o(filenames[i], &error);
		if (error != MMAP_MACH_O_SUCCESS)
		{
			binary_array[i].content = MAP_FAILED;
			ft_printf("%s: %s\n", filenames[i], strerror(error));
		}
		i++;
	}
	return (binary_array);
}

t_binary mmap_mach_o(char *bin_name, int *error)
{
	t_binary	bin;
	int			bin_fd;
	struct stat	bin_stat;
	int			err;
	
	bin_fd = open(bin_name, O_RDONLY);
	if (bin_fd < 0)
		*error = errno;
	err = fstat(bin_fd, &bin_stat);
	if (err < 0)
		*error = errno;
	bin.content = mmap(0, bin_stat.st_size, PROT_READ, MAP_PRIVATE, bin_fd, 0);
	if (bin.content == MAP_FAILED)
		*error = errno;
	return bin;
}
