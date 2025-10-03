#include "media_manager.h"

template <typename T>
void warnIfFoundInTable(std::map<std::string, T> table, std::string name)
{
    if (table.find(name) != table.end())
    {
        std::cout << "Warning: Element '" << name << "' already exsists in table" << std::endl;
    }
}

std::shared_ptr<Image> MediaManager::createImage(const std::string filePath, const std::string name, const int width, const int height)
{
    std::shared_ptr<Image> img(new Image(filePath, name, width, height));
    warnIfFoundInTable(mediaTable, name);
    mediaTable[name] = img;
    return img;
}

std::shared_ptr<Video> MediaManager::createVideo(const std::string filePath, const std::string name, const unsigned int duration)
{
    std::shared_ptr<Video> video(new Video(filePath, name, duration));
    warnIfFoundInTable(mediaTable, name);
    mediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> MediaManager::createFilm(const std::string filePath, const std::string name, const int duration, const unsigned int chapterCount, unsigned int *const chapters)
{
    std::shared_ptr<Film> film(new Film(filePath, name, duration, chapterCount, chapters));
    warnIfFoundInTable(mediaTable, name);
    mediaTable[name] = film;
    return film;
}

GroupPtr MediaManager::createGroup(const std::string name)
{
    std::shared_ptr<Group> group(new Group(name));
    warnIfFoundInTable(groupTable, name);
    groupTable[name] = group;
    return group;
}

bool MediaManager::searchMedia(const std::string searchedName) const
{
    auto elem = mediaTable.find(searchedName);
    if (elem == mediaTable.end())
    {
        std::cout << "Warning: Media '" << searchedName << "' not found in table" << std::endl;
        return false;
    }
    else
    {
        std::cout << *elem->second << std::endl;
        return true;
    }
}

bool MediaManager::searchGroup(const std::string searchedName) const
{
    auto elem = groupTable.find(searchedName);
    if (elem == groupTable.end())
    {
        std::cout << "Warning: Group '" << searchedName << "' not found in table" << std::endl;
        return false;
    }
    else
    {
        std::cout << *elem->second << std::endl;
        return true;
    }
}

bool MediaManager::playMedia(const std::string mediaName) const
{
    auto elem = mediaTable.find(mediaName);
    if (elem == mediaTable.end())
    {
        std::cout << "Warning: Media '" << mediaName << "' not found in table" << std::endl;
        return false;
    }
    else
    {
        elem->second->play();
        return true;
    }
}

bool MediaManager::deleteGroup(const std::string groupName)
{
    auto elem = groupTable.find(groupName);
    if (elem == groupTable.end())
    {
        std::cout << "Warning: Group '" << groupName << "' not found in table" << std::endl;
        return false;
    }
    else
    {
        groupTable.erase(groupName);
        return true;
    }
}

bool MediaManager::deleteMedia(const std::string mediaName)
{
    auto elem = mediaTable.find(mediaName);
    if (elem == mediaTable.end())
    {
        std::cout << "Warning: Media '" << mediaName << "' not found in table" << std::endl;
        return false;
    }
    else
    {
        // Remove the media from all the groups it's in
        for (auto groupElem = groupTable.begin(); groupElem != groupTable.end(); groupElem++)
        {
            GroupPtr currentGroup = groupElem->second;
            for (auto mediaElem = currentGroup->begin(); mediaElem != currentGroup->end(); mediaElem++)
            {
                MediaPtr currentMedia = *mediaElem;
                if (currentMedia->getName() == mediaName)
                {
                    currentGroup->remove(currentMedia);
                    break;
                }
            }
        }

        mediaTable.erase(mediaName);
        return true;
    }
}