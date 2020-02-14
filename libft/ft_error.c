/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:06:22 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/14 19:06:37 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void *p, void (*f)(void *), char *msg)
{
	msg ? write(2, "ERROR: ", 7) : 0;
	msg ? write(2, msg, ft_strlen(msg)) : 0;
	if (f && p)
		f(p);
	exit(EXIT_FAILURE);
}
