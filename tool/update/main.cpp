#include <io.h>
#include <cstring>
#include <iostream>
#include <string>

typedef void (*CallFile)(_finddata_t*);

void traverseFile(const std::string& path, CallFile call) {
	_finddata_t fdata;
	long handle = _findfirst((path + "*.*").c_str(), &fdata);
	if (handle != -1) {
		do {
			call(&fdata);
		} while (_findnext(handle, &fdata) == 0);
		_findclose(handle);
	}
}

void copyFile(_finddata_t* fdata) {
	if (strcmp(fdata->name, ".") != 0 && strcmp(fdata->name, "..")) {
		std::cout << fdata->name << std::endl;
	}
}

int main()
{
	traverseFile("../../", copyFile);
	
	return 0;
}
