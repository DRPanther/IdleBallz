#include <stdio.h>
#include <stdlib.h>
#include "OpenDoor.h"
#include "idleballz.h"

//#define BOARD_WIDTH 61
//#define BOARD_HEIGHT 21

struct ball {
    int active;
    int x;
    int y;
    int up;
    int down;
    int left;
    int right;
};

struct ball ball1;
struct ball ball2;
struct ball ball3;

/*struct score {
    int tens;
    int k;
    int m;
    int b;
}; */

int scoretens;
int scorek;
int scorem;
int scoreb;

//unsigned long int score=100;

int drawboard(void)
{
    int i;
    int j;

    for (i=1;i<BOARD_HEIGHT;i++)
    {
        od_set_cursor(i,1);
        od_printf("`blue`X");
        od_set_cursor(i,BOARD_WIDTH);
        od_printf("`blue`X");
    }

    for (j=1;j<BOARD_WIDTH;j++)
    {
        od_set_cursor(1,j);
        od_printf("`blue`X");
        od_set_cursor(BOARD_HEIGHT,j);
        od_printf("`blue`X");
    }
    od_set_cursor(BOARD_HEIGHT,BOARD_WIDTH);
    od_printf("X`white`");
    return 0;
}

void game(void)
{
    int quit=0;
    ball1.active=1;
    ball1.x=BOARD_HEIGHT/2;
    ball1.y=BOARD_WIDTH/2;
    ball1.up=1;
    ball1.down=0;
    ball1.right=1;
    ball1.left=0;
    ball2.active=0;
    ball2.x=BOARD_HEIGHT/2;
    ball2.y=BOARD_WIDTH/2;
    ball2.up=0;
    ball2.down=1;
    ball2.right=0;
    ball2.left=1;
    ball3.active=0;
    ball3.x=BOARD_HEIGHT/2;
    ball3.y=BOARD_WIDTH/2;
    ball3.up=0;
    ball3.down=1;
    ball3.right=0;
    ball3.left=1;
    char ch;
    int sleeptimer=1000;
    scoretens=0;

    drawboard();
    od_set_cursor(ball1.x,ball1.y);
    od_printf("`bright red`*");
    od_clear_keybuffer();
    while (!quit)
    {
        od_sleep(sleeptimer);
        od_set_cursor(ball1.x,ball1.y);
        od_printf(" ");
        od_set_cursor(ball2.x,ball2.y);
        od_printf(" ");
        od_set_cursor(ball3.x,ball3.y);
        od_printf(" ");
        if (ball1.up) ball1.x+=1;
        if (ball1.down) ball1.x-=1;
        if (ball1.right) ball1.y+=1;
        if (ball1.left) ball1.y-=1;

        if (ball2.active==1) {
            if (ball2.up) ball2.x+=2;
            if (ball2.down) ball2.x-=2;
            if (ball2.right) ball2.y+=1;
            if (ball2.left) ball2.y-=1;
        }

        if (ball3.active==1) {
            if (ball3.up) ball3.x+=1;
            if (ball3.down) ball3.x-=1;
            if (ball3.right) ball3.y+=2;
            if (ball3.left) ball3.y-=2;
        }

        if (ball1.x==2) {ball1.up=1; ball1.down=0; scoretens+=10;}
        if (ball1.y==2) {ball1.left=0; ball1.right=1; scoretens+=10;}
        if (ball1.x>=BOARD_HEIGHT-1) {ball1.up=0; ball1.down=1; scoretens+=10;}
        if (ball1.y>=BOARD_WIDTH-1) {ball1.left=1; ball1.right=0; scoretens+=10;}

        if (ball2.active==1) {
            if (ball2.x==2) {ball2.up=1; ball2.down=0; scoretens+=25;}
            if (ball2.y==2) {ball2.left=0; ball2.right=1; scoretens+=25;}
            if (ball2.x>=BOARD_HEIGHT-1) {ball2.up=0; ball2.down=1; scoretens+=25;}
            if (ball2.y>=BOARD_WIDTH-1) {ball2.left=1; ball2.right=0; scoretens+=25;}
            if (ball1.x==ball2.x && ball1.y==ball2.y) {scoretens+=500;}
        }

        if (ball3.active==1) {
            if (ball3.x==2) {ball3.up=1; ball3.down=0; scoretens+=100;}
            if (ball3.y==2) {ball3.left=0; ball3.right=1; scoretens+=100;}
            if (ball3.x>=BOARD_HEIGHT-1) {ball3.up=0; ball3.down=1; scoretens+=100;}
            if (ball3.y>=BOARD_WIDTH-1) {ball3.left=1; ball3.right=0; scoretens+=100;}
            if ((ball1.x==ball3.x && ball1.y==ball3.y) || (ball2.x==ball3.x && ball2.y==ball3.y)) {scoretens+=1000;}
        }

        od_set_cursor(ball1.x,ball1.y);
        od_printf("`bright red`*");
        od_set_cursor(ball2.x,ball2.y);
        if (ball2.active==1) od_printf("`bright red`*");
        od_set_cursor(ball3.x,ball3.y);
        if (ball3.active==1) od_printf("`bright red`*");
        od_set_cursor(2,63);
        od_printf("`white`Current Score: ");
        od_set_cursor(3,63);
        od_clr_line();
        od_printf("%d",scoretens);
        od_set_cursor(4,63);
        od_printf("1 - Delay:");
        od_set_cursor(5,63);
        od_clr_line();
        od_printf("%d",sleeptimer);
        od_set_cursor(6,63);
        od_printf("2 - Buy ball?");
        od_set_cursor(7,63);
        if (ball3.active==1) od_printf("3");
        else if (ball2.active==1) od_printf("2");
        else od_printf("1");
        od_set_cursor(23,1);


        ch=od_get_key(FALSE);
        if (ch=='q' || ch=='Q') {quit=1;}
        if (ch=='1' && scoretens>=10 && sleeptimer>50) {scoretens=scoretens-10; sleeptimer=sleeptimer-50;}
        if (ch=='2' && scoretens>=50 && ball2.active==0) {scoretens-=50; ball2.active=1;}
        if (ch=='2' && scoretens>=100 && ball3.active==0) {scoretens-=100; ball3.active=1;}
    }
    od_set_cursor(22,1);
}

#ifdef ODPLAT_WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
   LPSTR lpszCmdLine, int nCmdShow)
#else
int main(int argc, char *argv[])
#endif
{
    int i;

    od_control.od_force_local=TRUE;
    od_clr_scr();
    od_printf("Idle Ballz is now loading");
    for (i=0;i<5;i++)
    {
        od_sleep(500);
        od_printf(".");
    }
    od_clr_scr();
    game();
    return 0;
}
