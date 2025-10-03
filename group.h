#ifndef group_h
#define group_h

#include <list>
#include <string>
#include <memory>
#include "media.h"

class MediaManager;

typedef std::shared_ptr<Media> MediaPtr;

class Group : public std::list<MediaPtr>
{
    friend class MediaManager;

private:
    std::string name{};

protected:
    Group() {}
    Group(const std::string name) : name(name) {}

public:
    virtual ~Group() {}
    std::string getName() const { return name; }
    friend std::ostream &operator<<(std::ostream &os, const Group &group)
    {
        return group.print(os);
    };
    std::ostream &print(std::ostream &os) const;
};

#endif