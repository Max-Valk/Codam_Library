/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 15:28:36 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/08 14:44:09 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <MLX42.h>
#include <math.h>

static mlx_image_t *image;

int32_t	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}



void	ft_place_block(void *param)
{
	uint32_t color = ft_pixel(200, 100, 200, 255);
	for (size_t i = 0; i < image->width; i++)
	{
		for (size_t y = 0; y < image->height; y++)
		{
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void	ft_draw_line(int x0, int y0, int x1, int y1)
{
	
}
void	ft_hook(void *param)
{
	mlx_t *mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, const char *argv[])
{
	mlx_t	*mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "Hello World!", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 5, 200)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_place_block, mlx);
	image->instances[0].x += 500;
	image->instances[0].y += 500;
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}