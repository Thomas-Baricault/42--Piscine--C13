/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:53:00 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/12 09:53:00 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	int	diff;

	if (root == NULL)
		return (NULL);
	diff = (*cmpf)(data_ref, root->item);
	if (diff < 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	if (diff > 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	return (root->item);
}
