/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算阶乘】

一个正整数的阶乘（factorial）是所有小于及等于该数的正整数的积，并且0的阶乘为1。自然数n的阶乘写作n!。
例如：
5! = 5 * 4 * 3 * 2 * 1
3! = 3 * 2 * 1
1! = 1
0! = 1

输入
  输入n。（0 <= n <= 20）

输出
  输出n!的结果

示例
  输入：
	5

  输出：
	120
*/

#ifndef __B006__
#define __B006__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B006"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算阶乘") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	long long sum = 1;
		//	std::cin >> n;
		//	for (int i = 1; i <= n; ++i) {
		//		sum *= i;
		//	}
		//	std::cout << sum;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
