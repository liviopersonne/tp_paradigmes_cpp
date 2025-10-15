#include "media_manager.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>

template <typename T>
void warnIfFoundInTable(std::map<std::string, T> table, std::string name, std::stringstream &os)
{
    if (table.find(name) != table.end())
    {
        os << "Warning: Element '" << name << "' already exsists in table";
    }
}

std::shared_ptr<Image> MediaManager::createImage(const std::string &filePath, const std::string &name, const int width, const int height, std::stringstream &os)
{
    std::shared_ptr<Image> img(new Image(filePath, name, width, height));
    warnIfFoundInTable(mediaTable, name, os);
    mediaTable[name] = img;
    return img;
}

std::shared_ptr<Video> MediaManager::createVideo(const std::string &filePath, const std::string &name, const unsigned int duration, std::stringstream &os)
{
    std::shared_ptr<Video> video(new Video(filePath, name, duration));
    warnIfFoundInTable(mediaTable, name, os);
    mediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> MediaManager::createFilm(const std::string &filePath, const std::string &name, const int duration, const unsigned int chapterCount, unsigned int *const chapters, std::stringstream &os)
{
    std::shared_ptr<Film> film(new Film(filePath, name, duration, chapterCount, chapters));
    warnIfFoundInTable(mediaTable, name, os);
    mediaTable[name] = film;
    return film;
}

GroupPtr MediaManager::createGroup(const std::string &name, std::stringstream &os)
{
    std::shared_ptr<Group> group(new Group(name));
    warnIfFoundInTable(groupTable, name, os);
    groupTable[name] = group;
    return group;
}

bool MediaManager::searchMedia(const std::string &searchedName, std::stringstream &os) const
{
    auto elem = mediaTable.find(searchedName);
    if (elem == mediaTable.end())
    {
        os << "Warning: Media '" << searchedName << "' not found in table";
        return false;
    }
    else
    {
        os << *elem->second;
        return true;
    }
}

bool MediaManager::searchGroup(const std::string &searchedName, std::stringstream &os) const
{
    auto elem = groupTable.find(searchedName);
    if (elem == groupTable.end())
    {
        os << "Warning: Group '" << searchedName << "' not found in table";
        return false;
    }
    else
    {
        os << *elem->second;
        return true;
    }
}

bool MediaManager::playMedia(const std::string &mediaName, std::stringstream &os) const
{
    auto elem = mediaTable.find(mediaName);
    if (elem == mediaTable.end())
    {
        os << "Warning: Media '" << mediaName << "' not found in table";
        return false;
    }
    else
    {
        elem->second->play();
        return true;
    }
}

bool MediaManager::deleteGroup(const std::string &groupName, std::stringstream &os)
{
    auto elem = groupTable.find(groupName);
    if (elem == groupTable.end())
    {
        os << "Warning: Group '" << groupName << "' not found in table";
        return false;
    }
    else
    {
        groupTable.erase(groupName);
        return true;
    }
}

bool MediaManager::deleteMedia(const std::string &mediaName, std::stringstream &os)
{
    auto elem = mediaTable.find(mediaName);
    if (elem == mediaTable.end())
    {
        os << "Warning: Media '" << mediaName << "' not found in table";
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

std::shared_ptr<Media> MediaManager::createMedia(const std::string &className)
{
    if (className == "Image")
    {
        return std::shared_ptr<Image>(new Image());
    }
    else if (className == "Video")
    {
        return std::shared_ptr<Video>(new Video());
    }
    else if (className == "Film")
    {
        return std::shared_ptr<Film>(new Film());
    }
    return nullptr;
};

bool MediaManager::readFile(const std::string &filename, std::stringstream &os)
{
    std::ifstream f(filename);
    if (!f)
    {
        os << "Can't open file " << filename;
        return false;
    }

    mediaTable.clear();
    groupTable.clear();

    while (f)
    {
        std::string classname;
        getline(f, classname);
        if (classname == "")
            break;
        std::shared_ptr<Media> media(createMedia(classname));
        if (!media)
        {
            os << "Invalid classname: '" << classname;
            return false;
        }
        media->read(f);
        if (f.fail())
        {
            os << "Read error in " << filename;
            return false;
        }
        else
        {
            warnIfFoundInTable(mediaTable, media->name, os);
            mediaTable[media->name] = media;
        }
        // Buffer a line here to move onto the next object
        std::string buffer;
        getline(f, buffer);
    }
    f.close();
    os << "File loaded successfully !";
    return true;
}

bool MediaManager::writeFile(const std::string &filename, std::stringstream &os)
{
    std::ofstream f(filename);
    if (!f)
    {
        os << "Can't open file " << filename;
        return false;
    }

    for (auto &it : mediaTable)
    {
        MediaPtr media = it.second;
        f << media->classname() << '\n';
        media->write(f);
        if (f.fail())
        {
            os << "Write error in " << filename;
            return false;
        }
    }
    f.close();
    os << "File saved successfully !";
    return true;
}