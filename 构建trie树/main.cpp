#include "head.h"
#include "����trie��.cpp"

int main() {
	Trie a;
	a.insert("hello");
	bool b = a.search("hello");
	cout << b << endl;
}