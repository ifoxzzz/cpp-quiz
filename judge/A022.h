/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【每行5个的数列】
输入
  输入两个整数M，N。（M <= N）

输出
  从小到大依次输出从M到N范围内的所有整数；
  每行输出5个数，分多行输出；
  每个数采用宽度为3的左对齐格式输出。

示例
  输入：
	1 20
  输出：
	1  2  3  4  5
	6  7  8  9  10
	11 12 13 14 15
	16 17 18 19 20
*/

#ifndef __A022__
#define __A022__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A022"

namespace foxzzz {

	class TheJudge : public StrictJudge {
	private:
		virtual void build() {
			setTitle("每行5个的数列");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int m, n;
		//	scanf("%d%d", &m, &n);
		//	for (int i = m; i <= n; ++i) {
		//		printf("%-3d", i);
		//		if ((i - m) % 5 == 4) {
		//			printf("\n");
		//		}
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
