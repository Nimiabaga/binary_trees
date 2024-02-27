#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full, 1. Otherwise, 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Base case: an empty tree is full by definition */
	if (tree == NULL)
		return (1);

	/* If the current node has one child, the tree is not full */
	if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL))
		return (0);

	/* Recursively check the subtrees */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

