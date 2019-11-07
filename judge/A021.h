/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【不能被4整除的数列】
输入
  输入两个整数M，N。（M <= N）

输出
  从小到大依次输出从M到N范围内的所有不能被4整除的数。

示例
  输入：
	0 10
  输出：
	1 3 5 7 9
*/

#ifndef __A021__
#define __A021__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A021"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("不能被4整除的数列");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int m, n;
		//	std::cin >> m >> n;
		//	for (int i = m; i <= n; ++i) {
		//		if (i % 4 != 0) {
		//			std::cout << i << " ";
		//		}
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
