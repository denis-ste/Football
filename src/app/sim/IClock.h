// IClock.h
#pragma once

class IClock {
public:
    virtual ~IClock() = default; // komentarz: interfejs
    virtual void sleepMs(int ms) = 0; // komentarz: uśpij na ms
};
