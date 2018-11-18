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

t_binary mmap_mach_o(char *bin_name, int *error)
{
	t_binary 	bin;
	int 		bin_fd;
	struct stat	bin_stat;
	int 		err;
	
	bin_fd = open(bin_name, O_RDONLY);
	if (bin_fd < 0)
		*error = SYSTEM_CALL_ERROR;
	err = fstat(bin_fd, &bin_stat);
	if (err == -1)
		*error = SYSTEM_CALL_ERROR;
	if (S_ISREG(bin_stat.st_mode) == 0)
		*error = SYSTEM_CALL_ERROR;
	bin.bin_ptr = mmap(0, bin_stat.st_size, PROT_READ, MAP_PRIVATE, bin_fd, 0);
	if (bin.bin_ptr == MAP_FAILED)
		*error = SYSTEM_CALL_ERROR;
	return bin;
}
