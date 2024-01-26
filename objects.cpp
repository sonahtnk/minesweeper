#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "objects.h"

int mode = 0, gamemode = 0, ctac = 0;
int cont = 0;
int L, H, tmp;
 vector <toado> opennorm{};
 sf::RenderWindow window;
 sf::Font font;
 vector <int> makebomb;
 int visit1[200][200];
 bool isempty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
//mode 0
 sf::Image title;
 sf::RectangleShape newgame, highscore, minesweeper, continuegame;
 sf::Text minsw, newg, highs, cong;
 sf::Texture texture;
 sf::Sprite sprite;
//mode 1
 sf::RectangleShape easy, medium, hard, custom, backtomenu1;
 sf::Text ez, med, har, cus, bac1;
//mode 2
 sf::RectangleShape row, column, mines, backto12;
 sf::Text rowt, colt, mint, bac12;
 sf::RectangleShape rown, columnn, minesn, start;
 sf::Text rownt, columnnt, minesnt, startt;
 int rownum, rowtmp, columnnum, columntmp, minenum, minetmp, cusmode;
//mode 3
int m, n, z, flag, need; 
int timetmp = 0, flagtmp = 0, needtmp = 0, winmodetmp = 0, tmpright = 0;
sf::RectangleShape times, flags, backto13;
sf::RectangleShape shape[200][200];
sf::RectangleShape shape1[200][200];
sf::RectangleShape shapeflag[200][200];
 sf::RectangleShape shapebit[200][200];
sf::RectangleShape block[11];
 sf::Text text[200][200];
 sf::Text flagt, flagtext, timetext, timec, back3;
 sf::Time elapse1, elapse2;
 int localb[200][200];
 int bombb[200][200];
 int bomb[200 * 200 - 1];
 int local[200 * 200 - 1];
 int pointtmp, point, winmode;
//mode 4
 sf::RectangleShape gameover, backtomenu4, che;
 sf::Text gameovert, menu4t;
//mode 5
 sf::RectangleShape congratulation, newhigh;
 sf::Text congratt, newhight;

//mode 6
 sf::RectangleShape higheasy, highmedium, highhard, backtomenu6;
 sf::Text highez, highmed, highhar, bac6, numez, nummed, numhar;








 sf::Clock clockt;