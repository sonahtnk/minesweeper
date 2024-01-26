#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "stdc++.h"
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "OpenNorm.h"
#include "objects.h"
using namespace std;

void OpenNorm(int u, int v)
{
    toado A, B;
    A.x = u; //u chi so cot, v chi so hang
    A.y = v;
    //cout << A.x << A.y;
    opennorm.push_back(A);
    

    int index = 1;
    while (!opennorm.empty())
    {
        cout << opennorm[0].x << opennorm[0].y << endl;
        int x0 = opennorm[0].x;
        int y0 = opennorm[0].y;
        if (visit1[x0][y0] == 2) flag++;
        if (visit1[x0][y0] != 1)
        {
            visit1[x0][y0] = 1;
            need--;
        }
        if (localb[x0][y0] == 0)
        {
            if (x0 != m - 1 && visit1[x0 + 1][y0] != 1)
            {
                B.x = x0 + 1;
                B.y = y0;
                opennorm.push_back(B);
                index++;
            }
            if (x0 != 0 && visit1[x0 - 1][y0] != 1)
            {
                B.x = x0 - 1;
                B.y = y0;
                opennorm.push_back(B);
                index++;
            }
            if (x0 != m - 1 && y0 != n - 1 && visit1[x0 + 1][y0 + 1] != 1)
            {
                B.x = x0 + 1;
                B.y = y0 + 1;
                opennorm.push_back(B);
                index++;
            }
            if (x0 != m - 1 && y0 != 0 && visit1[x0 + 1][y0 - 1] != 1)
            {
                B.x = x0 + 1;
                B.y = y0 - 1;
                opennorm.push_back(B);
                index++;
            }
            if (x0 != 0 && y0 != 0 && visit1[x0 - 1][y0 - 1] != 1)
            {
                B.x = x0 - 1;
                B.y = y0 - 1;
                opennorm.push_back(B);
                index++;
            }
            if (x0 != 0 && y0 != n - 1 && visit1[x0 - 1][y0 + 1] != 1)
            {
                B.x = x0 - 1;
                B.y = y0 + 1;
                opennorm.push_back(B);
                index++;
            }
            if (y0 != n - 1 && visit1[x0][y0 + 1] != 1)
            {
                B.x = x0;
                B.y = y0 + 1;
                opennorm.push_back(B);
                index++;
            }
            if (y0 != 0 && visit1[x0][y0 - 1] != 1)
            {
                B.x = x0;
                B.y = y0 - 1;
                opennorm.push_back(B);
                index++;
            }
        }
        opennorm.erase(opennorm.begin());
        index--;
    }
}