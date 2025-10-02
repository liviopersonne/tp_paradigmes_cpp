#include "group.h"

Group::Group(const std::string &name, unsigned int mediaCount, Media **medias) : name(name)
{
    for (unsigned int i = 0; i < mediaCount; i++)
    {
        this->push_back(medias[i]);
    }
};

std::ostream &Group::print(std::ostream &os) const
{
    const std::string lineTab = "\n\t";
    os << "Group[";
    for (const Media *e : *this)
    {
        os << lineTab << *e;
    }

    os << "\n]" << std::endl;
    return os;
};