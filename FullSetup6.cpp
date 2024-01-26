#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup6.h"
#include "objects.h"
using namespace std;
void FullSetup6()
{
    higheasy.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    higheasy.setPosition(L / 4.f, H / 18.f);
    higheasy.setFillColor(sf::Color(0, 0, 200));
    highez.setFont(font);
    highez.setString("Easy");
    highez.setCharacterSize(L / 20);
    highez.setFillColor(sf::Color::Red);
    highez.setStyle(sf::Text::Bold | sf::Text::Italic);
    highez.setPosition(11 * L / 32.f, H / 15.f);
    numez.setFont(font);
    //numez.setString("Easy");
    numez.setCharacterSize(L / 20);
    numez.setFillColor(sf::Color::Red);
    numez.setStyle(sf::Text::Bold | sf::Text::Italic);
    numez.setPosition(29 * L / 48.f, H / 15.f);

    highmedium.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    highmedium.setPosition(L / 4.f, 5 * H / 18.f);
    highmedium.setFillColor(sf::Color(0, 0, 200));
    highmed.setFont(font);
    highmed.setString("Medium");
    highmed.setCharacterSize(L / 20);
    highmed.setFillColor(sf::Color::Red);
    highmed.setStyle(sf::Text::Bold | sf::Text::Italic);
    highmed.setPosition(11 * L / 32.f, H / 15 + 4 * H / 18.f);
    nummed.setFont(font);
    //nummed.setString("Medium");
    nummed.setCharacterSize(L / 20);
    nummed.setFillColor(sf::Color::Red);
    nummed.setStyle(sf::Text::Bold | sf::Text::Italic);
    nummed.setPosition(29 * L / 48.f, H / 15 + 4 * H / 18.f);

    highhard.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    highhard.setPosition(L / 4.f, 9 * H / 18.f);
    highhard.setFillColor(sf::Color(0, 0, 200));
    highhar.setFont(font);
    highhar.setString("Hard");
    highhar.setCharacterSize(L / 20);
    highhar.setFillColor(sf::Color::Red);
    highhar.setStyle(sf::Text::Bold | sf::Text::Italic);
    highhar.setPosition(11 * L / 32.f, H / 15 + 8 * H / 18.f);
    numhar.setFont(font);
    //numhar.setString("Hard");
    numhar.setCharacterSize(L / 20);
    numhar.setFillColor(sf::Color::Red);
    numhar.setStyle(sf::Text::Bold | sf::Text::Italic);
    numhar.setPosition(29 * L / 48.f, H / 15 + 8 * H / 18.f);

    backtomenu6.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    backtomenu6.setPosition(3 * L / 4.f, 3 * H / 4.f);
    backtomenu6.setFillColor(sf::Color(0, 0, 120));
    bac6.setFont(font);
    bac6.setString("Back");
    bac6.setCharacterSize(L / 20);
    bac6.setFillColor(sf::Color::Red);
    bac6.setStyle(sf::Text::Bold | sf::Text::Italic);
    bac6.setPosition(4 * L / 5.f, 4 * H / 5.f);
}