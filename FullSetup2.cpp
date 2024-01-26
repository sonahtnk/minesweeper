#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup2.h"
#include "objects.h"
using namespace std;

void FullSetup2()
//mode 2
{
    row.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    row.setPosition(L / 4.f, H / 18.f);
    row.setFillColor(sf::Color(0, 0, 200));
    rowt.setFont(font);
    rowt.setString("Rows (1-80)");
    rowt.setCharacterSize(L / 25);
    rowt.setFillColor(sf::Color::Red);
    rowt.setStyle(sf::Text::Bold | sf::Text::Italic);
    rowt.setPosition(9 * L / 32.f, H / 15.f);

    rown.setSize(sf::Vector2f(L / 15.f, H / 6.f));
    rown.setPosition(5 * L / 8.f, H / 18.f);
    rown.setFillColor(sf::Color(0, 0, 200));
    rownt.setFont(font);
    rownt.setCharacterSize(L / 25);
    rownt.setFillColor(sf::Color::Red);
    rownt.setStyle(sf::Text::Bold | sf::Text::Italic);
    rownt.setPosition(17 * L / 64 + 3 * L / 8.f, H / 15.f);

    column.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    column.setPosition(L / 4.f, 5 * H / 18.f);
    column.setFillColor(sf::Color(0, 0, 200));
    colt.setFont(font);
    colt.setString("Columns(1-80)");
    colt.setCharacterSize(L / 25);
    colt.setFillColor(sf::Color::Red);
    colt.setStyle(sf::Text::Bold | sf::Text::Italic);
    colt.setPosition(17 * L / 64.f, H / 15 + 4 * H / 18.f);

    columnn.setSize(sf::Vector2f(L / 15.f, H / 6.f));
    columnn.setPosition(5 * L / 8.f, 5 * H / 18.f);
    columnn.setFillColor(sf::Color(0, 0, 200));
    columnnt.setFont(font);
    columnnt.setCharacterSize(L / 25);
    columnnt.setFillColor(sf::Color::Red);
    columnnt.setStyle(sf::Text::Bold | sf::Text::Italic);
    columnnt.setPosition(17 * L / 64 + 3 * L / 8.f, H / 15 + 4 * H / 18.f);

    mines.setSize(sf::Vector2f(L / 3.f, H / 6.f));
    mines.setPosition(L / 4.f, 9 * H / 18.f);
    mines.setFillColor(sf::Color(0, 0, 200));
    mint.setFont(font);
    mint.setString("Mines(1-300)");
    mint.setCharacterSize(L / 25);
    mint.setFillColor(sf::Color::Red);
    mint.setStyle(sf::Text::Bold | sf::Text::Italic);
    mint.setPosition(9 * L / 32.f, H / 15 + 8 * H / 18.f);

    minesn.setSize(sf::Vector2f(L / 15.f, H / 6.f));
    minesn.setPosition(5 * L / 8.f, 9 * H / 18.f);
    minesn.setFillColor(sf::Color(0, 0, 200));
    minesnt.setFont(font);
    minesnt.setCharacterSize(L / 25);
    minesnt.setFillColor(sf::Color::Red);
    minesnt.setStyle(sf::Text::Bold | sf::Text::Italic);
    minesnt.setPosition(17 * L / 64 + 3 * L / 8.f, H / 15 + 8 * H / 18.f);

    backto12.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    backto12.setPosition(3 * L / 4.f, 3 * H / 4.f);
    backto12.setFillColor(sf::Color(0, 0, 200));
    bac12.setFont(font);
    bac12.setString("Back");
    bac12.setCharacterSize(L / 25);
    bac12.setFillColor(sf::Color::Red);
    bac12.setStyle(sf::Text::Bold | sf::Text::Italic);
    bac12.setPosition(4 * L / 5.f, 4 * H / 5.f);

    start.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    start.setPosition(L / 2.f, 3 * H / 4.f);
    start.setFillColor(sf::Color(0, 0, 200));
    startt.setFont(font);
    startt.setString("Start");
    startt.setCharacterSize(L / 25);
    startt.setFillColor(sf::Color::Red);
    startt.setStyle(sf::Text::Bold | sf::Text::Italic);
    startt.setPosition(4 * L / 5 - L / 4.f, 4 * H / 5.f);
}