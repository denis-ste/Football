#pragma once

class APilkarz;
class IZagranie {
public:
    virtual ~IZagranie() = default;
    virtual int buildStaminaCost() = 0;
    virtual int getStaminaCost() const = 0;
};

