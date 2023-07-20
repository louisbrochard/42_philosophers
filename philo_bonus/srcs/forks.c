/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:27:53 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/20 10:27:54 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_fork(t_phil *phil)
{
	sem_wait(phil->params->sem_forks);
	write_state("has taken a fork", phil);
}

void	release_forks_and_sleep(t_phil *phil)
{
	sem_post(phil->params->sem_forks);
	sem_post(phil->params->sem_forks);
	write_state("is sleeping", phil);
	ft_usleep(phil->params->time_to_sleep);
}
