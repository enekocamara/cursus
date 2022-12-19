/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:33:43 by ecamara           #+#    #+#             */
/*   Updated: 2022/09/13 10:45:15 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	int const IthinkImRight = 1;
	Karen	Me = Karen();

	while (IthinkImRight)
	{
		Me.complain("DEBUG");
		Me.complain("INFO");
		Me.complain("WARING");
		Me.complain("ERROR");
	}
	return (0);
}