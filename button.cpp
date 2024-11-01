#include "button.hpp"

void MyButton::setButtonPosition(sf::Vector2f position){
    buttonPosition = position;
    button.move(position);
}

void MyButton::setButtonText(std::string_view text, sf::Color color){
    buttonText.setFont(font);
    buttonText.setString(static_cast<std::string>(text));
    buttonText.setCharacterSize(12);
    buttonText.setFillColor(color);
    buttonText.move(sf::Vector2f(buttonPosition.x + 40.f, buttonPosition.y + 50.f));
}

void MyButton::drawButton(sf::RenderWindow *app){
    app->draw(button);
    app->draw(buttonText);
}