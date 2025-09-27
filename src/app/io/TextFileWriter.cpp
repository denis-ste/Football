#include "TextFileWriter.h"
#include <fstream>
#include <stdexcept>

void TextFileWriter::overwrite(const std::string & path, const std::vector<std::string> & lines) {
    std::ofstream out(path, std::ios::trunc); // komentarz: nadpisanie
    if (!out) {
        throw std::runtime_error("Nie mogę otworzyć pliku do zapisu: " + path);
    } // komentarz: jasny błąd
    for (const auto & s : lines) {
        out << s << '\n';
    } // komentarz: linia po linii
}

