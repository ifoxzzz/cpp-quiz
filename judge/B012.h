/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【数组翻转】
输入
  参数numbers是个整数数组；
  参数len是numbers的长度；

输出
  注意，这道题不需要输出；
  但是需要首尾交换numbers数组中的元素。

示例
  输入：
	numbers:[1,2,3,4,5]
	len:5
  输出：
	numbers:[5,4,3,2,1]
*/

#ifndef __B012__
#define __B012__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B012"

namespace foxzzz {

	typedef void (*WrapperCall)(int numbers[], int len);

	void wrapper(WrapperCall call) {
		int len;
		int numbers[20] = { 0 };
		std::cin >> len;
		for (int i = 0; i < len; ++i) {
			std::cin >> numbers[i];
		}
		call(numbers, len);
		for (int i = 0; i < len; ++i) {
			std::cout << numbers[i] << " ";
		}
	};

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("数组翻转");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	wrapper(reverse);
		//}

		//static void reverse(int numbers[], int len) {
		//	for (int i = 0; i < len / 2; ++i) {
		//		int t = numbers[i];
		//		numbers[i] = numbers[len - i - 1];
		//		numbers[len - i - 1] = t;
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

void mycode(int numbers[], int len);

int main() {
	foxzzz::wrapper(mycode);
	return 0;
}

#endif

#endif
