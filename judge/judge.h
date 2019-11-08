/*
################################################
. Summary : a small c++ judging tool on windows
. Author  : foxzzz, i@foxzzz.com, QQ 406609631
. Date    : 2019/11/01
################################################
*/

#ifndef __FOXZZZ_JUDGE__
#define __FOXZZZ_JUDGE__

#ifdef JUDGE_MODE

#define _CRT_SECURE_NO_WARNINGS //for visual studio

#ifndef COMMON_LVB_UNDERSCORE
#define COMMON_LVB_UNDERSCORE 0x8000 //for code::blocks
#endif


#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define LAUNCH_JUDGE(JUDGE)\
	JUDGE judge;\
	foxzzz::Launcher* launcher = new Launcher(judge);\

int main();

namespace foxzzz {
	class Reader {
	public:
		Reader(std::ifstream& input) : input_(input) {

		}

		~Reader() {

		}

	public:
		Reader& operator >> (std::string& str) {
			readString(input_, str);
			return *this;
		}

		Reader& operator >> (int& value) {
			readInt(input_, value);
			return *this;
		}

		Reader& operator >> (unsigned int& value) {
			readUnInt(input_, value);
			return *this;
		}

		Reader& operator >> (double& value) {
			readDouble(input_, value);
			return *this;
		}

	private:
		static void readString(std::ifstream& input, std::string& str) {
			unsigned int size = 0;
			input.read((char*)& size, sizeof(size));
			if (size) {
				char* buffer = new char[size + 1];
				buffer[size] = '\0';
				input.read(buffer, size);
				str = buffer;
				delete[] buffer;
			}
		}

		static void readInt(std::ifstream& input, int& value) {
			input.read((char*)& value, sizeof(value));
		}

		static void readUnInt(std::ifstream& input, unsigned int& value) {
			input.read((char*)& value, sizeof(value));
		}

		static void readDouble(std::ifstream& input, double& value) {
			input.read((char*)& value, sizeof(value));
		}

	private:
		std::ifstream& input_;
	};

	class Writer
	{
	public:
		Writer(std::ofstream& output) : output_(output) {

		}

		~Writer() {

		}

	public:
		Writer& operator << (const std::string& str) {
			writeString(output_, str);
			return *this;
		}

		Writer& operator << (const int& value) {
			writeInt(output_, value);
			return *this;
		}

		Writer& operator << (const unsigned int& value) {
			writeUnInt(output_, value);
			return *this;
		}

		Writer& operator << (const double& value) {
			writeDouble(output_, value);
			return *this;
		}

	private:
		static void writeString(std::ofstream& output, const std::string& str) {
			unsigned int size = (unsigned int)str.length();
			output.write((char*)& size, sizeof(size));
			if (size) {
				output.write(str.c_str(), size);
			}
		}

		static void writeInt(std::ofstream& output, const int& value) {
			output.write((char*)& value, sizeof(value));
		}

		static void writeUnInt(std::ofstream& output, const unsigned int& value) {
			output.write((char*)& value, sizeof(value));
		}

		static void writeDouble(std::ofstream& output, const double& value) {
			output.write((char*)& value, sizeof(value));
		}

	private:
		std::ofstream& output_;
	};

	typedef void (*ProcedureCall)();

	class Judge {
	public:
		struct Example {
			Example() {}
			Example(const std::string& input, const std::string& expect)
				:input(input), expect(expect) {}
			std::string input;
			std::string expect;
		};

		struct ErrorInfo {
			ErrorInfo(const std::string& name, const std::string& input, const std::string& output, const std::string& expect)
				: name(name), input(input), output(output), expect(expect) {}
			std::string name;
			std::string input;
			std::string output;
			std::string expect;
		};

		struct ScoreInfo {
			ScoreInfo() : score(0), time(0) {}
			ScoreInfo(const std::string& id, unsigned int score, unsigned int time)
				: id(id), score(score), time(time) {}
			std::string id;
			unsigned int score;
			unsigned int time;
		};

	public:
		Judge() : call_(NULL), duration_(0), defaultColorAttrs_(0) {
			getDefaultColorAttrs();
		}

	public:
		void setCall(ProcedureCall call) {
			call_ = call;
		}

		ProcedureCall getVerify() {
			return verify();
		}

		void run() {
			showTitleBar();
			showSummary();
			build();
			if (!examples_.empty()) {
				execute();
				showInfo();
				waitingPressAnyKey();
			}
		}

	protected:
		void setID(const std::string& id) {
			id_ = id;
		}

		void setTitle(const std::string& title) {
			title_ = title;
		}

		void setSummary(const std::string& summary) {
			summary_ = summary;
		}

		void addExample(const Example& example) {
			examples_.push_back(example);
		}

		bool loadExamples() {
			if (!id_.empty()) {
				std::vector<Example> examples;
				loadExamplesDirectory(id_, examples);
				examples_.swap(examples);
				return true;
			}
			return false;
		}

	protected:
		static bool compareList(const std::vector<std::string>& expect, const std::vector<std::string>& output) {
			if (expect.size() != output.size()) return false;
			for (std::size_t index = 0; index < expect.size(); ++index) {
				if (expect[index] != output[index]) return false;
			}
			return true;
		}

		static void extractLine(const std::string& text, std::vector<std::string>& list) {
			std::stringstream ss;
			ss << text;

			std::string line;
			while (getline(ss, line)) {
				std::stringstream lss;
				std::string item;
				lss << line;
				if (lss >> item) {
					list.push_back(line);
				}
			}
		}

		static void tidyLine(std::vector<std::string>& list) {
			for (std::size_t index = 0; index < list.size(); ++index) {
				std::string& line = list[index];
				std::stringstream lss;
				std::string item;
				lss << line;
				std::string tidy;
				while (lss >> item) {
					if (!tidy.empty()) {
						tidy += ' ';
					}
					tidy += item;
				}
				line = tidy;
			}
		}

	private:
		virtual bool compare(const std::string& expect, const std::string& output) = 0;
		virtual void build() = 0;
		virtual ProcedureCall verify() { return NULL; };

	private:
		void execute() {
			int count = 0;
			errors_.clear();
			printColorText(FOREGROUND_BLUE, "╔----------------------------------------------------╗\n");
			printf("%3s", " ");
			printColorText(FOREGROUND_GREEN | COMMON_LVB_UNDERSCORE | FOREGROUND_BLUE, " %-20s%-20s%s \n", "测试数据", "执行耗时", "执行结果");
			for (std::size_t index = 0; index < examples_.size(); ++index) {
				const Example& example = examples_[index];
				input_ = example.input;
				expect_ = example.expect;
				generateInput();
				generateOutput();
				readOutput();

				char name[128] = { 0 };
				sprintf(name, "TEST-%u", (unsigned int)(index + 1));
				printColorText(FOREGROUND_BLUE | FOREGROUND_INTENSITY, "    %-20s", name);
				char duration[128] = { 0 };
				sprintf(duration, "%dms", duration_);
				printf("%-20s", duration);
				if (compare(expect_, output_)) {
					printColorText(FOREGROUND_GREEN, "%-20s\n", "正确");
					++count;
				}
				else {
					printColorText(FOREGROUND_RED, "%-20s\n", "错误");
					errors_.push_back(ErrorInfo(name, input_, output_, expect_));
				}
			}

			unsigned int score = (int)(((double)count / examples_.size()) * 100);
			appendScore(id_, score);

			printColorText(FOREGROUND_GREEN | FOREGROUND_INTENSITY, "\n%40s : %-3u 』\n", "『 得分", score);
			printColorText(FOREGROUND_BLUE, "╚----------------------------------------------------╝\n");
			clearFile();
		}

	private:
		void generateInput() {
			std::ofstream ofs(getInputFileName().c_str());
			if (ofs) {
				ofs << input_;
			}
			else {
				std::cout << "don't save input.txt!" << std::endl;
			}
		}

		void generateOutput() {
			if (freopen(getInputFileName().c_str(), "r", stdin) == NULL) {
				std::cout << "error ： freopen stdin" << std::endl;
			}
			if (freopen(getOutputFileName().c_str(), "w", stdout) == NULL) {
				std::cout << "error ： freopen stdout" << std::endl;
			}
			std::cin.clear();
			std::cout.clear();
			duration_ = ::GetTickCount();
			call_();
			duration_ = ::GetTickCount() - duration_;
			if (freopen("CON", "r", stdin) == NULL) {
				std::cout << "error ： freopen stdin" << std::endl;
			}
			if (freopen("CON", "w", stdout) == NULL) {
				std::cout << "error ： freopen stdout" << std::endl;
			}
		}

		void readOutput() {
			std::ifstream ifs(getOutputFileName().c_str());
			if (ifs) {
				output_ = "";
				std::string line;
				while (std::getline(ifs, line)) {
					if (!output_.empty()) {
						output_ += '\n';
					}
					output_ += line;
				}
			}
			else {
				std::cout << "don't load output.txt!" << std::endl;
			}
		}

		void clearFile() const {
			remove(getInputFileName().c_str());
			remove(getOutputFileName().c_str());
		}

	private:
		std::string getInputFileName() const {
			return id_ + "_input.txt";
		}

		std::string getOutputFileName() const {
			return id_ + "_output.txt";
		}

	private:
		void showTitleBar() const {
			if (!title_.empty()) {
				std::string title = "【" + id_ + " " + title_ + "】";
#ifdef _UNICODE
				DWORD dBufSize = ::MultiByteToWideChar(CP_ACP, 0, title.c_str(), (int)title.length(), NULL, 0) + 1;
				wchar_t* dBuf = new wchar_t[dBufSize];
				memset(dBuf, 0, dBufSize * sizeof(wchar_t));
				if (::MultiByteToWideChar(CP_ACP, 0, title.c_str(), (int)title.length(), dBuf, dBufSize) > 0) {
					::SetConsoleTitle(dBuf);
				}
				delete[] dBuf;
#else
				::SetConsoleTitle(title.c_str());
#endif
			}
		}

		void showSummary() const {
			if (!summary_.empty()) {
				std::cout << summary_ << std::endl;
			}
		}

		void showInfo() const {
			if (errors_.empty()) {
				showTotalScore();
			}
			else {
				showError();
			}
		}

		void showError() const {
			if (!errors_.empty()) {
				printf("\n\n%14s", " ");
				printColorText(FOREGROUND_RED | FOREGROUND_INTENSITY, "『 按任意键查看错误信息 』");
				waitingPressAnyKey();
				const ErrorInfo& info = errors_[0];
				printColorText(FOREGROUND_GREEN | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE, "$ %s $\n\n", info.name.c_str());
				printColorText(FOREGROUND_GREEN, "  # 数据 #\n\n");
				printColorText(FOREGROUND_BLUE | FOREGROUND_INTENSITY, "%s", info.input.c_str());
				printColorText(FOREGROUND_GREEN, "\n\n  # 预期 #\n\n");
				printColorText(FOREGROUND_BLUE | FOREGROUND_INTENSITY, "%s", info.expect.c_str());
				printColorText(FOREGROUND_GREEN, "\n\n  # 结果 #\n\n");
				printColorText(FOREGROUND_RED | FOREGROUND_INTENSITY, "%s\n", info.output.c_str());
			}
		}

	private:
		void printColorText(WORD color, const char* format, ...) const {
			char* buffer = new char[10240];
			va_list args;
			va_start(args, format);
			HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
			::SetConsoleTextAttribute(handle, color);
			vsnprintf(buffer, 10240, format, args);
			printf(buffer);
			delete[] buffer;
			::SetConsoleTextAttribute(handle, defaultColorAttrs_);
			va_end(args);
		}

		void getDefaultColorAttrs() {
			CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
			::GetConsoleScreenBufferInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
			defaultColorAttrs_ = csbiInfo.wAttributes;
		}

	private:
		static void loadExamplesDirectory(const std::string& directory, std::vector<Example>& output) {
			std::vector<std::string> examples;
			if (loadExamplesFileList(directory, examples)) {
				for (std::size_t index = 0; index < examples.size(); ++index) {
					const std::string& name = examples[index];
					Example example;
					loadExampleFile(directory, name, example);
					output.push_back(example);
				}
			}
		}

		static bool loadExamplesFileList(const std::string& directory, std::vector<std::string>& list) {
			std::string filename = getCurrentDirectory() + "\\" + directory + "\\" + "examples.txt";
			std::ifstream ifs(filename.c_str());
			if (ifs.is_open()) {
				std::string line;
				while (ifs >> line) {
					list.push_back(line);
				}
				return true;
			}
			return false;
		}

		static void loadExampleFile(const std::string& directory, const std::string& name, Example& example) {
			std::string inputname = getCurrentDirectory() + "\\" + directory + "\\" + name + "_input.txt";
			std::ifstream input(inputname.c_str());
			if (input.is_open()) {
				std::stringstream buffer;
				buffer << input.rdbuf();
				example.input = buffer.str();
			}
			std::string expectname = getCurrentDirectory() + "\\" + directory + "\\" + name + "_expect.txt";
			std::ifstream expect(expectname.c_str());
			if (expect.is_open()) {
				std::stringstream buffer;
				buffer << expect.rdbuf();
				example.expect = buffer.str();
			}
		}

	private:
		void showTotalScore() const {
			printf("\n\n%14s", " ");
			printColorText(FOREGROUND_RED | FOREGROUND_INTENSITY, "『 按任意键查看总成绩 』");
			waitingPressAnyKey();
			printColorText(FOREGROUND_BLUE, "╔----------------------------------------------------╗\n");
			printf("%3s", " ");
			printColorText(FOREGROUND_GREEN | COMMON_LVB_UNDERSCORE | FOREGROUND_BLUE, " %-20s%-20s%s \n", "题目", "时间", "得分");
			std::vector<ScoreInfo> infolist;
			loadScore(infolist);
			unsigned int total = 0;
			for (std::size_t index = 0; index < infolist.size(); ++index) {
				const ScoreInfo& info = infolist[index];
				printColorText(FOREGROUND_BLUE | FOREGROUND_INTENSITY, "    %-20s", info.id.c_str());
				std::string time;
				formatTime(info.time, time);
				printf("%-20s", time.c_str());
				printColorText(FOREGROUND_GREEN, "%-20u\n", info.score);
				total += info.score;
			}
			printColorText(FOREGROUND_GREEN | FOREGROUND_INTENSITY, "\n%40s : %-5u 』\n", "『 总成绩", total);
			printColorText(FOREGROUND_BLUE, "╚----------------------------------------------------╝\n");
		}

		static void appendScore(const std::string& id, unsigned int score) {
			std::vector<ScoreInfo> infolist;
			loadScore(infolist);
			std::vector<ScoreInfo>::iterator position = infolist.end();
			for (std::vector<ScoreInfo>::iterator iter = infolist.begin(); iter != infolist.end(); ++iter) {
				if (iter->id == id) {
					position = iter;
					break;
				}
			}
			if (position == infolist.end()) {
				ScoreInfo info;
				info.id = id;
				info.score = score;
				info.time = (unsigned int)time(NULL);
				infolist.push_back(info);
			}
			else {
				if (position->score != score) {
					position->score = score;
					position->time = (unsigned int)time(NULL);
				}
			}
			saveScore(infolist);
		}

		static void loadScore(std::vector<ScoreInfo>& infolist) {
			std::ifstream input("score.db", std::ios::binary);
			if (input.is_open()) {
				Reader reader(input);
				unsigned int count;
				reader >> count;
				for (unsigned int index = 0; index < count; ++index) {
					ScoreInfo info;
					reader >> info.id;
					reader >> info.score;
					reader >> info.time;
					infolist.push_back(info);
				}
			}
		}

		static void saveScore(const std::vector<ScoreInfo>& infolist) {
			std::ofstream output("score.db", std::ios::binary);
			if (output.is_open()) {
				Writer writer(output);
				unsigned int count = (unsigned int)infolist.size();
				writer << count;
				for (unsigned int index = 0; index < count; ++index) {
					const ScoreInfo& info = infolist[index];
					writer << info.id;
					writer << info.score;
					writer << info.time;
				}
			}
		}

		static void formatTime(time_t tt, std::string& str) {
			struct tm* t;
			t = localtime(&tt);
			char buf[256] = { 0 };
			sprintf(buf, "%04d/%02d/%02d %02d:%02d", \
				t->tm_year + 1900,
				t->tm_mon + 1, \
				t->tm_mday, \
				t->tm_hour, \
				t->tm_min);
			str = buf;
		}

		static std::string getCurrentDirectory() {
			//std::string fullname = __FILE__;
			//std::size_t position = fullname.find_last_of("\\");
			//return fullname.substr(0, position);
			std::string directory = ".\\judge";
			return directory;
		}

		static void waitingPressAnyKey() {
			emptyStdin();
		}

		static void emptyStdin() {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

	private:
		std::string id_;
		std::string title_;
		std::string summary_;
		std::string input_;
		std::string expect_;
		std::string output_;
		ProcedureCall call_;
		std::vector<Example> examples_;
		std::vector<ErrorInfo> errors_;
		DWORD duration_;
		WORD defaultColorAttrs_;
	};

	class LooseJudge : public Judge {
	public:
		LooseJudge(const std::string& id, const std::string& title, const std::string& summary = "") {
			setID(id);
			setTitle(title);
			setSummary(summary);
		}

	private:
		virtual void build() {
			loadExamples();
		}

		virtual bool compare(const std::string& expect, const std::string& output) {
			std::vector<std::string> ev;
			std::vector<std::string> ov;
			extractLine(expect, ev);
			extractLine(output, ov);
			tidyLine(ev);
			tidyLine(ov);
			return compareList(ev, ov);
		}
	};

	class StrictJudge : public Judge {
	public:
		StrictJudge(const std::string& id, const std::string& title, const std::string& summary = "") {
			setID(id);
			setTitle(title);
			setSummary(summary);
		}

	private:
		virtual void build() {
			loadExamples();
		}

		virtual bool compare(const std::string& expect, const std::string& output) {
			std::vector<std::string> ev;
			std::vector<std::string> ov;
			extractLine(expect, ev);
			extractLine(output, ov);
			return compareList(ev, ov);
		}
	};

	class Launcher {
	public:
		Launcher(Judge& judge) {

			ProcedureCall call = judge.getVerify();
			if (!call) {
				call = entry;
			}
			judge.setCall(call);
			judge.run();
			exit(0);
		}

	private:
		static void entry() {
			main();
		}
	};
}

#endif

#endif
