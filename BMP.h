#pragma once
#include <stdio.h>
#include "stb_image.h"
#include <vector>

class BMP
{
private:
    std::uint32_t width, height;
    std::uint16_t BitsPerPixel;
    std::vector<std::uint8_t> Pixels;

public:
    BMP(const char* FilePath);
    std::vector<std::uint8_t> GetPixels() const;
    std::uint32_t GetWidth() const;
    std::uint32_t GetHeight() const;
    bool HasAlphaChannel();
};

