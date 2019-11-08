/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【拆分一个两位数】
输入
  输入一个两位的正整数n。

输出
  输出n的个位数和十位数。

示例
  输入：
	23
  输出：
	3
	2
*/

#ifndef __A010__
#define __A010__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A010"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "拆分一个两位数") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	std::cin >> n;
		//	std::cout << n % 10 << std::endl;
		//	std::cout << n / 10 << std::endl;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
