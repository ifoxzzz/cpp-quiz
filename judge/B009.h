/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【回文判断】

回文是指正着读和倒着读都一样的文字。
例如：
a
aa
aba
abba
abcdcba

输入
  输入一个字符串s。(s长度在20个字符内)

输出
  判断s是否是回文，如果是回文，输出“YES”,否则输出“NO”。

示例
  输入：
	aba

  输出：
	YES
*/

#ifndef __B009__
#define __B009__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B009"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("回文判断");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	char s[20] = { 0 };
		//	std::cin >> s;
		//	int len = 0;
		//	for (int i = 0; s[i]; ++i) {
		//		len = i + 1;
		//	}
		//	bool yes = true;
		//	for (int i = 0; i < len; ++i) {
		//		if (s[i] != s[len - i - 1]) {
		//			yes = false;
		//			break;
		//		}
		//	}
		//	if (yes) {
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
