#include<headerfiles.h>
#include <math.h>
#include <string>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include <cstdlib>
#include <ctime>
#include<chrono>
#include <time.h>
#include <random>
int life=6;
///declaring root 2 so as to simply use the macro;

void square(int x1,int y1,int side)
{
    ///this function will draw a square so as to make drawing the shape easy so use just have to input the radius/side, x, and y points;
    int x2,y2;
    x2 = x1 + side;
    y2 = y1 + side;
    setcolor(WHITE);
    for(int i = 0;i < 5;i++)
    rectangle(x1 - i,y1 - i,x2 + i,y2 + i);
}
void display ()
{
        ///declaring the screen width and height
    DWORD screenwidth=GetSystemMetrics(SM_CXSCREEN);
    DWORD screenheight=GetSystemMetrics(SM_CYSCREEN);

    ///initiating the graphical window
    initwindow(screenwidth,screenheight,"Falling Objects");
}
void lives(int x,int y,int life)
{
        if (life==1)
        {

        }
        if(life==2){
        circle(x+20,y,8);
        }
        if (life==3){
        circle(x+20,y,8);
        circle(x+40,y,8);
        }
        if (life==4){
        circle(x+20,y,8);
        circle(x+40,y,8);
        circle(x+60,y,8);
        }
        if (life==5){
        circle(x+20,y,8);
        circle(x+40,y,8);
        circle(x+60,y,8);
        circle(x+80,y,8);
        }
        if (life==6){

        circle(x+20,y,8);
        circle(x+40,y,8);
        circle(x+60,y,8);
        circle(x+80,y,8);
        circle(x+100,y,8);
        }
}
int putsq6(int speed,int run)
{
    /// this function will do the main job it will draw the square and do the main part of the game;

    char* char_type="0";    ///declaring so as to display on the screen
    char* char_type1="0";
    string s;
    /// Declaring the points
    POINT cursorposition;
    int page = 0 , highscore; ///declaring the basic variables
    srand( time(0) ); /// seeding the rand ();
    ///reading the value of the high score and assigning it to the string s;
    ifstream ramesh;
    ramesh.open("high score.txt");
    ramesh>>s;

    /// the value stored in the file gets converted to an integer so that it can be manipulated later

    stringstream iamtired (s);
    iamtired >> highscore;

    while(1)
    {
        int a = rand() % 1400 + 50;
        setcolor(WHITE);
            for(int i = 0;i < 144;i++)
            {
                setactivepage( page );                      ///avoid flicker
                setvisualpage( 1-page );                    ///avoid flicker
                cleardevice();                              ///avoid flicker
                square(a, speed * i, 100);                  ///drawing the square ( coefficient of i decides the speed
                GetCursorPos(&cursorposition);              ///get the cursor position
                if( GetAsyncKeyState (VK_LBUTTON) && i<126)
                {
                    if( cursorposition.x <= a + 100 && cursorposition.x >= a)                   ///checking if the cursor was on the square (x-Axis)
                    {
                        if( cursorposition.y <= speed*i + 100 && cursorposition.y >=  speed*i)  ///checking if the cursor was on the square ( y axis )
                        {
                            ///at this point the player gains a point;
                            cleardevice();
                            run += 1;///increase point

                            ///this part of the code will convert the points gained by the user to a char* so a as to print on the graphical window

                                stringstream strs;
                                strs << run;
                                string temp_str = strs.str();
                                char_type = (char*) temp_str.c_str();


                            if (run >= highscore)
                            {

                                ///manipulating high scores

                                highscore = run;            ///  int high score now gets the value of the present points if the points are greater than the high score
                                s = to_string(highscore);   /// the now changed high score value gets assigned to the string s

                                /// the new score now gets written to the file to be saved as the new high score
                                ofstream suresh;
                                suresh.open("high score.txt");
                                suresh<<s;

                            }

                            cleardevice();
                            break;
                        }
                    }
                }
                else if (i==134)
                {
                    life--;
                }
                if (life==0)
                {
                    cout<<"GAME OVER, YOUR SCORE : "<<run;
                    cout<<"\nHIGH SCORE : "<<highscore;
                    cleardevice();
                    outtext("GAMEOVER PLEASE TRY AGAIN...");
                    playyy("gameover");
                    getch();
                    return 0;
                }

                string highscore_str;///declaring a new string so as to read the high score from

                ///read the high score from the file and assign it to another string

                ifstream highsc;
                highsc.open("high score.txt");
                highsc >> highscore_str;

                ///since the outtextxy function only takes a char* as an input, the following again converts the newly read value of the high score and then displays it on the screen

                char* char_type2 = &highscore_str[0u];

                ///converting the present points to a char*

                stringstream strs;
                strs << highscore;
                string temp_str = strs.str();
                char_type1 = (char*) temp_str.c_str();

                ///printing the  value on the screen constantly because of the for loop

                outtextxy(1280,700,"YOUR SCORE : ");
                outtextxy(1280,720,"HIGH SCORE : ");
                outtextxy(1400,720,char_type2);
                outtextxy(1400,700,char_type);
                page=1-page;///avoid flicker
                lives(1420,700,life);
                if (run>=50)
                {
                    cout<<"YOU ARE THE BOSS IN THIS GAME\n";
                    closegraph();
                    return 1;
                }
            }
        }

    }

    int putsq5(int speed,int run)
{
    /// this function will do the main job it will draw the square and do the main part of the game;

    char* char_type="0";    ///declaring so as to display on the screen
    char* char_type1="0";
    string s;
    /// Declaring the points
    POINT cursorposition;
    int page = 0 , highscore; ///declaring the basic variables
    srand( time(0) ); /// seeding the rand ();
    ///reading the value of the high score and assigning it to the string s;
    ifstream ramesh;
    ramesh.open("high score.txt");
    ramesh>>s;

    /// the value stored in the file gets converted to an integer so that it can be manipulated later

    stringstream iamtired (s);
    iamtired >> highscore;

    while(1)
    {
        int a = rand() % 1400 + 50;
        setcolor(WHITE);
            for(int i = 0;i < 172;i++)
            {
                setactivepage( page );                      ///avoid flicker
                setvisualpage( 1-page );                    ///avoid flicker
                cleardevice();                              ///avoid flicker
                square(a, speed * i, 100);                  ///drawing the square ( coefficient of i decides the speed
                GetCursorPos(&cursorposition);              ///get the cursor position
                if( GetAsyncKeyState (VK_LBUTTON) && i<152)
                {
                    if( cursorposition.x <= a + 100 && cursorposition.x >= a)                   ///checking if the cursor was on the square (x-Axis)
                    {
                        if( cursorposition.y <= speed*i + 100 && cursorposition.y >=  speed*i)  ///checking if the cursor was on the square ( y axis )
                        {
                            ///at this point the player gains a point;
                            cleardevice();
                            run += 1;///increase point

                            ///this part of the code will convert the points gained by the user to a char* so a as to print on the graphical window

                                stringstream strs;
                                strs << run;
                                string temp_str = strs.str();
                                char_type = (char*) temp_str.c_str();


                            if (run >= highscore)
                            {

                                ///manipulating high scores

                                highscore = run;            ///  int high score now gets the value of the present points if the points are greater than the high score
                                s = to_string(highscore);   /// the now changed high score value gets assigned to the string s

                                /// the new score now gets written to the file to be saved as the new high score
                                ofstream suresh;
                                suresh.open("high score.txt");
                                suresh<<s;

                            }

                            cleardevice();
                            break;
                        }
                    }
                }
                else if (i==165)
                {
                    life--;
                }
                if (life==0)
                {
                    cout<<"GAME OVER, YOUR SCORE : "<<run;
                    cout<<"\nHIGH SCORE : "<<highscore;
                    cleardevice();
                    outtext("GAMEOVER PLEASE TRY AGAIN...");
                    playyy("gameover");
                    getch();
                    return 0;
                }

                string highscore_str;///declaring a new string so as to read the high score from

                ///read the high score from the file and assign it to another string

                ifstream highsc;
                highsc.open("high score.txt");
                highsc >> highscore_str;

                ///since the outtextxy function only takes a char* as an input, the following again converts the newly read value of the high score and then displays it on the screen

                char* char_type2 = &highscore_str[0u];

                ///converting the present points to a char*

                stringstream strs;
                strs << highscore;
                string temp_str = strs.str();
                char_type1 = (char*) temp_str.c_str();

                ///printing the  value on the screen constantly because of the for loop

                outtextxy(1280,700,"YOUR SCORE : ");
                outtextxy(1280,720,"HIGH SCORE : ");
                outtextxy(1400,720,char_type2);
                outtextxy(1400,700,char_type);
                page=1-page;///avoid flicker
                lives(1420,700,life);
                if (run>=40)
                {
                    putsq6(6,run);
                }

            }
        }

    }
    int putsq4(int speed,int & run)
{
    /// this function will do the main job it will draw the square and do the main part of the game;

    char* char_type="0";    ///declaring so as to display on the screen
    char* char_type1="0";
    string s;
    /// Declaring the points
    POINT cursorposition;
    int page = 0 , highscore; ///declaring the basic variables
    srand( time(0) ); /// seeding the rand ();
    ///reading the value of the high score and assigning it to the string s;
    ifstream ramesh;
    ramesh.open("high score.txt");
    ramesh>>s;

    /// the value stored in the file gets converted to an integer so that it can be manipulated later

    stringstream iamtired (s);
    iamtired >> highscore;

    while(1)
    {
        int a = rand() % 1400 + 50;
        setcolor(WHITE);
            for(int i = 0;i < 216;i++)
            {
                setactivepage( page );                      ///avoid flicker
                setvisualpage( 1-page );                    ///avoid flicker
                cleardevice();                              ///avoid flicker
                square(a, speed * i, 100);                  ///drawing the square ( coefficient of i decides the speed
                GetCursorPos(&cursorposition);              ///get the cursor position
                if( GetAsyncKeyState (VK_LBUTTON) && i<190)
                {
                    if( cursorposition.x <= a + 100 && cursorposition.x >= a)                   ///checking if the cursor was on the square (x-Axis)
                    {
                        if( cursorposition.y <= speed*i + 100 && cursorposition.y >=  speed*i)  ///checking if the cursor was on the square ( y axis )
                        {
                            ///at this point the player gains a point;
                            cleardevice();
                            run += 1;///increase point

                            ///this part of the code will convert the points gained by the user to a char* so a as to print on the graphical window

                                stringstream strs;
                                strs << run;
                                string temp_str = strs.str();
                                char_type = (char*) temp_str.c_str();


                            if (run >= highscore)
                            {

                                ///manipulating high scores

                                highscore = run;            ///  int high score now gets the value of the present points if the points are greater than the high score
                                s = to_string(highscore);   /// the now changed high score value gets assigned to the string s

                                /// the new score now gets written to the file to be saved as the new high score
                                ofstream suresh;
                                suresh.open("high score.txt");
                                suresh<<s;

                            }

                            cleardevice();
                            break;
                        }
                    }
                }
                else if (i==206)
                {
                    life--;
                }
                if (life==0)
                {
                    cout<<"GAME OVER, YOUR SCORE : "<<run;
                    cout<<"\nHIGH SCORE : "<<highscore;
                    cleardevice();
                    outtext("GAMEOVER PLEASE TRY AGAIN...");
                    playyy("gameover");
                    getch();
                    return 0;
                }

                string highscore_str;///declaring a new string so as to read the high score from

                ///read the high score from the file and assign it to another string

                ifstream highsc;
                highsc.open("high score.txt");
                highsc >> highscore_str;

                ///since the outtextxy function only takes a char* as an input, the following again converts the newly read value of the high score and then displays it on the screen

                char* char_type2 = &highscore_str[0u];

                ///converting the present points to a char*

                stringstream strs;
                strs << highscore;
                string temp_str = strs.str();
                char_type1 = (char*) temp_str.c_str();

                ///printing the  value on the screen constantly because of the for loop

                outtextxy(1280,700,"YOUR SCORE : ");
                outtextxy(1280,720,"HIGH SCORE : ");
                outtextxy(1400,720,char_type2);
                outtextxy(1400,700,char_type);
                page=1-page;///avoid flicker
                lives(1420,700,life);
                if (run >= 30)
                {
                    putsq5(5,run);
                }

            }
        }

    }
int putsq3(int speed,int &run)
{
    /// this function will do the main job it will draw the square and do the main part of the game;

    char* char_type="0";    ///declaring so as to display on the screen
    char* char_type1="0";
    string s;
    /// Declaring the points
    POINT cursorposition;
    int page = 0 , highscore; ///declaring the basic variables
    srand( time(0) ); /// seeding the rand ();
    ///reading the value of the high score and assigning it to the string s;
    ifstream ramesh;
    ramesh.open("high score.txt");
    ramesh>>s;

    /// the value stored in the file gets converted to an integer so that it can be manipulated later

    stringstream iamtired (s);
    iamtired >> highscore;
    while(1)
    {
        int a = rand() % 1400 + 50;
        setcolor(WHITE);
            for(int i = 0;i < 289;i++)
            {
                setactivepage( page );                      ///avoid flicker
                setvisualpage( 1-page );                    ///avoid flicker
                cleardevice();                              ///avoid flicker
                square(a, speed * i, 100);                  ///drawing the square ( coefficient of i decides the speed
                GetCursorPos(&cursorposition);              ///get the cursor position
                if( GetAsyncKeyState (VK_LBUTTON) && i<280)
                {
                    if( cursorposition.x <= a + 100 && cursorposition.x >= a)                   ///checking if the cursor was on the square (x-Axis)
                    {
                        if( cursorposition.y <= speed*i + 100 && cursorposition.y >=  speed*i)  ///checking if the cursor was on the square ( y axis )
                        {
                            ///at this point the player gains a point;
                            cleardevice();
                            run += 1;///increase point

                            ///this part of the code will convert the points gained by the user to a char* so a as to print on the graphical window

                                stringstream strs;
                                strs << run;
                                string temp_str = strs.str();
                                char_type = (char*) temp_str.c_str();


                            if (run >= highscore)
                            {

                                ///manipulating high scores

                                highscore = run;            ///  int high score now gets the value of the present points if the points are greater than the high score
                                s = to_string(highscore);   /// the now changed high score value gets assigned to the string s

                                /// the new score now gets written to the file to be saved as the new high score
                                ofstream suresh;
                                suresh.open("high score.txt");
                                suresh<<s;

                            }

                            cleardevice();
                            break;
                        }
                    }
                }
                else if (i==280)
                {
                    life--;
                }
                if (life==0)
                {
                    cout<<"GAME OVER, YOUR SCORE : "<<run;
                    cout<<"\nHIGH SCORE : "<<highscore;
                    cleardevice();
                    outtext("GAMEOVER PLEASE TRY AGAIN...");
                    playyy("gameover");
                    getch();
                    return 0;
                }

                string highscore_str;///declaring a new string so as to read the high score from

                ///read the high score from the file and assign it to another string

                ifstream highsc;
                highsc.open("high score.txt");
                highsc >> highscore_str;

                ///since the outtextxy function only takes a char* as an input, the following again converts the newly read value of the high score and then displays it on the screen

                char* char_type2 = &highscore_str[0u];

                ///converting the present points to a char*

                stringstream strs;
                strs << highscore;
                string temp_str = strs.str();
                char_type1 = (char*) temp_str.c_str();

                ///printing the  value on the screen constantly because of the for loop

                outtextxy(1280,700,"YOUR SCORE : ");
                outtextxy(1280,720,"HIGH SCORE : ");
                outtextxy(1400,720,char_type2);
                outtextxy(1400,700,char_type);
                page=1-page;///avoid flicker
                lives(1420,700,life);
                if (run>=20)
                {
                    putsq4(4,run);
                }
            }
        }
    }
int putsq2(int speed)
{
    /// this function will do the main job it will draw the square and do the main part of the game;

    char* char_type="0";    ///declaring so as to display on the screen
    char* char_type1="0";
    string s;
    /// Declaring the points
    POINT cursorposition;
    int page = 0 , highscore , run = 0; ///declaring the basic variables
    srand( time(0) ); /// seeding the rand ();
    ///reading the value of the high score and assigning it to the string s;
    ifstream ramesh;
    ramesh.open("high score.txt");
    ramesh>>s;

    /// the value stored in the file gets converted to an integer so that it can be manipulated later

    stringstream iamtired (s);
    iamtired >> highscore;

    while(1)
    {
        int a = rand() % 1400 + 50;

            for(int i = 0;i < 450;i++)
            {        setcolor(BLUE);
                setactivepage( page );                      ///avoid flicker
                setvisualpage( 1-page );                    ///avoid flicker
                cleardevice();                              ///avoid flicker
                square(a, 2 * i, 100);                  ///drawing the square ( coefficient of i decides the speed
                GetCursorPos(&cursorposition);              ///get the cursor position
                if( GetAsyncKeyState (VK_LBUTTON) && i<400)
                {
                    if( cursorposition.x <= a + 100 && cursorposition.x >= a)                   ///checking if the cursor was on the square (x-Axis)
                    {
                        if( cursorposition.y <= 2*i + 100 && cursorposition.y >=  2 * i)  ///checking if the cursor was on the square ( y axis )
                        {
                            ///at this point the player gains a point;
                            cleardevice();
                            run += 1;///increase point

                            ///this part of the code will convert the points gained by the user to a char* so a as to print on the graphical window

                                stringstream strs;
                                strs << run;
                                string temp_str = strs.str();
                                char_type = (char*) temp_str.c_str();


                            if (run >= highscore)
                            {

                                ///manipulating high scores

                                highscore = run;            ///  int high score now gets the value of the present points if the points are greater than the high score
                                s = to_string(highscore);   /// the now changed high score value gets assigned to the string s

                                /// the new score now gets written to the file to be saved as the new high score
                                ofstream suresh;
                                suresh.open("high score.txt");
                                suresh<<s;

                            }

                            cleardevice();
                            break;
                        }
                    }
                }
                else if (i==380)
                {
                    life--;
                }
                if (life==0)
                {
                    cout<<"GAME OVER, YOUR SCORE : "<<run;
                    cout<<"\nHIGH SCORE : "<<highscore;
                    cleardevice();
                    outtext("GAMEOVER PLEASE TRY AGAIN...");
                    playyy("gameover");
                    getch();
                    return 0;
                }
                string highscore_str;///declaring a new string so as to read the high score from

                ///read the high score from the file and assign it to another string

                ifstream highsc;
                highsc.open("high score.txt");
                highsc >> highscore_str;

                ///since the outtextxy function only takes a char* as an input, the following again converts the newly read value of the high score and then displays it on the screen

                char* char_type2 = &highscore_str[0u];

                ///converting the present points to a char*

                stringstream strs;
                strs << highscore;
                string temp_str = strs.str();
                char_type1 = (char*) temp_str.c_str();

                ///printing the  value on the screen constantly because of the for loop

                outtextxy(1280,700,"YOUR SCORE : ");
                outtextxy(1280,720,"HIGH SCORE : ");
                outtextxy(1400,720,char_type2);
                outtextxy(1400,700,char_type);
                page=1-page;///avoid flicker
                int bun=run;
                lives(1420,700,life);
                if (bun>=10)
                {
                    putsq3(3,bun);
                    cout<<bun;
                }
            }
        }

    }


int main()
{
display();
int a;
putsq2(2);
return 0;
}

