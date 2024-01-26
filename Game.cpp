#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "objects.h"
#include "Game.h"
using namespace std;

void Game(int m, int n, int z)
{
    srand(time(0));
    cout << m << " " << n << " " << z << endl; 
    for (int i = 0; i < m * n; i++)
    {
        makebomb.push_back(i);
        bomb[i] = 0;
        local[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            localb[i][j] = 0;
            bombb[i][j] = 0;
            cout << bombb[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle(makebomb.begin(), makebomb.end(), std::default_random_engine(num));
    for (int i = 0; i < z; i++)
    {
        bomb[makebomb[i]] = 1;
    }
    int sum = 0; int index = 0;
    for (int i = 0; i < m * n; i++)
    {
        //cout<<bomb[i];
        sum += bomb[i];
        index++;
        //        cout<<i/n<<" "<<i%n<<endl;
        int x = i / n;
        int y = i % n;
        bombb[x][y] = bomb[i];
    }
    //cout<<endl;
    //cout<<sum<<" "<<index<<endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<bombb[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != 0 && i != m - 1 && j != 0 && j != n - 1) localb[i][j] = bombb[i][j + 1] + bombb[i - 1][j + 1] + bombb[i + 1][j + 1] + bombb[i][j] + bombb[i + 1][j] + bombb[i - 1][j] + bombb[i][j - 1] + bombb[i + 1][j - 1] + bombb[i - 1][j - 1];
            if (i == 0)
            {
                if (j == 0) localb[i][j] = bombb[i][j + 1] + bombb[i + 1][j + 1] + bombb[i + 1][j];
                else if (j == n - 1) localb[i][j] = bombb[i][j - 1] + bombb[i + 1][j - 1] + bombb[i + 1][j];
                else localb[i][j] = bombb[i][j - 1] + bombb[i + 1][j - 1] + bombb[i][j + 1] + bombb[i + 1][j + 1] + bombb[i + 1][j];
            }
            if (i == m - 1)
            {
                if (j == 0) localb[i][j] = bombb[i][j + 1] + bombb[i - 1][j + 1] + bombb[i - 1][j];
                else if (j == n - 1) localb[i][j] = bombb[i][j - 1] + bombb[i - 1][j - 1] + bombb[i - 1][j];
                else localb[i][j] = bombb[i][j - 1] + bombb[i][j + 1] + bombb[i - 1][j] + bombb[i - 1][j + 1] + bombb[i - 1][j - 1];
            }

            if (j == 0)
            {
                if (i != 0 && i != m - 1)
                    localb[i][j] = bombb[i][j + 1] + bombb[i + 1][j + 1] + bombb[i - 1][j + 1] + bombb[i + 1][j] + bombb[i - 1][j];
            }
            if (j == n - 1)
            {
                if (i != 0 && i != m - 1)
                    localb[i][j] = bombb[i][j - 1] + bombb[i + 1][j - 1] + bombb[i - 1][j - 1] + bombb[i + 1][j] + bombb[i - 1][j];
            }
            if (bombb[i][j] == 1)localb[i][j] = 9;
        }
    }
        /*for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<localb[i][j]<<" ";
            }
            cout<<endl;
        }*/
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = (L / 70 + 1) * j;
            int v = (L / 70 + 1) * i;
            visit1[i][j] = 0;

            text[i][j].setFont(font);
            text[i][j].setString(to_string(localb[i][j]));
            text[i][j].setCharacterSize(L / 70);
            text[i][j].setFillColor(sf::Color::Red);
            text[i][j].setStyle(sf::Text::Bold | sf::Text::Italic);
            text[i][j].setPosition(u * 1.f, v * 1.f);

            shape[i][j].setSize(sf::Vector2f(L / 70.f, L / 70.f));
            shape[i][j].setPosition(u * 1.f, v * 1.f);
            shape[i][j].setFillColor(sf::Color(80, 80, 200));

            shape1[i][j].setSize(sf::Vector2f(L / 70.f, L / 70.f));
            shape1[i][j].setPosition(u * 1.f, v * 1.f);
            int m = 20 * (localb[i][j] + 1);
            shape1[i][j].setFillColor(sf::Color(m, 0, 0));

            shapeflag[i][j].setSize(sf::Vector2f(L / 70.f, L / 70.f));
            shapeflag[i][j].setPosition(u * 1.f, v * 1.f);
            shapeflag[i][j].setFillColor(sf::Color(0, 200, 0));

            shapebit[i][j].setSize(sf::Vector2f(L / 70.f, L / 70.f));
            shapebit[i][j].setPosition(u * 1.f, v * 1.f);
            shapebit[i][j].setFillColor(sf::Color(100, 100, 100));
        }
    }
}