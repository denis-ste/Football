#pragma once
#include <string>

// komentarz: dopisywanie linii na końcu pliku (Journal)
class IFileAppender {
public:
    virtual ~IFileAppender() = default; // komentarz: interfejs
    virtual void appendLine(const std::string & path, const std::string & line) = 0; // komentarz: dopisz jedną linię
};
