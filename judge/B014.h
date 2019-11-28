/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################

【检测IP地址】

IP地址是由4个0~255之间的数组成，并且以.分隔。
以下都是合法的IP地址格式：

192.168.0.1
255.255.255.255
127.0.0.1

以下是不合法的IP地址格式：

a.b.c.d
-1.1.1.1
..255.255
192.168.0.1.
127.0.0.0.1

你需要判断一系列IP地址格式，哪些合法，哪些不合法。

输入
  第一行，输入一个数字n，告诉你接下来将输入n个IP地址；
  后续行，每行输入一个IP地址，共输入n个IP地址。

输出
  如果当前输入的IP地址合法，输出“Yes”，否则输出“No”；
  分多行输出。

示例
  输入：
	2
	192.168.0.1
	a.b.c.d

  输出：
	Yes
	No
*/

#ifndef __B014__
#define __B014__

#ifdef JUDGE_MODE
#include "./judge.h"

#define ID "B014"

namespace foxzzz {

	class TheJudge : public LooseJudge {
	public:
		TheJudge() : LooseJudge(ID, "检测IP地址") {}

	private:
		virtual ProcedureCall verify() {
			return verifyCode;
		}

		static void verifyCode() {
			int number;
			std::cin >> number;
			for (int index = 0; index < number; ++index) {
				char ip[128] = { 0 };
				std::cin >> ip;
				char* cursor = ip;
				int count = 0;
				bool first = true;
				int part = 0;
				bool succeed = true;
				while (true) {
					if (*cursor >= '0' && *cursor <= '9') {
						if (first) {
							part = *cursor - '0';
							first = false;
						}
						else {
							part *= 10;
							part += *cursor - '0';
						}
					}
					else if (*cursor == '.') {
						++count;
						if (first || part < 0 || part > 255) {
							succeed = false;
							break;
						}
						first = true;
					}
					else if (*cursor == '\0') {
						++count;
						if (count != 4 || first || part < 0 || part > 255) {
							succeed = false;
						}
						break;
					}
					else {
						succeed = false;
						break;
					}
					++cursor;
				}
				if (succeed) {
					std::cout << "Yes" << std::endl;
				}
				else {
					std::cout << "No" << std::endl;
				}
			}
		}
	};

	LAUNCH_JUDGE(TheJudge)
}

#endif

#endif
