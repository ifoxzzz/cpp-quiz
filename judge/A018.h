/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【从M到N的整数数列】
输入
  输入两个整数M，N。（M <= N）

输出
  从小到大依次输出从M到N的所有整数。

示例
  输入：
	5 10
  输出：
	5 6 7 8 9 10
*/

#ifndef __A018__
#define __A018__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A018"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("从M到N的整数数列");
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
		//		std::cout << i << " ";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
