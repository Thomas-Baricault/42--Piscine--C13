/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:53:07 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/12 09:53:07 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	btree_call(t_btree *root, int current_level, int *data,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (root == NULL)
		return (0);
	if (current_level == data[1])
	{
		applyf(root->item, data[1], data[0]);
		data[0] = 0;
		return (1);
	}
	else
		return (btree_call(root->left, current_level + 1, data, applyf)
			| btree_call(root->right, current_level + 1, data, applyf));
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	data[2];

	if (root == NULL)
		return ;
	data[0] = 1;
	data[1] = 0;
	while (btree_call(root, 0, data, applyf))
	{
		data[0] = 1;
		data[1]++;
	}
	return ;
}
