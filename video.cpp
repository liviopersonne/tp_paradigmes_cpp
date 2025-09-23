#include "video.h"

std::ostream &operator<<(std::ostream &os, const Video &video)
{
    os << "Video<name:" << video.getName() << ", path:" << video.getFilePath()
       << ", duration:" << video.duration << ">";
    return os;
}