#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "core/screen.h"

class GameScreen: public Screen
{
public:
    GameScreen();
    ~GameScreen();

    void resize(int width, int height) override;
    void render() override;
    void update() override;
};

#endif // GAMESCREEN_H
