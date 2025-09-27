// IFileWriter.h
#pragma once
#include <string>
#include <vector>

class IFileWriter {
public:
    virtual ~IFileWriter() = default; // komentarz: interfejs zapisu
    virtual void overwrite(const std::string & path, const std::vector<std::string> & lines) = 0; // komentarz: nadpisanie pliku
};
