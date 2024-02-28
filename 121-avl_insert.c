#include "binary_trees.h"

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree.
 * @node: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *custom_avl_insert_recursive(avl_t **node, avl_t *parent,
        avl_t **new_node, int value)
{
    int balance_factor;

    if (*node == NULL)
        return (*new_node = binary_tree_node(parent, value));

    if ((*node)->n > value)
    {
        (*node)->left = custom_avl_insert_recursive(&(*node)->left, *node, new_node, value);
        if ((*node)->left == NULL)
            return (NULL);
    }
    else if ((*node)->n < value)
    {
        (*node)->right = custom_avl_insert_recursive(&(*node)->right, *node, new_node, value);
        if ((*node)->right == NULL)
            return (NULL);
    }
    else
        return (*node);

    balance_factor = binary_tree_balance(*node);
    if (balance_factor > 1 && (*node)->left->n > value)
        *node = binary_tree_rotate_right(*node);
    else if (balance_factor < -1 && (*node)->right->n < value)
        *node = binary_tree_rotate_left(*node);
    else if (balance_factor > 1 && (*node)->left->n < value)
    {
        (*node)->left = binary_tree_rotate_left((*node)->left);
        *node = binary_tree_rotate_right(*node);
    }
    else if (balance_factor < -1 && (*node)->right->n > value)
    {
        (*node)->right = binary_tree_rotate_right((*node)->right);
        *node = binary_tree_rotate_left(*node);
    }

    return (*node);
}

/**
 * custom_avl_insert - Inserts a value into an AVL tree.
 * @root: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *custom_avl_insert(avl_t **root, int value)
{
    avl_t *new_node = NULL;

    if (root == NULL)
        return (NULL);
    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }
    custom_avl_insert_recursive(root, *root, &new_node, value);
    return (new_node);
}
#include "binary_trees.h"

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree.
 * @node: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *custom_avl_insert_recursive(avl_t **node, avl_t *parent,
        avl_t **new_node, int value)
{
    int balance_factor;

    if (*node == NULL)
        return (*new_node = binary_tree_node(parent, value));

    if ((*node)->n > value)
    {
        (*node)->left = custom_avl_insert_recursive(&(*node)->left, *node, new_node, value);
        if ((*node)->left == NULL)
            return (NULL);
    }
    else if ((*node)->n < value)
    {
        (*node)->right = custom_avl_insert_recursive(&(*node)->right, *node, new_node, value);
        if ((*node)->right == NULL)
            return (NULL);
    }
    else
        return (*node);

    balance_factor = binary_tree_balance(*node);
    if (balance_factor > 1 && (*node)->left->n > value)
        *node = binary_tree_rotate_right(*node);
    else if (balance_factor < -1 && (*node)->right->n < value)
        *node = binary_tree_rotate_left(*node);
    else if (balance_factor > 1 && (*node)->left->n < value)
    {
        (*node)->left = binary_tree_rotate_left((*node)->left);
        *node = binary_tree_rotate_right(*node);
    }
    else if (balance_factor < -1 && (*node)->right->n > value)
    {
        (*node)->right = binary_tree_rotate_right((*node)->right);
        *node = binary_tree_rotate_left(*node);
    }

    return (*node);
}

/**
 * custom_avl_insert - Inserts a value into an AVL tree.
 * @root: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *custom_avl_insert(avl_t **root, int value)
{
    avl_t *new_node = NULL;

    if (root == NULL)
        return (NULL);
    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }
    custom_avl_insert_recursive(root, *root, &new_node, value);
    return (new_node);
}
