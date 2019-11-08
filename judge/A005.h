/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【绝对值】
输入
  输入一个整数。

输出
  该数的绝对值。

示例
  输入：
	-3
  输出：
	3
*/

#ifndef __A005__
#define __A005__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A005"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "绝对值") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int i;
		//	std::cin >> i;
		//	if (i < 0) {
		//		std::cout << -i;
		//	}
		//	else {
		//		std::cout << i;
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
