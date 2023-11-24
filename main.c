/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:05:34 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/21 11:02:47 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*fd;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	fd = malloc (argc);
	if (!fd)
		return (0);
	while (i < argc - 2 && argc > 2)
	{
		fd[i] = open(argv[i + 2], O_RDONLY);
		if (fd[i] == -1)
		{
			free(fd);
			return (0);
		}
		i++;
	}
	if (argc <= 2)
		fd[i++] = open("./test", O_RDONLY);
	while (j < atoi(argv[1]))
	{
		k = 0;
		while (k < i)
			printf("%s", get_next_line(fd[k++]));
		j++;
	}
	while (k >= 0)
		close(fd[k--]);
	free(fd);
	return (0);
}
