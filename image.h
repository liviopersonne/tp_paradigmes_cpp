#ifndef image_h
#define image_h

#include "media.h"

class Image : public Media
{
private:
    int width{};
    int height{};

public:
    Image(std::string filePath, std::string name, int width, int height) : Media(filePath, name), width(width), height(height) {}
    Image() {}
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    std::ostream &print(std::ostream &os) const override;

    void play() const
    {
        system(("gwenview " + getFilePath() + " &").data());
    }
};

#endif