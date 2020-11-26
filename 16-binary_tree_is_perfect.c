#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, size_t depth, size_t level);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is perfect, otherwise 0. If tree is NULL, returns 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth = binary_tree_height(tree);

	if (tree == NULL)
		return (0);

	return (is_perfect(tree, depth, 0));
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	for (height = 0; tree != NULL; height++)
		tree = tree->left;

	return (height);
}

/**
 * is_perfect - checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * @depth: Depth of the tree.
 * @level: Node current depth level.
 *
 * Return: 1 if tree is perfect, otherwise 0.
 */
int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	/*
	 * If both children are NULL, we got to the last node in the branch.
	 * Check if current depth level is the same as @depth.
	 */
	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level + 1)
			return (1);
		else
			return (0);
	}

	/* If either child is NULL, return 0 because tree is not perfect. */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/*
	 * If both children's subtrees are perfect, return 1, otherwise
	 * return 0.
	 */
	if (is_perfect(tree->left, depth, level + 1) &&
	    is_perfect(tree->right, depth, level + 1))
		return (1);
	else
		return (0);
}
