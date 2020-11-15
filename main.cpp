#include <SFML/Graphics.hpp>
using sf::Event;
using sf::Color;
using sf::Vector2u;
using sf::Vector2i;
using sf::Vector2f;

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
    win.setPosition(Vector2i(100, 100));
    win.setVerticalSyncEnabled(true);

    // initialization
    sf::CircleShape shape(100.0f);
    shape.setFillColor(Color::Green);

    while (win.isOpen()) {
        // event handling
        Event ev;
        while (win.pollEvent(ev)) {
            switch(ev.type) {
                case Event::Closed:
                    win.close();
                    break;
                case Event::KeyPressed:
                    if (ev.text.unicode < 128) // if in valid unicode range
                        cout << static_cast<char>(ev.text.unicode) << endl;
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
