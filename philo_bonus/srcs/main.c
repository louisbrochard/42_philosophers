/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:28:03 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/20 15:26:01 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	free_all(t_phil *philos, t_params *params, int exit_code)
{
	free(philos);
	sem_close(params->sem_forks);
	sem_close(params->sem_console);
	sem_close(params->finished);
	return (exit_code);
}

int	check_nb(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		ft_printf("Usage : ./philo number_philos time_die ");
		ft_printf("time_eat time_sleep [number_eat]\n");
		return (0);
	}
	while (i != argc)
	{
		if (!check_nb(argv[i]))
		{
			printf("Syntax Error in argv[%d].", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_phil		*philos;
	int			return_code;

	return_code = EXIT_SUCCESS;
	if (!check_arg(argc, argv))
		return (EXIT_FAILURE);
	if (!init_params(&params, argc, argv))
		return (EXIT_FAILURE);
	if (!create_philos(&philos, &params))
		return (EXIT_FAILURE);
	if (!create_process(&philos, &params))
		return_code = stop_process(&philos, &params);
	if (!wait_process(&philos, &params))
		return (free_all(philos, &params, EXIT_FAILURE));
	return (free_all(philos, &params, return_code));
}
