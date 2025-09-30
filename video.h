#ifndef video_h
#define video_h

#include "media.h"

class Video : public Media
{
private:
    int duration{};

public:
    Video(const std::string filePath, const std::string name, const int duration) : Media(filePath, name), duration(duration) {}
    Video() {}
    int getDuration() const { return duration; }
    void setDuration(const int d) { duration = d; }
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