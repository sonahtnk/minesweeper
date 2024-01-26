#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "FullSetup5.h"
#include "objects.h"
using namespace std;
void FullSetup5()
{
    congratulation.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    congratulation.setPosition(L / 20.f, 3 * H / 4.f);
    congratulation.setFillColor(sf::Color(0, 0, 120));
    congratt.setFont(font);
    congratt.setString("You win");
    congratt.setCharacterSize(L / 40);
    congratt.setFillColor(sf::Color::Red);
    congratt.setStyle(sf::Text::Bold | sf::Text::Italic);
    congratt.setPosition(L / 10.f, 4 * H / 5.f);

    newhigh.setSize(sf::Vector2f(L / 5.f, H / 5.f));
    newhigh.setPosition(11 * L / 20.f, 3 * H / 4.f);
    newhigh.setFillColor(sf::Color(0, 0, 120));
    newhight.setFont(font);
    newhight.setString("New highscore");
    newhight.setCharacterSize(L / 75);
    newhight.setFillColor(sf::Color::Red);
    newhight.setStyle(sf::Text::Bold | sf::Text::Italic);
    newhight.setPosition(7 * L / 20.f, 4 * H / 5.f);
}