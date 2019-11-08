/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【一组数中统计高于平均值的数的数量】
输入
  第一行输入一个整数N，表示接下来要输入N个整数（0 < N < 20）；
  第二行是N个整数。

输出
  第一行输出N个整数的平均数（保留两位小数）；
  第二行输出N个整数中，高于平均值的数的数量。

示例
  输入：
	10
	1 2 3 4 5 6 7 8 9 10
  输出：
	5.50
	5
	（说明：大于5.5的数有5个）
*/

#ifndef __B002__
#define __B002__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B002"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "一组数中统计高于平均值的数的数量") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	int a[20] = { 0 };
		//	int sum = 0;
		//	int total = 0;
		//	scanf("%d", &n);
		//	for (int i = 0; i < n; ++i) {
		//		scanf("%d", &a[i]);
		//		sum += a[i];
		//	}
		//	double ave = (double)sum / n;
		//	for (int i = 0; i < n; ++i) {
		//		if (a[i] > ave) {
		//			++total;
		//		}
		//	}
		//	printf("%.2lf\n", ave);
		//	printf("%d", total);
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
