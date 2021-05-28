#include "head.h"
#include "¹¹½¨trieÊ÷.cpp"

int main() {
	Trie a;
	a.insert("hello");
	bool b = a.search("hello");
	cout << b << endl;
}