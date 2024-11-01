#ifndef APP
#define APP

#include "main.hpp"

class App{
    public:
        App();
        ~App();
        void Run();
        void Close();
        bool isRunning(){return running;}


    private:
        Menu menuScene;
        void Render();
        void handleInput();
        bool running{false};
        sf::RenderWindow app;

};

#endif