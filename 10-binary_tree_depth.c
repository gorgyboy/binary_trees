#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: depth of the node. If tree is NULL, return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	/* If tree or partent is NULL */
	if (tree == NULL || tree->parent == NULL)
		return (0);

	depth += binary_tree_depth(tree->parent);

	return (++depth);
}
