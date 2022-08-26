#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left - binary tree node insertion to left
 * @parent: pointer to binary tree structure
 * @value: node data
 * Return: pointer to new node or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;



	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	/* is parent left null or not */
	if (parent->left != NULL)
	{
		/* put current left pointer to new_node*/
		parent->left->parent = new_node;
		/*  new left connection */
		new_node->left = parent->left;
	}

	/* connect current left to current parent */
	parent->left = new_node;

	return (new_node);
}
