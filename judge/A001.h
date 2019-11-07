/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出“你好，世界！”】
输入
  （无）

输出
  你好，世界！
*/

#ifndef __A013__
#define __A013__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A001"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("输出“你好，世界！”");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	std::cout << "你好，世界！";
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
