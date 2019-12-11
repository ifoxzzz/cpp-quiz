/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【打印矩形】
输入
  第一行，输入一个整数N。（0 <= N <= 50）

输出
  输出一个矩形，该矩形有N行，每行有5个星号。

示例
  输入：
	6
  输出：
	*****
	*****
	*****
	*****
	*****
	*****
*/

#ifndef __A041__
#define __A041__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A041"

namespace foxzzz {

	class TheJudge : public StrictJudge {
	public:
		TheJudge() : StrictJudge(ID, "打印矩形") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int count;
		//	std::cin >> count;
		//	for (int i = 0; i < count; ++i) {
		//		std::cout << "*****" << std::endl;
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
