/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算一年中的第几天】
输入
  输入三个整数变量y、m、d，分别表示年、月、日。

输出
  根据y、m、d算出这是一年中的第几天。（需要考虑闰年的情况）

闰年计算方法：
  1.能被4整除且不能被100整除的年份是闰年；
  2.能被400整除的年份是闰年。

示例
  输入：
	2019 12 31
  输出：
	365
*/

#ifndef __B004__
#define __B004__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B004"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("计算一年中的第几天");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int year, month, day, count = 0;
		//	int monthdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//	std::cin >> year >> month >> day;

		//	count = day;
		//	for (int index = 1; index < month; ++index) {
		//		count += monthdays[index - 1];
		//	}

		//	if (month > 2) {
		//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		//			count += 1;
		//		}
		//	}

		//	std::cout << count;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
