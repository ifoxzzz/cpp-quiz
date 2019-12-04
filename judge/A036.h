/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算多个整数的和II】
输入
  输入一些数量未知的整数，遇到输入的整数是-1的情况表示输入结束。（数的总量不会超过200）

输出
  第一行，输出这些整数的和（最后的-1不参与计算）；
  第二行，按输入顺序输出每个整数（最后的-1不输出）；

示例
  输入：
	1 2 3 4 5 -1
  输出：
	15
	1 2 3 4 5
*/

#ifndef __A036__
#define __A036__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A036"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算多个整数的和II") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int count = 0;
			int sum = 0;
			int numbers[200] = { 0 };
			while (true) {
				int n;
				std::cin >> n;
				if (n == -1) break;
				numbers[count++] = n;
				sum += n;
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
