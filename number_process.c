/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btekinli <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:46:06 by btekinli          #+#    #+#             */
/*   Updated: 2022/08/16 22:46:06 by btekinli         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_numprocess(t_data *p, int ac, char **av)
{
	int	i;
	int	j;
	int	nm_start;

	ft_init(p);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		nm_start = 0;
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			nm_start = j;
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			while (av[i][j] && av[i][j] != ' ')
				j++;
			ft_putnumber(p, &av[i][nm_start]);
			while (av[i][j] && av[i][j] == ' ')
				j++;
		}
	}
}

void	ft_putnumber(t_data *p, char *str)
{
	int	number;

	number = ft_atoi(str);
	if (ft_check_samenum(p->arr_a, number,
			p->total_size - p->a_size, p->total_size) == 1)
		ft_error("Error");
	ft_array_push(p->arr_a, (p->total_size - 1) - p->a_size++, number);
}
