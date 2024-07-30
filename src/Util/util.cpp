#include "util.hpp"

#include <QGuiApplication>
#include <cstdlib>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef Q_OS_UNIX
#include <pwd.h>
#endif

namespace Util {

const char *home_dir() {
	static const char *result = nullptr;
	if (!result) {
		result = getenv("HOME");
#ifdef Q_OS_UNIX
		if (!result) {
			result = getpwuid(getuid())->pw_dir;
		}
#endif
	}

	return result;
}

std::string pwd() {
	static std::string result;
	if (result.empty()) {
		result = std::filesystem::current_path().string();
	}
	return result;
}
}
