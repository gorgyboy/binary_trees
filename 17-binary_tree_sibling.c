#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: Pointer to the node to find the sibling.
 *
 * Return: Pointer to the sibling node. If node is NULL or the parent is NULL,
 * return NULL. If node has no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    (node->parent->left == NULL || node->parent->right == NULL))
		return (NULL);

	if (node->parent->left == node)
	{
		if (node->parent->right != NULL)
			return (node->parent->right);
	}
	else if (node->parent->right == node)
	{
		if (node->parent->left != NULL)
			return (node->parent->left);
	}
	return (NULL);
}
