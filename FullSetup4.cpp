#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup4.h"
#include "objects.h"
using namespace std;
void FullSetup4()
{
    gameover.setSize(sf::Vector2f(L / 6.f, H / 6.f));
    gameover.setPosition(L / 12.f, 3 * H / 4.f);
    gameover.setFillColor(sf::Color(0, 0, 120));
    gameovert.setFont(font);
    gameovert.setString("Game over");
    gameovert.setCharacterSize(L / 40);
    gameovert.setFillColor(sf::Color::Red);
    gameovert.setStyle(sf::Text::Bold | sf::Text::Italic);
    gameovert.setPosition(5 * L / 48.f, 38 * H / 48.f);

    backtomenu4.setSize(sf::Vector2f(L / 6.f, H / 6.f));
    backtomenu4.setPosition(L / 3.f, 3 * H / 4.f);
    backtomenu4.setFillColor(sf::Color(0, 0, 120));
    menu4t.setFont(font);
    menu4t.setString("Back");
    menu4t.setCharacterSize(L / 40);
    menu4t.setFillColor(sf::Color::Red);
    menu4t.setStyle(sf::Text::Bold | sf::Text::Italic);
    menu4t.setPosition(18 * L / 48.f, 38 * H / 48.f);

    che.setSize(sf::Vector2f(L / 4.f, H / 2.f));
    che.setPosition(3 * L / 4.f, H / 2.f);
    che.setFillColor(sf::Color::Black);
}
