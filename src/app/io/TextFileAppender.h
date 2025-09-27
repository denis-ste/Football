// TextFileAppender.h
#pragma once
#include "IFileAppender.h"

class TextFileAppender : public IFileAppender {
public:
    void appendLine(const std::string & path, const std::string & line) override; // komentarz: implementacja
};
