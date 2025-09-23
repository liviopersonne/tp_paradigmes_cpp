#include "media.h"

std::ostream &Media::print(std::ostream &os) const
{
    os << "Media<name:" << this->getName() << ", path:" << this->getFilePath() << ">";
    return os;
}
