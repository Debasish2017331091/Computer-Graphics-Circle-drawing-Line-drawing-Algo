#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int window_w=1000, window_h=800 ;
struct PT   ///Point Stracture
{
    double x,y;
    PT()
    {
    }
    PT(double a,double b)
    {
        x=a;
        y=b;
    }
};

PT convert_pixel(PT p)///Point convert with respect to axis
{
    p.x+=(window_w/2);
    p.y=-p.y;
    p.y+=(window_h/2);
    return p;
}

void draw_pixel(PT p,int color) ///Pixel filling with color
{
    p=convert_pixel(p);
    putpixel( (int)(p.x+0.5), (int)(p.y+0.5), color );
}

void draw_axis()///x,y axis drawing
{
    for(int i=0 ; i<=window_w ; i++)
    {
        delay(0.2);
        putpixel( i, (window_h/2), GREEN );
    }
    for(int i=0 ; i<=window_h ; i++)
    {
        putpixel( (window_w/2), i, GREEN);
        delay(0.2);
    }
}
/******/
void drawCirclePoint(PT p,int color)
{
    draw_pixel(PT(p.x,p.y),color);
    draw_pixel(PT(p.x,-p.y),color);
    draw_pixel(PT(p.y,-p.x),color);
    draw_pixel(PT(-p.y,-p.x),color);
    draw_pixel(PT(-p.x,-p.y),color);
    draw_pixel(PT(-p.x,p.y),color);
    draw_pixel(PT(-p.y,p.x),color);
    draw_pixel(PT(p.y,p.x),color);
}

void DrawCircle_bassenhams(int radius) ///Bassenhams circle drawing algorithm
{
    int xi=0,yi=radius;
    int d=3-2*radius;
    while(xi<=yi)
    {
        drawCirclePoint(PT(xi,yi),YELLOW);
        if(d<0)
        {
            d+=(4*xi-6);
        }
        else
        {
            d+=(4*(xi-yi)+10);
            yi--;
        }
        xi++;
    }
}
void DrawCircle_midpoint(int radius) ///Midpoint circle drawing algorithm
{
    int xi=0,yi=radius;
    int d=1-radius;
    while(xi<=yi)
    {
        drawCirclePoint(PT(xi,yi),YELLOW);
        if(d<0)
        {
            d+=(2*xi+3);
        }
        else
        {
            d+=(2*(xi-yi)+5);
            yi--;
        }
        xi++;
    }
}
void Boundary_Filling(PT p,int color,int boundary_color)
{
    PT p1=convert_pixel(p);
    int current_color=getpixel(p1.x,p1.y);
    if(current_color==boundary_color||current_color==color)
    {
        return;
    }
    draw_pixel(p,color);
    Boundary_Filling(PT(p.x,p.y+1), color, boundary_color);
    Boundary_Filling(PT(p.x,p.y-1), color, boundary_color);
    Boundary_Filling(PT(p.x+1,p.y), color, boundary_color);
    Boundary_Filling(PT(p.x-1,p.y), color, boundary_color);
}
int main()
{
    initwindow(window_w,window_h);
    //draw_axis();

    /**Uncomment the line for testing the circle drawing algorithms**/

    /**Test case for bassenhams algorithm**/

    DrawCircle_bassenhams(85);
    Boundary_Filling(PT(0,0),RED,YELLOW);


    /**Test case for Midpoint algorithm**/
    //DrawCircle_midpoint(80);


    getchar();
    return 0;
}
