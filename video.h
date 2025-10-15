#ifndef video_h
#define video_h

#include "media.h"

class MediaManager;

class Video : public Media
{
    friend class MediaManager;

private:
    unsigned int duration{};

protected:
    Video(const std::string &filePath, const std::string &name, const unsigned int duration) : Media(filePath, name), duration(duration) {}
    Video() {}

public:
    std::string classname() const override { return "Video"; }
    virtual ~Video() { std::cout << "Destruction of video" << std::endl; }
    unsigned int getDuration() const { return duration; }
    void setDuration(const unsigned int d) { duration = d; }
    void print(std::ostream &os) const override
    {
        os << "Video<name:" << getName() << ", path:" << getFilePath()
           << ", duration:" << duration << ">";
    };

    void play() const
    {
        system(("vlc " + getFilePath() + " &").data());
    }
    virtual void write(std::ostream &f) override
    {
        Media::write(f);
        f << duration << '\n';
    }
    virtual void read(std::istream &f) override
    {
        Media::read(f);
        f >> duration;
    }
};

#endif