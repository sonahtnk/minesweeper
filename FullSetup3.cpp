#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup3.h"
#include "objects.h"
using namespace std;
void FullSetup3()
{
    backto13.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    backto13.setPosition(3 * L / 4.f, 3 * H / 4.f);
    backto13.setFillColor(sf::Color(0, 0, 120));
    back3.setFont(font);
    back3.setString("Back");
    back3.setCharacterSize(L / 25);
    back3.setFillColor(sf::Color::Red);
    back3.setStyle(sf::Text::Bold | sf::Text::Italic);
    back3.setPosition(4 * L / 5.f, 4 * H / 5.f);

    flagtext.setFont(font);
    flagtext.setString("Flags:");
    flagtext.setCharacterSize(L / 20);
    flagtext.setFillColor(sf::Color::Red);
    flagtext.setStyle(sf::Text::Bold | sf::Text::Italic);
    flagtext.setPosition(3 * L / 4.f, H / 2.f);
    flagt.setFont(font);
    flagt.setCharacterSize(L / 20);
    flagt.setFillColor(sf::Color::Red);
    flagt.setStyle(sf::Text::Bold | sf::Text::Italic);
    flagt.setPosition(11 * L / 12.f, H / 2.f);

    timetext.setFont(font);
    timetext.setString("Time:");
    timetext.setCharacterSize(L / 20);
    timetext.setFillColor(sf::Color::Red);
    timetext.setStyle(sf::Text::Bold | sf::Text::Italic);
    timetext.setPosition(3 * L / 4.f, 3 * H / 5.f);
    timec.setFont(font);
    timec.setCharacterSize(L / 20);
    timec.setFillColor(sf::Color::Red);
    timec.setStyle(sf::Text::Bold | sf::Text::Italic);
    timec.setPosition(29 * L / 32.f, 3 * H / 5.f);
}