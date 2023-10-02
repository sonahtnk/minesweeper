#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <bits/stdc++.h>

using namespace std;

sf::RenderWindow window;
sf::Font font;

int mode=0, gamemode=0; int ctac=0;
//mode 0
sf::Image title;
sf::RectangleShape newgame, highscore, minesweeper, continuegame;
sf::Text minsw,newg,highs, cong;
sf::Texture texture;
sf::Sprite sprite;
int cont=0;
//mode 1
sf::RectangleShape easy, medium, hard, custom, backtomenu1;
sf::Text ez,med,har,cus,bac1;
//mode 2
sf::RectangleShape row, column, mines, backto12;
sf::Text rowt,colt,mint,bac12;
sf::RectangleShape rown,columnn,minesn, start;
sf::Text rownt,columnnt,minesnt,startt;
int rownum, rowtmp, columnnum, columntmp, minenum, minetmp, cusmode;
//mode 3
int m,n,z,flag, need; int timetmp=0, flagtmp=0; int needtmp=0, winmodetmp=0; int tmpright=0;
sf::RectangleShape times, flags, backto13;
sf::RectangleShape shape[200][200];
sf::RectangleShape shape1[200][200];
sf::RectangleShape shapeflag[200][200];
sf::RectangleShape shapebit[200][200];
sf::RectangleShape block[11];
sf::Text text[200][200];
sf::Text flagt, flagtext, timetext, timec, back3;
sf::Clock clockt;
sf::Time elapse1, elapse2;
int localb[200][200];
int bombb[200][200];
int bomb[200*200-1];
int local[200*200-1];
//mode 4
sf::RectangleShape gameover, backtomenu4, che;
sf::Text gameovert,menu4t;
//mode 5
sf::RectangleShape congratulation, newhigh; int pointtmp, point, winmode;
sf::Text congratt, newhight;

//mode 6
sf::RectangleShape higheasy,highmedium,highhard,backtomenu6;
sf::Text highez, highmed, highhar, bac6, numez,nummed,numhar;

struct toado
{
    int x,y;
};


vector<int> makebomb;
vector<toado> opennorm;
int visit1[200][200];
void FullSetup0();
void FullSetup1();
void FullSetup2();
void FullSetup3();
void FullSetup4();
void FullSetup5();
void FullSetup6();
void OpenMenu(); //mode 0
void OpenHighscore(); //mode 6
void OpenMode(); //mode 1
void OpenCustom();//mode 2
void OpenGameplay(int x, int y, int z); //mode 3
void Game(int m,int n, int p);
void OpenNorm(int x,int y);

void Congrats();   //mode 5
void GameOver();   //mode 4
int L=1350; int H=700;
int tmp=0;

bool isempty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


int main()
{
if(!title.loadFromFile("title.png")) return -1;

if(!font.loadFromFile("arial.ttf"))
{
    sf::err()<<"couldn't load font\n";
    return -1;
}
    std::ifstream file("higheasy.txt");
    if(isempty(file))
    {
    ofstream Highez("higheasy.txt");
    Highez<<-1;
    Highez.close();
    }

    std::ifstream file2("highmed.txt");
    if(isempty(file2))
    {
    ofstream Highmed("highmed.txt");
    Highmed<<-1;
    Highmed.close();
    }

    std::ifstream file4("highhard.txt");
    if(isempty(file4))
    {
    ofstream Highhard("highhard.txt");
    Highhard<<-1;
    Highhard.close();
    }
    mode=0;
    sf::RenderWindow window(sf::VideoMode(L, H), "SFML works!");
    FullSetup0();
    FullSetup1();
    FullSetup2();
    FullSetup3();
    FullSetup4();
    FullSetup5();
    FullSetup6();
    sf::Clock clockt;
    while (window.isOpen())
    {
        sf::Event event;
        if(mode!=5)
        {
            pointtmp=0;
        }
        if(mode!=3)
        {
            timetmp=0;
            flagtmp=0;
            needtmp=0;
            winmodetmp=0;
        }
        if(mode!=2)
        {
            tmp=0;
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

//        window.draw(shape);

//mode 0
        if(mode==0)
        {
                window.clear();
                //window.draw(minesweeper);
                window.draw(newgame);
                window.draw(highscore);
                //window.draw(minsw);
                window.draw(newg);
                window.draw(highs);
                window.draw(sprite);

                if(cont==0)
                {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    int x=sf::Mouse::getPosition(window).x;
                    int y=sf::Mouse::getPosition(window).y;
                    //cout<<x<<" "<<y<<endl;
                    if(x<=2*L/3 &&x>=L/3 &&y>=17*H/24 &&y<=23*H/24)
                    {
                        mode=6;
                    }
                    if(x<=2*L/3 &&x>=L/3 &&y>=5*H/12 &&y<=2*H/3)
                    {
                        mode=1;
                    }
                    //cout<<mode<<endl;
                }
                }
                if(cont==1)
                {

                    window.draw(continuegame); window.draw(cong);
                    int x=sf::Mouse::getPosition(window).x;
                    int y=sf::Mouse::getPosition(window).y;
                    //cout<<x<<" "<<y<<endl;
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(x<=2*L/3 &&x>=L/3 &&y>=17*H/24 &&y<=23*H/24)
                    {
                        mode=6;
                    }
                    if(x<=2*L/3 &&x>=L/3 &&y>=5*H/12 &&y<=2*H/3)
                    {
                        mode=1;
                    }
                    if(x>=3*L/4 && x<=11*L/12 && y>=5*H/12 &&y<=2*H/3)
                    {
                        mode=3;
                    }
                    //cout<<mode<<endl;
                }
                }
        }
//mode 1
        if(mode==1)
        {

                window.clear();
                window.draw(easy);      window.draw(ez);
                window.draw(medium);    window.draw(med);
                window.draw(hard);      window.draw(har);
                window.draw(custom);    window.draw(cus);
                window.draw(backtomenu1); window.draw(bac1);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    int x=sf::Mouse::getPosition(window).x;
                    int y=sf::Mouse::getPosition(window).y;
                    if(x<=19*L/20 &&x>=3*L/4 &&y>=3*H/4 &&y<=19*H/20)
                    {
                        mode=0;
                    }
                    if(x>=L/4 && x<=7*L/12 &&y>=13*H/18 &&y<=17*H/18)
                    {
                        mode=2;
                    }
                    if(x>=L/4 && x<=7*L/12 &&y>=H/18 &&y<=4*H/18)
                    {
                        mode=3;
                        cont=0;
                        gamemode=1;
                    }
                    if(x>=L/4 && x<=7*L/12 &&y>=5*H/18 &&y<=8*H/18)
                    {
                        mode=3;
                        cont=0;
                        gamemode=2;
                    }
                    if(x>=L/4 && x<=7*L/12 &&y>=9*H/18 &&y<=12*H/18)
                    {
                        mode=3;
                        cont=0;
                        gamemode=3;
                    }
                    //cout<<mode<<endl;
                }

        }
//mode 2
        if(mode==2)
        {
            if(tmp==0)
            {
            tmp=1;
            rownum=0;
            columnnum=0;
            minenum=0;
            rowtmp=0;
            columntmp=0;
            minetmp=0;
            cusmode=0;
            }

                window.clear();
                window.draw(row);       window.draw(rowt);
                window.draw(column);    window.draw(colt);
                window.draw(mines);     window.draw(mint);
                window.draw(backto12);  window.draw(bac12);
                window.draw(rown);      window.draw(rownt);
                window.draw(columnn);   window.draw(columnnt);
                window.draw(minesn);    window.draw(minesnt);
                window.draw(start);     window.draw(startt);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    int x=sf::Mouse::getPosition(window).x;
                    int y=sf::Mouse::getPosition(window).y;
                    if(x<=19*L/20 &&x>=3*L/4 &&y>=3*H/4 &&y<=19*H/20)
                    {
                        mode=0;
                    }
                    if(x<=14*L/20 &&x>=L/2 &&y>=3*H/4 &&y<=19*H/20)
                    {
                        gamemode=4;
                        mode=3;
                        cont=0;
                    }
                    if(x>=L/4 && x<=7*L/12 && y>=H/18 && y<=4*H/18)
                    {
                        cusmode=1;
                    }
                    if(x>=L/4 && x<=7*L/12 && y>=5*H/18 && y<=8*H/18)
                    {
                        cusmode=2;
                    }
                    if(x>=L/4 && x<=7*L/12 && y>=9*H/18 && y<=13*H/18)
                    {
                        cusmode=3;
                    }
                    //cout<<cusmode<<endl;
                }

                if(cusmode==1)
                {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(rownum>0) rowtmp=-1;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(rownum<80)rowtmp=1;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(rownum>9)rowtmp=-10;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(rownum<71)rowtmp=10;
                }
                }
                if(cusmode==2)
                {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(columnnum>0) columntmp=-1;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(columnnum<80)columntmp=1;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(columnnum>9)columntmp=-10;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(columnnum<71)columntmp=10;
                }
                }


                if(cusmode==3)
                {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(minenum>0) minetmp=-1;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(minenum<300)minetmp=1;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(minenum>9)minetmp=-10;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sf::sleep(sf::milliseconds(200));
                    if(minenum<291)minetmp=10;
                }
                }
            if(rowtmp!=0)
                {
                    rownum+=rowtmp;
                    rowtmp=0;
                }
            if(columntmp!=0)
            {
                columnnum+=columntmp;
                columntmp=0;
            }
            if(minetmp!=0)
            {
                minenum+=minetmp;
                minetmp=0;
            }
            rownt.setString(to_string(rownum));
            columnnt.setString(to_string(columnnum));
            minesnt.setString(to_string(minenum));

        }
//mode 3
        if(mode==3)
        {
            if(cont==0)
            {
                makebomb.clear();
            if(winmodetmp==0)
            {
                winmode=gamemode;
                winmodetmp=1;
            }

            if(gamemode==1)
            {
                Game(9,9,10);
                m=9;
                n=9;
                z=10;
                gamemode=0;
            }
            if(gamemode==2)
            {
                Game(16,16,40);
                m=16;
                n=16;
                z=40;
                gamemode=0;
            }
            if(gamemode==3)
            {
                Game(24,24,99);
                m=24;
                n=24;
                z=99;
                gamemode=0;
            }
            if(gamemode==4)
            {
                m=rownum;
                n=columnnum;
                z=minenum;
                Game(m,n,z);
                gamemode=0;
            }
            if(timetmp==0)
            {
                elapse1=clockt.getElapsedTime();
                timetmp=1;
            }
            if(flagtmp==0)
            {
                flag=z;
                flagtmp=1;
            }
            if(needtmp==0)
            {
                needtmp=1;
                need=m*n-z;
            }
            }

                window.clear();
                elapse2=clockt.getElapsedTime();
                timec.setString(to_string(int(elapse2.asSeconds()-elapse1.asSeconds())));
                bac1.setFont(font);
                window.draw(flagtext);
                window.draw(timetext);
                window.draw(backto13);  window.draw(back3);
                window.draw(timec);
                for(int i=0 ; i<m ; i++)
                {
                    for(int j=0 ; j<n ; j++)
                    {
                        if(visit1[j][i]==0)
                        {
                            window.draw(shape[i][j]);
                        }
                        else if(visit1[j][i]==1)
                        {
                            window.draw(shape1[i][j]);
                            window.draw(text[i][j]);
                        }
                        else if(visit1[j][i]==2)
                        {
                            window.draw(shapeflag[i][j]);
                        }
                    }
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::sleep(sf::milliseconds(200));
                    int x=sf::Mouse::getPosition(window).x;
                    int y=sf::Mouse::getPosition(window).y;
                    if(x<=19*L/20 &&x>=3*L/4 &&y>=3*H/4 &&y<=19*H/20)
                    {

                        mode=1;
                        cont=1;
                    }
                    int u=x/(L/70 +1);
                    int v=y/(L/70 +1);
                    if(v<m && u<n &&v>=0 && u>=0)
                    {
                        OpenNorm(v,u);
                        if(bombb[v][u]==1)
                        {
                             window.draw(shape1[u][v]);
                            mode=4;
                        }
                    }
//cout<<bombb[v][u]<<" "<<v<<" "<<u<<endl;

//                    for(int i=0 ; i<m ; i++)
//                    {
//                        for(int j=0 ; j<n ; j++)
//                        {
//                            cout<<visit1[i][j]<<" ";
//                        }
//                        cout<<endl;
//                    }
                    //cout<<need;
                    //cout<<endl;

                    if(need==0)
                    {
                        window.draw(shape1[u][v]); window.draw(text[u][v]);
                        mode=5;
                    }
                }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))

                {
                    sf::sleep(sf::milliseconds(200));
                    //cout<<flag;
                        int x=sf::Mouse::getPosition(window).x;
                        int y=sf::Mouse::getPosition(window).y;

                        int u=x/(L/70 +1);
                        int v=y/(L/70 +1);
                        if(v<m && u<n &&v>=0 && u>=0)
                        {
                            if(visit1[v][u]!=1)
                            {
                                    if (visit1[v][u]==0)
                                    {
                                        flag--;
                                    }
                                    if (visit1[v][u]==2)
                                    {
                                        flag++;
                                    }
                                    visit1[v][u]=2-visit1[v][u];
                                    //cout<<flag<<endl;
                            }
                        }

                }
                 flagt.setString(to_string(flag));
                window.draw(flagt);
        }
//mode 4
        if(mode==4)
        {
            cont=0;
            window.draw(gameover); window.draw(gameovert);
            window.draw(backtomenu4); window.draw(menu4t);
            window.draw(che);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x=sf::Mouse::getPosition(window).x;
                int y=sf::Mouse::getPosition(window).y;
                //cout<<x<<" "<<y<<endl;
                if(x<=L/2 &&x>=L/3 &&y>=3*H/4 &&y<=11*H/12)
                {
                    mode=0;
                    makebomb.clear();
                }
                //cout<<mode<<endl;
            }
        }
        //mode 5
        if(mode==5)
        {
            cont=0;
            window.draw(congratulation);    window.draw(congratt);

            window.draw(backtomenu4); window.draw(menu4t);
            window.draw(che);

            if(pointtmp==0)
            {
                elapse2=clockt.getElapsedTime();
                point=int(elapse2.asSeconds()-elapse1.asSeconds());
                pointtmp=1;
                cout<<point<<endl;
                cout<<winmode<<endl;
            int scoreez, scoremed,scorehar;
            if(winmode==1)
            {
                ifstream highez("higheasy.txt");
                stringstream geek;
                string Ezhigh;
                getline(highez, Ezhigh);
                geek<<Ezhigh;
                geek>>scoreez;
                cout<<scoreez<<endl;
                if(point<scoreez || scoreez==-1)
                {
                    scoreez=point;
                    cout<<"ok"<<endl;
                    ofstream Highez1("higheasy.txt");
                    Highez1<<scoreez;
                    window.draw(newhigh);           window.draw(newhight);
                    Highez1.close();

                }
            }
            if(winmode==2)
            {
                ifstream highmedfile("highmed.txt");
                stringstream geek;
                string medhighstring;
                getline(highmedfile,medhighstring);
                geek<<medhighstring;
                geek>>scoremed;
                cout<<scoremed<<endl;
                if(point<scoremed || scoremed==-1)
                {
                    scoremed=point;
                    cout<<"ok"<<endl;
                    ofstream Highmed1("highmed.txt");
                    Highmed1<<scoremed;
                    window.draw(newhigh);           window.draw(newhight);
                    Highmed1.close();
                }
            }
            if(winmode==3)
            {
                ifstream highhardfile("highhard.txt");
                stringstream geek;
                string harhighstring;
                getline(highhardfile,harhighstring);
                geek<<harhighstring;
                geek>>scorehar;
                cout<<scorehar<<endl;
                if(point<scorehar|| scorehar==-1)
                {
                    scorehar=point;
                    cout<<"ok"<<endl;
                    ofstream Highhar1("highhard.txt");
                    Highhar1<<scorehar;
                    window.draw(newhigh);           window.draw(newhight);
                    Highhar1.close();
                }
            }
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(sf::milliseconds(200));
                int x=sf::Mouse::getPosition(window).x;
                int y=sf::Mouse::getPosition(window).y;
                cout<<x<<" "<<y<<endl;
                if(x<=L/2 &&x>=L/3 &&y>=3*H/4 &&y<=11*H/12)
                {
                    mode=0;
                    makebomb.clear();
                }
                cout<<mode<<endl;
            }
        }
//mode 6
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
                cout<<x<<" "<<y<<endl;
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

void Game(int m,int n, int z)
{
    srand(time(0));
    cout<<m<<" "<<n<<" "<<z<<endl;
    for(int i=0; i<m*n; i++)
    {
        makebomb.push_back(i);
        bomb[i]=0;
        local[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            localb[i][j]=0;
            bombb[i][j]=0;
            cout<<bombb[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle(makebomb.begin(), makebomb.end(), default_random_engine(num));
    for(int i=0; i<z; i++)
    {
        bomb[makebomb[i]]=1;
    }
    int sum=0; int index=0;
    for(int i=0; i<m*n; i++)
    {
        //cout<<bomb[i];
        sum+=bomb[i];
        index++;
//        cout<<i/n<<" "<<i%n<<endl;
        int x=i/n;
        int y=i%n;
        bombb[x][y]=bomb[i];
    }
    //cout<<endl;
    //cout<<sum<<" "<<index<<endl;
//    for(int i=0; i<m; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout<<bombb[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=0 && i!=m-1 && j!=0 && j!=n-1) localb[i][j]=bombb[i][j+1]+bombb[i-1][j+1]+bombb[i+1][j+1]+bombb[i][j]+bombb[i+1][j]+bombb[i-1][j]+bombb[i][j-1]+bombb[i+1][j-1]+bombb[i-1][j-1];
            if(i==0)
            {
                if(j==0) localb[i][j]=bombb[i][j+1]+bombb[i+1][j+1]+bombb[i+1][j];
                else if(j==n-1) localb[i][j]=bombb[i][j-1]+bombb[i+1][j-1]+bombb[i+1][j];
                else localb[i][j]=bombb[i][j-1]+bombb[i+1][j-1]+bombb[i][j+1]+bombb[i+1][j+1]+bombb[i+1][j];
            }
            if(i==m-1)
            {
                if(j==0) localb[i][j]=bombb[i][j+1]+bombb[i-1][j+1]+bombb[i-1][j];
                else if(j==n-1) localb[i][j]=bombb[i][j-1]+bombb[i-1][j-1]+bombb[i-1][j];
                else localb[i][j]=bombb[i][j-1]+bombb[i][j+1]+bombb[i-1][j]+bombb[i-1][j+1]+bombb[i-1][j-1];
            }

            if(j==0)
            {
                if(i!=0 && i!=m-1)
                    localb[i][j]=bombb[i][j+1]+bombb[i+1][j+1]+bombb[i-1][j+1]+bombb[i+1][j]+bombb[i-1][j];
            }
            if(j==n-1)
            {
                if(i!=0 && i!=m-1)
                    localb[i][j]=bombb[i][j-1]+bombb[i+1][j-1]+bombb[i-1][j-1]+bombb[i+1][j]+bombb[i-1][j];
            }
            if(bombb[i][j]==1)localb[i][j]=9;
        }
    }
//    for(int i=0; i<m; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout<<localb[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int u=(L/70 +1)*i;
            int v=(L/70 +1)*j;
            visit1[i][j]=0;

            text[i][j].setFont(font);
            text[i][j].setString(to_string(localb[j][i]));
            text[i][j].setCharacterSize(L/70);
            text[i][j].setFillColor(sf::Color::Red);
            text[i][j].setStyle(sf::Text::Bold | sf::Text::Italic);
            text[i][j].setPosition(u*1.f,v*1.f);

            shape[i][j].setSize(sf::Vector2f(L/70.f,L/70.f));
            shape[i][j].setPosition(u*1.f,v*1.f);
            shape[i][j].setFillColor(sf::Color(80,80,200));

            shape1[i][j].setSize(sf::Vector2f(L/70.f,L/70.f));
            shape1[i][j].setPosition(u*1.f,v*1.f);
            int m=20*(localb[i][j]+1);
            shape1[j][i].setFillColor(sf::Color(m,0,0));

            shapeflag[i][j].setSize(sf::Vector2f(L/70.f,L/70.f));
            shapeflag[i][j].setPosition(u*1.f,v*1.f);
            shapeflag[i][j].setFillColor(sf::Color(0,200,0));

            shapebit[i][j].setSize(sf::Vector2f(L/70.f,L/70.f));
            shapebit[i][j].setPosition(u*1.f,v*1.f);
            shapebit[i][j].setFillColor(sf::Color(100,100,100));
        }
    }



}



void OpenNorm(int v,int u)
{
    toado A, B;
    A.x=v;
    A.y=u;
    opennorm.push_back(A);
    int index=1;
    while(!opennorm.empty())
    {

        int x0=opennorm[0].x;
        int y0=opennorm[0].y;
        if(visit1[x0][y0]==2) flag++;
        if(visit1[x0][y0]!=1)
        {
        visit1[x0][y0]=1;
        need--;
        }
        if(localb[x0][y0]==0)
        {
        if(x0!=m-1 && visit1[x0+1][y0]!=1)
        {
            B.x=x0+1;
            B.y=y0;
            opennorm.push_back(B);
            index++;
        }
        if(x0!=0 && visit1[x0-1][y0]!=1)
        {
            B.x=x0-1;
            B.y=y0;
            opennorm.push_back(B);
            index++;
        }
        if(x0!=m-1 && y0!=n-1 && visit1[x0+1][y0+1]!=1)
        {
            B.x=x0+1;
            B.y=y0+1;
            opennorm.push_back(B);
            index++;
        }
        if(x0!=m-1 && y0!=0 && visit1[x0+1][y0-1]!=1)
        {
            B.x=x0+1;
            B.y=y0-1;
            opennorm.push_back(B);
            index++;
        }
        if(x0!=0 && y0!=0 && visit1[x0-1][y0-1]!=1)
        {
            B.x=x0-1;
            B.y=y0-1;
            opennorm.push_back(B);
            index++;
        }
        if(x0!=0 && y0!=n-1 && visit1[x0-1][y0+1]!=1)
        {
            B.x=x0-1;
            B.y=y0+1;
            opennorm.push_back(B);
            index++;
        }
        if(y0!=n-1 && visit1[x0][y0+1]!=1)
        {
            B.x=x0;
            B.y=y0+1;
            opennorm.push_back(B);
            index++;
        }
        if(y0!=0 && visit1[x0][y0-1]!=1)
        {
            B.x=x0;
            B.y=y0-1;
            opennorm.push_back(B);
            index++;
        }
        }
        opennorm.erase(opennorm.begin());
        index--;
    }
}
void FullSetup0()
{
    for(int i=1; i<=10 ; i++)
    {
        block[i].setFillColor(sf::Color(0,0,i*2));
        block[i].setSize(sf::Vector2f(20.f,20.f));
    }
//mode 0

texture.loadFromImage(title);

sprite.setTexture(texture);
sprite.setPosition(L/5,H/24);

    minesweeper.setSize(sf::Vector2f(L/2.f,H/3.f));
    minesweeper.setPosition(L/4.f,H/24.f);
    minesweeper.setFillColor(sf::Color(0,0,200));
    minsw.setFont(font);
    minsw.setString("Minesweeper");
    minsw.setCharacterSize(L/18);
    minsw.setFillColor(sf::Color::Red);
    minsw.setStyle(sf::Text::Bold | sf::Text::Italic);
    minsw.setPosition(L/3.f,H/9.f);

    newgame.setSize(sf::Vector2f(L/3.f,H/4.f));
    newgame.setPosition(L/3.f,5*H/12.f);
    newgame.setFillColor(sf::Color(0,0,200));
    newg.setFont(font);
    newg.setString("New game");
    newg.setCharacterSize(L/27);
    newg.setFillColor(sf::Color::Red);
    newg.setStyle(sf::Text::Bold | sf::Text::Italic);
    newg.setPosition(19*L/48.f,H/2.f);

    continuegame.setSize(sf::Vector2f(L/6.f,H/4.f));
    continuegame.setPosition(3*L/4.f,5*H/12.f);
    continuegame.setFillColor(sf::Color(0,0,200));
    cong.setFont(font);
    cong.setString("Continue");
    cong.setCharacterSize(L/36);
    cong.setFillColor(sf::Color::Red);
    cong.setStyle(sf::Text::Bold | sf::Text::Italic);
    cong.setPosition(37*L/48.f,H/2.f);

    highscore.setSize(sf::Vector2f(L/3.f,H/4.f));
    highscore.setPosition(L/3.f,17*H/24.f);
    highscore.setFillColor(sf::Color(0,0,200));
    highs.setFont(font);
    highs.setString("High scores");
    highs.setCharacterSize(L/27);
    highs.setFillColor(sf::Color::Red);
    highs.setStyle(sf::Text::Bold | sf::Text::Italic);
    highs.setPosition(19*L/48.f,19*H/24.f);
}
void FullSetup1()
{
    easy.setSize(sf::Vector2f(L/3.f,H/6.f));
    easy.setPosition(L/4.f,H/18.f);
    easy.setFillColor(sf::Color(0,0,200));
    ez.setFont(font);
    ez.setString("Easy");
    ez.setCharacterSize(L/20);
    ez.setFillColor(sf::Color::Red);
    ez.setStyle(sf::Text::Bold | sf::Text::Italic);
    ez.setPosition(11*L/32.f,H/15.f);

    medium.setSize(sf::Vector2f(L/3.f,H/6.f));
    medium.setPosition(L/4.f,5*H/18.f);
    medium.setFillColor(sf::Color(0,0,200));
    med.setFont(font);
    med.setString("Medium");
    med.setCharacterSize(L/20);
    med.setFillColor(sf::Color::Red);
    med.setStyle(sf::Text::Bold | sf::Text::Italic);
    med.setPosition(11*L/32.f,H/15+4*H/18.f);

    hard.setSize(sf::Vector2f(L/3.f,H/6.f));
    hard.setPosition(L/4.f,H/2.f);
    hard.setFillColor(sf::Color(0,0,200));
    har.setFont(font);
    har.setString("Hard");
    har.setCharacterSize(L/20);
    har.setFillColor(sf::Color::Red);
    har.setStyle(sf::Text::Bold | sf::Text::Italic);
    har.setPosition(11*L/32.f,H/15+8*H/18.f);

    custom.setSize(sf::Vector2f(L/3.f,H/6.f));
    custom.setPosition(L/4.f,13*H/18.f);
    custom.setFillColor(sf::Color(0,0,200));
    cus.setFont(font);
    cus.setString("Custom");
    cus.setCharacterSize(L/20);
    cus.setFillColor(sf::Color::Red);
    cus.setStyle(sf::Text::Bold | sf::Text::Italic);
    cus.setPosition(11*L/32.f,H/15+12*H/18.f);

    backtomenu1.setSize(sf::Vector2f(L/5.f,H/5.f));
    backtomenu1.setPosition(3*L/4.f,3*H/4.f);
    backtomenu1.setFillColor(sf::Color(0,0,120));
    bac1.setFont(font);
    bac1.setString("Back");
    bac1.setCharacterSize(L/20);
    bac1.setFillColor(sf::Color::Red);
    bac1.setStyle(sf::Text::Bold | sf::Text::Italic);
    bac1.setPosition(4*L/5.f,4*H/5.f);
}
void FullSetup2()
//mode 2
{
    row.setSize(sf::Vector2f(L/3.f,H/6.f));
    row.setPosition(L/4.f,H/18.f);
    row.setFillColor(sf::Color(0,0,200));
    rowt.setFont(font);
    rowt.setString("Rows (1-80)");
    rowt.setCharacterSize(L/25);
    rowt.setFillColor(sf::Color::Red);
    rowt.setStyle(sf::Text::Bold | sf::Text::Italic);
    rowt.setPosition(9*L/32.f,H/15.f);

    rown.setSize(sf::Vector2f(L/15.f,H/6.f));
    rown.setPosition(5*L/8.f,H/18.f);
    rown.setFillColor(sf::Color(0,0,200));
    rownt.setFont(font);
    rownt.setCharacterSize(L/25);
    rownt.setFillColor(sf::Color::Red);
    rownt.setStyle(sf::Text::Bold | sf::Text::Italic);
    rownt.setPosition(17*L/64+3*L/8.f,H/15.f);

    column.setSize(sf::Vector2f(L/3.f,H/6.f));
    column.setPosition(L/4.f,5*H/18.f);
    column.setFillColor(sf::Color(0,0,200));
    colt.setFont(font);
    colt.setString("Columns(1-80)");
    colt.setCharacterSize(L/25);
    colt.setFillColor(sf::Color::Red);
    colt.setStyle(sf::Text::Bold | sf::Text::Italic);
    colt.setPosition(17*L/64.f,H/15+4*H/18.f);

    columnn.setSize(sf::Vector2f(L/15.f,H/6.f));
    columnn.setPosition(5*L/8.f,5*H/18.f);
    columnn.setFillColor(sf::Color(0,0,200));
    columnnt.setFont(font);
    columnnt.setCharacterSize(L/25);
    columnnt.setFillColor(sf::Color::Red);
    columnnt.setStyle(sf::Text::Bold | sf::Text::Italic);
    columnnt.setPosition(17*L/64+3*L/8.f,H/15+4*H/18.f);

    mines.setSize(sf::Vector2f(L/3.f,H/6.f));
    mines.setPosition(L/4.f,9*H/18.f);
    mines.setFillColor(sf::Color(0,0,200));
    mint.setFont(font);
    mint.setString("Mines(1-300)");
    mint.setCharacterSize(L/25);
    mint.setFillColor(sf::Color::Red);
    mint.setStyle(sf::Text::Bold | sf::Text::Italic);
    mint.setPosition(9*L/32.f,H/15+8*H/18.f);

    minesn.setSize(sf::Vector2f(L/15.f,H/6.f));
    minesn.setPosition(5*L/8.f,9*H/18.f);
    minesn.setFillColor(sf::Color(0,0,200));
    minesnt.setFont(font);
    minesnt.setCharacterSize(L/25);
    minesnt.setFillColor(sf::Color::Red);
    minesnt.setStyle(sf::Text::Bold | sf::Text::Italic);
    minesnt.setPosition(17*L/64+3*L/8.f,H/15+8*H/18.f);

    backto12.setSize(sf::Vector2f(L/5.f,H/5.f));
    backto12.setPosition(3*L/4.f,3*H/4.f);
    backto12.setFillColor(sf::Color(0,0,200));
    bac12.setFont(font);
    bac12.setString("Back");
    bac12.setCharacterSize(L/25);
    bac12.setFillColor(sf::Color::Red);
    bac12.setStyle(sf::Text::Bold | sf::Text::Italic);
    bac12.setPosition(4*L/5.f,4*H/5.f);

    start.setSize(sf::Vector2f(L/5.f,H/5.f));
    start.setPosition(L/2.f,3*H/4.f);
    start.setFillColor(sf::Color(0,0,200));
    startt.setFont(font);
    startt.setString("Start");
    startt.setCharacterSize(L/25);
    startt.setFillColor(sf::Color::Red);
    startt.setStyle(sf::Text::Bold | sf::Text::Italic);
    startt.setPosition(4*L/5-L/4.f,4*H/5.f);
}
void FullSetup3()
{
    backto13.setSize(sf::Vector2f(L/5.f,H/5.f));
    backto13.setPosition(3*L/4.f,3*H/4.f);
    backto13.setFillColor(sf::Color(0,0,120));
    back3.setFont(font);
    back3.setString("Back");
    back3.setCharacterSize(L/25);
    back3.setFillColor(sf::Color::Red);
    back3.setStyle(sf::Text::Bold | sf::Text::Italic);
    back3.setPosition(4*L/5.f,4*H/5.f);

    flagtext.setFont(font);
    flagtext.setString("Flags:");
    flagtext.setCharacterSize(L/20);
    flagtext.setFillColor(sf::Color::Red);
    flagtext.setStyle(sf::Text::Bold | sf::Text::Italic);
    flagtext.setPosition(3*L/4.f,H/2.f);
    flagt.setFont(font);
    flagt.setCharacterSize(L/20);
    flagt.setFillColor(sf::Color::Red);
    flagt.setStyle(sf::Text::Bold | sf::Text::Italic);
    flagt.setPosition(11*L/12.f,H/2.f);

    timetext.setFont(font);
    timetext.setString("Time:");
    timetext.setCharacterSize(L/20);
    timetext.setFillColor(sf::Color::Red);
    timetext.setStyle(sf::Text::Bold | sf::Text::Italic);
    timetext.setPosition(3*L/4.f,3*H/5.f);
    timec.setFont(font);
    timec.setCharacterSize(L/20);
    timec.setFillColor(sf::Color::Red);
    timec.setStyle(sf::Text::Bold | sf::Text::Italic);
    timec.setPosition(29*L/32.f,3*H/5.f);
}
void FullSetup4()
{
    gameover.setSize(sf::Vector2f(L/6.f,H/6.f));
    gameover.setPosition(L/12.f,3*H/4.f);
    gameover.setFillColor(sf::Color(0,0,120));
    gameovert.setFont(font);
    gameovert.setString("Game over");
    gameovert.setCharacterSize(L/40);
    gameovert.setFillColor(sf::Color::Red);
    gameovert.setStyle(sf::Text::Bold | sf::Text::Italic);
    gameovert.setPosition(5*L/48.f,38*H/48.f);

    backtomenu4.setSize(sf::Vector2f(L/6.f,H/6.f));
    backtomenu4.setPosition(L/3.f,3*H/4.f);
    backtomenu4.setFillColor(sf::Color(0,0,120));
    menu4t.setFont(font);
    menu4t.setString("Back");
    menu4t.setCharacterSize(L/40);
    menu4t.setFillColor(sf::Color::Red);
    menu4t.setStyle(sf::Text::Bold | sf::Text::Italic);
    menu4t.setPosition(18*L/48.f,38*H/48.f);

    che.setSize(sf::Vector2f(L/4.f,H/2.f));
    che.setPosition(3*L/4.f,H/2.f);
    che.setFillColor(sf::Color::Black);
}
void FullSetup5()
{
    congratulation.setSize(sf::Vector2f(L/5.f,H/5.f));
    congratulation.setPosition(L/20.f,3*H/4.f);
    congratulation.setFillColor(sf::Color(0,0,120));
    congratt.setFont(font);
    congratt.setString("You win");
    congratt.setCharacterSize(L/40);
    congratt.setFillColor(sf::Color::Red);
    congratt.setStyle(sf::Text::Bold | sf::Text::Italic);
    congratt.setPosition(L/10.f,4*H/5.f);

    newhigh.setSize(sf::Vector2f(L/5.f,H/5.f));
    newhigh.setPosition(11*L/20.f,3*H/4.f);
    newhigh.setFillColor(sf::Color(0,0,120));
    newhight.setFont(font);
    newhight.setString("New highscore");
    newhight.setCharacterSize(L/75);
    newhight.setFillColor(sf::Color::Red);
    newhight.setStyle(sf::Text::Bold | sf::Text::Italic);
    newhight.setPosition(7*L/20.f,4*H/5.f);
}
void FullSetup6()
{
    higheasy.setSize(sf::Vector2f(L/3.f,H/6.f));
    higheasy.setPosition(L/4.f,H/18.f);
    higheasy.setFillColor(sf::Color(0,0,200));
    highez.setFont(font);
    highez.setString("Easy");
    highez.setCharacterSize(L/20);
    highez.setFillColor(sf::Color::Red);
    highez.setStyle(sf::Text::Bold | sf::Text::Italic);
    highez.setPosition(11*L/32.f,H/15.f);
    numez.setFont(font);
    //numez.setString("Easy");
    numez.setCharacterSize(L/20);
    numez.setFillColor(sf::Color::Red);
    numez.setStyle(sf::Text::Bold | sf::Text::Italic);
    numez.setPosition(29*L/48.f,H/15.f);

    highmedium.setSize(sf::Vector2f(L/3.f,H/6.f));
    highmedium.setPosition(L/4.f,5*H/18.f);
    highmedium.setFillColor(sf::Color(0,0,200));
    highmed.setFont(font);
    highmed.setString("Medium");
    highmed.setCharacterSize(L/20);
    highmed.setFillColor(sf::Color::Red);
    highmed.setStyle(sf::Text::Bold | sf::Text::Italic);
    highmed.setPosition(11*L/32.f,H/15+4*H/18.f);
    nummed.setFont(font);
    //nummed.setString("Medium");
    nummed.setCharacterSize(L/20);
    nummed.setFillColor(sf::Color::Red);
    nummed.setStyle(sf::Text::Bold | sf::Text::Italic);
    nummed.setPosition(29*L/48.f,H/15+4*H/18.f);

    highhard.setSize(sf::Vector2f(L/3.f,H/6.f));
    highhard.setPosition(L/4.f,9*H/18.f);
    highhard.setFillColor(sf::Color(0,0,200));
    highhar.setFont(font);
    highhar.setString("Hard");
    highhar.setCharacterSize(L/20);
    highhar.setFillColor(sf::Color::Red);
    highhar.setStyle(sf::Text::Bold | sf::Text::Italic);
    highhar.setPosition(11*L/32.f,H/15+8*H/18.f);
    numhar.setFont(font);
    //numhar.setString("Hard");
    numhar.setCharacterSize(L/20);
    numhar.setFillColor(sf::Color::Red);
    numhar.setStyle(sf::Text::Bold | sf::Text::Italic);
    numhar.setPosition(29*L/48.f,H/15+8*H/18.f);

    backtomenu6.setSize(sf::Vector2f(L/5.f,H/5.f));
    backtomenu6.setPosition(3*L/4.f,3*H/4.f);
    backtomenu6.setFillColor(sf::Color(0,0,120));
    bac6.setFont(font);
    bac6.setString("Back");
    bac6.setCharacterSize(L/20);
    bac6.setFillColor(sf::Color::Red);
    bac6.setStyle(sf::Text::Bold | sf::Text::Italic);
    bac6.setPosition(4*L/5.f,4*H/5.f);
}
