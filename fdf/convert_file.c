/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:58:46 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/10 18:13:13 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


u_int32_t count_row(char *file)
{
	u_int32_t count;
	ssize_t n_read;
	char check;
	int fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("open"), 1);
	while (n_read > 0)
	{
		n_read = read(fd, &check, 1);
		if (n_read == -1)
			return (perror("read"), close(fd));
		if (check == '\n')
			count++;
	}
	close(fd);
	return (count - 1);
}

u_int32_t	collumn_count(char **line)
{
	u_int32_t	count;

	if (!line)
		return (0);
	count = 0;
	while (line[count] != NULL && line[count][0] != '\n')
		count++;
	return (count);
}

void	error_exit(char *function, int error_num)
{
	perror(function);
	exit(error_num);
}

// t_input_map	*allocate_struct(u_int32_t rows, u_int32_t collumns)
// {
// 	t_point3d	**map;
// 	t_input_map	*input_map;

// 	map = malloc(sizeof(t_point3d) * (rows * collumns));
// 	if (map == NULL)
// 		return (NULL);
// 	input_map = malloc(sizeof(t_input_map));
// 	if (!input_map)
// 		return (NULL);
// 	input_map->map = map;
// 	input_map->row_count = rows;
// 	input_map->col_count = collumns;
// 	return (input_map);
// }

void	*free_map_struct(u_int32_t y_end, t_point3d **map)
{
	u_int32_t	i;
	// u_int32_t	j;

	i = 0;
	// j = 0;
	while (i <= y_end)
	{
		free(map[i]);
		i++;
	}
	// free(map);
	return (NULL);
}

t_point3d	**allocate_struct(u_int32_t rows, u_int32_t columns)
{
	t_point3d	**map;
	// t_input_map *input_map = malloc(sizeof(t_input_map));
	// if (!input_map)
	// 	return (NULL);
	// Allocate memory for input_map->map
	map = ft_calloc(sizeof(t_point3d *), (rows + 1));
	for (int i = 0; i < rows; i++)
		map[i] = ft_calloc(sizeof(t_point3d), (columns + 1));
	// Initialize row_count and col_count
	
	// Initialize input_map->map
	// for (int i = 0; i <= rows; i++)
	// {
	// 	for (int j = 0; j <= columns; j++)
	// 	{
	// 		input_map->map[i][j].x = 0;
	// 		input_map->map[i][j].y = 0;
	// 		input_map->map[i][j].z = 0;
	// 	}
	// }
	
	return (map);
}


t_point3d	new_3d_point(int32_t x, int32_t y, int32_t z)
{
	t_point3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	file_to_2d_arr(t_fdf *s_fdf, int fd)
{
	char	**row;
	char	*line;
	int		col_i;
	int		row_i;

	line = get_next_line(fd);
	row = ft_split(line, ' ');
	s_fdf->col = collumn_count(row);
	s_fdf->map = allocate_struct(s_fdf->row, s_fdf->col);
	row_i = 0;
	while (row_i < s_fdf->row)
	{
		col_i = 0;
		while (col_i < s_fdf->col)
		{
			// s_fdf->map[row_i][col_i] = new_3d_point(col_i * 50, row_i * 50, ft_atoi(row[col_i]) * 10);
			s_fdf->map[row_i][col_i] = new_3d_point(col_i * (WIDTH / (s_fdf->col * 2)), row_i * (HEIGHT / (s_fdf->row * 2)), (ft_atoi(row[col_i]) * 10));
			col_i++;
		}
		for (u_int32_t i = 0; i < s_fdf->col; i++)
			free (row[i]);
		free (row);
		free (line);
		line = get_next_line(fd);
		row = ft_split(line, ' ');
		row_i++;
	}
}

void print_input_map(t_fdf *input_map)
{
	ft_printf("row_count: %d\n", input_map->row);
	ft_printf("col: %d\n", input_map->col);
	ft_printf("map:\n");
	for (u_int32_t i = 0; i < input_map->row; i++){
		// printf("row: %d=", i);
		for (u_int32_t j = 0; j < input_map->col; j++){
			ft_printf("[x= %d y= %d z= %d]", input_map->map[i][j].x, input_map->map[i][j].y, input_map->map[i][j].z);
		}
		ft_printf("\n");
	}
}

// int	**char_to_int(char** arr, int rows, int cols) 
// {
// 	int** result = (int**) malloc(rows * sizeof(int*));  // allocate memory for the rows
// 	int i = 0;
// 	while (i < rows) 
// 	{
// 		result[i] = (int*) malloc(cols * sizeof(int));  // allocate memory for the columns
// 		int j = 0;
// 		while (j < cols) 
// 		{
// 			result[i][j] = atoi(arr[i][j]);  // convert each char to int using atoi
// 			j++;
// 		}
// 		i++;
// 	}
// 	print_int_array(result);
// 	return (result);
// }


/*
int	**make_map(int fdf_file)
{
	char	*line;
	char	**split_line = NULL;
	int		**int_map;
	int		i;

	int_map = ft_calloc(sizeof(int **), 100);
	line = get_next_line(fdf_file);
	split_line = ft_split(line, ' ');
	while (line != NULL)
	{
		i = 0;
		while (*split_line)
		{
			if (check_num(*split_line))
				int_map = ft_atoi(*split_line);
			else
				error_exit("invalid character in input", 1);
			i++;
			split_line++;
		}
		free(line);
		free(split_line);
		line = get_next_line(fdf_file);
		split_line = ft_split(line, ' ');
		int_map++;
	}
	print_int_array(&int_map[0]);
	return (int_map);
}




// t_point3d	*init_landscape(int fdf_file)
// {
// 	t_point3d	*landscape;

	
	
// }*/