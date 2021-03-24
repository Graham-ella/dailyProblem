#include "head.h"
int main() {
	int m, n;//表示背包容量为M，物品个数为n
	std::cin >> m >> n;
	int w[100] = { 0 };//代表物品的重量
	int c[100] = { 0 };//代表物品的价值
	int s[100] = { 0 };//每个物品的数量有限
	int dp[1050] = { 0 };
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i]>>s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; --j) {
			for (int k = 0; k <= s[i] && j >= k * w[i]; k++) {
				dp[j] = (dp[j] >= (dp[j - k * w[i]] + k * c[i])) ? dp[j] : dp[j - k * w[i]] + k * c[i];
			}
		}
	}
	cout << dp[m] << endl;
}