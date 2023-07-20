/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:07:26 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/20 10:07:29 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	print_str(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur])
		write(1, &str[cur++], 1);
	return (cur);
}

static int	print_str_size(char *str, int size)
{
	int	cur;

	if (size == -1)
		return (print_str(str));
	cur = 0;
	while (str[cur] && cur < size)
		write(1, &str[cur++], 1);
	return (cur);
}

int	pf_printstr(char *str, t_opt opt)
{
	int	cur;
	int	len;

	cur = 0;
	if (!str)
		len = 6;
	else
		len = pf_strlen(str);
	while (cur + len < opt.min_width)
		cur += print_char(' ');
	if (!opt.dot)
		opt.precision = -1;
	if (!str)
		cur += print_str_size("(null)", opt.precision);
	else
		cur += print_str_size(str, opt.precision);
	while (cur < opt.offset)
		cur += print_char(' ');
	return (cur);
}
