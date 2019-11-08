/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【将一个三位数翻转后跟原来的数相加】
输入
  输入一个三位的正整数n。

输出
  输出n翻转的数加上n的结果。

示例
  输入：
	123
  输出：
	444
	（说明：123 + 321 = 444）
*/

#ifndef __A012__
#define __A012__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A012"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "将一个三位数翻转后跟原来的数相加") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	std::cin >> n;
		//	int t = n, r;
		//	r = t % 10;
		//	t /= 10;
		//	r *= 10;
		//	r += t % 10;
		//	t /= 10;
		//	r *= 10;
		//	r += t % 10;
		//	std::cout << n + r;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
