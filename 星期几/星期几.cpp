/*
已知 1 年 1 月 1 日是星期一。

现在给定一个日期，请你判断是星期几。

注意闰年的 2 月有 29 天。

满足下面条件之一的是闰年：

年份是 4 的整数倍，而且不是 100 的整数倍；
年份是 400 的整数倍。
输入格式
输入包含多组测试数据。

每组数据占一行，包含一个整数 d 表示日，一个字符串 m 表示月，一个整数 y 表示年。

月份 1∼12，依次如下所示：

January, February, March, April, May, June, July, August, September, October, November, December
输出格式
每组数据输出一行结果，输出一个字符串表示给定日期是星期几。

周一至周日依次如下所示：

Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
数据范围
1000≤y≤3000,
给定日期保证合法。
每个输入最多包含 100 组数据。

输入样例：
9 October 2001
14 October 2001
输出样例：
Tuesday
Sunday
*/

//思路：从 1 年 1 月 1 日开始一直算到输入的日子

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int monthdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int isLeapyear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int getdays(int year, int month) {
	if (month == 2) {
		return monthdays[month] + isLeapyear(year);
	}
	return monthdays[month];
}//获取当年、当月的天数


unordered_map<string, int> month = {   //输入的mon的str形式，要获取他们对应的数字1-12
	{"January",1},
	{"February",2},
	{"March",3},
	{"April",4},
	{"May",5},
	{"June",6},
	{"July",7},
	{"August",8},
	{"September",9},
	{"October",10},
	{"November",11},
	{"December",12},
};

string  res[7] = {
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};



int main() {
	int d, m, y;//d:日 m:月 y:年
	string str="";
	
	while (cin >> d >> str >> y) {
		int countDays = 0;//用来统计从1 年 1 月 1 日到现在需要多少经过多少天
		int month_number = month[str];
		int i = 1, j = 1, k = 1;//i用来到达天数，j用来到达月份，k用来到达年份
		while (i < d || j < month_number || k < y) {
			i++;
			countDays++;
			if (i > getdays(k, j)) {
				i = 1;
				j++;
				if (j > 12) {
					j = 1;
					k++;
				}
			}
		}
		cout << res[countDays % 7]<<endl;
 	}

}
