#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
#define ssize 30
class MATRIX{
public:
    int X[10],Y[20];
    bool POS[20][10];
    MATRIX()
    {
        for(int x=0;x<10;x++)
            X[x]=20+x*ssize;
        for(int x=0;x<20;x++)
        {
           Y[x]=x*ssize;
            for(int y=0;y<10;y++)
            {
                POS[x][y]=false;
            }
        }
    }
    int getindexx(int a)
    {
        for(int x=0;x<10;x++)
            if(X[x]<=a && X[x]+ssize>a)
                return x;
        return -1;
    }
    int getindexy(int a)
    {
        for(int x=0;x<20;x++)
        {
            if(Y[x]<=a && Y[x]+ssize>a)
                return x;
        }
        return -1;
    }
};
MATRIX *mat;
void sqr(int x,int y){
        register int ss=30,shado=4,poly[12];
        setcolor(BLACK);
        line(x,y,x+ss,y);
        poly[0]=x+1;
        poly[1]=y+1;

        poly[2]=x+ss-2;
        poly[3]=y+1;

        poly[4]=x+ss-2;
        poly[5]=y+ss-2;

        poly[6]=x+ss-shado;
        poly[7]=y+ss-shado;

        poly[8]=x+ss-shado;
        poly[9]=y+shado;

        poly[10]=x+shado;
        poly[11]=y+shado;


        setcolor(COLOR(109,207,246));
        setfillstyle(1,COLOR(109,207,246));
        fillpoly(6,poly);

        poly[0]=x+1;
        poly[1]=y+1;

        poly[2]=x+1;
        poly[3]=y+ss-2;

        poly[4]=x+ss-2;
        poly[5]=y+ss-2;

        poly[6]=x+ss-shado;
        poly[7]=y+ss-shado;

        poly[8]=x+shado;
        poly[9]=y+ss-shado;

        poly[10]=x+shado;
        poly[11]=y+shado;

        setcolor(COLOR(82,142,163));
        setfillstyle(1,COLOR(82,142,163));
        fillpoly(6,poly);

        setfillstyle(1,CYAN);
        bar(x+1+shado,y+1+shado,x+ss-shado,y+ss-shado);
}
void sqr1(int x,int y,int clr=CYAN){
    setcolor(BLACK);
    line(x,y,x+ssize,y);
    setcolor(COLOR(109,207,246));
    setfillstyle(1,clr);
    bar3d(x+1,y+1,x+ssize-1,y+ssize-1,0,0);
}
void clean(int x,int y){
    setfillstyle(1,BLACK);
    bar(x,y,x+ssize,y+ssize);
}
class psqr7{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=2;
    bool movabler(int x,int y,int p)
    {
        if(p==1)
        {
            if(mat->getindexx(x)==6) return false;
            bool tflag=true;
            for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+4])
                tflag= false;
            return tflag;
        }
        else if(p==2)
        {
            if(mat->getindexx(x)==8) return false;
            bool tflag=true;
            for(int z=0;z<3;z++)
            for(int i=0;i<=2;i++)
            if(mat->POS[mat->getindexy(y+ssize*z)+i][mat->getindexx(x)+2])
                tflag= false;
            return tflag;
        }
    }
    bool movablel(int x,int y,int p)
    {
        if(p==1)
        {
            if(mat->getindexx(x)==0) return false;
            bool tflag=true;
            for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                tflag= false;
            return tflag;
        }
        else if(p==2)
        {
            if(mat->getindexx(x+ssize)==0) return false;
            bool tflag=true;
            for(int z=0;z<3;z++)
            for(int i=0;i<=2;i++)
            if(mat->POS[mat->getindexy(y+ssize*z)+i][mat->getindexx(x)])
                tflag= false;
            return tflag;
        }
    }
    bool transform(int &x,int &y, int &r){
        if(r==1){
            if(mat->getindexy(y)>=16 || mat->POS[mat->getindexy(y)+4][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                return false;
        }
        else if(r==2){
            if(mat->getindexx(x)==-1 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)]){
                for(int i=1;i<=4;i++){
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+i])
                        return false;
                    else if(mat->getindexx(x)+i-2==8)
                        return false;
                }
                x+=ssize;
            }
            else if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2]){
                for(int i=0;i<3;i++){
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-i] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-i])
                        return false;
                    else if(mat->getindexx(x)-i+1==0)
                        return false;
                }
                x-=ssize*2;
            }
            else if(mat->getindexx(x)==7 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+3]){
                for(int i=1;i<=2;i++){
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1])
                        return false;
                    else if(mat->getindexx(x)-i+2==0)
                        return false;
                }
                x-=ssize;
            }
        }
        return true;
    }
    bool print(int &x,int &y,int r=1,bool dflag=false,bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold+ssize,yold+ssize);
                clean(xold,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
                clean(xold+ssize*3,yold+ssize);
            }
            else if(pold==2)
            {
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize*2);
                clean(xold+ssize,yold+ssize*3);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==18)
                        loop=true;
                    else for(int i=0;i<4;i++)
                        if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i]){
                            loop=true;
                            break;
                        }
                }
                flag=true;
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*3,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
            }
            else if(mat->getindexy(y)==18)
                flag=true;
            else for(int i=0;i<4;i++)
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i]){
                    flag=true;
                    break;
                }
            if(flag){
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*3)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y+ssize);
                sqr(x+ssize*2,y+ssize);
                sqr(x+ssize*3,y+ssize);
                sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {
            bool flag=false;
            if(mat->getindexy(y)==16)
                flag=true;
            else if(mat->POS[mat->getindexy(y)+4][mat->getindexx(x)+1])
                flag=true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==16)
                        loop=true;
                    else if(mat->POS[mat->getindexy(y)+4][mat->getindexx(x)+1])
                        loop=true;
                }
                flag=true;
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+3]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*3)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x+ssize,y);
                sqr(x+ssize,y+ssize*2);
                sqr(x+ssize,y+ssize*3);
                sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
    }
};
class psqr2{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=4;
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            if(mat->POS[mat->getindexy(y)][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            return true;
        }
        if(r==3)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            return true;
        }
        if(r==4)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=0;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
    }
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if (0==mat->getindexx(x))
                return false;
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            return true;
        }
        if(r==2)
        {
            if (-1==mat->getindexx(x))
                return false;
            for(int i=0;i<4;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            return true;
        }
        if(r==3)
        {
            if (0==mat->getindexx(x))
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                    return false;
            for(int i=2;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+1])
                    return false;
            return true;
        }
        if(r==4)
        {
            if (0==mat->getindexx(x))
                return false;
            for(int i=2;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                    return false;
            for(int i=0;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                    return false;
            return true;
        }
    }
    bool transform(int &x,int &y, int &r){
        if(r==1){
            if(mat->getindexy(y)==17 || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)][mat->getindexx(x)+2])
            {
                return false;
            }
        }
        else if(r==2){
            if(mat->getindexx(x)==-1 || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)]){
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+3])
                    return false;
                else if(mat->getindexx(x)==7)
                    return false;
                else
                    x+=ssize;
            }
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                return false;

        }
        else if(r==3){
            if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                return false;
        }
        else if(r==4){
            if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]){
                if(mat->POS[mat->getindexy(y)][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1])
                    return false;
                else if(mat->getindexx(x)==0)
                    return false;
                else
                    x-=ssize;
            }
            else if(mat->POS[mat->getindexy(y)][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                return false;

        }
        return true;
    }
    bool print(int &x,int &y,int &r,bool dflag=false, bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold,yold);
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
            }
            else if(pold==2)
            {
                clean(xold+ssize,yold);
                clean(xold+ssize*2,yold);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold+ssize*2);
            }
            else if(pold==3)
            {
                clean(xold,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize*2);
            }
            else if(pold==4)
            {
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize*2);
                clean(xold+ssize,yold+ssize);
                clean(xold,yold+ssize*2);
            }
        }
        if(r==1)
        {
            bool flag=false;
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag= true;
            if(mat->getindexy(y)==18)
                flag=true;
            else if(down){
                bool loop =false;
                while(!loop)
                {
                    y+=ssize;
                    for(int i=0;i<3;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop= true;
                    if(mat->getindexy(y)==18)
                        loop=true;
                }
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1]);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x,y);
                sqr(x,y+ssize);
                sqr(x+ssize,y+ssize);
                sqr(x+ssize*2,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {

            bool flag=false;
            if(mat->getindexy(y)==17)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexy(x)+2])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexy(x)+2])
                        loop= true;
                }
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2]);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x+ssize,y);
                sqr(x+ssize*2,y);
                sqr(x+ssize,y+ssize);
                sqr(x+ssize,y+ssize*2);
            }
            old(x,y,r);
            return flag;

        }
        else if(r==3)
        {
            bool flag=false;
            if(mat->getindexy(y)==17)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                flag= true;
            else for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag=true;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                        loop= true;
                    else for(int i=0;i<2;i++)
                        if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop=true;
                }
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+2]);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x,y+ssize);
                sqr(x+ssize*2,y+ssize);
                sqr(x+ssize,y+ssize);
                sqr(x+ssize*2,y+ssize*2);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==4)
        {

            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else
                    for(int i=0;i<2;i++)
                        if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+i])
                            loop= true;
                }
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x,mat->Y[mat->getindexy(y)+2]);
                flag=true;
            }
            else if(mat->getindexy(y)==17)
                flag= true;
            else
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+i])
                    flag= true;
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x)]=true;
            }
            if(!down){
                sqr(x+ssize,y);
                sqr(x+ssize,y+ssize*2);
                sqr(x+ssize,y+ssize);
                sqr(x,y+ssize*2);
            }
            old(x,y,r);
            return flag;
        }
    }
};
class psqr3{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=4;
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=1;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=1;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            return true;
        }
        if(r==3)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=0;i<=1;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==4)
        {
            if(mat->getindexx(x)==-1)
                return false;
            for(int i=0;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            return true;
        }
    }
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=2;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=0;i<4;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
        if(r==3)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=0;i<3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            return true;
        }
        if(r==4)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=2;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=0;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
    }
    bool transform(int &x, int &y, int &r){
        if(r==1){
            if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)][mat->getindexx(x)])
                return false;
        }
        else if(r==2){
            if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2])
                if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1] || mat->getindexx(x)==0)
                    return false;
                else
                    x-=ssize;
            else if(mat->POS[mat->getindexy(y)][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                return false;
        }
        else if(r==3){
            if(mat->getindexy(y)==17 || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+2])
                return false;
            else if(mat->POS[mat->getindexy(y)][mat->getindexx(x)+1])
                return false;
        }
        else if(r==4){
            if(mat->getindexx(x)==-1 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)]){
                if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+3]||mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+3])
                    return false;
                else if(mat->getindexx(x)==7)
                    return false;
                else
                    x+=ssize;
            }
        }
        return true;
    }
    bool print(int x,int y,int r,bool dflag=false, bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold,yold+ssize*2);
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
            }
            else if(pold==2)
            {
                clean(xold+ssize,yold);
                clean(xold,yold);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold+ssize*2);
            }
            else if(pold==3)
            {
                clean(xold,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold);
            }
            else if(pold==4)
            {
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize*2);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize*2);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)])
                        loop= true;
                    else for(int i=1;i<=2;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop= true;
                }
                sqr(x,mat->Y[mat->getindexy(y)+2]);
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                flag=true;
            }
            else if(mat->getindexy(y)==17)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)])
                flag= true;
            else for(int i=1;i<=2;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag= true;
            if(flag){
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y+ssize*2);
                sqr(x,y+ssize);
                sqr(x+ssize*2,y+ssize);
                sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {
            bool flag=false;
            if(mat->getindexy(y)==17)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                        loop= true;
                }
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                flag=true;

            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
            sqr(x+ssize,y);
            sqr(x,y);
            sqr(x+ssize,y+ssize*2);
            sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==3)
        {

            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==18)
                        loop= true;
                    else for(int i=0;i<3;i++)
                        if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                            loop= true;
                }
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                flag=true;
            }
            else if(mat->getindexy(y)==18)
                flag= true;
            else for(int i=0;i<3;i++)
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                    flag= true;
            if(flag){
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y+ssize);
                sqr(x+ssize*2,y+ssize);
                sqr(x+ssize*2,y);
                sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==4)
        {
            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop= true;
                    else
                    for(int i=1;i<=2;i++)
                        if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+i])
                        loop= true;
                }
                flag=true;
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+2]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
            }
            else if(mat->getindexy(y)==17)
                flag= true;
            else
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+i])
                flag= true;
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
            sqr(x+ssize,y);
            sqr(x+ssize,y+ssize*2);
            sqr(x+ssize*2,y+ssize*2);
            sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
    }
};
class psqr4{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=2;
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+i+2][mat->getindexx(x)])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                    return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                    return false;
            return true;
        }
    }
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=1;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            for(int i=0;i<=1;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
    }
    bool transform(int &x, int &y,int &r){
        if(r==1){
            if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]){
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1])
                    return false;
                else if(mat->getindexx(x)==0)
                    return false;
                else x-=ssize;
            }
        }
        else if(r==2){
            if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                return false;
            else if(mat->POS[mat->getindexy(y)][mat->getindexx(x)])
                return false;
        }
        return true;
    }
    bool print(int &x,int &y,int r=1, bool dflag=false, bool down=false)
    {
        if(dflag)
        {
            if(pold==1)
            {
                clean(xold,yold);
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold+ssize*2);
            }
            else if(pold==2)
            {
                clean(xold,yold+ssize);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold);
                clean(xold+ssize*2,yold);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(mat->getindexy(y)>16)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)>16)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)+1])
                        loop= true;
                }
                flag=true;
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+2]);
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y);
                sqr(x,y+ssize);
                sqr(x+ssize,y+ssize);
                sqr(x+ssize,y+ssize*2);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {
            bool flag=false;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)>17)
                        loop= true;
                    else
                    for(int i=0;i<2;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop= true;
                    else if((mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]))
                        loop= true;
                }
                flag=true;
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)]);
            }
            else if(mat->getindexy(y)>17)
                flag= true;
            else
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag= true;
            else if((mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2]))
                flag= true;
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x+ssize,y);
                sqr(x,y+ssize);
                sqr(x+ssize,y+ssize);
                sqr(x+ssize*2,y);
            }
            old(x,y,r);
            return flag;
        }
    }
};
class psqr5{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=2;
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=0;i<3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i+2][mat->getindexx(x)+1])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            return true;
        }
    }
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=1;i<=3;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=0; i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            return true;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            return true;
        }
    }
    bool transform(int &x ,int &y,int &r){
        if(r==1){
            if(mat->getindexx(x)==8 || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+2])
                if(mat->POS[mat->getindexy(y)][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1])
                    return false;
                else if(mat->getindexx(x)==0)
                    return false;
                else
                    x-=ssize;
        }
        else if(r==2){
            if(mat->getindexy(y)==17 || mat->POS[mat->getindexy(y)+3][mat->getindexx(x)] || mat->POS[mat->getindexy(y)+2][mat->getindexx(x)])
                return false;
        }
        return true;
    }
    bool print(int &x,int &y,int r=1,bool dflag=false,bool down=false)
    {
        if(dflag){
            if(pold==1)
            {
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize);
                clean(xold,yold+ssize);
                clean(xold,yold+ssize*2);
            }
            else if(pold==2)
            {
                clean(xold,yold);
                clean(xold+ssize,yold);
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize*2,yold+ssize);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(mat->getindexy(y)==17)
                flag=true;
            else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)])
                flag=true;
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==17)
                        loop=true;
                    else if(mat->POS[mat->getindexy(y)+3][mat->getindexx(x)])
                        loop=true;
                    else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                        loop= true;
                }
                flag=true;
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x,mat->Y[mat->getindexy(y)+1]);
                sqr(x,mat->Y[mat->getindexy(y)+2]);
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y+ssize*2)][mat->getindexx(x)]=true;
            }
            if(!down){
                sqr(x+ssize,y);
                sqr(x+ssize,y+ssize);
                sqr(x,y+ssize);
                sqr(x,y+ssize*2);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==2)
        {
            if(mat->getindexx(x)>7)
                x=mat->X[7];
            bool flag=false;
            if(down){
                bool loop =false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==18)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                        loop= true;
                    else for(int i=1;i<=2;i++)
                        if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                        loop= true;
                }
                flag=true;
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)+1]);
            }
            else if(mat->getindexy(y)==18)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                flag= true;
            else for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                flag= true;
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x,y);
                sqr(x+ssize,y);
                sqr(x+ssize,y+ssize);
                sqr(x+ssize*2,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
    }
};
class psqr6{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=1;
    bool movablel(int x,int y,int r)
    {
        if(mat->getindexx(x)==0)
            return false;
        for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
            return false;
        return true;
    }
    bool movabler(int x,int y,int r)
    {
        if(mat->getindexx(x)==8)
            return false;
        for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
            return false;
        return true;
    }
    bool print(int x,int y, int r=1,bool dflag=false,bool down=false)
    {
        if(dflag)
        {
            clean(xold,yold);
            clean(xold+ssize,yold);
            clean(xold+ssize,yold+ssize);
            clean(xold,yold+ssize);
        }
        bool flag=false;
        if(down){
            bool loop =false;
            while(!loop){
                y+=ssize;
                if(mat->getindexy(y)==18)
                    loop= true;
                else for(int i=0;i<2;i++)
                    if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
                    loop= true;
            }
            flag=true;
            sqr(x,mat->Y[mat->getindexy(y)]);
            sqr(x+ssize,mat->Y[mat->getindexy(y)]);
            sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
            sqr(x,mat->Y[mat->getindexy(y)+1]);
        }
        else if(mat->getindexy(y)==18)
            flag= true;
        else for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+i])
            flag= true;
        if(flag){
            mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
            mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
            mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x)]=true;
        }
        if(!down){
            sqr(x,y);
            sqr(x+ssize,y);
            sqr(x+ssize,y+ssize);
            sqr(x,y+ssize);
        }
        old(x,y,r);
        return flag;
    }
};
class psqr1{
    int xold,yold,pold;
    void old(int x,int y,int r){
        xold=x;
        yold=y;
        pold=r;
    }
public:
    int const totpos=4;
    bool movablel(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
            for(int i=0;i<=1;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=-1;i<=0;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
        }
        if(r==3)
        {
            if(mat->getindexx(x)==0)
                return false;
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)-1])
                return false;
            for(int i=-1;i<=0;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
        }
        if(r==4)
        {
            if(mat->getindexx(x)==-1)
                return false;
            for(int i=-1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)])
                return false;
        }
        return true;
    }
    bool movabler(int x,int y,int r)
    {
        if(r==1)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
        }
        if(r==2)
        {
            if(mat->getindexx(x)==8)
                return false;
            for(int i=-1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
        }
        if(r==3)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=-1;i<1;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
        }
        if(r==4)
        {
            if(mat->getindexx(x)==7)
                return false;
            for(int i=0;i<2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+3])
                return false;
            for(int i=1;i<=2;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
            for(int i=-1;i<1;i++)
                if(mat->POS[mat->getindexy(y)+i][mat->getindexx(x)+2])
                return false;
        }
        return true;
    }
    bool transform(int &x,int &y,int &r)
    {
        if(r==1){
            return true;
        }
        else if(r==2){
            if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2] || mat->getindexx(x)==8){
                if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)-1] || mat->POS[mat->getindexy(y)][mat->getindexx(x)-1] || mat->getindexx(x)==0)
                    return false;
                else x-=ssize;
            }
            else if(mat->getindexx(x)==0 || mat->POS[mat->getindexy(y)][mat->getindexx(x)-1]){
                if(mat->POS[mat->getindexy(y)][mat->getindexx(x)+2])
                return false;
            }
        }
        else if(r==3){
            if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1] || mat->getindexy(y)==18)
            return false;
        }
        else if(r==4){
            if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)] || mat->getindexx(x)==-1 || mat->POS[mat->getindexy(y)][mat->getindexx(x)] || mat->getindexx(x)==-1){
                if(mat->POS[mat->getindexy(y)][mat->getindexx(x)+3] || mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+3] || mat->getindexx(x)==7)
                    return false;
                else
                    x+=ssize;
            }
        }
        return true;

    }
    bool print(int &x,int &y,int &r,bool dflag=false,bool down=false)
    {
        if(dflag)
        {
            clean(xold+ssize,yold);
            if(pold==1){
                clean(xold,yold);
                clean(xold+ssize*2,yold);
                clean(xold+ssize,yold+ssize);
            }
            else if(pold==2){
                clean(xold,yold);
                clean(xold+ssize,yold-ssize);
                clean(xold+ssize,yold+ssize);
            }
            else if(pold==3){
                clean(xold,yold);
                clean(xold+ssize,yold-ssize);
                clean(xold+ssize*2,yold);
            }
            else if(pold==4){
                clean(xold+ssize,yold+ssize);
                clean(xold+ssize,yold-ssize);
                clean(xold+ssize*2,yold);
            }
        }
        if(r==1)
        {
            bool flag=false;
            if(mat->getindexy(y)==18)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y=y+ssize;
                    if(mat->getindexy(y)==18)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+2])
                        loop= true;
                }
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                flag= true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y);
                sqr(x+ssize*2,y);
                sqr(x+ssize,y);
                sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;

        }
        else if(r==2)
        {

            bool flag=false;
            if(mat->getindexy(y)==18)
                flag= true;
            else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                flag= true;
            else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                flag= true;
            else if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==18)
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)])
                        loop= true;
                    else if(mat->POS[mat->getindexy(y)+2][mat->getindexx(x)+1])
                        loop= true;
                }
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)-1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)+1]);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y-ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
            }
            if(!down){
                sqr(x,y);
                sqr(x+ssize,y-ssize);
                sqr(x+ssize,y);
                sqr(x+ssize,y+ssize);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==3)
        {
            bool flag=false;
            if(mat->getindexy(y)==19)
                flag= true;
            else
            for(int i=0;i<3;i++)
            if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+i])
                flag= true;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==19)
                        loop= true;
                    else
                    for(int i=0;i<3;i++)
                    if(mat->POS[mat->getindexy(y)+1][mat->getindexx(x)+i])
                        loop= true;
                }
                sqr(x,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)-1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)]);
                flag =true;
            }
            if(flag){
                mat->POS[mat->getindexy(y)][mat->getindexx(x)]=true;
                mat->POS[mat->getindexy(y-ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x,y);
                sqr(x+ssize,y-ssize);
                sqr(x+ssize,y);
                sqr(x+ssize*2,y);
            }
            old(x,y,r);
            return flag;
        }
        else if(r==4)
        {
            bool flag=false;
            if(mat->getindexy(y)==18)
                flag= true;
            else
            for(int i=0;i<2;i++)
            if(mat->POS[mat->getindexy(y)+2-i][mat->getindexx(x)+1+i])
                flag= true;
            if(down){
                bool loop=false;
                while(!loop){
                    y+=ssize;
                    if(mat->getindexy(y)==18)
                        loop= true;
                    else
                    for(int i=0;i<2;i++)
                    if(mat->POS[mat->getindexy(y)+2-i][mat->getindexx(x)+1+i])
                        loop= true;
                }
                sqr(x+ssize,mat->Y[mat->getindexy(y+ssize)]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)-1]);
                sqr(x+ssize,mat->Y[mat->getindexy(y)]);
                sqr(x+ssize*2,mat->Y[mat->getindexy(y)]);
                flag=true;
            }
            if(flag){
                mat->POS[mat->getindexy(y+ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y-ssize)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize)]=true;
                mat->POS[mat->getindexy(y)][mat->getindexx(x+ssize*2)]=true;
            }
            if(!down){
                sqr(x+ssize,y+ssize);
                sqr(x+ssize,y-ssize);
                sqr(x+ssize,y);
                sqr(x+ssize*2,y);
            }
            old(x,y,r);
            return flag;
        }
    }
};
void getup(){
    setfillstyle(1,LIGHTCYAN);
    setcolor(LIGHTCYAN);
    bar(0,0,19,620);
    bar(0,601,400,620);
    bar(321,0,600,620);

    setcolor(BLACK);
    setbkcolor(LIGHTCYAN);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(360, 40, "Tetris Game");
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(385, 100, "Next Piece");
    outtextxy(360, 300, "Level : 1");
    outtextxy(360, 350, "Score : 0");
    outtextxy(360, 400, "Press 0(Zero) to");
    outtextxy(360, 420, "Pause and Play");
    outtextxy(360, 470, "Playing...");
    settextstyle(3, HORIZ_DIR, 2);
    outtextxy(360, 510, "Keys: LEFT, RIGHT,");
    outtextxy(360, 540, "DOWN, SPACE, 0");
    setcolor(RED);
    settextstyle(3, HORIZ_DIR, 1);
    outtextxy(340, 570, "www.YouTube.com/projectcoding");
    int x=400,y=150,s=5;
    setfillstyle(1,BLACK);
    bar(x-s,y-s,x+ssize*4+s,y+ssize*4+s);
    if(false){
    sqr(x,y);
    sqr(x+ssize,y);
    sqr(x+ssize*2,y);
    sqr(x+ssize*3,y);

    sqr(x,y+ssize);
    sqr(x+ssize,y+ssize);
    sqr(x+ssize*2,y+ssize);
    sqr(x+ssize*3,y+ssize);

    sqr(x,y+ssize*2);
    sqr(x+ssize,y+ssize*2);
    sqr(x+ssize*2,y+ssize*2);
    sqr(x+ssize*3,y+ssize*2);

    sqr(x,y+ssize*3);
    sqr(x+ssize,y+ssize*3);
    sqr(x+ssize*2,y+ssize*3);
    sqr(x+ssize*3,y+ssize*3);}
}
class ALL{
    public:
    psqr1 *p1;
    psqr2 *p2;
    psqr3 *p3;
    psqr4 *p4;
    psqr5 *p5;
    psqr6 *p6;
    psqr7 *p7;
    int value,next=0,pos,nextpos;
    int refresh(){
        if(next==0) {
            next=rand()%7+1;
            switch(next){
                case 1 : p1=new psqr1; break;
                case 2 : p2=new psqr2; break;
                case 3 : p3=new psqr3; break;
                case 4 : p4=new psqr4; break;
                case 5 : p5=new psqr5; break;
                case 6 : p6=new psqr6; break;
                case 7 : p7=new psqr7; break;
            }
            nextpos=rand()%totpos(next)+1;
        }
        value=next;
        pos=nextpos;
        next=rand()%7+1;
        switch(next){
            case 1 : p1=new psqr1; break;
            case 2 : p2=new psqr2; break;
            case 3 : p3=new psqr3; break;
            case 4 : p4=new psqr4; break;
            case 5 : p5=new psqr5; break;
            case 6 : p6=new psqr6; break;
            case 7 : p7=new psqr7; break;
        }
        nextpos= rand()%totpos(next)+1;
        int x=400,y=150;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
        {
            clean(x+ssize*i,y+ssize*j);
        }
        switch(next){
            case 1 : y+=ssize; p1->print(x,y,nextpos); break;
            case 2 : p2->print(x,y,nextpos); break;
            case 3 : p3->print(x,y,nextpos); break;
            case 4 : p4->print(x,y,nextpos); break;
            case 5 : p5->print(x,y,nextpos); break;
            case 6 : p6->print(x,y,nextpos); break;
            case 7 : p7->print(x,y,nextpos); break;
        }
        return pos;
    }
    bool transform(int *x,int *y,int *r)
    {
        if(value==1)
            return p1->transform(*x,*y,*r);
        if(value==2)
            return p2->transform(*x,*y,*r);
        if(value==3)
            return p3->transform(*x,*y,*r);
        if(value==4)
            return p4->transform(*x,*y,*r);
        if(value==5)
            return p5->transform(*x,*y,*r);
        if(value==6)
            return false;
        if(value==7)
            return p7->transform(*x,*y,*r);
    }
    int totpos(int value){
        if(value==1)
            return p1->totpos;
        if(value==2)
            return p2->totpos;
        if(value==3)
            return p3->totpos;
        if(value==4)
            return p4->totpos;
        if(value==5)
            return p5->totpos;
        if(value==6)
            return p6->totpos;
        if(value==7)
            return p7->totpos;
    }
    int totpos(){
        if(value==1)
            return p1->totpos;
        if(value==2)
            return p2->totpos;
        if(value==3)
            return p3->totpos;
        if(value==4)
            return p4->totpos;
        if(value==5)
            return p5->totpos;
        if(value==6)
            return p6->totpos;
        if(value==7)
            return p7->totpos;
    }
    bool movablel(int x,int y,int r){
        if(value==1)
            return p1->movablel(x,y,r);
        if(value==2)
            return p2->movablel(x,y,r);
        if(value==3)
            return p3->movablel(x,y,r);
        if(value==4)
            return p4->movablel(x,y,r);
        if(value==5)
            return p5->movablel(x,y,r);
        if(value==6)
            return p6->movablel(x,y,r);
        if(value==7)
            return p7->movablel(x,y,r);
    }
    bool movabler(int x,int y,int r){
        if(value==1)
            return p1->movabler(x,y,r);
        if(value==2)
            return p2->movabler(x,y,r);
        if(value==3)
            return p3->movabler(x,y,r);
        if(value==4)
            return p4->movabler(x,y,r);
        if(value==5)
            return p5->movabler(x,y,r);
        if(value==6)
            return p6->movabler(x,y,r);
        if(value==7)
            return p7->movabler(x,y,r);
    }
    bool print(int *x,int *y, int *r ,bool flag,bool down=false){
        if(value==1)
            return p1->print(*x,*y,*r,flag,down);
        if(value==2)
            return p2->print(*x,*y,*r,flag,down);
        if(value==3)
            return p3->print(*x,*y,*r,flag,down);
        if(value==4)
            return p4->print(*x,*y,*r,flag,down);
        if(value==5)
            return p5->print(*x,*y,*r,flag,down);
        if(value==6)
            return p6->print(*x,*y,*r,flag,down);
        if(value==7)
            return p7->print(*x,*y,*r,flag,down);
    }
};
int main(){
    initwindow(600,620,"Tetris Game - www.youtube.com/projectcoding",300,10,false,true);
    getup();
	mat=new MATRIX();
    int y=0-ssize*3,r,x=mat->X[3];
    static int SCORE,LEVEL;
    char ch;
    bool flag=false,down_flag=false;
    srand(time(NULL));
    ALL *all;
    all=new ALL();
    r=all->refresh();
    while(true)
    {
        while(!kbhit())
        {
            //if(all.print(&x,&y,&r,flag))
            if(all->print(&x,&y,&r,flag,down_flag))
            {
                int coun;
                for(int y=0;y<20;y++){ // delete a row
                    coun=0;
                    for(int x=0;x<10;x++){
                        if(mat->POS[y][x])
                            coun++;
                        else
                            break;
                    }
                    if(coun==10){
                        for(int i=y;i>0;i--){
                            for(int x=0;x<10;x++){
                                mat->POS[i][x]=mat->POS[i-1][x];
                            }
                        }
                        for(int i=0;i<20;i++)
                            for(int x=0;x<10;x++)
                                clean(mat->X[x],mat->Y[i]);
                        for(int i=0;i<20;i++)
                            for(int x=0;x<10;x++)
                                if(mat->POS[i][x])
                                    sqr(mat->X[x],mat->Y[i]);

                        setcolor(BLACK);
                        setbkcolor(LIGHTCYAN);
                        settextstyle(4, HORIZ_DIR, 2);
                        SCORE++;
                        if(SCORE/10)
                            LEVEL=SCORE/10;
                        char tmpc[10];
                        itoa(SCORE,tmpc,10);
                        strcat(tmpc,"    ");
                        outtextxy(463, 350, tmpc);
                        itoa(LEVEL,tmpc,10);
                        strcat(tmpc,"    ");
                        outtextxy(460, 300, tmpc);
                    }
                }
                for(int x=0;x<10;x++){ // game over
                    if(mat->POS[0][x]){
                        cout<<"game over";
                        setcolor(BLACK);
                        setbkcolor(LIGHTCYAN);
                        settextstyle(4, HORIZ_DIR, 2);
                        outtextxy(360, 470, "Game Over  ");
                        //while(getch()!='0');
                        do{
                            char tc;
                            while(!kbhit()){
                                Sleep(500);
                                outtextxy(360, 470, "Game Over  ");
                                Sleep(500);
                                outtextxy(360, 470, "                    ");
                            }
                            ch=getch();
                        }while(ch!='0');

                        outtextxy(360, 470, "Playing...    ");

                        SCORE=0;
                        LEVEL=1;
                        char tmpc[10];
                        itoa(SCORE,tmpc,10);
                        strcat(tmpc,"    ");
                        outtextxy(463, 350, tmpc);
                        itoa(LEVEL,tmpc,10);
                        strcat(tmpc,"    ");
                        outtextxy(460, 300, tmpc);

                        setfillstyle(1,BLACK);
                        bar(mat->X[0],0,mat->X[9]+ssize,600);
                        // cout<<endl<<mat->Y[19]+ssize;
                        mat=new MATRIX();
                    }
                }
                r=all->refresh();
                x=mat->X[3];
                y=0-ssize*3;
            }
            Sleep(10);
            flag=false;
            down_flag=false;
            y++;
        }
        ch=getch();
        switch(ch)
        {
            case 'x' : return 0;
            case '0' :
                setcolor(BLACK);
                setbkcolor(LIGHTCYAN);
                settextstyle(4, HORIZ_DIR, 2);
                outtextxy(360, 470, "Paused   ");
                //while(getch()!='0');
                do{
                    char tc;
                    while(!kbhit()){
                        Sleep(500);
                        outtextxy(360, 470, "Paused  ");
                        Sleep(500);
                        outtextxy(360, 470, "             ");
                    }
                    ch=getch();
                }while(ch!='0');
                outtextxy(360, 470, "Playing...");
                break;
            case ' ' : if(!all->transform(&x,&y,&r))
                        break;
                if(r==all->totpos())
                    r=1;
                else
                    r++;
                flag=true;
                break;
            case 0 : char temp=getch();
                if(temp==80)
                {
                    down_flag=true;
                }
                else if(temp==75 && all->movablel(x,y,r))
                    x=x-ssize;
                else if(temp==77 && all->movabler(x,y,r))
                    x=x+ssize;
                flag=true;
                break;
        }
    }
    getch();
}
