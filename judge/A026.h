/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出整数序列】
输入
  输入一些数量未知的整数。

输出
  输出这些整数，但遇到输入的数是-1的情况下程序终止。

示例
  输入：
	3 6 -1 7 99
  输出：
	3 6
*/

#ifndef __A026__
#define __A026__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A026"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "输出整数序列") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	while (true) {
		//		int number;
		//		std::cin >> number;
		//		if (number != -1) {
		//			std::cout << number << " ";
		//		}
		//		else {
		//			break;
		//		}
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
