#include "head.h"
int main() {
	Tree T = setTree();
	int height = minDepth(T);
	cout << "树的最小高度为:" << height << endl;
}