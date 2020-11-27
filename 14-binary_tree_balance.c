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

	if (tree == NULL)
		return (0);

	/**
	 * If a child exists, then the balance counter for that child is equal
	 * to the accumulated from the child's children plus one from the
	 * current child, else it would be zero, becuase there is no children.
	 */
	if (tree->left != NULL)
		b_left = binary_tree_balance(tree->left) + 1;
	if (tree->right != NULL)
		b_right = binary_tree_balance(tree->right) + 1;

	return (b_left - b_right);
}
