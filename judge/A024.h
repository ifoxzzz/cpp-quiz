/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出N个整数】
输入
  第一行，输入一个整数N，表示接下来将输入N个整数；
  第二行，输入N个整数。

输出
  将N个整数按输入顺序输出。

示例
  输入：
	5
	3 6 -2 7 99
  输出：
	3 6 -2 7 99
*/

#ifndef __A024__
#define __A024__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A024"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("输出N个整数");
			setID(ID);
			loadExamples(ID);
		}

		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int n;
			std::cin >> n;
			for (int i = 0; i < n; ++i) {
				int number;
				std::cin >> number;
				std::cout << number << " ";
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
