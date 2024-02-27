#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);


/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree where the node will be removed
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{

	if (!root)

		return (NULL);

	if (value < root->n)

		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			bst_t *temp = root->right;

			free(root);

			return (temp);
		}
		else if (!root->right)

		{

			bst_t *temp = root->left;

			free(root);


			return (temp);
		}

		bst_t *temp = root->right;

		while (temp->left)
			temp = temp->left;

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

