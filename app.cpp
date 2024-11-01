#include "app.hpp"

App::App(){
    app.create(sf::VideoMode(800, 600), "Age Calculator");
    running = app.isOpen() ? true : false;
    menuScene.app = &app;
}

App::~App(){

}


void App::Run(){

    while(running){
        handleInput();
        Render();
    }
}

void App::Close(){
    app.close();
}



void App::Render(){
    app.clear(sf::Color::White);
    menuScene.Render();
    app.display();
}

void App::handleInput(){
    sf::Event event;

    while(app.pollEvent(event)){
        menuScene.handleInput(event);

        switch(event.type){
            case sf::Event::Closed:
                running = false;
                break;
            default:
                break;
        }
    }
}
