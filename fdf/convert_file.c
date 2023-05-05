/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 14:58:46 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/05 15:01:05 by mvalk         ########   odam.nl         */
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
	while (line[count] != NULL)
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

void	*free_map_struct(u_int32_t end, t_point3d **map)
{
	u_int32_t	i;

	i = 0;
	while (i < end)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

t_input_map	*allocate_struct(u_int32_t rows, u_int32_t columns)
{
	t_point3d	**map;
	t_input_map	*input_map;

	map = malloc(sizeof(t_point3d *) * rows);
	if (map == NULL)
		return (NULL);
	for (u_int32_t i = 0; i < rows; i++)
	{
		map[i] = malloc(sizeof(t_point3d) * columns);
		if (map[i] == NULL)
		{
			return (free_map_struct(i, map));
			// for (u_int32_t j = 0; j < i; j++)
			// 	free(map[j]);
			// free(map);
			// return (NULL);
		}
	}
	input_map = malloc(sizeof(t_input_map));
	if (!input_map)
	{
		return (free_map_struct(rows, map));
		// for (u_int32_t i = 0; i < rows; i++)
		// 	free(map[i]);
		// free(map);
		// return (NULL);
	}
	input_map->map = map;
	input_map->row_count = rows;
	input_map->col_count = columns;
	return (input_map);
}

t_point3d	*new_3d_point(int32_t x, int32_t y, int32_t z)
{
	t_point3d	*point;

	point = malloc(sizeof(t_point3d));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_input_map	*file_to_2d_arr(u_int32_t row_count, int fd)
{
	t_input_map	*input_map;
	t_point3d	*point;
	char	**row;
	char	*line;
	int		col_i;
	int		row_i;

	line = get_next_line(fd);
	row = ft_split(line, ' ');
	input_map = allocate_struct(row_count, collumn_count(row));
	row_i = 0;
	while (row_i < row_count)
	{
		col_i = 0;
		while (col_i < input_map->col_count)
		{
			point = new_3d_point(col_i, row_i, ft_atoi(row[col_i]));
			if (!point)
				return (NULL);
			input_map->map[row_i][col_i] = *point;
			col_i++;
		}
		free (row);
		free (line);
		line = get_next_line(fd);
		row = ft_split(line, ' ');
		row_i++;
	}
	return (input_map);
}

void print_input_map(t_input_map *input_map)
{
    printf("row_count: %d\n", input_map->row_count);
    printf("col_count: %d\n", input_map->col_count);
    printf("map:\n");
	for (u_int32_t i = 0; i < input_map->row_count; i++){
		printf("row: %d=", i);
		for (u_int32_t j = 0; j < input_map->col_count; j++){
			printf("[x= %d y= %d z= %d]", input_map->map[i][j].x, input_map->map[i][j].y, input_map->map[i][j].z);
		}
        printf("\n");
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