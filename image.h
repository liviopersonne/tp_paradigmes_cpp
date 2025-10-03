#ifndef image_h
#define image_h

#include "media.h"

class MediaManager;

class Image : public Media
{
    friend class MediaManager;

private:
    int width{};
    int height{};

protected:
    Image(const std::string filePath, const std::string name, const int width, const int height) : Media(filePath, name), width(width), height(height) {}
    Image() {}

public:
    virtual ~Image() { std::cout << "Destruction of image" << std::endl; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    std::ostream &print(std::ostream &os) const override
    {
        os << "Image<name:" << getName() << ", path:" << getFilePath()
           << ", width:" << width << ", height:" << height << ">";
        return os;
    };

    void play() const
    {
        system(("gwenview " + getFilePath() + " &").data());
    }
};

#endif