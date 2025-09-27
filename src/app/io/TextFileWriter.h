// TextFileWriter.h
#pragma once
#include "IFileWriter.h"

class TextFileWriter : public IFileWriter {
public:
    void overwrite(const std::string & path, const std::vector<std::string> & lines) override; // komentarz: implementacja TXT
};
