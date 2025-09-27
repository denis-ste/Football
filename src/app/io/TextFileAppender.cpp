// TextFileAppender.cpp
#include "TextFileAppender.h"
#include <fstream>
#include <stdexcept>
void TextFileAppender::appendLine(const std::string & path, const std::string & line) {
    std::ofstream out(path, std::ios::app); // komentarz: dopisywanie
    if (!out) {
        throw std::runtime_error("Nie mogę otworzyć pliku do dopisania: " + path);
    } // komentarz: jasny błąd
    out << line << '\n'; // komentarz: dopisz
}
