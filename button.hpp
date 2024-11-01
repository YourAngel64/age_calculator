#ifndef BUTTON
#define BUTTON

#include "main.hpp"

/*
STEPS TO CREATE A BUTTON:

*/

class MyButton{
    public:
        template<typename Func, typename ...args>
        void createButton(sf::Vector2f size, sf::Color color, Func function, args... Args);
        void setButtonPosition(sf::Vector2f position);
        void setButtonText(std::string_view text, sf::Color color);
        void drawButton(sf::RenderWindow *app);


        sf::Font font;
        sf::RenderWindow *app;
        std::any results;

    private:
        sf::RectangleShape button;
        sf::Vector2f buttonPosition;
        sf::Text buttonText;

        template<typename Func, typename ...args>
        void onClick(sf::RenderWindow *app, Func function, args... Args);
};

//template functions on header file cause they are cry babies:

template<typename Func, typename ...args>
void MyButton::createButton(sf::Vector2f size, sf::Color color, Func function, args... Args){
    button = sf::RectangleShape(size);
    button.setFillColor(color);
    
    //onClick Function
    onClick(app, function, Args...);
}


template<typename Func, typename ...args>
void MyButton::onClick(sf::RenderWindow *app, Func function ,args... Args){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::Vector2f mouse = app->mapPixelToCoords(sf::Mouse::getPosition(*app));
        sf::FloatRect bound = button.getGlobalBounds();

        if(bound.contains(mouse)){
            results = function(Args...);
            std::string results_string = std::any_cast<std::string>(results);
            cout << "Results: " << results_string << endl;
        }
    }
}



#endif