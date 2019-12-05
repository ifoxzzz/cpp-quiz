/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出数列中从第M个数开始的后续数列】
输入
  第一行，输入一个整数N，表示接下来要输入N个整数；（0 <= N <= 200）
  第二行，输入N个整数；
  第三行，输入M，表示从第M个数开始的后续数列。（M <= N）

输出
  输出数列中从第M个数开始的后续数列。

示例
  输入：
	5
	2 4 6 8 10
	3
  输出：
	6 8 10
*/

#ifndef __A039__
#define __A039__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A039"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "输出数列中从第M个数开始的后续数列") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int count, position;
		//	int numbers[200] = { 0 };
		//	std::cin >> count;
		//	for (int index = 0; index < count; ++index) {
		//		std::cin >> numbers[index];
		//	}
		//	std::cin >> position;
		//	for (int index = position - 1; index < count; ++index) {
		//		std::cout << numbers[index] << " ";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
