#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree via level-order
 * @tree: Ptr to the root node of the tree to traverse
 * @func: Ptr to a func to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);  // Assuming a maximum of 1024 nodes
	if (!queue)
		return;

	int front = 0, rear = 0;
	binary_tree_t *current;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;

		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}


/**
 * tree_level - Recursive function to execute func on nodes at a specific level
 * @tree: Pointer to the root of the tree
 * @a: Tree level
 * @func: Pointer to the function to execute
 */
void tree_level(const binary_tree_t *tree, int a, void (*func)(int))
{
	if (!tree)
		return;
	if (a == 1)
		func(tree->n);
	else if (a > 1)
	{
		tree_level(tree->left, a - 1, func);
		tree_level(tree->right, a - 1, func);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}