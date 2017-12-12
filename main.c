/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:14:28 by yholub            #+#    #+#             */
/*   Updated: 2017/12/07 21:14:30 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	prrinterror(void)
{
	ft_putendl("error");
	exit(0);
}

char	*read_file(char *str)
{
	char	buffer;
	char	*fig;
	int		i;
	int		size;
	int		fd;

	fig = NULL;
	i = 0;
	size = 1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		prrinterror();
	while (read(fd, &buffer, 1) != 0)
	{
		fig = ft_realloc(fig, size++);
		fig[i++] = buffer;
	}
	if (fig == NULL)
	{
		prrinterror();
	}
	fig[i++] = '\0';
	return (fig);
}

void	chek_argc(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit sample_file");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	char		*file;
	t_figur		*temp;
	char		**map;
	int			i;
	int			kil_map;

	i = 0;
	chek_argc(argc);
	file = read_file(argv[1]);
	g_countfig = block_count(file);
	if (!cmp_block2(file))
		return (0);
	temp = initializ(file, g_countfig);
	normilize(temp, g_countfig);
	kil_map = ft_sqrt(4 * g_countfig);
	map = init_map(kil_map);
	while (!reurcia_f(map, (int)ft_strlen(map[0]), temp, 0))
	{
		map = clean_map(map);
		++i;
		map = init_map(kil_map + i);
	}
	print_map(map);
	map = clean_map(map);
	return (0);
}
