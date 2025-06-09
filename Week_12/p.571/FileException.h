#pragma once
#include <string>

struct FileException {
    std::string filename;
    bool bRead;
    FileException(std::string name, bool b) : filename(name), bRead(b) {}
};