/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 02:06:26 by doriol            #+#    #+#             */
/*   Updated: 2018/03/26 02:30:03 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

#include <unistd.h>

static int	getfractal(char *str)
{
	if (!ft_strcmp(str, "julia"))
		return ('j');
	if (!ft_strcmp(str, "mandelbrot"))
		return ('m');
	if (!ft_strcmp(str, "ship"))
		return ('s');
	if (!ft_strcmp(str, "bird"))
		return ('b');
	return (0);
}

int			main(int ac, char **av)
{
	t_fract		*fract;
	int			type;

	if (ac != 2 || !(type = getfractal(av[1])))
		write(1, "usage: fractol [julia/mandelbrot/bird/ship]\n", 45);
	else if ((fract = setup(type)))
	{
		system("afplay ./song.mp3 & ");
		run(fract);
	}
	return (0);
}
