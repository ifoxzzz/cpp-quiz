/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【最长连续升序数列】

有若干个整数，找出其中最长的连续升序数列，并打印。

输入
  第一行，输入一个数字n，告诉你接下来将输入n个整数；
  第二行，输入N个整数。

输出
  输出这些整数中，最长的连续升序数列。

示例
  输入：
	12
	1 2 3 1 2 3 3 5 10 1 2 3

  输出：
	1 2 3 3 5 10
*/

#ifndef __B015__
#define __B015__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B015"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "最长连续升序数列") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	std::cin >> n;
		//	int numbers[100] = { 0 };
		//	for (int index = 0; index < n; ++index) {
		//		std::cin >> numbers[index];
		//	}
		//	int count = 1;
		//	int max = 0;
		//	int start = 0;
		//	for (int index = 1; index < n; ++index) {
		//		if (numbers[index - 1] <= numbers[index]) {
		//			++count;
		//		}
		//		else {
		//			if (max < count) {
		//				max = count;
		//				count = 1;
		//				start = index - max;
		//			}
		//		}
		//	}
		//	if (max < count) {
		//		max = count;
		//		count = 1;
		//		start = n - max;
		//	}
		//	while (max--) {
		//		std::cout << numbers[start++] << " ";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
