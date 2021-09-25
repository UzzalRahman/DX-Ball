#pragma comment(lib, "winmm.lib")
#include<bits/stdc++.h>
#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
DWORD screenwidth;
DWORD screenhight;
int bax,bay,dir=2,score=0,life=5,pvar=90,brickamount=0,level=1,turn=1,cheat=0;
int px,px1,py,py1,angx=8,angy=8,speed=25;
int scsiw=screenwidth/2,scsih=screenhight/2,startd;
int count_[100][100];
void mainframe();
void break_brick();
void point();
void life_level()
{
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    if(life==5)
    {
        outtextxy(screenwidth-220,5,"LIFE: *****");
    }
    else if(life==4)
    {
        outtextxy(screenwidth-220,5,"LIFE: **** ");
    }
    else if(life==3)
    {
        outtextxy(screenwidth-220,5,"LIFE: ***  ");
    }
    else if(life==2)
    {
        outtextxy(screenwidth-220,5,"LIFE: **   ");
    }
    else if(life==1)
    {
        outtextxy(screenwidth-220,5,"LIFE: *    ");
    }
    if(level==1)
    {
        outtextxy(5,5,"LEVEL: 1");
    }
    else if(level==2)
    {
        outtextxy(5,5,"LEVEL: 2");
    }
    else if(level==3)
    {
        outtextxy(5,5,"LEVEL: 3");
    }
    else if(level==4)
    {
        outtextxy(5,5,"LEVEL: 4");
    }
    else if(level==5)
    {
        outtextxy(5,5,"LEVEL: 5");
    }
    else if(level==6)
    {
        outtextxy(5,5,"LEVEL: 6");
    }
}
void variables()
{
    px=screenwidth-500,py=screenhight-50,px1=px+pvar,py1=py+10;
    bax=screenwidth-470,bay=screenhight-110;
    dir=2;
    px,px1,py,py1,angx=8,angy=8;
    bax=screenwidth-470,bay=screenhight-160;
}

void win()
{
    int x,y,z=0;

    for(x=1; x<15; x++)
    {
        for(y=1; y<15; y++)
        {
            if(count_[x][y]>0)
                z++;
        }
    }
    if(cheat==1)
    {
        z=0;
        cheat=0;
    }
    if(z<3)
    {
        level++;
        pvar-=10;
        speed=speed-2;
        for(x=0; x<15; x++)
        {
            for(y=0; y<15; y++)
            {
                count_[x][y]=0;
            }
        }
        break_brick();
        variables();
        int pag=0;
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                break;
            }
            setactivepage(pag);
            setvisualpage(1-pag);
            cleardevice();
            mainframe();
            setcolor(10);
            setfillstyle(SOLID_FILL,WHITE);
            settextstyle(BOLD_FONT,HORIZ_DIR,6);
            if(level>6)
            {
                outtextxy(250,350,"***GAME OVER***");
            }
            else
            {
                life_level();
                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                outtextxy(scsiw-175,250,"***YOU WIN***");
                outtextxy(scsiw-300,350,"PRESS SPACE TO CONTINUE");
            }
            setcolor(WHITE);
            delay(50);
            pag=1-pag;
        }
    }
}
void point()
{
    char c[1000];
    sprintf(c,"score: %d",score);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(screenwidth-220,40,c);

}
void mainframe()
{
    setfillstyle(SOLID_FILL ,7);
    bar(0,0,100,screenhight);
    //bar(0,screenhight-100,screenwidth,screenhight);
    bar(screenwidth-100,0,screenwidth,screenhight);
    bar(0,0,screenwidth,75);
}
void welcome()
{
    int xva=0,color=1,dir=1,pag=0;
    while(1)
    {
        setactivepage(pag);
        setvisualpage(1-pag);
        setfillstyle(SOLID_FILL,3);
        bar(0,0,screenwidth,screenhight);
        setcolor(color);
        settextstyle(BOLD_FONT,HORIZ_DIR,6);
        outtextxy(xva+150,150,"****GAME****");
        outtextxy(xva+150,250,"***DX-BALL***");
        outtextxy(xva,350,"PRESS SPACE TO CONTINUE");
        delay(5);
        if(GetAsyncKeyState(VK_SPACE))
        {
            break;
        }
        if(dir==1)
            xva++;
        else
            xva--;
        if(xva==0)
            dir=1;
        if(xva==screenwidth-700)
            dir=0;
        color++;
        if(color>15)
            color=1;
        pag=1-pag;
    }
    setcolor(WHITE);
}
void break_brick()
{
    scsiw=screenwidth/2;

    int a,b,c;
    if(level==1)
    {
        c=4*66+125;
        startd=scsiw-c;
        startd=startd/70;
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+7; b++)
            {
                if(a+b==(startd+startd+7)||a==b)
                    count_[a][b]=1;
            }
        }
    }
    else if(level==2)
    {
        c=4*66+125;
        startd=scsiw-c;
        startd=startd/70;
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(a==startd||a==startd+7)
                    count_[a][b]=1;
                else if(b==startd||b==startd+9)
                    count_[a][b]=1;
            }
        }
    }
    else if(level==3)
    {
        c=4*66+125;
        startd=scsiw-c;
        startd=startd/70;
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(a==startd||a==startd+7||a==b||(a+b)==startd+(startd+9))
                    count_[a][b]=1;
                else if(b==startd||b==startd+9)
                    count_[a][b]=1;
            }
        }
    }
    else if(level==4)
    {
        c=4*66+125;
        startd=scsiw-c;
        startd=startd/70;
        for(a=startd; a<=startd+8; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(a%2!=0)
                    count_[a][b]=1;
                else if(a%2==0)
                {
                    if(turn==1&&b==startd)
                    {
                        count_[a][b]=1;
                        turn++;
                        break;
                    }
                    else if(turn==2&&b==startd+9)
                    {
                        count_[a][b]=1;
                        turn--;
                        break;
                    }
                }
            }
        }
    }
    else if(level==5)
    {
        c=4*66+125;
        startd=scsiw-c;
        startd=startd/70;
        for(a=startd; a<startd+8; a++)
        {
            for(b=startd; b<startd+10; b++)
            {
                count_[a][b]=1;
            }
        }
    }
    else if(level==6)
    {
        c=4*66+125;
        startd=scsiw-c;
        startd=startd/70;
        for(a=startd; a<startd+8; a++)
        {
            for(b=startd; b<startd+10; b++)
            {
                count_[a][b]=2;
            }
        }
    }
}

void ball_direction();
void creating_frame()
{
    int a,b,x=55,y=25,co=2;
    if(level==1)
    {
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+7; b++)
            {
                if(count_[a][b]==1)
                {
                    setfillstyle(SOLID_FILL,co);
                    bar(b*70+125,a*30+100,b*70+125+66,a*30+99+26);
                }
                if(co>12)
                    co=2;
                co++;
            }
        }
    }
    else if(level==2)
    {
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(count_[a][b]==1)
                {
                    setfillstyle(SOLID_FILL,co);
                    bar(b*70+125,a*30+100,b*70+125+66,a*30+99+26);
                }
                if(co>13)
                    co=1;
                co++;
            }

        }
    }
    else if(level==3)
    {
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(count_[a][b]==1)
                {
                    setfillstyle(SOLID_FILL,co);
                    bar(b*70+125,a*30+100,b*70+125+66,a*30+99+26);
                }
                if(co>13)
                    co=1;
                co++;
            }

        }
    }
    else if(level==4)
    {
        for(a=startd; a<=startd+8; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(count_[a][b]==1)
                {
                    setfillstyle(SOLID_FILL,co);
                    bar(b*70+125,a*30+100,b*70+125+66,a*30+99+26);
                }
                if(co>13)
                    co=1;
                co++;
            }

        }
    }
    else if(level==5)
    {
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(count_[a][b]==1)
                {
                    setfillstyle(SOLID_FILL,co);
                    bar(b*70+125,a*30+100,b*70+125+66,a*30+99+26);
                }
                if(co>13)
                    co=1;
                co++;
            }

        }
    }
    else if(level==6)
    {
        for(a=startd; a<=startd+7; a++)
        {
            for(b=startd; b<=startd+9; b++)
            {
                if(count_[a][b]==1)
                {
                    setfillstyle(SOLID_FILL,co);
                    bar(b*70+125,a*30+100,b*70+125+66,a*30+99+26);
                }
                if(co>13)
                    co=1;
                co++;
            }

        }
    }
    setfillstyle(SOLID_FILL,WHITE);
}
void paddel()
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(px,py,px1,py1);
    setfillstyle(SOLID_FILL,1);
    circle(px-4,py+4,8);
    floodfill(px-4,py+4,WHITE);
    circle(px1+4,py+4,8);
    floodfill(px1+4,py+4,WHITE);
}
void move_paddel(int n)
{
    if(n==1)
    {
        if(px>85)
        {
            px=px-15;
            px1=px1-15;
        }
    }
    else if(n==2)
    {
        if(px1<screenwidth-85)
        {
            px=px+15;
            px1=px1+15;
        }

    }
}
void ball()
{

    setfillstyle(SOLID_FILL,14);
    circle(bax,bay-20,8);
    floodfill(bax,bay-20,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
}
void ball_hit_paddal()
{
    if(bax>=px-10&&bax<=px+10)
        angx=8,angy=4,dir=1 ;
    if(bax>=px+11&&bax<=px+30)
        angx=8,angy=8,dir=1 ;
    if(bax>=px+31&&bax<=px+50)
        angx=4,angy=8,dir=1 ;
    if(bax>=px+51&&bax<=px+60)
        angx=8,angy=8,dir=2 ;
    if(bax>=px+61&&bax<=px+70)
        angx=8,angy=8,dir=2 ;
    if(bax>=px+71&&bax<=px+pvar)
        angx=8,angy=4,dir=2 ;
    if(bax<=px||bax>=px+pvar)
        dir=0;
}
void ball_hit_brick()
{
    count_[(bay-100)/30][(bax-125)/70]=count_[(bay-100)/30][(bax-125)/70]-1;
    score=score+100;
    win();
}
void move_ball()
{
    circle(bax,bay-20,8);
    setfillstyle(SOLID_FILL,14);
    floodfill(bax,bay-20,WHITE);
    if(bay>(screenhight-40))
    {
        ball_hit_paddal();
    }
    setfillstyle(SOLID_FILL,WHITE);

    if(dir==1 && bay<450&&count_[(bay-100)/30][(bax-125)/70]>0)//ball hits brick start
    {
        dir=3;
        ball_hit_brick();
    }
    if(dir==2 && bay<450&&count_[(bay-100)/30][(bax-125)/70]>0)
    {
        dir=4;
        ball_hit_brick();
    }

    if(dir==3 && bay<450&&count_[(bay-100)/30][(bax-125)/70]>0)
    {
        dir=1;
        ball_hit_brick();
    }
    if(dir==4 && bay<450&&count_[(bay-100)/30][(bax-125)/70]>0)
    {
        dir=2;
        ball_hit_brick();
    }//ball hits brick stop


    if(GetAsyncKeyState(VK_LEFT))
    {
        move_paddel(1);
    }
    else if(GetAsyncKeyState(VK_RIGHT))
    {
        move_paddel(2);
    }
    ball_direction();
    if(dir==1)// top left
    {
        bax=bax-angx;
        bay=bay-angy;
    }
    else if(dir==2)//top right
    {
        bax=bax+angx;
        bay=bay-angy;
    }
    else if(dir==3)//bottom left
    {
        bax=bax-angx;
        bay=bay+angy;
    }
    else if(dir==4)//bottom right
    {
        bax=bax+angx;
        bay=bay+angy;
    }
}
void ball_direction()
{
    if(dir==1&&bay<100)
        dir=3;
    else if(dir==1&&bax<105)
        dir=2;
    else if(dir==2&&bay<100)
        dir=4;
    else if(dir==2&&bax>(screenwidth-105))
        dir=1;
    else if(dir==3&&bax<105)
        dir=4;
    else if(dir==4&& bax>(screenwidth-105))
        dir=3;
    else if(dir==0)
    {
        life--;
    }
}

int main()
{

    int page=0;
    int colo=1;
    screenwidth= GetSystemMetrics(SM_CXSCREEN)-5;
    screenhight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenwidth,screenhight,"DX-BALL",0,0);
    mainframe();
    welcome();
    break_brick();
    int z=300;
    while(life!=0)
    {
        px=screenwidth-500,py=screenhight-50,px1=px+pvar,py1=py+9;
        bax=screenwidth-470,bay=screenhight-38;
        dir=2;
        creating_frame();
        paddel();
        ball();
        point();
        life_level();
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(scsiw-85,screenhight-250,"LIFE Lose");
        outtextxy(scsiw-215,screenhight-200,"PRESS SPACE TO CONTINUE");
        settextstyle(BOLD_FONT,HORIZ_DIR,6);
        outtextxy(300,10,"***DX-BALL***");
        mainframe();
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        page=1-page;
        if(GetAsyncKeyState(VK_SPACE))
        {
            while(0!=dir)
            {
                if(GetAsyncKeyState(VK_ADD))
                {
                    cheat=1;
                    win();
                }
                if(GetAsyncKeyState(VK_TAB))
                {
                    while(1)
                    {

                        if(GetAsyncKeyState(VK_SPACE))
                        {
                            break;
                        }
                    }
                }
                settextstyle(BOLD_FONT,VERT_DIR,3);
                outtextxy(screenwidth-75,(screenhight/2)+100,"PRESS SPACE TO RESUME");
                outtextxy(35,(screenhight/2)+100,"PRESS TAB TO PAUSE");
                settextstyle(BOLD_FONT,HORIZ_DIR,6);
                outtextxy(300,10,"***DX-BALL***");
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();
                mainframe();
                creating_frame();
                life_level();
                point();
                paddel();
                move_ball();
                page=1-page;
                delay(speed);
            }
        }
    }
    getch();
    closegraph();
}

