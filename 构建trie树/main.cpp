#include "head.h"
#include "¹¹½¨trieÊ÷.cpp"

int main() {
	Trie a;
	a.insert("hello");
	a.insert("hell");
	bool b = a.startsWith("hell");
	cout << b << endl;
}