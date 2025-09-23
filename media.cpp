#include "media.h"

std::ostream &operator<<(std::ostream &os, const Media &media)
{
    os << "Media<name:" << media.getName() << ", path:" << media.getFilePath() << ">";
    return os;
}
