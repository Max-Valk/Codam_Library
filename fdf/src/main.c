/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:54:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/20 14:35:14 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

void	lk(void)
{
	system("leaks -q fdf");
}

int32_t	main(int argc, char *argv[])
{
	int32_t		fdf_file;
	t_fdf		*s_fdf;

	atexit(lk);
	if (argc == 2)
	{
		s_fdf = ft_calloc(1, sizeof(t_fdf));
		if (!s_fdf)
			error_exit(errno);
		s_fdf->line = ft_calloc(1, sizeof(t_line));
		if (!s_fdf->line)
			error_exit(errno);
		s_fdf->row = count_row(argv[1]);
		fdf_file = open(argv[1], O_RDONLY);
		if (fdf_file < 0)
			error_exit(errno);
		file_to_2d_arr(s_fdf, fdf_file);
		if (s_fdf->map == NULL)
			error_exit(errno);
		init_window(s_fdf);
		free_struct(s_fdf);
		return (0);
	}
	error_exit(EINVAL);
}
