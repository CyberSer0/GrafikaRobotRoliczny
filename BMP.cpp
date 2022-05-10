#include "BMP.h"

BMP::BMP(const char* FilePath)
{
    
}


std::vector<std::uint8_t> BMP::GetPixels() const 
{ 
    return this->Pixels; 
}



std::uint32_t BMP::GetWidth() const 
{ 
    return this->width; 
}

std::uint32_t BMP::GetHeight() const 
{ 
    return this->height; 
}

bool BMP::HasAlphaChannel() 
{ 
    return BitsPerPixel == 32; 
}
