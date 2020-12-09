/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:36:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/12/09 18:57:44 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libft_printf.h"
char				*ft_itoa(int n);

int				main(void)
{
	printf("ORIGA PRINTF\n");
	printf("-----\n\n");

	#pragma region INT_ORIGINAL_PRINTF
	printf("-d    12345   [%-d]\n", 12345);
	printf("10d   12345   [%10d]\n", 12345);
	printf("10d  -12345   [%10d]\n", -12345);
	printf("-10d  12345   [%-10d]\n", 12345);
	printf("-10d -12345   [%-10d]\n", -12345);
	printf("010d  12345   [%010d]\n", 12345);
	printf("010d -12345   [%010d]\n", -12345);
	// printf(".10d -12345   [%.10d]\n", -12345);
	printf("15.10d 12345: [%15.10d]\n", 12345);
	// printf("15......10d 12345: [%15......10d]\n", 12345);	// warning		flags: ERROR!
	printf("    015.10d 12345: [%015.10d]\n", 12345);
	printf("0000015.10d 12345: [%0000015.10d]\n", 12345);
	printf("    -15.10d 12345: [%-15.10d]\n", 12345);
	printf("-----15.10d 12345: [%-----15.10d]\n", 12345);
	// printf("Int 50 0-35d :[%0-35d]\n", 50);					// warning
	printf("dva [%%]: %%\n");
	printf("%%---0.3 yes\n");
	#pragma endregion INT_ORIGINAL_PRINTF

	printf("\nMEIN FT_PRINTF\n");
	printf("-----\n\n");
	// ft_printf("dva [%%]: %%\n");
	ft_printf("Int -12345 :[%000000-10...22d]\n", -12345);
	ft_printf("Int 200 :   [%10...22d] 1234567890 \n", 200);
	printf("\n-----\n");


	// printf("check itoa %s\n", ft_itoa(0));
}
