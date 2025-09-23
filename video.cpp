#include "video.h"

std::ostream &Video::print(std::ostream &os) const
{
    os << "Video<name:" << getName() << ", path:" << getFilePath()
       << ", duration:" << duration << ">";
    return os;
}