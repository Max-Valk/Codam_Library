/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:54:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/09 19:13:52 by mvalk         ########   odam.nl         */
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
	u_int32_t	row_count;
	t_input_map	*mapp;

	atexit(lk);
	if (argc == 2)
	{
		row_count = count_row(argv[1]);
		fdf_file = open(argv[1], O_RDONLY);
		mapp = file_to_2d_arr(row_count, fdf_file);
		if (mapp == NULL)
			return (1);
		// printf("kot\n");
		print_input_map(mapp);
		fdf(mapp);
		free_map_struct(mapp->row_count, mapp->map);
		free (mapp);
	}
	return (0);
}