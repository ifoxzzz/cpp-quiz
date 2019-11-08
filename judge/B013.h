/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【盘旋矩阵】

该矩阵的左上角的数字是1，然后往右行进，每个数字加1；
到最右边后往下行进，每个数字加1；
到最下边后往左行进，每个数字加1；
到最左边后往上行进，每个数字加1；
以上过程重复，直到将矩阵中的所有位置都填满。

输入
  输入两个变量w,h，代表二维矩阵的宽度和高度。

输出
  打印一个w列*h行的二维矩阵。

示例
  输入：
	5 5

  输出：
	1   2   3   4   5
	16  17  18  19  6
	15  24  25  20  7
	14  23  22  21  8
	13  12  11  10  9

	（注意：打印需要采取左对齐，并且填充宽度是4）
*/

#ifndef __B013__
#define __B013__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B013"

namespace foxzzz {

	class TheJudge : public StrictJudge {
	public:
		TheJudge() : StrictJudge(ID, "盘旋矩阵") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int w, h, x = 0, y = 0, count = 0;
		//	int a[20][20] = { 0 };
		//	scanf("%d%d", &w, &h);

		//	while (true) {
		//		bool flag = false;
		//		if (x < w && a[y][x] == 0) {
		//			while (x < w && a[y][x] == 0) {
		//				a[y][x] = ++count;
		//				++x;
		//			}
		//			--x;
		//			++y;
		//			flag = true;
		//		}
		//		if (y < h && a[y][x] == 0) {
		//			while (y < h && a[y][x] == 0) {
		//				a[y][x] = ++count;
		//				++y;
		//			}
		//			--y;
		//			--x;
		//			flag = true;
		//		}
		//		if (x > 0 && a[y][x] == 0) {
		//			while (x >= 0 && a[y][x] == 0) {
		//				a[y][x] = ++count;
		//				--x;
		//			}
		//			++x;
		//			--y;
		//			flag = true;
		//		}
		//		if (y > 0 && a[y][x] == 0) {
		//			while (y >= 0 && a[y][x] == 0) {
		//				a[y][x] = ++count;
		//				--y;
		//			}
		//			++y;
		//			++x;
		//			flag = true;
		//		}
		//		if (!flag) break;
		//	}

		//	for (int i = 0; i < h; ++i) {
		//		for (int j = 0; j < w; ++j) {
		//			printf("%-4d", a[i][j]);
		//		}
		//		printf("\n");
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
