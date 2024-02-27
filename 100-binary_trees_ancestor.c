#include "binary_trees.h"

/**
 * binary_trees_ancestor - Func finds the lowest common ancestor of two nodes
 * @first: Ptr to the first node
 * @second: Ptr to the second node
 *
 * Return: Ptr to the lowest common ancestor,or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *as, *af = first;

	if (!first || !second)
		return (NULL);

	/* Traverse upwards from the first/second node to the root */
	while (af)
	{
		as = second;

		while (as)
		{
			/* Check if a common ancestor is found */
			if (af == as)
				return ((binary_tree_t *)af);

			/* Move up to the parent of the second/first ancestor */
			as = as->parent;
		}

		af = af->parent;
	}

	return (NULL);
}
