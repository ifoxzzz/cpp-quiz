/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【打印三角形III】
输入
  第一行，输入一个整数N。（0 <= M，N <= 50）

输出
  用星号打印一个N行的直角三角形。

示例
  输入：
	5
  输出：
		*
	   **
	  ***
	 ****
	*****
*/

#ifndef __A046__
#define __A046__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A046"

namespace foxzzz {

	class TheJudge : public  StrictJudge {
	public:
		TheJudge() : StrictJudge(ID, "打印三角形III") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int clumn;
		//	std::cin >> clumn;
		//	for (int i = 0; i < clumn; ++i) {
		//		for (int j = clumn - i - 1; j > 0; --j) {
		//			std::cout << " ";
		//		}
		//		for (int j = 0; j < i + 1; ++j) {
		//			std::cout << "*";
		//		}
		//		std::cout << std::endl;
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
