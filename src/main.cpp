#define WIDTH 1200
#define HEIGHT 800

#define RADIUS 20.0
#define MOVESPEED 20.0
#define OMOVESPEED 5.0

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

using sf::Vector2u;
using sf::Vector2i;
using sf::Vector2f;
using sf::Color;
using sf::Event;
using sf::Keyboard;
using sf::CircleShape;

using std::string;
using std::unordered_map;

int main() {
    // settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // create window
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Window",
            sf::Style::Titlebar, settings);
    win.setPosition(Vector2i(100, 100));
    //win.setVerticalSyncEnabled(true);
    win.setFramerateLimit(60);
    win.setKeyRepeatEnabled(false);

    // input handler
    unordered_map<char, bool> ih = unordered_map<char, bool>();

    // initialization
    // player
    CircleShape player(RADIUS);
    player.setFillColor(Color(250, 250, 40));
    // enemy
    CircleShape other(RADIUS*2);
    other.setFillColor(Color(40, 250, 40));
    float ex = OMOVESPEED, ey = OMOVESPEED;

    Vector2f pos;

    while (win.isOpen()) {
        // event handling
        Event ev;
        while (win.pollEvent(ev)) {
            switch(ev.type) {
                case Event::Closed:
                    win.close();
                    break;
                case Event::TextEntered:
                    // if in valid unicode range
                    //if (32 < ev.text.unicode && ev.text.unicode < 127)
                        //cout << static_cast<char>(ev.text.unicode) << endl;
                    break;
                case Event::KeyPressed:
                    if (ev.key.code == Keyboard::W)
                        ih['w'] = true;
                    else if (ev.key.code == Keyboard::A)
                        ih['a'] = true;
                    else if (ev.key.code == Keyboard::S)
                        ih['s'] = true;
                    else if (ev.key.code == Keyboard::D)
                        ih['d'] = true;
                    break;
                case Event::KeyReleased:
                    if (ev.key.code == Keyboard::W)
                        ih['w'] = false;
                    else if (ev.key.code == Keyboard::A)
                        ih['a'] = false;
                    else if (ev.key.code == Keyboard::S)
                        ih['s'] = false;
                    else if (ev.key.code == Keyboard::D)
                        ih['d'] = false;
                    break;
                default:
                    break;

            }
        }
        // updating
        if (ih.find('w') != ih.end() && ih['w']) {
            player.move(Vector2f(0.0, -MOVESPEED));
        }
        if (ih.find('a') != ih.end() && ih['a']) {
            player.move(Vector2f(-MOVESPEED, 0.0));
        }
        if (ih.find('s') != ih.end() && ih['s']) {
            player.move(Vector2f(0.0, MOVESPEED));
        }
        if (ih.find('d') != ih.end() && ih['d']) {
            player.move(Vector2f(MOVESPEED, 0.0));
        }
        other.move(ex, ey);
        // collision
        pos = player.getPosition();
        if (pos.x < 0)
            player.setPosition(0, pos.y);
        else if (pos.x > WIDTH - RADIUS * 2)
            player.setPosition(WIDTH - RADIUS * 2, pos.y);
        pos = player.getPosition();
        if (pos.y < 0)
            player.setPosition(pos.x, 0);
        else if (pos.y > HEIGHT - RADIUS * 2)
            player.setPosition(pos.x, HEIGHT - RADIUS * 2);
        pos = other.getPosition();
        if (pos.x < 0)
            ex *= -1;
        else if (pos.x > WIDTH - RADIUS * 4)
            ex *= -1;
        pos = other.getPosition();
        if (pos.y < 0)
            ey *= -1;
        else if (pos.y > HEIGHT - RADIUS * 4)
            ey *= -1;
        // rendering
        win.clear();
        win.draw(player);
        win.draw(other);
        win.display();
    }
    return 0;
}
