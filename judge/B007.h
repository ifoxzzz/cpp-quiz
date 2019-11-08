/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算斐波那契数列】

斐波那契数列指的是这样一个数列：
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144........
这个数列从第3项开始，每一项都等于前两项之和。

输入
  输入n。（0 < n <= 47）

输出
  输出第n个斐波拉契数是多少。

示例
  输入：
	4

  输出：
	3
*/

#ifndef __B007__
#define __B007__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B007"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算斐波那契数列") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	unsigned int a = 1, b = 1;
		//	std::cin >> n;
		//	for (int i = 3; i <= n; ++i) {
		//		unsigned int t = a;
		//		a = b;
		//		b = t + a;
		//	}
		//	std::cout << b;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
