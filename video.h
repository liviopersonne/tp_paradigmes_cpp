#ifndef video_h
#define video_h

#include "media.h"

class Video : public Media
{
private:
    unsigned int duration{};

public:
    Video(const std::string filePath, const std::string name, const unsigned int duration) : Media(filePath, name), duration(duration) {}
    Video() {}
    virtual ~Video() {}
    unsigned int getDuration() const { return duration; }
    void setDuration(const unsigned int d) { duration = d; }
    std::ostream &print(std::ostream &os) const override
    {
        os << "Video<name:" << getName() << ", path:" << getFilePath()
           << ", duration:" << duration << ">";
        return os;
    };

    void play() const
    {
        system(("vlc " + getFilePath() + " &").data());
    }
};

#endif