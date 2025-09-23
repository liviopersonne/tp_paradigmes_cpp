#include "image.h"

std::ostream &operator<<(std::ostream &os, const Image &image)
{
    os << "Image<name:" << image.getName() << ", path:" << image.getFilePath()
       << ", width:" << image.width << ", height:" << image.height << ">";
    return os;
}
