#ifndef ROOK_H
#define ROOK_H
#include<iostream>
#include<conio.h>

using namespace std;
class rook
{
    int xInitial, yInitial;
    int xFinal, yFinal;
    int initialx, initialy; //for moveCheck()
    int borw;

public:
    rook(int b)
    {
        borw = b;
    }
    void find(int x, int y, int n = 99, int m = 99);
    bool moveCheck();
    void move();
    void kill();
    void setData(int xi, int yi, int xf, int yf)
    {
        xInitial = initialx = xi;
        xFinal = xf;
        yInitial = initialy = yi;
        yFinal = yf;
    }
};

bool rook::moveCheck()
{
    int finalx, finaly;
    finalx = xFinal;
    finaly = yFinal;
    if(finalx==initialx)
    {
	if(initialy>finaly)
	{ finaly++;
	    for(int i=1;initialy-i>-1 && (initialy-i>=finaly);i++)
		if(board[finalx][initialy-i]!=0)
		    return false;
	}
	if(initialy<finaly)
	{finaly--;
	    for(int i=1;initialy+i<8 && (initialy+i<=finaly);i++)
		if(board[finalx][initialy+i]!=0)
		    return false;
	}
    }

   else if(finaly==initialy)
    {
	if(initialx>finalx)
	{finalx++;
	    for(int i=1;initialx-i>-1 && (initialx-i>=finalx);i++)
		if(board[initialx-i][finaly]!=0)
		    return false;
	}
	if(initialx<finalx)
	{finalx--;
	    for(int i=1;initialx+i<8 && (initialx+i<=finalx);i++)
		if(board[initialx+i][finaly]!=0)
		    {return false;}
	}
    }
    else return false;
    return true;
}

void rook::find(int x, int y, int n, int m)
{
    int count = 0;
    int q, w;
    xFinal = x;
    yFinal = y;
    xInitial = yInitial = 99;
    if (borw == 0)
    {
        q = 13;
        w = 14;
    }
    else
    {
        q = 29;
        w = 30;
    }

    if(n == 99 && m == 99)
    {
	for(int i = 0; i < 8; i++)
	    if(board[x][i] == q || board[x][i] == w)
	{
	    n = x;
	    m = i;
	    initialx =  n;
	    initialy =  m;
	    if(moveCheck() == true)
		{
		    xInitial = n;
            yInitial = m;
            inv = 0;
            count++;
        }
		else
        {
		    inv = 0;
		}
	}
	for(int i = 0; i < 8; i++)
	    if(board[i][y] == q || board[i][y] == w)
	{
	    n = i;
	    m = y;
	    initialx = n;
	    initialy = m;
	    if(moveCheck() == true)
		{
		    xInitial = n;
		    yInitial = m;
		    inv = 0;
		    count++;
        }
	    else
        {
		    inv = 0;
        }

	}
    }

    else if(n == 99)
    {
	for(int i = 0; i < 8; i++)
	    if(board[i][m] == q || board[i][m] == w)
	{
	    initialx = i;
	    initialy = m;
	    if(moveCheck() == true)
        {
            xInitial = i;
            yInitial = m;
            n = i;
        }
	    count++;
	}

    }
    else if(m == 99)
    {
	for(int i = 0; i < 8; i++)
	    if(board[n][i] == q || board[n][i] == w)
	{
	    initialx = n;
	    initialy = i;
	    if(moveCheck() == true)
            {yInitial = i;
            xInitial = n;
            m = i;}
	    count++;
	}

    }
    if(count > 1)
	inv++;
	if(n == 99 || m == 99)
	inv++;
    if(xInitial != 99 && yInitial != 99)
        {
            initialx = xInitial;
            initialy = yInitial;
            if(moveCheck() == false)
                inv++;
        }
    else
        inv++;
}

void rook::move()
{
	if(xFinal==xInitial)
    {
	if(yInitial>yFinal)
	{
	    for(int i=1;yInitial-i>-1 &&(yInitial-i>=yFinal);i++)
	    {
		if(board[xFinal][yInitial-i]==0)
		    {
		       board[xFinal][yInitial-i]=board[xFinal][yInitial-i+1];
		       board[xFinal][yInitial-i+1]=0;
		    }
		    else
            {
                inv++;
                board[xInitial][yInitial] = board[xFinal][yInitial-i+1];
                if(1 - i != 0)
                    board[xFinal][yInitial-i+1]=0;
                break;
            }
	    }
	}
	else if(yInitial<yFinal)
	{
	    for(int i=1;yInitial+i<8 &&(yInitial+i<=yFinal);i++)
	    {
		if(board[xFinal][yInitial+i]==0)
		    {
		       board[xFinal][yInitial+i]=board[xFinal][yInitial+i-1];
		       board[xFinal][yInitial+i-1]=0;
		    }
		    else
            {
                inv++;
                board[xInitial][yInitial] = board[xFinal][yInitial+i-1];
                if(i - 1 != 0)
                board[xFinal][yInitial+i-1]=0;
                break;}
	    }
	}
	else inv++;
    }

   else if(yFinal==yInitial)
    {
	if(xInitial>xFinal)
	{
	    for(int i=1;xInitial-i>-1 &&(xInitial-i>=xFinal);i++)
	    {
		if(board[xInitial-i][yFinal]==0)
		    {
		       board[xInitial-i][yFinal]=board[xInitial-i+1][yFinal];
		       board[xInitial-i+1][yFinal]=0;
		    }
		    else
            {
                inv++;
                board[xInitial][yInitial] = board[xInitial-i+1][yFinal];
                if(1 - i != 0)
                    board[xInitial-i+1][yFinal] = 0;
                break;
            }
	    }
	}
	else if(xInitial<xFinal)
	{
	    for(int i=1;xInitial+i<8 &&(xInitial+i<=xFinal);i++)
	    {
		if(board[xInitial+i][yFinal]==0)
		    {
		       board[xInitial+i][yFinal]=board[xInitial+i-1][yFinal];
		       board[xInitial+i-1][yFinal]=0;
		    }
		    else
            {
                inv++;
                board[xInitial][yInitial] = board[xInitial+i-1][yFinal];
                if(i - 1 != 0)
                    board[xInitial + i - 1][yFinal] = 0;
                break;
		    }

	    }
	}
	else inv++;
    }
    if(inv == 0)
        mov[board[xFinal][yFinal]]++;
}

void rook::kill()
{
    bool check;
    if(borw == 0)
        check = board[xFinal][yFinal] > 16;
    else
        check = (board[xFinal][yFinal] < 17) && (board[xFinal][yFinal] != 0);
    if(moveCheck() == true && check == true)
    {
        board[xFinal][yFinal]=0;
        move();
    }
    else inv++;
}

#endif // ROOK_H

