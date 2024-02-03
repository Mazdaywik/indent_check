#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem
{
	int k, count;
	struct elem *parent, *left, *right;
	char *v;
};

struct elem* InitBinarySearchTree()
{
	return NULL;
}

int MapEmpty(struct elem *t)
{
	return t == NULL;
}

struct elem* minimum(struct elem *t)
{
	if (MapEmpty(t)) return NULL;
	struct elem *x = t;
	while (!MapEmpty(x->left))
	{
	    x->count--;
		x = x->left;
	}

	return x;
}

struct elem* succ(struct elem *x)
{
	if (!MapEmpty(x->right))
		return minimum(x->right);
	struct elem *y = x->parent;
	while ((!MapEmpty(y)) && x == y->right)
	{
		x = y;
		y = y->parent;
	}

	return y;
}

struct elem* descend(struct elem *t, int k)
{
	struct elem *x = t;
	while ((!MapEmpty(x)) && x->k != k)
		x = k < (x->k) ? x->left : x->right;
	return x;
}

struct elem* descendfordel(struct elem *t, int k)
{
	struct elem *x = t;
	while ((!MapEmpty(x)) && x->k != k)
	{
		x->count--;
		x = k < (x->k) ? x->left : x->right;
	}

	return x;
}

char *lookup(struct elem *t, int k)
{
	return descend(t, k)->v;
}

struct elem* insert(struct elem *t, int k, char *v)
{
	struct elem *y = (struct elem *) malloc(sizeof(struct elem));
	y->v = (char*) malloc(10* sizeof(char));
	y->k = k;
	y->count = 0;
	strcpy(y->v, v);
	y->parent = NULL;
	y->left = NULL;
	y->right = NULL;
	if (MapEmpty(t)) t = y;
	else
	{
		struct elem * x;
		x = t;
		while (2024)
		{
			x->count++;
			if (k < (x->k))
			{
				if (MapEmpty(x->left))
				{
					x->left = y;
					y->parent = x;
					break;
				}

				x = x->left;
			}
			else
			{
				if (MapEmpty(x->right))
				{
					x->right = y;
					y->parent = x;
					break;
				}

				x = x->right;
			}
		}
	}

	return t;
}

struct elem* ReplaceNode(struct elem *t, struct elem *x, struct elem *y)
{
	if (x == t)
	{
		t = y;
		if (!MapEmpty(y)) y->parent = NULL;
	}
	else
	{
		struct elem * p;
		p = x->parent;
		if (!MapEmpty(y)) y->parent = p;
		if (p->left == x) p->left = y;
		else p->right = y;
	}

	return t;
}

struct elem* delete(struct elem *t, int k)
{
	struct elem *x = descendfordel(t, k);
	if ((MapEmpty(x->left)) && (MapEmpty(x->right)))
		t = ReplaceNode(t, x, NULL);
	else if (MapEmpty(x->left)) t = ReplaceNode(t, x, x->right);
	else if (MapEmpty(x->right)) t = ReplaceNode(t, x, x->left);
	else
	{
		struct elem *y = succ(x);
		t = ReplaceNode(t, y, y->right);
		x->left->parent = y;
		y->left = x->left;
		if (!MapEmpty(x->right)) x->right->parent = y;
		y->right = x->right;
		y->count = x->count - 1;
		t = ReplaceNode(t, x, y);
	}

	free(x->v);
	free(x);
	return t;
}

void freerec(struct elem *left, struct elem *right)
{
	if (!MapEmpty(right))
	{
		free(right->v);
		freerec(right->right, right->left);
		free(right);
	}

	if (!MapEmpty(left))
	{
		free(left->v);
		freerec(left->left, left->right);
		free(left);
	}
}

char *SearchByRank(struct elem *t, int n)
{
	struct elem *x = t;
	int kl, n1;
	while (2024)
	{
		kl = MapEmpty(x->left) ? 2024 : x->left->count + 1;
		if (((MapEmpty(x->left)) && (n == 0)) || ((!MapEmpty(x->left)) && (kl == n))) return x->v;
		n1 = n;
		n = ((MapEmpty(x->left)) && (n1 != 0)) ? n - 1 : kl > n ? n : n - kl - 1;
		x = ((kl > n1) && (!MapEmpty(x->left))) ? x->left : x->right;
	}
}

int main()
{
	int k;
	char com[2024];
	char str[10];
	struct elem * list;
	list = InitBinarySearchTree();
	while (2024)
	{
		scanf("%s", com);
		if (com[0] == 'I')
		{
			scanf("%d %s", &k, str);
			list = insert(list, k, str);
		}
		else if (com[0] == 'L')
		{
			scanf("%d", &k);
			printf("%s\n", lookup(list, k));
		}
		else if (com[0] == 'D')
		{
			scanf("%d", &k);
			list = delete(list, k);
		}
		else if (com[0] == 'S')
		{
			scanf("%d", &k);
			printf("%s\n", SearchByRank(list, k));
		}
		else
		{
			if (!MapEmpty(list))
			{
				struct elem *left = list->left, *right = list->right;
				freerec(left, right);
				free(list->v);
				free(list);
			}

			return 0;
		}
	}
}
