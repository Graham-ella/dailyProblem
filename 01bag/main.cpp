#include "head.h"
int main() {
	int m, n;//表示背包容量为M，物品个数为n
	std::cin >> m >> n;
	int w[100] = { 0 };//代表物品的重量
	int c[100] = { 0 };//代表物品的价值
	
	
	/*

	//二维的dp数组
	int dp[100][500] = { 0 };
	//完善初始的物品信息
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				//dp[i][j] = max(dp[i - 1][j], c[i] + dp[i - 1][j - w[i]]);
				dp[i][j] = (dp[i - 1][j] >= (c[i] + dp[i - 1][j - w[i]])) ? dp[i - 1][j] : (c[i] + dp[i - 1][j - w[i]]);
			}
		}
	}
	//打印一下dp表
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	*/

	//根据无后效性原则：当前状态只和前一个状态有关
	//我们可以将dp变为一维数组，节省空间
	int dp[500] = { 0 };
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {//注意要从后往前推，否则每行值会类似于斐波那契额数列一样增长
			if (j >= w[i]) {
				dp[j] = (dp[j] >= (c[i] + dp[j - w[i]])) ? dp[j] : (c[i] + dp[j - w[i]]);
			}
		}
		for (int j = 1; j <= m; j++) {
			cout << dp[j] << " ";
		}
		cout << endl;

	}
	
	
}