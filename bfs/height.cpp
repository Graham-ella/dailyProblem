#include "head.h"
int main() {
	Tree T = setTree();
	int min_height = minDepth(T);
	cout << "������С���Ϊ:" << min_height << endl;
	int max_height = maxDepth(T);
	cout << "����������Ϊ:" << max_height << endl;

}