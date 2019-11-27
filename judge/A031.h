/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算多个整数的和】
输入
  输入一些数量未知的整数，遇到输入的整数是-1的情况表示输入结束。

输出
  计算这些整数相加的和，但最后的整数-1不参加求和运算。

示例
  输入：
	1 2 3 4 5 -1
  输出：
	15
*/

#ifndef __A031__
#define __A031__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A031"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算多个整数的和") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int sum = 0;
		//	while (true) {
		//		int number;
		//		std::cin >> number;
		//		if (number == -1) break;
		//		sum += number;
		//	}
		//	std::cout << sum;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
