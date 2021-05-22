#include <iostream>
#include <queue>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;
typedef struct node {
	char a;
	struct node* left;
	struct node* right;
}Node;

typedef Node* Tree;

Tree setTree();
int minDepth(Tree root);
int maxDepth(Tree root);