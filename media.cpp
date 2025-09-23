#include "media.h"

std::ostream &operator<<(std::ostream &os, const Media &media)
{
    os << "Media<name: " << media.name << ", path: " << media.filePath << ">";
    return os;
}