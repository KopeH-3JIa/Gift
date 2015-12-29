#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>
#include "global.hpp"

using StringArray = std::vector<std::string>;

class Screen;

class Application
{
public:
    static Application& instance();
    ~Application();

    Application&        setArguments(const StringArray& args);
    StringArray         arguments() const;



    void setScreen(Screen *screen);

    int run(Screen *screen = nullptr);

    void exit(int code = 0);


private:
    void _initialize();
    void _render();
    void _finalize();
    void _update();
    void _resize(int w, int h);

    Application();
    Application(const Application&) = delete;
    void operator =(const Application&) = delete;
    Application(const Application&&) = delete;
    void operator =(const Application&&) = delete;
};

#endif // APPLICATION_H
