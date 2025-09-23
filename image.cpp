#include "image.h"

std::ostream &Image::print(std::ostream &os) const
{
    os << "Image<name:" << getName() << ", path:" << getFilePath()
       << ", width:" << width << ", height:" << height << ">";
    return os;
}
