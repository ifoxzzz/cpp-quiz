/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算圆的周长和面积】
输入
  输入一个半径r。(r可能是浮点数)

输出
  计算半径r的周长和面积。（结果保留3位小数）

运算说明：
  π = 3.14159
  如果r小于0，输出“输入错误”

示例
  输入：
	2
  输出：
	12.566 12.566
*/

#ifndef __A009__
#define __A009__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A009"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算圆的周长和面积") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	double r;
		//	scanf("%lf", &r);
		//	if (r > 0) {
		//		double pi = 3.14159;
		//		double C = 2 * pi * r;
		//		double S = pi * r * r;
		//		printf("%.3lf %.3lf", C, S);
		//	}
		//	else {
		//		std::cout << "输入错误";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
