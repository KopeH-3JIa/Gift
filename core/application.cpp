#include "application.h"
#include <iostream>

namespace{
    StringArray g_ApplicationArgs;
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

int Application::run(){
    return 0;
}

