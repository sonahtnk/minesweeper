#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#ifndef GLOBAL_OBJECTS_H
#define GLOBAL_OBJECTS_H
using namespace std;
extern struct toado
{
    int x, y;
};
extern vector <toado> opennorm;
extern sf::RenderWindow window;
extern sf::Font font;
extern int mode, gamemode, ctac;
extern vector <int> makebomb;
extern int visit1[200][200];
extern bool isempty(std::ifstream& pFile);
//mode 0
extern sf::Image title;
extern sf::RectangleShape newgame, highscore, minesweeper, continuegame;
extern sf::Text minsw, newg, highs, cong;
extern sf::Texture texture;
extern sf::Sprite sprite;
extern int cont;
//mode 1
extern sf::RectangleShape easy, medium, hard, custom, backtomenu1;
extern sf::Text ez, med, har, cus, bac1;
//mode 2
extern sf::RectangleShape row, column, mines, backto12;
extern sf::Text rowt, colt, mint, bac12;
extern sf::RectangleShape rown, columnn, minesn, start;
extern sf::Text rownt, columnnt, minesnt, startt;
extern int rownum, rowtmp, columnnum, columntmp, minenum, minetmp, cusmode;
//mode 3
extern int m, n, z, flag, need, timetmp, flagtmp, needtmp, winmodetmp, tmpright;
extern sf::RectangleShape times, flags, backto13;
extern sf::RectangleShape shape[200][200];
extern sf::RectangleShape shape1[200][200];
extern sf::RectangleShape shapeflag[200][200];
extern sf::RectangleShape shapebit[200][200];
extern sf::RectangleShape block[11];
extern sf::Text text[200][200];
extern sf::Text flagt, flagtext, timetext, timec, back3;
extern sf::Time elapse1, elapse2;
extern int localb[200][200];
extern int bombb[200][200];
extern int bomb[200 * 200 - 1];
extern int local[200 * 200 - 1];
//mode 4
extern sf::RectangleShape gameover, backtomenu4, che;
extern sf::Text gameovert, menu4t;
//mode 5
extern sf::RectangleShape congratulation, newhigh; 
extern int pointtmp, point, winmode;
extern sf::Text congratt, newhight;

//mode 6
extern sf::RectangleShape higheasy, highmedium, highhard, backtomenu6;
extern sf::Text highez, highmed, highhar, bac6, numez, nummed, numhar;
extern int L, H, tmp;
extern sf::Clock clockt;
#endif GLOBAL_OBJECTS_H