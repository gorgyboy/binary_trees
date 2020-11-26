#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0;
	size_t h_right = 0;

	/* If tree is NULL or if it doesn't have childs */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	h_left += binary_tree_height(tree->left);
	h_right += binary_tree_height(tree->right);

	if (h_left >= h_right)
		return (++h_left);
	else
		return (++h_right);
}
