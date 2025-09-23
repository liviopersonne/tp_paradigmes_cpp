#ifndef media_h
#define media_h

#include <string>
#include <iostream>

class Media
{
private:
    std::string filePath{};
    std::string name{};

public:
    Media(std::string filePath, std::string name) : filePath(filePath), name(name) {}
    Media() {}
    virtual ~Media() {}
    std::string getFilePath() const { return filePath; }
    std::string getName() const { return name; }
    void setFilePath(std::string p) { filePath = p; }
    void setName(std::string n) { name = n; }

    // Operator redefinition to print an instance
    friend std::ostream &operator<<(std::ostream &os, const Media &media)
    {
        return media.print(os);
    };
    virtual std::ostream &print(std::ostream &os) const;
    virtual void play() const = 0;
};

#endif