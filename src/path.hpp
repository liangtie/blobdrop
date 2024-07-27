#pragma once

#include <QUrl>
#include <filesystem>
#include <iostream>

class Path {
public:
	Path(const std::string &p);
	std::filesystem::path path;
	bool used = false;
	QUrl thumbnail;
	bool exists = false;
	std::string iconName;
	bool multiselect = false;

	std::string get_uri() const;
	QUrl get_url() const;
	std::string pretty_print() const;
	bool open() const;
};
