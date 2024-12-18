#include "iGraphics.h"

void drawhomepage();
void drawstartpage();
void startbuttonclick();
void drawscorepage();
void scorebuttonclick();
void backbuttonclick();
void drawgameoverpage();
void restartbuttonclick();
void draweasypage();
void drawmediumpage();
void drawhardpage();
void easybuttonclick();
void mediumbuttonclick();
void hardbuttonclick();
void drawhomepage2();
void drawcreditpage();
void creditbuttonclick();
int startbutton = 0;
int startpage = 0;
int homepage = 1;
int scorepage = 0;
int gameoverpage = 0;
int easypage = 0;
int mediumpage = 0;
int hardpage = 0;
int creditpage = 0;

int playerx = 0, playery = 0;
int run_idx = 0, run_idx_1 = 0, run_idx_2 = 0, run_idx_3 = 0, run_idx_4 = 0;
char playerrun[8][100];
char enemy1run[9][100];
char enemy2run[6][100];
char enemy3run[5][100];
char enemy4run[7][100];
int px = 150, py = 150;
int c1x = 800, c1y = 600;
int c2x = c1x + 700, c2y = 600;
int c3x = c2x + 700, c3y = 600;
int e1x = 1800, e1y = 150;
int e2x = 2300, e2y = 150;
int e3x = 2700, e3y = 150;
int e4x = 2500, e4y = 250;
int jump = 0, jumpup = 0, jumpdown = 0;
bool musicon = true;
int heart = 5;

int yourscore;
int second = 0;
int score = 0;
char sec[10000];
int totalsecond = 0;
int totalscore = 0;
char point[10000];

void newhighscore();
void readscore();
int len = 0;
char str1[100];
bool newscore = true;

struct hscore
{
    char name[30];
    int score = 0;
} highscore[5];

// player animation
void player_running()
{
    for (int i = 0; i < 8; i++)
    {
        sprintf(playerrun[i], "spite\\tile00%d.bmp", i);
    }
}
void update_run()
{
    run_idx = (run_idx + 1) % 8;
}
void drawchar()
{
    iShowBMP2(px, py, playerrun[run_idx], 0);
}
// enemy1 animation
void enemy1_running()
{
    for (int i = 0; i < 9; i++)
    {
        sprintf(enemy1run[i], "spite\\enemy1\\tile00%d.bmp", i);
    }
}
void update_run_1()
{
    run_idx_1 = (run_idx_1 + 1) % 9;
}
void drawenemy1()
{
    iShowBMP2(e1x, e1y, enemy1run[run_idx_1], 0);
}
// enemy2 animation
void enemy2_running()
{
    for (int i = 0; i < 6; i++)
    {
        sprintf(enemy2run[i], "spite\\enemy2\\tile00%d.bmp", i);
    }
}
void update_run_2()
{
    run_idx_2 = (run_idx_2 + 1) % 6;
}
void drawenemy2()
{

    iShowBMP2(e2x, e2y, enemy2run[run_idx_2], 0);
}
// enemy3 animation
void enemy3_running()
{
    for (int i = 0; i < 5; i++)
    {
        sprintf(enemy3run[i], "spite\\enemy3\\tile00%d.bmp", i);
    }
}
void update_run_3()
{
    run_idx_3 = (run_idx_3 + 1) % 5;
}
void drawenemy3()
{

    iShowBMP2(e3x, e3y, enemy3run[run_idx_3], 0);
}
// enemy4 animation
void enemy4_running()
{
    for (int i = 0; i < 7; i++)
    {
        sprintf(enemy4run[i], "spite\\enemy4\\tile00%d.bmp", i);
    }
}
void update_run_4()
{
    run_idx_4 = (run_idx_4 + 1) % 7;
}
void drawenemy4()
{

    iShowBMP2(e4x, e4y, enemy4run[run_idx_4], 0);
}

// Time and score
void changetimer()
{
    if (easypage == 1 || mediumpage == 1 || hardpage == 1)
    {
        totalsecond = second++;
        totalscore = score + second;
    }
}

void drawtimer()
{
    if (easypage == 1 || mediumpage == 1 || hardpage == 1)
    {
        iSetColor(50, 162, 168);
        iFilledRectangle(1700, 950, 200, 50);
        iSetColor(0, 0, 0);
        sprintf(sec, "%d", second);
        iText(1820, 965, sec, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1720, 965, "Timer", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(74, 50, 168);
        iFilledRectangle(1700, 900, 200, 50);
        iSetColor(0, 0, 0);
        iText(1720, 915, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
        sprintf(point, "%d", totalscore);
        iText(1820, 915, point, GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

// leaderboard
void readscore()
{
    FILE *fp;
    fp = fopen("score.txt", "r");
    char showname[5][30], showscore[5][5];
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d\n", highscore[i].name, &highscore[i].score);
    }
    for (int i = 0; i < 5; i++)
    {
        sprintf(showname[i], "%s", highscore[i].name);
        sprintf(showscore[i], "%d", highscore[i].score);
        iSetColor(0, 255, 255);
        iText(800, 750 - 50 * i, showname[i], GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1000, 750 - 50 * i, showscore[i], GLUT_BITMAP_TIMES_ROMAN_24);
    }
    fclose(fp);
}

void newhighscore()
{
    FILE *fp;
    fp = fopen("score.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d\n", highscore[i].name, &highscore[i].score);
    }
    if (newscore)
    {
        for (int i = 0; i < 5; i++)
        {
            if (highscore[i].score < yourscore)
            {
                highscore[4].score = yourscore;
                strcpy(highscore[4].name, str1);
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 5; k > j; k--)
                    {
                        if (highscore[k].score > highscore[k - 1].score)
                        {
                            int t = highscore[k - 1].score;
                            highscore[k - 1].score = highscore[k].score;
                            highscore[k].score = t;

                            char n[50];
                            strcpy(n, highscore[k - 1].name);
                            strcpy(highscore[k - 1].name, highscore[k].name);
                            strcpy(highscore[k].name, n);
                        }
                    }
                }
                FILE *fp = fopen("score.txt", "w");
                for (int i = 0; i < 5; i++)
                {
                    fprintf(fp, "%s %d\n", highscore[i].name, highscore[i].score);
                }
                fclose(fp);
                newscore = false;
                break;
            }
        }
    }
}
// Enter name
void showchar()
{
    iSetColor(255, 0, 0);
    iText(400, 500, "Enter your name:", GLUT_BITMAP_TIMES_ROMAN_24);
    iRectangle(580, 495, 160, 30);
    iText(585, 500, str1, GLUT_BITMAP_HELVETICA_18);
}

void takeinput(unsigned key)
{
    if (key == '\r')
    {
        newhighscore();
    }
    else if (key == '\b')
    {
        if (len <= 0)
        {
            len = 0;
        }
        else
            len--;
        str1[len] = '\0';
    }
    else
    {
        str1[len] = key;
        len++;
        if (len > 15)
        {
            len = 15;
        }
        str1[len] = '\0';
    }
}

void collision()
{
    if (((px + 30 >= e1x && px <= e1x + 30) && (py + 60 >= e1y && py <= e1y + 60)) || ((px + 20 >= e2x && px <= e2x + 20) && (py + 60 >= e2y && py <= e2y + 60)) || ((px + 20 >= e3x && px <= e3x + 20) && (py + 60 >= e3y && py <= e3y + 60)) || ((px + 20 >= e4x && px <= e4x + 20) && (py + 40 >= e4y && py <= e4y + 40)))
    {
        if (heart == 0)
        {
            gameoverpage = 1;
            startpage = 0;
            yourscore = totalscore;
            score = 0;
            second = 0;
        }
        else
            heart--;

    }
}
////////////////////////////////////////////////////////// DRAW ///////////////////////////////////////////////////////////////
void iDraw()
{
    iClear();
    if (homepage == 1)
    {
        drawhomepage();
    }
    else if (startpage == 1)
    {
        drawstartpage();
    }
    else if (scorepage == 1)
    {
        drawscorepage();
    }
    else if (gameoverpage == 1)
    {
        drawgameoverpage();
        showchar();
    }
    else if (easypage == 1)
    {
        draweasypage();
    }
    else if (mediumpage == 1)
    {
        drawmediumpage();
    }
    else if (hardpage == 1)
    {
        drawhardpage();
    }
    else if (creditpage == 1)
    {
        drawcreditpage();
    }
}

void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        printf("x = %d, y= %d\n", mx, my);
        if (homepage == 1 && (mx >= 780 && mx <= 1070) && (my >= 400 && my <= 510))
        {
            startbuttonclick();
        }
        else if (homepage == 1 && (mx >= 780 && mx <= 1070) && (my >= 180 && my <= 305))
        {
            scorebuttonclick();
        }
        else if ((startpage == 1 || scorepage == 1 || easypage == 1 || mediumpage == 1 || hardpage == 1 || creditpage == 1) && (mx >= 20 && mx <= 170) && (my >= 965 && my <= 1040))
        {
            backbuttonclick();
        }
        else if (gameoverpage == 1 && (mx >= 860 && mx <= 1020) && (my >= 270 && my <= 340))
        {
            restartbuttonclick();
        }
        else if (startpage == 1 && (mx >= 800 && mx <= 1175) && (my >= 700 && my <= 845))
        {
            easybuttonclick();
        }
        else if (startpage == 1 && (mx >= 800 && mx <= 1175) && (my >= 500 && my <= 645))
        {
            mediumbuttonclick();
        }
        else if (startpage == 1 && (mx >= 800 && mx <= 1175) && (my >= 300 && my <= 445))
        {
            hardbuttonclick();
        }
        else if (gameoverpage == 1 && (mx >= 860 && mx <= 1020) && (my >= 170 && my <= 240))
        {
            exit(0);
        }
        if (homepage == 1 && (mx >= 1760 && mx <= 1840) && (my >= 410 && my <= 490))
        {
            creditbuttonclick();
        }
        if (homepage == 1 && (mx >= 1760 && mx <= 1840) && (my >= 265 && my <= 340))
        {
            if (musicon)
            {
                musicon = false;
                PlaySound(0, 0, 0);
            }
            else
            {
                musicon = true;
                PlaySound(TEXT("music\\music1.wav"), NULL, SND_LOOP | SND_ASYNC);
            }
        }
        if (homepage == 1 && (mx >= 1760 && mx <= 1840) && (my >= 120 && my <= 190))
        {
            exit(0);
        }
    }
}

void iKeyboard(unsigned char key)
{
    if (key == ' ')
    {
        jump = 1;
    }
    if (gameoverpage == 1)
    {
        takeinput(key);
    }
}
void iMouseMove(int mx, int my)
{
    // place your codes here
}
/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
    */

void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_F1)
    {
        if (musicon)
        {
            musicon = false;
            PlaySound(0, 0, 0);
        }
        else
        {
            musicon = true;
            PlaySound(TEXT("music\\music1.wav"), NULL, SND_LOOP | SND_ASYNC);
        }
    }
}
// Make character jump
void jumping()
{
    if (jump == 0)
        return;
    else if (jumpup == 0 && jumpdown == 0)
    {
        jumpup = 1;
        jumpdown = 0;
    }

    if (jumpup == 1)
    {
        if (py < 250)
        {
            if (easypage == 1)
            {
                py += 10;
            }
            else if (hardpage == 1 || mediumpage == 1)
            {
                py += 15;
            }
        }
        if (py >= 250)
        {
            jumpup = 0;
            jumpdown = 1;
        }
    }
    else if (jumpdown == 1)
    {
        if (py > 150)
        {
            if (easypage == 1)
            {
                py -= 10;
            }
            else if (hardpage == 1 || mediumpage == 1)
            {
                py -= 15;
            }
        }
        if (py <= 155)
        {
            py = 155;
            jumpdown = 0;
            jump = 0;
        }
    }
}

// Make space between enemies
void makespace()
{
    if ((e1x - e2x) < 300 && (e1x - e2x) > 50 || (e1x - e3x) < 300 && (e1x - e3x) > 50 || (e1x - e4x) < 150 && (e1x - e4x) > 0)
    {
        e1x = e1x + 300;
    }
    if ((e2x - e3x) < 300 && (e2x - e3x) > 50 || (e2x - e1x) < 300 && (e2x - e1x) > 50 || (e2x - e4x) < 150 && (e2x - e4x) > 0)
    {
        e2x = e2x + 300;
    }
    if ((e3x - e2x) < 300 && (e3x - e2x) > 50 || (e3x - e1x) < 300 && (e3x - e1x) > 50 || (e3x - e4x) < 150 && (e3x - e4x) > 00)
    {
        e3x = e3x + 300;
    }
    if ((e4x - e2x) < 150 && (e4x - e2x) > 0 || (e4x - e1x) < 150 && (e4x - e1x) > 0 || (e4x - e3x) < 150 && (e4x - e3x) > 0)
    {
        e4x = e4x + 150;
    }
}
void cloud()
{
    iShowBMP2(c1x, c1y, "spite\\cloud1.bmp", 0);
    c1x = c1x - 10;
    if (c1x <= 0)
    {
        c1x = 1800 + rand() % 100;
    }
    iShowBMP2(c2x, c2y, "spite\\cloud2.bmp", 0);
    c2x = c2x - 10;
    if (c2x <= 0)
    {
        c2x = c1x + 700;
    }
    iShowBMP2(c3x, c3y, "spite\\cloud3.bmp", 0);
    c3x = c3x - 10;
    if (c3x <= 0)
    {
        c3x = c2x + 700;
    }
}
void drawheart()
{
    if (heart == 5 || heart==4)
    {
        iShowBMP2(1000, 1000, "images\\heart.bmp", 0);
        iShowBMP2(1050, 1000, "images\\heart.bmp", 0);
        iShowBMP2(1100, 1000, "images\\heart.bmp", 0);
    }
    else if (heart == 3 || heart ==2)
    {
        iShowBMP2(1000, 1000, "images\\heart.bmp", 0);
        iShowBMP2(1050, 1000, "images\\heart.bmp", 0);
    }
    else
    {
        iShowBMP2(1000, 1000, "images\\heart.bmp", 0);
    }
}
void creditbuttonclick()
{
    homepage = 0;
    creditpage = 1;
}
void drawcreditpage()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background5.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iSetColor(255, 255, 255);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP2(300, 250, "images\\me.bmp", 0);
    iSetColor(255, 0, 0);
    iText(1150, 800, "CREDIT", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 0);
    iText(900, 700, "Nafis Mahmud Siyam", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(900, 600, "BUET CSE Level-1/Term-1", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(900, 500, "ROLL: 2305037", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(900, 400, "SUPERVISOR: MAI", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawgameoverpage()
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(550, 550, "images\\gameover.bmp", 0);
    iShowBMP2(840, 200, "images\\restart.bmp", 0);
    iSetColor(0, 0, 0);
    iText(900, 300, "Restart", GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP2(840, 100, "images\\restart.bmp", 0);
    iSetColor(0, 0, 0);
    iText(915, 200, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 0, 0);
    iText(400, 440, "(Press 'ENTER' to save)", GLUT_BITMAP_HELVETICA_12);
    iText(1100, 500, "Your score is:", GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(point, "%d", yourscore);
    iText(1300, 500, point, GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawhomepage()
{
    iSetColor(128, 128, 128);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background.bmp", 0);
    iShowBMP2(750, 260, "images\\button.bmp", 0);
    iShowBMP2(750, 50, "images\\button.bmp", 0);
    iShowBMP2(1750, 100, "images\\button4.bmp", 0);
    if (musicon == 1)
    {
        iShowBMP2(1750, 250, "images\\button5.bmp", 0);
    }
    else
        iShowBMP2(1750, 250, "images\\button5_1.bmp", 0);
    iShowBMP2(1750, 400, "images\\button6.bmp", 0);
    iShowBMP2(580, 500, "images\\junglerunlogo.bmp", 0);
    iSetColor(255, 255, 255);
    iText(900, 450, "Start", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(900, 230, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawscorepage()
{
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background3.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iSetColor(255, 255, 255);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(820, 850, "LEADERBOARD", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 255);
    iText(790, 790, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(970, 790, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
    readscore();
}
void scorebuttonclick()
{
    homepage = 0;
    startpage = 0;
    scorepage = 1;
}
void drawhardpage()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background2.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iSetColor(255, 255, 255);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
    cloud();
    drawheart();
    player_running();
    update_run();
    drawchar();
    jumping();
    enemy1_running();
    update_run_1();
    drawenemy1();
    e1x = e1x - 30;
    if (e1x <= 0)
    {
        e1x = 1800 + rand() % 100;
        score = score + 5;
    }
    enemy2_running();
    update_run_2();
    drawenemy2();
    e2x = e2x - 30;
    if (e2x <= 0)
    {
        e2x = 2300 + rand() % 300;
        score = score + 5;
    }
    enemy3_running();
    update_run_3();
    drawenemy3();
    e3x = e3x - 30;
    if (e3x <= 0)
    {
        e3x = 2700 + rand() % 400;
        score = score + 5;
    }
    enemy4_running();
    update_run_4();
    drawenemy4();
    e4x = e4x - 30;
    if (e4x <= 0)
    {
        e4x = 2700 + rand() % 400;
        score = score + 5;
    }
    makespace();
    collision();
    drawtimer();
}
void drawmediumpage()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background2.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iSetColor(255, 255, 255);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
    cloud();
    drawheart();
    player_running();
    update_run();
    drawchar();
    jumping();
    enemy1_running();
    update_run_1();
    drawenemy1();
    e1x = e1x - 25;
    if (e1x <= 0)
    {
        e1x = 1800 + rand() % 100;
        score = score + 5;
    }
    enemy2_running();
    update_run_2();
    drawenemy2();
    e2x = e2x - 25;
    if (e2x <= 0)
    {
        e2x = 2300 + rand() % 300;
        score = score + 5;
    }
    enemy3_running();
    update_run_3();
    drawenemy3();
    e3x = e3x - 25;
    if (e3x <= 0)
    {
        e3x = 2700 + rand() % 400;
        score = score + 5;
    }
    enemy4_running();
    update_run_4();
    drawenemy4();
    e4x = e4x - 25;
    if (e4x <= 0)
    {
        e4x = 2700 + rand() % 400;
        score = score + 5;
    }
    makespace();
    collision();
    drawtimer();
}
void draweasypage()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background2.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iSetColor(255, 255, 255);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
    cloud();
    drawheart();
    player_running();
    update_run();
    drawchar();
    jumping();
    enemy1_running();
    update_run_1();
    drawenemy1();
    e1x = e1x - 20;
    if (e1x <= 0)
    {
        e1x = 1800 + rand() % 100;
        score = score + 5;
    }
    enemy2_running();
    update_run_2();
    drawenemy2();
    e2x = e2x - 20;
    if (e2x <= 0)
    {
        e2x = 2300 + rand() % 300;
        score = score + 5;
    }
    enemy3_running();
    update_run_3();
    drawenemy3();
    e3x = e3x - 20;
    if (e3x <= 0)
    {
        e3x = 2700 + rand() % 400;
        score = score + 5;
    }
    if ((e1x - e2x) < 300 && (e1x - e2x) > 50 || (e1x - e3x) < 300 && (e1x - e3x) > 50)
    {
        e1x = e1x + 300;
    }
    if ((e2x - e3x) < 300 && (e2x - e3x) > 50 || (e2x - e1x) < 300 && (e2x - e1x) > 50)
    {
        e2x = e2x + 300;
    }
    if ((e3x - e2x) < 300 && (e3x - e2x) > 50 || (e3x - e1x) < 300 && (e3x - e1x) > 50)
    {
        e3x = e3x + 300;
    }
    collision();
    drawtimer();
}
void drawhomepage2()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background4.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawstartpage()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 1920, 1080);
    iShowBMP2(0, 0, "images\\background4.bmp", 0);
    iShowBMP2(0, 900, "images\\back.bmp", 0);
    iText(80, 1000, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255, 0, 0);
    iShowBMP2(750, 530, "images\\button2.bmp", 0);
    iShowBMP2(750, 330, "images\\button2.bmp", 0);
    iShowBMP2(750, 130, "images\\button2.bmp", 0);
    iText(945, 760, "EASY", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(930, 560, "MEDIUM", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(945, 365, "HARD", GLUT_BITMAP_TIMES_ROMAN_24);
}

void startbuttonclick()
{
    homepage = 0;
    scorepage = 0;
    startpage = 1;
    easypage = 0;
    mediumpage = 0;
    hardpage = 0;
    gameoverpage = 0;
}
void backbuttonclick()
{
    if (easypage == 1)
    {
        easypage = 0;
        startpage = 1;
        e1x = 1800;
        e2x = 2300;
        e3x = 2700;
        e4x = 2500;
        score = 0;
        second = 0;
        heart=5;
        newscore = true;
    }
    else if (mediumpage == 1)
    {
        mediumpage = 0;
        startpage = 1;
        e1x = 1800;
        e2x = 2300;
        e3x = 2700;
        e4x = 2500;
        score = 0;
        second = 0;
        heart=5;
        newscore = true;
    }
    else if (hardpage == 1)
    {
        hardpage = 0;
        startpage = 1;
        e1x = 1800;
        e2x = 2300;
        e3x = 2700;
        e4x = 2500;
        score = 0;
        second = 0;
        heart=5;
        newscore = true;
    }
    else
    {
        easypage = 0;
        mediumpage = 0;
        hardpage = 0;
        scorepage = 0;
        startpage = 0;
        homepage = 1;
        e1x = 1800;
        e2x = 2300;
        e3x = 2700;
        e4x = 2500;
        score = 0;
        second = 0;
        newscore = true;
    }
}
void restartbuttonclick()
{
    e1x = 1800;
    e2x = 2300;
    e3x = 2700;
    e4x = 2500;
    gameoverpage = 0;
    startpage = 1;
    easypage = 0;
    mediumpage = 0;
    hardpage = 0;
    score = 0;
    second = 0;
    heart=5;
    newscore = true;
}
void easybuttonclick()
{
    homepage = 0;
    scorepage = 0;
    startpage = 0;
    easypage = 1;
    mediumpage = 0;
    hardpage = 0;
    gameoverpage = 0;
}
void mediumbuttonclick()
{
    homepage = 0;
    scorepage = 0;
    startpage = 0;
    easypage = 0;
    mediumpage = 1;
    hardpage = 0;
    gameoverpage = 0;
}
void hardbuttonclick()
{
    homepage = 0;
    scorepage = 0;
    startpage = 0;
    easypage = 0;
    mediumpage = 0;
    hardpage = 1;
    gameoverpage = 0;
}
int main()
{
    if (musicon)
    {
        PlaySound(TEXT("music\\music1.wav"), NULL, SND_LOOP | SND_ASYNC);
    }
    iSetTimer(1000, changetimer);
    iInitialize(1925, 1080, "Jungle Run");
    return 0;
}