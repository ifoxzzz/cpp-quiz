/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【马拉松选手抵达终点通报名次】
输入
  （无）

输出
  每行输出“第N名选手抵达终点！”，N的数从1递增到20。

示例
  输入：
	（无）
  输出：
	第1名选手抵达终点！
	第2名选手抵达终点！
	第3名选手抵达终点！
	...
	...
	第19名选手抵达终点！
	第20名选手抵达终点！
*/

#ifndef __A015__
#define __A015__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A015"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("马拉松选手抵达终点通报名次");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	for (int i = 1; i <= 20; ++i) {
		//		std::cout << "第" << i << "名选手抵达终点！" << std::endl;
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
