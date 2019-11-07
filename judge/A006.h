/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【自助套餐办理】
输入
  输入一个整数。

输出
  该整数对应的套餐。

套餐说明：
  0 您退订了套餐
  1 您选择了普通套餐
  2 您选择了尊享套餐
  3 您选择了豪华套餐
  X 没有该套餐
  (X代表除0~3以外的其他数字)

示例
  输入：
	2
  输出：
	您选择了尊享套餐
*/

#ifndef __A006__
#define __A006__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "A006"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	private:
		virtual void build() {
			setTitle("自助套餐办理");
			setID(ID);
			loadExamples(ID);
		}

		//virtual ProcedureCall verify() {
		//	return verifyCode;
		//}

		//static void verifyCode() {
		//	int n;
		//	std::cin >> n;
		//	switch (n) {
		//	case 0:
		//		std::cout << "您退订了套餐";
		//		break;
		//	case 1:
		//		std::cout << "您选择了普通套餐";
		//		break;
		//	case 2:
		//		std::cout << "您选择了尊享套餐";
		//		break;
		//	case 3:
		//		std::cout << "您选择了豪华套餐";
		//		break;
		//	default:
		//		std::cout << "没有该套餐";
		//		break;
		//	}
		//}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
