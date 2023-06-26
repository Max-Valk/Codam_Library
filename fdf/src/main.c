/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:54:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/26 17:09:30 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int32_t	main(int argc, char *argv[])
{
	int32_t		fdf_fd;
	t_fdf		*s_fdf;

	if (argc == 2)
	{
		s_fdf = ft_calloc(1, sizeof(t_fdf));
		if (!s_fdf)
			error_exit(errno);
		s_fdf->line = ft_calloc(1, sizeof(t_line));
		if (!s_fdf->line)
			error_exit(errno);
		fdf_fd = open(argv[1], O_RDONLY);
		if (fdf_fd < 0)
			error_exit(errno);
		s_fdf->row = count_row(fdf_fd);
		fdf_fd = open(argv[1], O_RDONLY);
		if (fdf_fd < 0)
			error_exit(errno);
		file_to_2d_arr(s_fdf, fdf_fd);
		set_z(s_fdf);
		init_fdf(s_fdf);
		free_struct(s_fdf);
		return (0);
	}
	return (EINVAL);
}
