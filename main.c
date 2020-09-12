#include <stdio.h>
#include <stdlib.h>
#include "OpenDoor.h"
#include "idleballz.h"

//#define BOARD_WIDTH 61
//#define BOARD_HEIGHT 21

struct balls {
    int active;
    int x;
    int y;
    int up;
    int down;
    int left;
    int right;
    int price;
};

struct balls ball[8];
//struct ball ball2;
//struct ball ball3;
//struct ball ball4;

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
    ball[1].active=1;
    ball[1].x=BOARD_HEIGHT/2;
    ball[1].y=BOARD_WIDTH/2;
    ball[1].up=1;
    ball[1].down=0;
    ball[1].right=1;
    ball[1].left=0;
    ball[1].price=0;
    ball[2].active=0;
    ball[2].x=BOARD_HEIGHT/2;
    ball[2].y=BOARD_WIDTH/2;
    ball[2].up=0;
    ball[2].down=1;
    ball[2].right=0;
    ball[2].left=1;
    ball[2].price=50;
    ball[3].active=0;
    ball[3].x=BOARD_HEIGHT/2;
    ball[3].y=BOARD_WIDTH/2;
    ball[3].up=0;
    ball[3].down=1;
    ball[3].right=0;
    ball[3].left=1;
    ball[3].price=100;
    ball[4].active=0;
    ball[4].x=BOARD_HEIGHT/2;
    ball[4].y=BOARD_WIDTH/2;
    ball[4].up=1;
    ball[4].down=0;
    ball[4].right=0;
    ball[4].left=1;
    ball[4].price=1000;
    ball[5].active=0;
    ball[5].x=BOARD_HEIGHT/2;
    ball[5].y=BOARD_WIDTH/2;
    ball[5].up=1;
    ball[5].down=0;
    ball[5].right=1;
    ball[5].left=0;
    ball[5].price=5000;
    ball[6].active=0;
    ball[6].x=BOARD_HEIGHT/2;
    ball[6].y=BOARD_WIDTH/2;
    ball[6].up=1;
    ball[6].down=0;
    ball[6].right=0;
    ball[6].left=1;
    ball[6].price=10000;
    ball[7].active=0;
    ball[7].x=BOARD_HEIGHT/2;
    ball[7].y=BOARD_WIDTH/2;
    ball[7].up=0;
    ball[7].down=1;
    ball[7].right=1;
    ball[7].left=0;
    ball[7].price=50000;
    ball[8].active=0;
    ball[8].x=BOARD_HEIGHT/2;
    ball[8].y=BOARD_WIDTH/2;
    ball[8].up=0;
    ball[8].down=1;
    ball[8].right=0;
    ball[8].left=1;
    ball[8].price=500000;
    char ch;
    int sleeptimer=1000;
    scoretens=0;
    int activeball=1;

    drawboard();
    od_set_cursor(ball[1].x,ball[1].y);
    od_printf("`bright red`*");
    od_clear_keybuffer();
    while (!quit)
    {
        od_sleep(sleeptimer);
        od_set_cursor(ball[1].x,ball[1].y);
        od_printf(" ");
        od_set_cursor(ball[2].x,ball[2].y);
        od_printf(" ");
        od_set_cursor(ball[3].x,ball[3].y);
        od_printf(" ");
        od_set_cursor(ball[4].x,ball[4].y);
        od_printf(" ");
        od_set_cursor(ball[5].x,ball[5].y);
        od_printf(" ");
        od_set_cursor(ball[6].x,ball[6].y);
        od_printf(" ");
        od_set_cursor(ball[7].x,ball[7].y);
        od_printf(" ");
        od_set_cursor(ball[8].x,ball[8].y);
        od_printf(" ");
        if (ball[1].up) ball[1].x+=2;
        if (ball[1].down) ball[1].x-=2;
        if (ball[1].right) ball[1].y+=2;
        if (ball[1].left) ball[1].y-=2;

        if (ball[2].active==1) {
            if (ball[2].up) ball[2].x+=2;
            if (ball[2].down) ball[2].x-=2;
            if (ball[2].right) ball[2].y+=2;
            if (ball[2].left) ball[2].y-=2;
        }

        if (ball[3].active==1) {
            if (ball[3].up) ball[3].x+=2;
            if (ball[3].down) ball[3].x-=2;
            if (ball[3].right) ball[3].y+=2;
            if (ball[3].left) ball[3].y-=2;
        }
        if (ball[4].active==1)
        {
            if (ball[4].up) ball[4].x+=2;
            if (ball[4].down) ball[4].x-=2;
            if (ball[4].right) ball[4].y+=2;
            if (ball[4].left) ball[4].y-=2;
        }
        if (ball[5].active==1)
        {
            if (ball[5].up) ball[5].x+=1;
            if (ball[5].down) ball[5].x-=1;
            if (ball[5].right) ball[5].y+=1;
            if (ball[5].left) ball[5].y-=1;
        }
        if (ball[6].active==1)
        {
            if (ball[6].up) ball[6].x+=1;
            if (ball[6].down) ball[6].x-=1;
            if (ball[6].right) ball[6].y+=1;
            if (ball[6].left) ball[6].y-=1;
        }
        if (ball[7].active==1)
        {
            if (ball[7].up) ball[7].x+=1;
            if (ball[7].down) ball[7].x-=1;
            if (ball[7].right) ball[7].y+=1;
            if (ball[7].left) ball[7].y-=1;
        }
        if (ball[8].active==1)
        {
            if (ball[8].up) ball[8].x+=1;
            if (ball[8].down) ball[8].x-=1;
            if (ball[8].right) ball[8].y+=1;
            if (ball[8].left) ball[8].y-=1;
        }

        if (ball[1].x==2) {ball[1].up=1; ball[1].down=0; scoretens+=10;}
        if (ball[1].y==2) {ball[1].left=0; ball[1].right=1; scoretens+=10;}
        if (ball[1].x>=BOARD_HEIGHT-1) {ball[1].up=0; ball[1].down=1; scoretens+=10;}
        if (ball[1].y>=BOARD_WIDTH-1) {ball[1].left=1; ball[1].right=0; scoretens+=10;}

        if (ball[2].active==1) {
            if (ball[2].x==2) {ball[2].up=1; ball[2].down=0; scoretens+=25;}
            if (ball[2].y==2) {ball[2].left=0; ball[2].right=1; scoretens+=25;}
            if (ball[2].x>=BOARD_HEIGHT-1) {ball[2].up=0; ball[2].down=1; scoretens+=25;}
            if (ball[2].y>=BOARD_WIDTH-1) {ball[2].left=1; ball[2].right=0; scoretens+=25;}
            if (ball[1].x==ball[2].x && ball[1].y==ball[2].y) {scoretens+=500;}
        }

        if (ball[3].active==1) {
            if (ball[3].x==2) {ball[3].up=1; ball[3].down=0; scoretens+=100;}
            if (ball[3].y==2) {ball[3].left=0; ball[3].right=1; scoretens+=100;}
            if (ball[3].x>=BOARD_HEIGHT-1) {ball[3].up=0; ball[3].down=1; scoretens+=100;}
            if (ball[3].y>=BOARD_WIDTH-1) {ball[3].left=1; ball[3].right=0; scoretens+=100;}
            if ((ball[1].x==ball[3].x && ball[1].y==ball[3].y) || (ball[2].x==ball[3].x && ball[2].y==ball[3].y)) {scoretens+=1000;}
        }
        if (ball[4].active==1)
        {
            if (ball[4].x==2) {ball[4].up=1; ball[4].down=0; scoretens+=1000;}
            if (ball[4].y==2) {ball[4].left=0; ball[4].right=1; scoretens+=1000;}
            if (ball[4].x>=BOARD_HEIGHT-1) {ball[4].up=0; ball[4].down=1; scoretens+=1000;}
            if (ball[4].y>=BOARD_WIDTH-1) {ball[4].left=1; ball[4].right=0; scoretens+=1000;}
            if ((ball[1].x==ball[4].x && ball[1].y==ball[4].y) || (ball[2].x==ball[4].x && ball[2].y==ball[4].y) || (ball[3].x==ball[4].x && ball[3].y==ball[4].y)) {scoretens+=10000;}
        }
        if (ball[5].active==1)
        {
            if (ball[5].x==2) {ball[5].up=1; ball[5].down=0; scoretens+=10000;}
            if (ball[5].y==2) {ball[5].left=0; ball[5].right=1; scoretens+=10000;}
            if (ball[5].x>=BOARD_HEIGHT-1) {ball[5].up=0; ball[5].down=1; scoretens+=10000;}
            if (ball[5].y>=BOARD_WIDTH-1) {ball[5].left=1; ball[5].right=0; scoretens+=10000;}
            if ((ball[1].x==ball[5].x && ball[1].y==ball[5].y) || (ball[2].x==ball[5].x && ball[2].y==ball[5].y) || (ball[3].x==ball[5].x && ball[3].y==ball[5].y) || (ball[4].x==ball[5].x && ball[4].y==ball[5].y)) {scoretens+=100000;}
        }
        if (ball[6].active==1)
        {
            if (ball[6].x==2) {ball[6].up=1; ball[6].down=0; scoretens+=50000;}
            if (ball[6].y==2) {ball[6].left=0; ball[6].right=1; scoretens+=50000;}
            if (ball[6].x>=BOARD_HEIGHT-1) {ball[6].up=0; ball[6].down=1; scoretens+=50000;}
            if (ball[6].y>=BOARD_WIDTH-1) {ball[6].left=1; ball[6].right=0; scoretens+=50000;}
            if ((ball[1].x==ball[6].x && ball[1].y==ball[6].y) || (ball[2].x==ball[6].x && ball[2].y==ball[6].y) || (ball[3].x==ball[6].x && ball[3].y==ball[6].y) || (ball[4].x==ball[6].x && ball[4].y==ball[6].y) || (ball[5].x==ball[6].x && ball[5].y==ball[6].y)) {scoretens+=500000;}
        }
        if (ball[7].active==1)
        {
            if (ball[7].x==2) {ball[7].up=1; ball[7].down=0; scoretens+=100000;}
            if (ball[7].y==2) {ball[7].left=0; ball[7].right=1; scoretens+=100000;}
            if (ball[7].x>=BOARD_HEIGHT-1) {ball[7].up=0; ball[7].down=1; scoretens+=100000;}
            if (ball[7].y>=BOARD_WIDTH-1) {ball[7].left=1; ball[7].right=0; scoretens+=100000;}
            if ((ball[1].x==ball[7].x && ball[1].y==ball[7].y) || (ball[2].x==ball[7].x && ball[2].y==ball[7].y) || (ball[3].x==ball[7].x && ball[3].y==ball[7].y) || (ball[4].x==ball[7].x && ball[4].y==ball[7].y) || (ball[5].x==ball[7].x && ball[5].y==ball[7].y) || (ball[6].x==ball[7].x && ball[6].y==ball[7].y)) {scoretens+=500000;}
        }
        if (ball[8].active==1)
        {
            if (ball[8].x==2) {ball[8].up=1; ball[8].down=0; scoretens+=500000;}
            if (ball[8].y==2) {ball[8].left=0; ball[8].right=1; scoretens+=500000;}
            if (ball[8].x>=BOARD_HEIGHT-1) {ball[8].up=0; ball[8].down=1; scoretens+=500000;}
            if (ball[8].y>=BOARD_WIDTH-1) {ball[8].left=1; ball[8].right=0; scoretens+=500000;}
            if ((ball[1].x==ball[8].x && ball[1].y==ball[8].y) || (ball[2].x==ball[8].x && ball[2].y==ball[8].y) || (ball[3].x==ball[8].x && ball[3].y==ball[8].y) || (ball[4].x==ball[8].x && ball[4].y==ball[8].y) || (ball[5].x==ball[8].x && ball[5].y==ball[8].y) || (ball[6].x==ball[8].x && ball[6].y==ball[8].y) || (ball[7].x==ball[8].x && ball[7].y==ball[8].y)) {scoretens+=1000000;}
        }

        od_set_cursor(ball[1].x,ball[1].y);
        od_printf("`bright red`*");
        od_set_cursor(ball[2].x,ball[2].y);
        if (ball[2].active==1) od_printf("`bright red`*");
        od_set_cursor(ball[3].x,ball[3].y);
        if (ball[3].active==1) od_printf("`bright red`*");
        od_set_cursor(ball[4].x,ball[4].y);
        if (ball[4].active==1) od_printf("`bright red`*");
        od_set_cursor(ball[5].x,ball[5].y);
        if (ball[5].active==1) od_printf("`bright red`*");
        od_set_cursor(ball[6].x,ball[6].y);
        if (ball[6].active==1) od_printf("`bright red`*");
        od_set_cursor(ball[7].x,ball[7].y);
        if (ball[7].active==1) od_printf("`bright red`*");
        od_set_cursor(ball[8].x,ball[8].y);
        if (ball[8].active==1) od_printf("`bright red`*");
        od_set_cursor(2,63);
        od_printf("`white`Current Score: ");
        od_set_cursor(3,63);
        od_clr_line();
        od_printf("%d",scoretens);
        od_set_cursor(5,63);
        od_clr_line();
        od_printf("1 - Delay: %d",sleeptimer);
        od_set_cursor(6,63);
        //od_clr_line();
        od_printf("Cost: 10");
        od_set_cursor(8,63);
        od_printf("2 - Buy ball %d?",activeball+1);
        /*if (ball[7].active==1) od_printf("7");
        else if (ball[6].active==1) od_printf("6");
        else if (ball[5].active==1) od_printf("5");
        else if (ball[4].active==1) od_printf("4");
        else if (ball[3].active==1) od_printf("3");
        else if (ball[2].active==1) od_printf("2");
        else od_printf("1");*/
        od_set_cursor(9,63);
        od_printf("Cost: %d",ball[activeball+1].price);
        od_set_cursor(9,69);
        if (activeball==8) od_printf("Not yet...");
        od_set_cursor(23,1);
        for (int x=1;x<=activeball;x++) ball[x].active=1;

        ch=od_get_key(FALSE);
        if (ch=='q' || ch=='Q') {quit=1;}
        if (ch=='1' && scoretens>=10 && sleeptimer>50) {scoretens=scoretens-10; sleeptimer=sleeptimer-50;}
        if (ch=='2' && scoretens>=ball[2].price && ball[2].active==0 && ball[1].active==1) {scoretens-=ball[2].price; ball[2].active=1; activeball=2;}
        if (ch=='2' && scoretens>=ball[3].price && ball[3].active==0 && ball[2].active==1) {scoretens-=ball[3].price; ball[3].active=1; activeball=3;}
        if (ch=='2' && scoretens>=ball[4].price && ball[4].active==0 && ball[3].active==1) {scoretens-=ball[4].price; ball[4].active=1; activeball=4;}
        if (ch=='2' && scoretens>=ball[5].price && ball[5].active==0 && ball[4].active==1) {scoretens-=ball[5].price; ball[5].active=1; activeball=5;}
        if (ch=='2' && scoretens>=ball[6].price && ball[6].active==0 && ball[5].active==1) {scoretens-=ball[6].price; ball[6].active=1; activeball=6;}
        if (ch=='2' && scoretens>=ball[7].price && ball[7].active==0 && ball[6].active==1) {scoretens-=ball[7].price; ball[7].active=1; activeball=7;}
        if (ch=='2' && scoretens>=ball[8].price && ball[8].active==0 && ball[7].active==1) {scoretens-=ball[8].price; ball[8].active=1; activeball=8;}
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
