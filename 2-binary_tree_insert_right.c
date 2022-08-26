#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_right - binary tree node insertion to right
 * @parent: pointer to binary tree structure
 * @value: node data
 * Return: pointer to new node or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;



	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	/* is parent right null or not */
	if (parent->right != NULL)
	{
		/* put current right pointer to new_node*/
		parent->right->parent = new_node;
		/*  new right connection */
		new_node->right = parent->right;
	}

	/* connect current right to current parent */
	parent->right = new_node;

	return (new_node);
}
