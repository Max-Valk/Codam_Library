/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:54:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/12 17:04:12 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// u_int32_t count_row(char *file)
// {
// 	u_int32_t count;
// 	ssize_t n_read;
// 	char check;
// 	int fd;

// 	count = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		return (perror("open"), 1);
// 	while (n_read > 0)
// 	{
// 		n_read = read(fd, &check, 1);
// 		if (n_read == -1)
// 			return (perror("read"), close(fd));
// 		if (check == '\n')
// 			count++;
// 	}
// 	close(fd);
// 	return (count - 1);
// }

void	lk()
{
	system("leaks -q fakedef");
}

int32_t	main(int argc, char *argv[])
{
	int32_t	fdf_file;
	t_point3d	start = {100, 100, 0};
	t_point3d	end = {200, 150, 0};

	// u_int32_t	row_count;
	// t_input_map	*mapp;
	t_fdf		*s_fdf;
	s_fdf = ft_calloc(1, sizeof(t_fdf));
	if (!s_fdf)
		return (1);
	atexit(lk);
	if (argc == 2)
	{
		s_fdf->row = count_row(argv[1]);
		fdf_file = open(argv[1], O_RDONLY);
		file_to_2d_arr(s_fdf, fdf_file);
		if (s_fdf->map == NULL)
			return (1);
		// printf("kot\n");
		// print_input_map(s_fdf);
		fdf(s_fdf);
		free_map_struct(s_fdf->row, s_fdf->map);
		free (s_fdf->map);
		free (s_fdf);
	}
	exit (0);
}