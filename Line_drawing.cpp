#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int window_w=1000 , window_h=800 ;
struct PT { ///Point Stracture
    double x,y;
    PT(){
    }
    PT(double a,double b){
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

void draw_pixel(PT p,int color){///Pixel filling with color
    p=convert_pixel(p);
    putpixel( (int)(p.x+0.5) , (int)(p.y+0.5) , color );
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
void line_draw_DDA(PT p1,PT p2){///DDA algorithm for line draging
    double dx=abs(p2.x-p1.x);
    double dy=abs(p2.y-p1.y);
    if(p1.y==p2.y) ///horijontal line
    {
        if(p1.x>p2.x){
            swap(p1,p2);
        }
        for(int i=p1.x ; i<=p2.x ; i++)
        {
            delay(0.2);
            draw_pixel(PT(i,p1.y),YELLOW);
        }
    }
    else if(p1.x==p2.x)  ///vertical line
    {
        if(p1.y>p2.y){
            swap(p1,p2);
        }
        for(int i=p1.y ; i<=p2.y ; i++)
        {
            draw_pixel(PT(p1.x,i),YELLOW);
        }
    }else if(dx>dy){
        if(p1.x>p2.x){
            swap(p1,p2);
        }
        draw_pixel(p1,YELLOW);
        double xi=p1.x;
        double yi=p1.y;
        double m=(p2.y-p1.y)/(p2.x-p1.x);
        while(xi<p2.x){
            xi+=1;
            yi+=(m);
            draw_pixel(PT(xi,yi),YELLOW);
        }
        draw_pixel(p2,YELLOW);
    }else{
        if(p1.y>p2.y){
            swap(p1,p2);
        }
        draw_pixel(p1,YELLOW);
        double xi=p1.x;
        double yi=p1.y;
        int n=abs(p2.y-p1.y);
        double m=(p2.y-p1.y)/(p2.x-p1.x);
        for(int i=1 ; i<n ; i++){
            xi+=(1/m);
            yi+=1;
            draw_pixel(PT(xi,yi),YELLOW);
        }
        draw_pixel(p2,YELLOW);
    }
}
void line_draw_Bressenham(PT p1,PT p2){ ///Bressenham's algorithm for line draging
    double dx=(p2.x-p1.x);
    double dy=(p2.y-p1.y);
    double m=dy/dx;
    if( (m>0) && (m<1) ){
        double d=(2*dy) - dx;
        double c1=2*(dy-dx);
        double c2=2*dy;
        double xi=p1.x , yi=p1.y ;
        draw_pixel(p1,YELLOW);
        while(xi<p2.x){
            xi++;
            if(d<0){
                d+=c2;
            }else{
                yi+=1;
                d+=c1;
            }
            draw_pixel(PT(xi,yi),YELLOW);
        }
    }else{

        cout << "This algorithm for those line where 0 < m < 1 ." << endl;
    }
}
int main(){
    initwindow(window_w,window_h);
    draw_axis();

    /**Uncomment the line for testing the algorithms**/

    /**Test case for DDA algorithm**/

    //DDA_line_draw(PT(0,50),PT(200,50));
    //DDA_line_draw(PT(200,100),PT(200,-100));
    //DDA_line_draw(PT(0,0),PT(200,300));
    //DDA_line_draw(PT(0,0),PT(-200,300));
    //DDA_line_draw(PT(0,0),PT(-300,-200));
    //DDA_line_draw(PT(0,0),PT(200,-300));*/
    /**Test case for Bressenhams  algorithm**/

    //line_draw_Bressenham(PT(0,0),PT(250,200));
    //line_draw_Bressenham(PT(0,-50),PT(250,0));
    //line_draw_Bressenham(PT(-300,0),PT(0,200));

    getchar();
    return 0;
}
