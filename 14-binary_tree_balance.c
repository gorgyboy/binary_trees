#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance measure. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int b_left = 0;
	int b_right = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	b_left += binary_tree_balance(tree->left);
	b_right -= binary_tree_balance(tree->right);

	if (tree->left != NULL)
		b_left++;
	if (tree->right != NULL)
		b_right--;

	return (b_left + b_right);
}
