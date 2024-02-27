#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Function that checks if a binary tree is a valid AVL
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_diff, left_avl, right_avl;

	if (!tree)
		return (0);

	height_diff = abs((int)binary_tree_height(tree->left) - (int)binary_tree_height(tree->right));

	if (height_diff > 1)
		return (0);

	left_avl = binary_tree_is_avl(tree->left);
	right_avl = binary_tree_is_avl(tree->right);

	return (left_avl && right_avl);
}

