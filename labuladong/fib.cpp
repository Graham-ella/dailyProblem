#include "head.h"


//时间复杂度达到指数级别
int fib_one(int N) {
	if (N == 1 || N == 2) {
		return 1;
	}
	else if (N <= 0) {
		return -1;
	} 
	else {
		return (fib_one(N - 1) + fib_one(N - 2));
	}
}

//使用一个数组充当备忘录
int helper(vector<int>& array, int N) {
	if (N == 1 || N == 2) {
		return 1;
	}
	if (array[N] != 0) {
		return array[N];
	}
	else {
		array[N] = helper(array, N - 1) + helper(array, N - 2);
	}
	return array[N];
}
int fib_two(int N) {
	if (N <= 0) {
		return -1;
	}
	vector<int> memo(N + 1, 0);
	return helper(memo, N);
}

//自底向上迭代解法
int fib_three(int N) {
	vector<int> dp(N + 1, 0);
	dp[1] = 1;
	dp[2] = 1;
	if (N <= 0){
		return -1;
	}
	else if(N == 1 || N == 2){
		return 1;
	}
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[N];
}

//降低空间复杂度
int fib_four(int N) {
	if (N <= 0) {
		return -1;
	}
	else if (N == 1 || N == 2) {
		return 1;
	}
	else {
		int sum;
		int pre = 1;
		int cur = 1;
		for (int i = 3; i <= N; i++) {
			sum = pre + cur;
			pre = cur;
			cur = sum;
		}
		return cur;
	}
}