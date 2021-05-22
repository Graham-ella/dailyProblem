#include "head.h"
int main() {
	Tree T = setTree();
	int min_height = minDepth(T);
	cout << "树的最小深度为:" << min_height << endl;
	int max_height = maxDepth(T);
	cout << "树的最大深度为:" << max_height << endl;

}