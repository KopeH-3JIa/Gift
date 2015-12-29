#include "application.h"
#include <iostream>
#include <thread>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "screen.h"

namespace{
    StringArray     g_ApplicationArgs;
    SDL_Window*     g_Window;
    SDL_GLContext   g_Context;
    int             g_Width = 800;
    int             g_Height = 600;
    Screen*         g_Screen;
    int             g_ExitCode = 0;
    bool            g_Running = false;
}

Application::Application(){

}

Application &Application::instance(){
    static Application a;
    return a;
}

Application::~Application(){

}

Application &Application::setArguments(const StringArray &args){
    g_ApplicationArgs = args;
    return (*this);
}

StringArray Application::arguments() const{
    return g_ApplicationArgs;
}

void Application::_initialize(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER , 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE     , 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE   , 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE    , 8);
    g_Window = SDL_CreateWindow("Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, g_Width, g_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    g_Context = SDL_GL_CreateContext(g_Window);
}

void Application::_render(){
    if(g_Screen){
        g_Screen->render();
    }
}

void Application::_finalize(){
    SDL_GL_DeleteContext(g_Context);
    SDL_Quit();
}

void Application::_update(){
    if(g_Screen){
        g_Screen->update();
    }
}

void Application::_resize(int w, int h){
    g_Width     = w;
    g_Height    = h;
    if(g_Screen)
        g_Screen->resize(w, h);
}

void Application::setScreen(Screen *screen){
    g_Screen = screen;
}

int Application::run(Screen *screen){
    setScreen(screen);
    if(g_Running)
        throw std::runtime_error("Application must be run once!");
    g_Running = true;

    _initialize();

    std::thread([&](){
        SDL_Event event;
        while(g_Running){
            while(SDL_PollEvent(&event)){
                switch(event.type){
                case SDL_QUIT:
                    Application::instance().exit();
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            Application::instance().exit();
                        break;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                        this->_resize(event.window.data1, event.window.data2);
                    }
                    break;
                }
            }
        }
    }).detach();


    while (g_Running) {
        if(g_Screen)
            g_Screen->render();
        SDL_GL_SwapWindow(g_Window);
    }


    _finalize();
    return g_ExitCode;
}

void Application::exit(int code){
    g_ExitCode  = code;
    g_Running   = false;
}


