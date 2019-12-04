/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算多个整数的和、最大数，最小数，平均数】
输入
  输入一些数量未知的整数，遇到输入的整数是-1的情况表示输入结束。

输出
  计算这些整数的和、最大数，最小数，平均数（保留2位小数），输出结果以空格分隔，但最后的整数-1不参与计算。

示例
  输入：
	1 2 3 4 5 -1
  输出：
	15 5 1 3.00
*/

#ifndef __A035__
#define __A035__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A035"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算多个整数的和、最大数，最小数，平均数") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int sum = 0;
			int count = 1;
			int max, min;
			std::cin >> max;
			sum = min = max;
			while (true) {
				int number;
				std::cin >> number;
				if (number == -1) break;
				sum += number;
				++count;
				if (max < number) {
					max = number;
				}
				if (min > number) {
					min = number;
				}
			}
			printf("%d %d %d %.2lf", sum, max, min, sum / (double)count);
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
