#include "binary_trees.h"

/**
 * balance_avl - Measures balance factor of an AVL tree
 * @avl_node: AVL tree node to check
 * Return: Balanced factor
 */
void balance_avl(avl_t **avl_node)
{
	int balance_factor;

	if (avl_node == NULL || *avl_node == NULL)
		return;

	if ((*avl_node)->left == NULL && (*avl_node)->right == NULL)
		return;

	balance_avl(&(*avl_node)->left);
	balance_avl(&(*avl_node)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*avl_node);

	if (balance_factor > 1)
		*avl_node = binary_tree_rotate_right((binary_tree_t *)*avl_node);
	else if (balance_factor < -1)
		*avl_node = binary_tree_rotate_left((binary_tree_t *)*avl_node);
}

/**
 * get_successor - Get the next successor, i.e., the min node in the right subtree
 * @node: Tree node to check
 * Return: The min value of this tree
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = get_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_node_type - Remove a node depending on its children type
 * @bst_root: Node to remove
 * Return: 0 if it has no children, or other value if it has
 */
int remove_node_type(bst_t *bst_root)
{
	int new_value = 0;

	if (!bst_root->left && !bst_root->right)
	{
		if (bst_root->parent->right == bst_root)
			bst_root->parent->right = NULL;
		else
			bst_root->parent->left = NULL;

		free(bst_root);
		return (0);
	}
	else if ((!bst_root->left && bst_root->right) || (!bst_root->right && bst_root->left))
	{
		if (!bst_root->left)
		{
			if (bst_root->parent->right == bst_root)
				bst_root->parent->right = bst_root->right;
			else
				bst_root->parent->left = bst_root->right;

			bst_root->right->parent = bst_root->parent;
		}

		if (!bst_root->right)
		{
			if (bst_root->parent->right == bst_root)
				bst_root->parent->right = bst_root->left;
			else
				bst_root->parent->left = bst_root->left;

			bst_root->left->parent = bst_root->parent;
		}

		free(bst_root);
		return (0);
	}
	else
	{
		new_value = get_successor(bst_root->right);
		bst_root->n = new_value;
		return (new_value);
	}
}

/**
 * remove_bst_node - Remove a node from a Binary Search Tree (BST)
 * @bst_root: Pointer to the root node of the BST
 * @value: Value to remove in the BST
 * Return: Pointer to the new root node
 */
bst_t *remove_bst_node(bst_t *bst_root, int value)
{
	int node_type = 0;

	if (!bst_root)
		return (NULL);

	if (value < bst_root->n)
		remove_bst_node(bst_root->left, value);
	else if (value > bst_root->n)
		remove_bst_node(bst_root->right, value);
	else if (value == bst_root->n)
	{
		node_type = remove_node_type(bst_root);
		if (node_type != 0)
			remove_bst_node(bst_root->right, node_type);
	}
	else
		return (NULL);

	return (bst_root);
}

/**
 * remove_avl_node - Remove a node from an AVL tree
 * @avl_root: Pointer to the root node of the AVL tree
 * @value: Value to remove in the AVL tree
 * Return: Pointer to the new root node
 */
avl_t *remove_avl_node(avl_t *avl_root, int value)
{
	avl_t *avl_root_a = (avl_t *)remove_bst_node((bst_t *)avl_root, value);

	if (avl_root_a == NULL)
		return (NULL);

	balance_avl(&avl_root_a);
	return (avl_root_a);
}
