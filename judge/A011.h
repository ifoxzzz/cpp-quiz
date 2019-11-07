/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【拆分一个三位数】
输入
  输入一个三位的正整数n。

输出
  输出n的个位数和十位数以及百位。

示例
  输入：
	123
  输出：
	3
	2
	1
*/

#ifndef __A011__
#define __A011__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A011"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("拆分一个三位数");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	std::cin >> n;
		//	std::cout << n % 10 << std::endl;
		//	n /= 10;
		//	std::cout << n % 10 << std::endl;
		//	n /= 10;
		//	std::cout << n % 10 << std::endl;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
