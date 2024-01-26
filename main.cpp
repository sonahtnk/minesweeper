#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <Windows.h>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "Game.h"
#include "FullSetup0.h"
#include "FullSetup1.h"
#include "FullSetup2.h"
#include "FullSetup3.h"
#include "FullSetup4.h"
#include "FullSetup5.h"
#include "FullSetup6.h"
#include "OpenNorm.h"
#include "objects.h"
using namespace std;

void FullSetup3();
void FullSetup4();
void FullSetup5();
void FullSetup6();
void OpenMenu(); //mode 0
void OpenHighscore(); //mode 6
void OpenMode(); //mode 1
void OpenCustom();//mode 2
void OpenGameplay(int x, int y, int z); //mode 3
void Game(int m, int n, int p);
void OpenNorm(int x, int y);

void Congrats();   //mode 5
void GameOver();   //mode 4


int main()
{
    HWND hDesktop = GetDesktopWindow();

    // Get screen width and height
    RECT desktopRect;
    GetWindowRect(hDesktop, &desktopRect);

    //int screenWidth = desktopRect.right;
    //int screenHeight = desktopRect.bottom;
    L = desktopRect.right*2.5*2/3; H = desktopRect.bottom*2.5*2/3; tmp = 0;
    if (!title.loadFromFile("title.png")) return -1;

    if (!font.loadFromFile("arial.ttf"))
    {
        sf::err() << "couldn't load font\n";
        return -1;
    }
    std::ifstream file("higheasy.txt");
    if (isempty(file))
    {
        ofstream Highez("higheasy.txt");
        Highez << -1;
        Highez.close();
    }

    std::ifstream file2("highmed.txt");
    if (isempty(file2))
    {
        ofstream Highmed("highmed.txt");
        Highmed << -1;
        Highmed.close();
    }

    std::ifstream file4("highhard.txt");
    if (isempty(file4))
    {
        ofstream Highhard("highhard.txt");
        Highhard << -1;
        Highhard.close();
    }
    mode = 0;
    sf::RenderWindow window(sf::VideoMode(L, H), "SFML works!");
    FullSetup0();
    FullSetup1();
    FullSetup2();
    FullSetup3();
    FullSetup4();
    FullSetup5();
    FullSetup6();

    while (window.isOpen())
    {
        sf::Event event;
        if (mode != 5)
        {
            pointtmp = 0;
        }
        if (mode != 3)
        {
            timetmp = 0;
            flagtmp = 0;
            needtmp = 0;
            winmodetmp = 0;
        }
        if (mode != 2)
        {
            tmp = 0;
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //mode 0
        if (mode == 0)
        {
            window.clear();
            window.draw(newgame);
            window.draw(highscore);
            window.draw(newg);
            window.draw(highs);
            window.draw(sprite);
            if (cont == 0)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    int x = sf::Mouse::getPosition(window).x;
                    int y = sf::Mouse::getPosition(window).y;
                    if (x <= 2 * L / 3 && x >= L / 3 && y >= 17 * H / 24 && y <= 23 * H / 24)
                    {
                        mode = 6;
                    }
                    if (x <= 2 * L / 3 && x >= L / 3 && y >= 5 * H / 12 && y <= 2 * H / 3)
                    {
                        mode = 1;
                    }
                }
            }
            if (cont == 1)
            {

                window.draw(continuegame); window.draw(cong);
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (x <= 2 * L / 3 && x >= L / 3 && y >= 17 * H / 24 && y <= 23 * H / 24)
                    {
                        mode = 6;
                    }
                    if (x <= 2 * L / 3 && x >= L / 3 && y >= 5 * H / 12 && y <= 2 * H / 3)
                    {
                        mode = 1;
                    }
                    if (x >= 3 * L / 4 && x <= 11 * L / 12 && y >= 5 * H / 12 && y <= 2 * H / 3)
                    {
                        mode = 3;
                    }
                }
            }
        }

        if (mode == 1)
        {

            window.clear();
            window.draw(easy);      window.draw(ez);
            window.draw(medium);    window.draw(med);
            window.draw(hard);      window.draw(har);
            window.draw(custom);    window.draw(cus);
            window.draw(backtomenu1); window.draw(bac1);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                //cout << x << y;
                if (x <= 19 * L / 20 && x >= 3 * L / 4 && y >= 3 * H / 4 && y <= 19 * H / 20)
                {
                    mode = 0;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= 13 * H / 18 && y <= 17 * H / 18)
                {
                    mode = 2;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= H / 18 && y <= 4 * H / 18)
                {
                    mode = 3;
                    cont = 0;
                    gamemode = 1;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= 5 * H / 18 && y <= 8 * H / 18)
                {
                    mode = 3;
                    cont = 0;
                    gamemode = 2;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= 9 * H / 18 && y <= 12 * H / 18)
                {
                    mode = 3;
                    cont = 0;
                    gamemode = 3;
                }
            }
        }
        if (mode == 2)
        {
            if (tmp == 0)
            {
                tmp = 1;
                rownum = 0;
                columnnum = 0;
                minenum = 0;
                rowtmp = 0;
                columntmp = 0;
                minetmp = 0;
                cusmode = 0;
            }
            //cout << rownum << " " << columnnum << " " << minenum << endl;
            window.clear();
            window.draw(row);       window.draw(rowt);
            window.draw(column);    window.draw(colt);
            window.draw(mines);     window.draw(mint);
            window.draw(backto12);  window.draw(bac12);
            window.draw(rown);      window.draw(rownt);
            window.draw(columnn);   window.draw(columnnt);
            window.draw(minesn);    window.draw(minesnt);
            window.draw(start);     window.draw(startt);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                //cout << x << " " << y << endl;
                if (x <= 19 * L / 20 && x >= 3 * L / 4 && y >= 3 * H / 4 && y <= 19 * H / 20)
                {
                    mode = 0;
                }
                if (x <= 14 * L / 20 && x >= L / 2 && y >= 3 * H / 4 && y <= 19 * H / 20)
                {
                    gamemode = 4;
                    mode = 3;
                    cont = 0;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= H / 18 && y <= 4 * H / 18)
                {
                    cusmode = 1;
                    //cout << "row" << endl;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= 5 * H / 18 && y <= 8 * H / 18)
                {
                    cusmode = 2;
                    //cout << "column" << endl;
                }
                if (x >= L / 4 && x <= 7 * L / 12 && y >= 9 * H / 18 && y <= 13 * H / 18)
                {
                    cusmode = 3;
                    //cout << "bombs" << endl;
                }
            }
            //cout << cusmode << endl;
            if (cusmode == 1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sf::sleep(sf::milliseconds(200));
                    //cout << "up";
                    if (rownum < 80 ) rowtmp = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (rownum > 0)rowtmp = -1;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (rownum < 71)rowtmp = 10;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (rownum > 9)rowtmp = -10;
                }
            }
            if (cusmode == 2)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (columnnum < 80) columntmp = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (columnnum > 0)columntmp = -1;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (columnnum < 71)columntmp = 10;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (columnnum > 9)columntmp = -10;
                }
            }


            if (cusmode == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (minenum < 300) minetmp = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (minenum > 0)minetmp = -1;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (minenum < 291)minetmp = 10;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sf::sleep(sf::milliseconds(200));
                    if (minenum > 9)minetmp = -10;
                }
            }
            if (rowtmp != 0)
            {
                rownum += rowtmp;
                rowtmp = 0;
            }
            if (columntmp != 0)
            {
                columnnum += columntmp;
                columntmp = 0;
            }
            if (minetmp != 0)
            {
                minenum += minetmp;
                minetmp = 0;
            }
            //cout << rownum << columnnum << minenum << endl;
            rownt.setString(to_string(rownum));
            columnnt.setString(to_string(columnnum));
            minesnt.setString(to_string(minenum));
        }
        if (mode == 3)
        {
            if (cont == 0)
            {
                makebomb.clear();
                if (winmodetmp == 0)
                {
                    winmode = gamemode;
                    winmodetmp = 1;
                }

                if (gamemode == 1)
                {
                    Game(9, 9, 10);
                    m = 9;
                    n = 9;
                    z = 10;
                    gamemode = 0;
                }
                if (gamemode == 2)
                {
                    Game(16, 16, 40);
                    m = 16;
                    n = 16;
                    z = 40;
                    gamemode = 0;
                }
                if (gamemode == 3)
                {
                    Game(24, 24, 99);
                    m = 24;
                    n = 24;
                    z = 99;
                    gamemode = 0;
                }
                if (gamemode == 4)
                {
                    m = rownum;
                    n = columnnum;
                    z = minenum;
                    Game(m, n, z);
                    gamemode = 0;
                }
                if (timetmp == 0)
                {
                    elapse1 = clockt.getElapsedTime();
                    timetmp = 1;
                }
                if (flagtmp == 0)
                {
                    flag = z;
                    flagtmp = 1;
                }
                if (needtmp == 0)
                {
                    needtmp = 1;
                    need = m * n - z;
                }
            }

            window.clear();
            elapse2 = clockt.getElapsedTime();
            timec.setString(to_string(int(elapse2.asSeconds() - elapse1.asSeconds())));
            bac1.setFont(font);
            window.draw(flagtext);
            window.draw(timetext);
            window.draw(backto13);  window.draw(back3);
            window.draw(timec);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visit1[i][j] == 0)
                    {
                        window.draw(shape[i][j]);
                    }
                    else if (visit1[i][j] == 1)
                    {
                        window.draw(shape1[i][j]);
                        window.draw(text[i][j]);
                    }
                    else if (visit1[i][j] == 2)
                    {
                        window.draw(shapeflag[i][j]);
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                if (x <= 19 * L / 20 && x >= 3 * L / 4 && y >= 3 * H / 4 && y <= 19 * H / 20)
                {

                    mode = 1;
                    cont = 1;
                }
                int u = x / (L / 70 + 1); //cot
                int v = y / (L / 70 + 1); //hang
                //cout << u << v << "ok" << endl;
                if (v < m && u < n && v >= 0 && u >= 0) //m hang n cot
                {
                    OpenNorm(v, u); //u cot v hang
                    if (bombb[v][u] == 1)
                    {
                        window.draw(shape1[u][v]);
                        mode = 4;
                    }
                }
                if (need == 0)
                {
                    window.draw(shape1[u][v]); window.draw(text[u][v]);
                    mode = 5;
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))

            {
                sf::sleep(sf::milliseconds(200));
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;

                int u = x / (L / 70 + 1);
                int v = y / (L / 70 + 1);
                if (v < m && u < n && v >= 0 && u >= 0)
                {
                    if (visit1[v][u] != 1)
                    {
                        if (visit1[v][u] == 0)
                        {
                            flag--;
                        }
                        if (visit1[v][u] == 2)
                        {
                            flag++;
                        }
                        visit1[v][u] = 2 - visit1[v][u];
                    }
                }

            }
            flagt.setString(to_string(flag));
            window.draw(flagt);
        }
        if (mode == 4)
        {
            cont = 0;
            window.draw(gameover); window.draw(gameovert);
            window.draw(backtomenu4); window.draw(menu4t);
            window.draw(che);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                if (x <= L / 2 && x >= L / 3 && y >= 3 * H / 4 && y <= 11 * H / 12)
                {
                    mode = 0;
                    makebomb.clear();
                }
            }
        }
        if (mode == 5)
        {
            cont = 0;
            window.draw(congratulation);    window.draw(congratt);

            window.draw(backtomenu4); window.draw(menu4t);
            window.draw(che);

            if (pointtmp == 0)
            {
                elapse2 = clockt.getElapsedTime();
                point = int(elapse2.asSeconds() - elapse1.asSeconds());
                pointtmp = 1;
                //cout << point << endl;
                //cout << winmode << endl;
                int scoreez, scoremed, scorehar;
                if (winmode == 1)
                {
                    ifstream highez("higheasy.txt");
                    stringstream geek;
                    string Ezhigh;
                    getline(highez, Ezhigh);
                    geek << Ezhigh;
                    geek >> scoreez;
                    //cout << scoreez << endl;
                    if (point < scoreez || scoreez == -1)
                    {
                        scoreez = point;
                        //cout << "ok" << endl;
                        ofstream Highez1("higheasy.txt");
                        Highez1 << scoreez;
                        window.draw(newhigh);           window.draw(newhight);
                        Highez1.close();

                    }
                }
                if (winmode == 2)
                {
                    ifstream highmedfile("highmed.txt");
                    stringstream geek;
                    string medhighstring;
                    getline(highmedfile, medhighstring);
                    geek << medhighstring;
                    geek >> scoremed;
                    //cout << scoremed << endl;
                    if (point < scoremed || scoremed == -1)
                    {
                        scoremed = point;
                        //cout << "ok" << endl;
                        ofstream Highmed1("highmed.txt");
                        Highmed1 << scoremed;
                        window.draw(newhigh);           window.draw(newhight);
                        Highmed1.close();
                    }
                }
                if (winmode == 3)
                {
                    ifstream highhardfile("highhard.txt");
                    stringstream geek;
                    string harhighstring;
                    getline(highhardfile, harhighstring);
                    geek << harhighstring;
                    geek >> scorehar;
                    //cout << scorehar << endl;
                    if (point < scorehar || scorehar == -1)
                    {
                        scorehar = point;
                        //cout << "ok" << endl;
                        ofstream Highhar1("highhard.txt");
                        Highhar1 << scorehar;
                        window.draw(newhigh);           window.draw(newhight);
                        Highhar1.close();
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x = sf::Mouse::getPosition(window).x;
                int y = sf::Mouse::getPosition(window).y;
                //cout << x << " " << y << endl;
                if (x <= L / 2 && x >= L / 3 && y >= 3 * H / 4 && y <= 11 * H / 12)
                {
                    mode = 0;
                    makebomb.clear();
                }
                //cout << mode << endl;
            }
        }
        if(mode==6)
        {
            ifstream eZ("higheasy.txt");
            string ezhighscore;
            getline(eZ,ezhighscore);
            numez.setString(ezhighscore);

            ifstream meD("highmed.txt");
            string medhighscore;
            getline(meD,medhighscore);
            nummed.setString(medhighscore);

            ifstream harD("highhard.txt");
            string hardhighscore;
            getline(harD,hardhighscore);
            numhar.setString(hardhighscore);

            window.clear();
            window.draw(higheasy);      window.draw(highez);    window.draw(numez);
            window.draw(highmedium);    window.draw(highmed);   window.draw(nummed);
            window.draw(highhard);      window.draw(highhar);   window.draw(numhar);
            window.draw(backtomenu6);   window.draw(bac6);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x=sf::Mouse::getPosition(window).x;
                int y=sf::Mouse::getPosition(window).y;
                //cout<<x<<" "<<y<<endl;
                if(x<=19*L/20 &&x>=3*L/4 &&y>=3*H/4 &&y<=19*H/20)
                    {
                        mode=0;
                    }
            }
        }
                window.display();
    }
    return 0;
}

void OpenMenu()
{
}

