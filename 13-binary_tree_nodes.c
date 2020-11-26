#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary
 * tree. A NULL pointer is not a node.
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 *
 * Return: Number of nodes with at least 1 child. If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	/* If tree is NULL or it doesn't have any child */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		return (++nodes);
	else
		return (nodes);
}
