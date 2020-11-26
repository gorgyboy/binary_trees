#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full, otherwise 0. If tree is NULL, returns 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int f_left;
	int f_right;

	if (tree == NULL)
		return (0);

	f_left = binary_tree_is_full(tree->left);
	f_right = binary_tree_is_full(tree->right);

	/*
	 * We return 0 when we get to the last node because it is NULL.
	 * So when both childs are NULL, the modulo by 2 is 0, so we return 1.
	 * At the next upper level we get 1 if both childs are NULL, the after
	 * adding them up, modulo is 0 againg, so we return 1. If we have only
	 * one child then at the upper level we recieve a
	 * 1 (child w or w/o children) and a 0 (child with only 1 children) and
	 * then modulo is 1. This is carrierd over in the recussion so that at
	 * the root node level we know if both subtrees are full or not.
	 */
	if ((f_left + f_right) % 2 == 0)
		return (1);
	else
		return (0);
}
