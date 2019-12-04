/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算多个整数的平均数】
输入
  输入一些数量未知的整数，遇到输入的整数是-1的情况表示输入结束。

输出
  计算这些整数的平均数，结果保留3位小数，但最后的整数-1不计入在内。

示例
  输入：
	1 2 3 4 5 -1
  输出：
	3.000
*/

#ifndef __A034__
#define __A034__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A034"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算多个整数的平均数") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			double sum = 0.0;
			int count = 0;
			while (true) {
				int number;
				std::cin >> number;
				if (number == -1) break;
				sum += number;
				++count;
			}
			if (count > 0) {
				printf("%.3lf", sum / count);
			}
			else {
				printf("0.000");
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
