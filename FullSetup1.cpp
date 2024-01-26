#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup1.h"
#include "objects.h"
using namespace std;

void FullSetup1()
{
    easy.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    easy.setPosition(L / 4.f, H / 18.f);
    easy.setFillColor(sf::Color(0, 0, 200));
    ez.setFont(font);
    ez.setString("Easy");
    ez.setCharacterSize(L / 20);
    ez.setFillColor(sf::Color::Red);
    ez.setStyle(sf::Text::Bold | sf::Text::Italic);
    ez.setPosition(11 * L / 32.f, H / 15.f);

    medium.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    medium.setPosition(L / 4.f, 5 * H / 18.f);
    medium.setFillColor(sf::Color(0, 0, 200));
    med.setFont(font);
    med.setString("Medium");
    med.setCharacterSize(L / 20);
    med.setFillColor(sf::Color::Red);
    med.setStyle(sf::Text::Bold | sf::Text::Italic);
    med.setPosition(11 * L / 32.f, H / 15 + 4 * H / 18.f);

    hard.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    hard.setPosition(L / 4.f, H / 2.f);
    hard.setFillColor(sf::Color(0, 0, 200));
    har.setFont(font);
    har.setString("Hard");
    har.setCharacterSize(L / 20);
    har.setFillColor(sf::Color::Red);
    har.setStyle(sf::Text::Bold | sf::Text::Italic);
    har.setPosition(11 * L / 32.f, H / 15 + 8 * H / 18.f);

    custom.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    custom.setPosition(L / 4.f, 13 * H / 18.f);
    custom.setFillColor(sf::Color(0, 0, 200));
    cus.setFont(font);
    cus.setString("Custom");
    cus.setCharacterSize(L / 20);
    cus.setFillColor(sf::Color::Red);
    cus.setStyle(sf::Text::Bold | sf::Text::Italic);
    cus.setPosition(11 * L / 32.f, H / 15 + 12 * H / 18.f);

    backtomenu1.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    backtomenu1.setPosition(3 * L / 4.f, 3 * H / 4.f);
    backtomenu1.setFillColor(sf::Color(0, 0, 120));
    bac1.setFont(font);
    bac1.setString("Back");
    bac1.setCharacterSize(L / 20);
    bac1.setFillColor(sf::Color::Red);
    bac1.setStyle(sf::Text::Bold | sf::Text::Italic);
    bac1.setPosition(4 * L / 5.f, 4 * H / 5.f);
}