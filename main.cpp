#include <SFML/Graphics.hpp>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#define WIDTH 1200
#define HEIGHT 800

int main() {
    // create window
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Window",
            sf::Style::Titlebar);
    win.setPosition(sf::Vector2i(100, 100));
    win.setVerticalSyncEnabled(true);

    // initialization
    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Green);

    while (win.isOpen()) {
        // event handling
        sf::Event ev;
        while (win.pollEvent(ev)) {
            switch(ev.type) {
                case sf::Event::Closed:
                    win.close();
                    break;
                case sf::Event::KeyPressed:
                    cout << ev.key.code << endl;
                    break;
                default:
                    break;

            }
        }
        // rendering
        win.clear();
        win.draw(shape);
        win.display();
    }
    return 0;
}
