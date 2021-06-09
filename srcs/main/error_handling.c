/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpinheir <lpinheir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:41:26 by lpinheir          #+#    #+#             */
/*   Updated: 2021/06/08 10:01:08 by lpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Receives a message, prints it, and exists with error */
void	error(char *message)
{
	printf("Error\n");
	printf(">> %s <<\n", message);
	exit(1);
}
