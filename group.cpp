#include "group.h"

void Group::print(std::ostream &os) const
{
    const std::string lineTab = "\n\t";
    os << "Group<" << this->getName() << ">[";
    for (const MediaPtr &e : *this)
    {
        os << lineTab << *e;
    }

    os << "\n]" << std::endl;
};