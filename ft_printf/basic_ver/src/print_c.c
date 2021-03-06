/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:18:50 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 11:30:41 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_header.h"

int		print_c(va_list ap, t_format *format)
{
	char	val;
	int		width;

	width = format->width;
	val = va_arg(ap, int);
	if (format->hypen == 1)
	{
		write(1, &val, 1);
		while (width-- > 1)
			write(1, &format->padc, 1);
	}
	else
	{
		while (width-- > 1)
			write(1, &format->padc, 1);
		write(1, &val, 1);
	}
	format->tot = format->width > 1 ? format->width : 1;
	return (0);
}
