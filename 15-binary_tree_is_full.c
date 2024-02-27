#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* If the tree is a leaf (no child), it is considered full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*
	 * If the tree has both children, check recursively for both subtrees.
	 * If any subtree is not full, the entire tree is not full.
	 */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If the tree has only one child, it is not full */
	return (0);
}

