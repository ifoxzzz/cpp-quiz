/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【三数之中的较大数】
输入
  输入三个整数a, b, c。

输出
  输出a, b, c中较大的数。

示例
  输入：
	5 3 1
  输出：
	5
*/

#ifndef __A004__
#define __A004__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A004"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "三数之中的较大数") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int a, b, c;
		//	std::cin >> a >> b >> c;
		//	int max = a;
		//	if (max < b) {
		//		max = b;
		//	}
		//	if (max < c) {
		//		max = c;
		//	}
		//	std::cout << max;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
