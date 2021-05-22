#include "head.h"
Tree setTree() {
	Tree T;
	char ch;
	cin >> ch;
	if (ch == '#') {
			T = NULL;
	}
	else {
			T = new Node;
			T->a = ch;
			T->left = setTree();
			T->right = setTree();
	}
	return T;
}

int minDepth(Tree root) {
	if (root == NULL) {
		return 0;
	}
	queue<Tree> q;
	//vector<Tree> visited;
	q.push(root);
	//visited.push_back(root);
	
	int depth = 1;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Tree cur = q.front();
			q.pop();
			if (cur->left == NULL && cur->right == NULL) {
				return depth;
			}
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
		}
		depth++;
	}

	return depth;
}

int maxDepth(Tree root) {
	if (root == NULL)
		return 0;
	else
	{
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}