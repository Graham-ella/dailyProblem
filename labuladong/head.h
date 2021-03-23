#include <iostream>
#include <vector>
using std::cout; 
using std::endl;
using std::vector;

//斐波那契数列问题
int fib_one(int N);//最普通的递归求解斐波那契数列
int fib_two(int N);//使用一个数组充当备忘录
int helper(vector<int>& array, int N);
int fib_three(int N);//dp数组的动态解法
int fib_four(int N);

//凑零钱问题
