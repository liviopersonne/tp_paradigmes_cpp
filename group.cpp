#include "group.h"

std::ostream &Group::print(std::ostream &os) const
{
    const std::string lineTab = "\n\t";
    os << "Group[";
    for (const MediaPtr &e : *this)
    {
        os << lineTab << *e;
    }

    os << "\n]" << std::endl;
    return os;
};