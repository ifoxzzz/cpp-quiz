/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出数列中从第M个数开始的C个数】
输入
  第一行，输入一个整数N，表示接下来要输入N个整数；（0 <= N <= 200）
  第二行，输入N个整数；
  第三行，输入M，C，其中M表示开始位置，C表示要输出的数的数量。（M <= N）

输出
  输出数列中从第M个数开始的C个数。

示例
  输入：
	5
	2 4 6 8 10
	3 2
  输出：
	6 8
*/

#ifndef __A040__
#define __A040__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A040"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "输出数列中从第M个数开始的C个数") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int count, position, total;
			int numbers[200] = { 0 };
			std::cin >> count;
			for (int index = 0; index < count; ++index) {
				std::cin >> numbers[index];
			}
			std::cin >> position >> total;
			for (int index = position - 1; index < position + total - 1; ++index) {
				std::cout << numbers[index] << " ";
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
