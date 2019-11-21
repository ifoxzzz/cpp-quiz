/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出能被3或5整除的整数序列】
输入
  输入一些数量未知的整数。

输出
  整数中如果存在能被3或5整除的数，输出这个整数。
  如遇到输入的数是-1的情况下程序终止。

示例
  输入：
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 -1
  输出：
	3 5 6 9 10 12 15 18 20 21 24 25 27 30 33 35 36 39 40 42 45 48 50
*/

#ifndef __A028__
#define __A028__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A028"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "输出能被3或5整除的整数序列") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	while (true) {
		//		int number;
		//		std::cin >> number;
		//		if (number == -1) break;
		//		if (number % 3 == 0 || number % 5 == 0) {
		//			std::cout << number << " ";
		//		}
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
