/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出数列中第M个数】
输入
  第一行，输入一个整数N，表示接下来要输入N个整数；（0 <= N <= 200）
  第二行，输入N个整数；
  第三行，输入M，表示N个整数中的第几个。（M <= N）

输出
  输出N个整数中的第M个整数。

示例
  输入：
	5
	2 4 6 8 10
	3
  输出：
	6
*/

#ifndef __A038__
#define __A038__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A038"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "输出数列中第M个数") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int count, position;
			int numbers[200] = { 0 };
			std::cin >> count;
			for (int index = 0; index < count; ++index) {
				std::cin >> numbers[index];
			}
			std::cin >> position;
			std::cout << numbers[position - 1];
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
