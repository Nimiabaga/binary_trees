#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	if (tree->left)
	{
		if (tree->left->n > tree->n || !binary_tree_is_heap(tree->left))
			return 0;
	}

	if (tree->right)
	{
		if (tree->right->n > tree->n || !binary_tree_is_heap(tree->right))
			return 0;
	}

	return 1;
}

