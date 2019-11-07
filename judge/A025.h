/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出N个整数II】
输入
  第一行，输入一个整数N，表示接下来将输入N个整数；
  第二行，输入N个整数。

输出
  将N个整数按输入顺序输出；
  但若在输出过程中遇到-1要终止后续的整数输出。

示例
  输入：
	5
	3 6 -1 7 99
  输出：
	3 6 -1
*/

#ifndef __A025__
#define __A025__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A025"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("输出N个整数II");
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
				if (number == -1) break;
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
