/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算多个整数的和III】
输入
  第一行，输入一个整数N，表示接下来要输入N个整数；（0 <= N <= 200）
  第二行，输入N个整数。

输出
  第一行，输出这些整数的和；
  第二行，按输入顺序输出每个整数；

示例
  输入：
	5
	1 2 3 4 5
  输出：
	15
	1 2 3 4 5
*/

#ifndef __A037__
#define __A037__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A037"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算多个整数的和III") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int count;
			int sum = 0;
			int numbers[200] = { 0 };
			std::cin >> count;
			for (int index = 0; index < count; ++index) {
				std::cin >> numbers[index];
				sum += numbers[index];
			}
			std::cout << sum << std::endl;
			for (int index = 0; index < count; ++index) {
				std::cout << numbers[index] << " ";
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
