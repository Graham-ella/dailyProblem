#include "head.h"
int  main() {
	int m, n;//��ʾ��������ΪM����Ʒ����Ϊn
	std::cin >> m >> n;
	int w[100] = { 0 };//������Ʒ������
	int c[100] = { 0 };//������Ʒ�ļ�ֵ
	
	/*
	//��άdp�ⷨ
	int dp[100][500] = { 0 };
	//���Ƴ�ʼ����Ʒ��Ϣ
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= w[i]) {
				dp[i][j] = (dp[i - 1][j] >= (dp[i][j - w[i]] + c[i])) ? dp[i - 1][j] : (dp[i][j - w[i]] + c[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	 */

	/**/
	//һάdp�ⷨ
	int dp[500] = { 0 };
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			for (int k = 0; k <= j / w[i]; k++) {
				dp[j] = (dp[j] >= (dp[j - k * w[i]] + k * c[i])) ? dp[j] : (dp[j - k * w[i]] + k * c[i]);
			}
		}
	}

	for (int q = 1; q <= m; q++) {
		cout << dp[q] << " ";
	}
	cout << endl;
	
	//�Ż���
	/*
	int dp[500] = { 0 };
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= m; j++) {
			dp[j] = (dp[j] >= (dp[j - w[i]] + c[i])) ? dp[j] : (dp[j - w[i]] + c[i]);
		}
		for (int k = 1; k <= m; k++) {
			cout << dp[k] << " ";
		}
		cout << endl;

	}
	*/
}