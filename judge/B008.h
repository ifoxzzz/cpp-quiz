/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【一段范围内的所有质数】

质数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
质数序列有：2 3 5 7 11 13 17 19 23 29 31 37 41.....
（注意：1不是质数）

输入
  输入m、n。（0 < m < n < 100000）

输出
  按从小到大的顺序输出m到n范围中的所有质数。
  注意：如果在m~n区间内没有一个质数，请输出“nothing”。

示例
  输入：
	2 20

  输出：
	2 3 5 7 11 13 17 19
*/

#ifndef __B008__
#define __B008__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B008"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "一段范围内的所有质数") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int m, n;
		//	std::cin >> m >> n;
		//	if (m < 2) {
		//		m = 2;
		//	}
		//	bool has = false;
		//	while (m <= n) {
		//		bool prime = true;
		//		for (int i = 2; i < m; ++i) {
		//			if (m % i == 0) {
		//				prime = false;
		//				break;
		//			}
		//		}
		//		if (prime) {
		//			std::cout << m << " ";
		//			if (!has) {
		//				has = true;
		//			}
		//		}
		//		++m;
		//	}
		//	if (!has) {
		//		std::cout << "nothing";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
