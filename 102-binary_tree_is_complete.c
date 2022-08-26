#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks to see if it's a pefect binary tree
 * @tree: binary tree
 *
 * Return: True or false
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int balance = 0;
	int fullness = 0;

	if (!tree)
		return (0);
	balance = binary_tree_balance(tree);
	fullness = binary_tree_is_full(tree);
	if (fullness && (!balance))
		return (1);
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor of
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (left - right);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root
 * Return: 0 or 1 for full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = 0;
	right_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);

	return (0);
}
