#ifndef group_h
#define group_h

#include <list>
#include <string>
#include "media.h"

typedef std::shared_ptr<Media> MediaPtr;

class Group : public std::list<MediaPtr>
{
private:
    std::string name{};

public:
    Group() {}
    Group(const std::string name) : name(name) {}
    virtual ~Group() {}
    std::string getName() const { return name; }
    friend std::ostream &operator<<(std::ostream &os, const Group &group)
    {
        return group.print(os);
    };
    std::ostream &print(std::ostream &os) const;
};

#endif