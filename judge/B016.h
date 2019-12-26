/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【计算文本串中所有数之和】

一行由和数字和其他字符组成的文本串，将其中的数提取出来，并计算它们的和。
例如有文本"&123&%&456(789##"，那么结果就是
123 + 456 + 789 = 1368

输入
  一行文本，回车表示文本结束。

输出
  第一行，输出其中的数；
  第二行，输出其中的数之和。

示例
  输入：
	123&%&456(789

  输出：
	123 456 789
	1368
*/

#ifndef __B016__
#define __B016__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B016"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "计算文本串中所有数之和") {}

	private:
		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	char str[1024];
		//	int a[128] = { 0 };
		//	int len, flag = 0, count = 0, sum = 0;
		//	std::cin >> str;

		//	len = strlen(str);

		//	for (int i = 0; i <= len; ++i) {
		//		char ch = str[i];
		//		if (ch >= '0' && ch <= '9') {
		//			flag = 1;
		//			a[count] *= 10;
		//			a[count] += str[i] - '0';
		//		}
		//		else {
		//			if (flag == 1) {
		//				count++;
		//			}
		//			flag = 0;
		//		}
		//	}

		//	for (int i = 0; i < count; ++i) {
		//		std::cout << a[i] << " ";
		//		sum += a[i];
		//	}

		//	std::cout << std::endl;
		//	std::cout << sum;
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
