/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【判断闰年】
输入
  输入年份m。

输出
  如果m是闰年，输出“YES”，否则输出“NO”。

闰年计算方法：
  1.能被4整除且不能被100整除的年份是闰年；
  2.能被400整除的年份是闰年。

示例
  输入：
	1696
  输出：
	YES
*/

#ifndef __B003__
#define __B003__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B003"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("判断闰年");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int year;
		//	std::cin >> year;
		//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		//		std::cout << "YES";
		//	}
		//	else {
		//		std::cout << "NO";
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
