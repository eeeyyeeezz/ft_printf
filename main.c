/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:36:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/04 18:39:49 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libft_printf.h"

int				main(void)
{
	printf("ORIGA PRINTF\n");
	printf("-----\n\n");

	printf(".10d 67895123 [%.10d]\n", 12345);
	printf("10d 67895123 [%10d]\n", 12345);
	printf("15.10d 12345: [%15.10d]\n", 12345);
	printf("dva [%%]: %%\n");
	printf("%%---0.3 yes\n");

	printf("\nMEIN FT_PRINTF\n");
	printf("-----\n\n");
	ft_printf("dva [%%]: %%\n");
	ft_printf("Int 50 :[%-d], Int -200: [%d], Int 2147483647 [%d], Int -2147483648 [%d]\n", 50, -200, 2147483647, -2147483648);
	printf("\n-----\n");
}
