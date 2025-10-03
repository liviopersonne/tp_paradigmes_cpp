#ifndef media_manager_h
#define media_manager_h

#include <map>
#include <string>
#include <sstream>
#include "media.h"
#include "group.h"
#include "image.h"
#include "video.h"
#include "film.h"

typedef std::shared_ptr<Group> GroupPtr;

class MediaManager
{
private:
    std::map<std::string, MediaPtr> mediaTable{};
    std::map<std::string, GroupPtr> groupTable{};

public:
    MediaManager() {};
    virtual ~MediaManager() {}
    std::shared_ptr<Image> createImage(const std::string filePath, const std::string name, const int width, const int height, std::stringstream &os);
    std::shared_ptr<Video> createVideo(const std::string filePath, const std::string name, const unsigned int duration, std::stringstream &os);
    std::shared_ptr<Film> createFilm(const std::string filePath, const std::string name, const int duration, const unsigned int chapterCount, unsigned int *const chapters, std::stringstream &os);
    GroupPtr createGroup(const std::string name, std::stringstream &os);
    bool searchMedia(const std::string searchedName, std::stringstream &os) const;
    bool searchGroup(const std::string searchedName, std::stringstream &os) const;
    bool playMedia(const std::string mediaName, std::stringstream &os) const;
    bool deleteGroup(const std::string groupName, std::stringstream &os);
    bool deleteMedia(const std::string mediaName, std::stringstream &os);
};

#endif