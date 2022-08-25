#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - binary tree node creation
 * @parent: pointer to binary tree structure
 * @value: node data
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	if (parent != NULL)
		node->parent = parent;
	else
		node->parent = NULL;
	node->right = node->left = NULL;
	node->n = value;

	return (node);
}
