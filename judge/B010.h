/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【数列排序】

输入
  第一行：输入整数N，代表接下来有N个整数。（0 < N < 20）；
  第二行：输入N个整数。

输出
  将N个整数由小到大排序后输出。

示例
  输入：
	5
	3 2 5 1 4

  输出：
	1 2 3 4 5
*/

#ifndef __B010__
#define __B010__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B010"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "数列排序") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	int a[20] = { 0 };
		//	std::cin >> n;

		//	for (int i = 0; i < n; ++i) {
		//		std::cin >> a[i];
		//	}

		//	for (int i = 0; i < n - 1; ++i) {
		//		int target = i;
		//		for (int j = i + 1; j < n; ++j) {
		//			if (a[target] > a[j]) {
		//				target = j;
		//			}
		//		}
		//		if (target != i) {
		//			int t = a[target];
		//			a[target] = a[i];
		//			a[i] = t;
		//		}
		//	}

		//	for (int i = 0; i < n; ++i) {
		//		std::cout << a[i] << " ";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
