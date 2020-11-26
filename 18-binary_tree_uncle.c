#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node. If node is NULL, returns NULL.
 * If node has no uncle, returns NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *ancestor;

	parent = node->parent;
	ancestor = parent->parent;

	if (node == NULL || parent == NULL || ancestor == NULL)
		return (NULL);

	if (ancestor->left == parent)
		return (ancestor->right);
	else if (ancestor->right == parent)
		return (ancestor->left);
	else
		return (NULL);
}
