/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:19:52 by muteza            #+#    #+#             */
/*   Updated: 2023/06/20 16:16:24 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	wich_text_width(t_data *data)
{
	if (data->hit == 3)
		return (data->door.text_open.widht);
	else if (data->hit == 2)
		return (data->door.text_close.widht);
	else if (data->side)
	{
		if (data->step_y < 0)
			return (data->text.sud.widht);
		else
			return (data->text.west.widht);
	}
	else
	{
		if (data->step_x > 0)
			return (data->text.est.widht);
		else
			return (data->text.nord.widht);
	}
}

int	wich_text_height(t_data *data)
{
	if (data->hit == 3)
		return (data->door.text_open.height);
	else if (data->hit == 2)
		return (data->door.text_close.height);
	else if (data->side)
	{
		if (data->step_y < 0)
			return (data->text.sud.height);
		else
			return (data->text.west.height);
	}
	else
	{
		if (data->step_x > 0)
			return (data->text.est.height);
		else
			return (data->text.nord.height);
	}
}
