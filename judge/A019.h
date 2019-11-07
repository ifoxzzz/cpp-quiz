/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【跳跃数列】
输入
  输入三个整数M，N，T。（M <= N， 0 < T）

输出
  从小到大依次输出从M到N范围内，每次跳跃T个数的数列。

示例
  输入：
	5 10 2
  输出：
	5 7 9
  输入：
    0 12 3
  输出：
	0 3 6 9 12
*/

#ifndef __A019__
#define __A019__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A019"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("跳跃数列");
			setID(ID);
			loadExamples(ID);
		}

		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int m, n, t;
			std::cin >> m >> n >> t;
			for (int i = m; i <= n; i += t) {
				std::cout << i << " ";
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
