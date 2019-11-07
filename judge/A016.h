/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【火箭发射倒计时报数】
输入
  （无）

输出
  每行输出“火箭将在N秒后发射”，N的数从10递减到0；
  0秒后，再输出一行“发射！”。

示例
  输入：
	（无）
  输出：
	火箭将在10秒后发射
	火箭将在9秒后发射
	火箭将在8秒后发射
	...
	...
	火箭将在1秒后发射
	火箭将在0秒后发射
	发射！
*/

#ifndef __A016__
#define __A016__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A016"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("火箭发射倒计时报数");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	for (int i = 10; i >= 0; --i) {
		//		std::cout << "火箭将在" << i << "秒后发射" << std::endl;
		//	}
		//	std::cout << "发射！";
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
