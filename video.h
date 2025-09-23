#ifndef video_h
#define video_h

#include "media.h"

class Video : public Media
{
private:
    int duration{};

public:
    Video(std::string filePath, std::string name, int duration) : Media(filePath, name), duration(duration) {}
    Video() {}
    int getDuration() const { return duration; }
    void setDuration(int d) { duration = d; }
    std::ostream &print(std::ostream &os) const override;

    void play() const
    {
        system(("vlc " + getFilePath() + " &").data());
    }
};

#endif