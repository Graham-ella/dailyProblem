//给定一个非负整数 n，请你判断是否存在一些整数 xi，能够使得 n = ∑1≤i≤txi!，其中 t≥1, xi≥0, xi = xj iff i = j。
//
//iff 表示当且仅当。
//
//输入格式
//输入包含多组测试数据。
//
//每组数据占一行，包含一个非负整数 n。
//
//最后一行是一个负数，表示输入结束，无需处理。
//
//输出格式
//每组数据输出一行结果，如果 n 能表示为若干数的阶乘之和，则输出 yes，否则输出 no。
//
//数据范围
//0≤n≤106,
//每组输入最多包含 100 组数据。
//
//输入样例：
//9
//- 1
//输出样例：
//yes

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;



unordered_set<int> res;
int f[10];



int main()
{

    int n;

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 9; i++) {
        f[i] = f[i - 1] * i;
    }//到这里为止计算出0!,1!,2!,.......,9!的所有值

    int sum;

    for (int i = 1; i < (1 << 10); i++) {
        sum = 0;
        for (int j = 0; j < 10; j++) {
            if ((i >> j) & 1) {
                sum += f[j];
            }
        }
        res.insert(sum);
    }


    while (cin >> n && n >= 0) {
        if (res.count(n)) {//对于n出现的次数进行计数，
                         //但是由于unordered_set容器不允许存储重复的元素，因此该功能通常用于检查容器中是否存在元素
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }




}
