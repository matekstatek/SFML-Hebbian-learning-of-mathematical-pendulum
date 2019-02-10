#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "hebbian_learning.hpp"

int main(int, char const**)
{
    Hebb *hebbian_learning = new Hebb();

    int ii = 0;
    double x = 0;
    double y = 300;
    double y_trained = 300;
    bool turn_around = false;
    
    sf::RenderWindow window(sf::VideoMode(640, 600), "Wahadlo matematyczne");
    sf::CircleShape shape(10);
    sf::CircleShape trained_shape(10);
    sf::RectangleShape rect;
    sf::VertexArray lines(sf::LinesStrip, 2);
    sf::VertexArray trained_lines(sf::LinesStrip, 2);
    
    lines[0].color = sf::Color::Black;
    lines[1].color = sf::Color::Black;
    trained_lines[0].color = sf::Color::Black;
    trained_lines[1].color = sf::Color::Black;
    
    rect.setSize(sf::Vector2f(100, 10));
    rect.setPosition(270, 100);
    rect.setFillColor(sf::Color(sf::Color::Red));
    
    shape.setFillColor(sf::Color(150,50,250));
    shape.setPosition(x,y);
    
    trained_shape.setFillColor(sf::Color(sf::Color::Blue));
    trained_shape.setPosition(x, y);
    
    while (window.isOpen())
    {
        lines[0].position = sf::Vector2f(320, 110);
        lines[1].position = sf::Vector2f(x+10, y+10);
        
        trained_lines[0].position = sf::Vector2f(320, 110);
        trained_lines[1].position = sf::Vector2f(x+10, y_trained+10);
        
        
        y = (abs(hebbian_learning->f(x/400)*50));
        //y_trained = (100*hebbian_learning->w[ii]);
        y_trained = 100*hebbian_learning->wx(ii);
        
        y *= 1.5;
        y_trained *= 1.5;
        
        y += 300;
        y_trained += 300;
        
        
        shape.setPosition(x, y);
        trained_shape.setPosition(x, y_trained);
        
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        
        window.clear(sf::Color::White);
        
        window.draw(rect);
        window.draw(shape);
        window.draw(trained_shape);
        window.draw(lines);
        window.draw(trained_lines);

        window.display();
        
        sf::sleep(sf::milliseconds(20));
        
        if(ii >= N - 2) turn_around = false;
        if(ii <= 2) turn_around = true;
        if(turn_around) {
            ii+=2;
            x+=8;
        }
        else {
            ii -= 2;
            x-=8;
        }
    }

    return EXIT_SUCCESS;
}
