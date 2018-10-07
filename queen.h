#ifndef QUEEN_H
#define Queen_h

#include<iostream>
#include<conio.h>
#include "bishop.h"
#include "rook.h"

bool check(int i, int j, int borw)      // To check if promoted queen is present at the location i,j
{
    if(borw == 0)
    {
        if(board[i][j] == -1)
            return true;
    }
    else
    {
        if(board[i][j] == 33)
            return true;
    }
    return false;
}

class queen
{
    int xFinal, yFinal;
    int xInitial, yInitial;
    int borw;
    int rorb;
    bool moveCheck();

public:
    queen(int n)
    {
        borw = n;
    }
    void find(int x, int y, int n = 99, int m = 99);
    void move();
    void kill();
};

bool queen::moveCheck()
{
    bishop w(0);
    rook r(0);
    w.setData(xInitial, yInitial, xFinal, yFinal);
    r.setData(xInitial, yInitial, xFinal, yFinal);

    //cout<<xInitial<<yInitial<<endl;
    //cout<<xFinal<<yFinal<<endl;
    //cout<<w.moveCheck()<<r.moveCheck()<<endl;getch();
    //cout << finalx <<" "<<initialx<<endl;
    //cout <<finaly<<" "<<initialy<<endl;
    //getch();

    if(r.moveCheck() == true || w.moveCheck() == true)
    {
        bool chk;
        inv = 0;
        chk = r.moveCheck();
        if(chk == true)
            rorb = 0;       //ROOK
        else
            rorb = 1;       //BISHOP
        inv = 0;
        return true;
    }
    return false;
}

void queen::find(int x, int y, int n, int m)
{
    int q, no = 0;
    xFinal = x;
    yFinal = y;
    xInitial = yInitial = 99;
    int initialx, initialy;
    if(borw == 0)
    {
        q = 15;
    }
    else
    {
        q = 31;
    }
    if(n==99&&m==99)
    {
        for(int i=0;i<8;i++)
	    {for(int j=0;j<8;j++)
	    {
		if(i+j==x+y)
		    if(board[i][j]==q || check(i, j, borw))
		    {
		        initialx = xInitial;
		        initialy = yInitial;
                xInitial = n = i;
                yInitial = m = j;
                if(moveCheck() == true)
                    no++;
                else
                {
                    xInitial = initialx;
                    yInitial = initialy;
                }
		    }
	    }
	  }
        for(int i=x,j=y;i>-1&&j>-1;i--,j--)
        {
            if(board[i][j]==q || check(i, j, borw))
            {
                initialx = xInitial;
		        initialy = yInitial;
                xInitial = n = i;
                yInitial = m = j;
                if(moveCheck() == true)
                    no++;
                else
                {
                    xInitial = initialx;
                    yInitial = initialy;
                }
		    }
        }
        for(int i=x,j=y;i<8&&j<8;i++,j++)
        {
            if(board[i][j]==q || check(i, j, borw))
            {
                initialx = xInitial;
		        initialy = yInitial;
                xInitial = n = i;
                yInitial = m = j;
                if(moveCheck() == true)
                    no++;
                else
                {
                    xInitial = initialx;
                    yInitial = initialy;
                }
		    }                                          //to find the queen
        }
        for(int i=0;i<8;i++)
	    if(board[x][i]==q || check(x, i, borw))
        {
            initialx = xInitial;
            initialy = yInitial;
            xInitial = n = x;
            yInitial = m = i;
            if(moveCheck() == true)
                no++;
            else
            {
                xInitial = initialx;
                yInitial = initialy;
            }
        }
        for(int i=0;i<8;i++)
            if(board[i][y]==q || check(i, y, borw))
            {
                initialx = xInitial;
		        initialy = yInitial;
                xInitial = n = i;
                yInitial = m = y;
                if(moveCheck() == true)
                    no++;
                else
                {
                    xInitial = initialx;
                    yInitial = initialy;
                }
            }
        if(no>1)
            inv++;
    }
	else if(m==99)
    {
        for (int d=0;d<8;d++)
        if(board[n][d]==q || check(n, d, borw))
        {
            xInitial = n;
            yInitial = d;
            if(moveCheck() == true)
            {m=d;no++;inv=0;}
        else inv++;
        }
    }
	else if(n==99)
    {
        for (int d=0;d<8;d++)
        if(board[d][m]==q || check(d, m, borw))
        {
            xInitial = d;
            yInitial = m;
            if(moveCheck() == true)
                {n=d;no++;inv=0;}
            else inv++;
        }
    }
    if(xInitial == 99 || yInitial == 99)
        inv++;
    if(inv > 0)
        return;
    if(moveCheck() == false)
        inv++;
}

void queen::move()
{
    rook r(borw);
    bishop b(borw);
    if(rorb == 0)
    {
        r.setData(xInitial, yInitial, xFinal, yFinal);
        if(r.moveCheck() == true && inv == 0)
            r.move();
        else
            inv++;
    }
    else
    {
        b.setData(xInitial, yInitial, xFinal, yFinal);
        if(b.moveCheck() == true && inv == 0)
            b.move();
        else
            inv++;
    }
}

void queen::kill()
{
    if(board[xInitial][yInitial] == 0)
    {
        inv++;
        return;
    }
    rook r(borw);
    bishop b(borw);
    if(rorb == 0)
        {
            r.setData(xInitial, yInitial, xFinal, yFinal);
            r.kill();
        }
        else
        {
            b.setData(xInitial, yInitial, xFinal, yFinal);
            b.kill();
        }
}

#endif // QUEEN_H
