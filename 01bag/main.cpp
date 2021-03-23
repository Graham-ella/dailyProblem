#include "head.h"
int main() {
	int m, n;//��ʾ��������ΪM����Ʒ����Ϊn
	std::cin >> m >> n;
	int w[100] = { 0 };//������Ʒ������
	int c[100] = { 0 };//������Ʒ�ļ�ֵ
	
	
	/*

	//��ά��dp����
	int dp[100][500] = { 0 };
	//���Ƴ�ʼ����Ʒ��Ϣ
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
	//��ӡһ��dp��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	*/

	//�����޺�Ч��ԭ�򣺵�ǰ״ֻ̬��ǰһ��״̬�й�
	//���ǿ��Խ�dp��Ϊһά���飬��ʡ�ռ�
	int dp[500] = { 0 };
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {//ע��Ҫ�Ӻ���ǰ�ƣ�����ÿ��ֵ��������쳲�����������һ������
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