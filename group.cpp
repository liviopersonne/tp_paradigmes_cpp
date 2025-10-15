#include "group.h"

void Group::print(std::ostream &os) const
{
    os << "Group<" << this->getName() << ">[";
    for (const MediaPtr &e : *this)
    {
        os << *e << ", ";
    }
    if (this->size() > 0)
        os << "\b\b";
    os << "]";
};

void Group::write(std::ostream &f)
{
    for (auto &it : *this)
    {
        f << it->getName() << std::endl;
    }
    f << "---" << std::endl;
}
void Group::read(std::istream &f, std::map<std::string, MediaPtr> mediaTable)
{
    std::string line;
    getline(f, line);

    while (line != "---")
    {
        auto elem = mediaTable.find(line);
        if (elem != mediaTable.end())
        {
            this->push_back(elem->second);
        }
        getline(f, line);
    }
}