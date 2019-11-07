/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【两数之和】
输入
  输入两个整数a, b。

输出
  输出a b相加的和数。

示例
  输入：
	5 3
  输出：
	8
*/

#ifndef __A002__
#define __A002__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A002"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("两数之和");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int a, b;
		//	std::cin >> a >> b;
		//	std::cout << a + b;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
