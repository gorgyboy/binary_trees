#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree. A NULL pointer
 * is not a leaf.
 * @tree: Pointer to the root node of the tree to count the number of leaves.
 *
 * Return: Number of leaves. If tree is NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (++leaves);
	else
		return (leaves);
}
