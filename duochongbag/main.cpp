#include "head.h"
int main() {
	int m, n;//��ʾ��������ΪM����Ʒ����Ϊn
	std::cin >> m >> n;
	int w[100] = { 0 };//������Ʒ������
	int c[100] = { 0 };//������Ʒ�ļ�ֵ
	int s[100] = { 0 };//ÿ����Ʒ����������
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