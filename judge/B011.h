/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【数列去重】

输入
  第一行：输入整数N，代表接下来将输入N个整数。（0 < N < 20）；
  第二行：输入N个整数。

输出
  将N个整数去除重复项后按首次出现的先后顺序依次输出。

示例
  输入：
	6
	3 2 6 3 2 9

  输出：
	3 2 6 9
*/

#ifndef __B011__
#define __B011__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B011"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "数列去重") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n, len = 0;
		//	int a[20] = { 0 };
		//	std::cin >> n;

		//	for (int i = 0; i < n; ++i) {
		//		int v;
		//		bool has = false;
		//		std::cin >> v;
		//		for (int j = 0; j < len; ++j) {
		//			if (a[j] == v) {
		//				has = true;
		//				break;
		//			}
		//		}
		//		if (!has) {
		//			a[len++] = v;
		//		}
		//	}

		//	for (int i = 0; i < len; ++i) {
		//		std::cout << a[i] << " ";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
