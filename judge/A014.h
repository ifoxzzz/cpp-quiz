/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【输出十遍“你好，世界！”】
输入
  （无）

输出
  每行输出一遍“你好，世界！”，分十行输出。

示例
  输入：
	（无）
  输出：
	你好，世界！
	你好，世界！
	你好，世界！
	你好，世界！
	....
	..
	.
	（共输出十行）
*/

#ifndef __A014__
#define __A014__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A014"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("输出十遍“你好，世界！”");
			setID(ID);
			loadExamples(ID);
		}

		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			for (int i = 1; i <= 10; ++i) {
				std::cout << "你好，世界！" << std::endl;
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
