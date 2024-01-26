#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup0.h"
#include "objects.h"
using namespace std;

void FullSetup0()
{
    for (int i = 1; i <= 10; i++)
    {
        block[i].setFillColor(sf::Color(0, 0, i * 2));
        block[i].setSize(sf::Vector2f(20.f, 20.f));
    }
    //mode 0

    texture.loadFromImage(title);

    sprite.setTexture(texture);
    sprite.setPosition(L / 5, H / 24);
    sprite.setScale(L*3/(5*sprite.getTextureRect().width), H/(4* sprite.getTextureRect().height));
    cout << sprite.getTextureRect().width << " " << sprite.getTextureRect().height;

    minesweeper.setSize(sf::Vector2f(L / 2.f, H / 3.f));
    minesweeper.setPosition(L / 4.f, H / 24.f);
    minesweeper.setFillColor(sf::Color(0, 0, 200));
    minsw.setFont(font);
    minsw.setString("Minesweeper");
    minsw.setCharacterSize(L / 18);
    minsw.setFillColor(sf::Color::Red);
    minsw.setStyle(sf::Text::Bold | sf::Text::Italic);
    minsw.setPosition(L / 3.f, H / 9.f);

    newgame.setSize(sf::Vector2f(L / 3.f, H / 4.f));
    newgame.setPosition(L / 3.f, 5 * H / 12.f);
    newgame.setFillColor(sf::Color(0, 0, 200));
    newg.setFont(font);
    newg.setString("New game");
    newg.setCharacterSize(L / 27);
    newg.setFillColor(sf::Color::Red);
    newg.setStyle(sf::Text::Bold | sf::Text::Italic);
    newg.setPosition(19 * L / 48.f, H / 2.f);

    continuegame.setSize(sf::Vector2f(L / 6.f, H / 4.f));
    continuegame.setPosition(3 * L / 4.f, 5 * H / 12.f);
    continuegame.setFillColor(sf::Color(0, 0, 200));
    cong.setFont(font);
    cong.setString("Continue");
    cong.setCharacterSize(L / 36);
    cong.setFillColor(sf::Color::Red);
    cong.setStyle(sf::Text::Bold | sf::Text::Italic);
    cong.setPosition(37 * L / 48.f, H / 2.f);

    highscore.setSize(sf::Vector2f(L / 3.f, H / 4.f));
    highscore.setPosition(L / 3.f, 17 * H / 24.f);
    highscore.setFillColor(sf::Color(0, 0, 200));
    highs.setFont(font);
    highs.setString("High scores");
    highs.setCharacterSize(L / 27);
    highs.setFillColor(sf::Color::Red);
    highs.setStyle(sf::Text::Bold | sf::Text::Italic);
    highs.setPosition(19 * L / 48.f, 19 * H / 24.f);
}