/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:53:02 by tbaricau          #+#    #+#             */
/*   Updated: 2025/09/12 09:53:02 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_level;
	int	right_level;

	if (root == NULL)
		return (0);
	left_level = btree_level_count(root->left);
	right_level = btree_level_count(root->right);
	if (left_level > right_level)
		return (left_level + 1);
	else
		return (right_level + 1);
}
