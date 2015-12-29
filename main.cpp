#include "core/application.h"
#include "screens/gamescreen.h"

int main(int argc, char **argv){
    Application &a = Application::instance();
    a.setArguments({argv, argv + argc});

    GameScreen gamescreen;

    return a.run(&gamescreen);
}
