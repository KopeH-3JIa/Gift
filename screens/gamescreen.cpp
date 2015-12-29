#include "gamescreen.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

GameScreen::GameScreen(){
}

GameScreen::~GameScreen(){    
}


void GameScreen::render(){
}


void GameScreen::update(){

}


void GameScreen::resize(int width, int height){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) width / (float) height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

    std::cout << "Window resize : " << width << " " << height << std::endl;
}
