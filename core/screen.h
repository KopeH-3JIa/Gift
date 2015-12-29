#ifndef SCREEN_H
#define SCREEN_H


class Screen
{
public:
    Screen();
    ~Screen();

    virtual void resize(int width, int height){}

    virtual void render(){}

    virtual void update(){}

};

#endif // SCREEN_H
