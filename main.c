/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:36:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/07 17:46:50 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libft_printf.h"

int				main(void)
{
	printf("ORIGA PRINTF\n");
	printf("-----\n\n");

	printf("10d 67895123 [%10d]\n", 12345);
	printf("010d 67895123 [%010d]\n", 12345);
	printf(".10d 67895123 [%.10d]\n", 12345);
	printf("15.10d 12345: [%15.10d]\n", 12345);
	// printf("15......10d 12345: [%15......10d]\n", 12345);	// warning		flags: ERROR!
	printf("    015.10d 12345: [%015.10d]\n", 12345);
	printf("0000015.10d 12345: [%0000015.10d]\n", 12345);
	printf("    -15.10d 12345: [%-15.10d]\n", 12345);
	printf("-----15.10d 12345: [%-----15.10d]\n", 12345);
	// printf("Int 50 0-35d :[%0-35d]\n", 50);		// warning
	printf("dva [%%]: %%\n");
	printf("%%---0.3 yes\n");

	printf("\nMEIN FT_PRINTF\n");
	printf("-----\n\n");
	// ft_printf("dva [%%]: %%\n");
	ft_printf("Int 50 (000000-353d) :[%000000-353d], Int -200 (55d): [%55d]\n", 50, -200);
	printf("\n-----\n");
}
