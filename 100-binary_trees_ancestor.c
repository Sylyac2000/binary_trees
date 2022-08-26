#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds uncle of a node
 * @first: pointer to the node we search uncle
 * @second: pointer to the node we search uncle
 * Return: pointer to uncle node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
			   const binary_tree_t *second)
{
	binary_tree_t *uno, *segundo;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	uno = first->parent, segundo = second->parent;
	if (first == segundo || !uno || (!uno->parent && segundo))
		return (binary_trees_ancestor(first, segundo));
	else if (uno == second || !segundo || (!segundo->parent && uno))
		return (binary_trees_ancestor(uno, second));
	return (binary_trees_ancestor(uno, segundo));

}
