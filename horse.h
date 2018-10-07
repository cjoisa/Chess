#ifndef HORSE_H
#define HORSE_H

class horse
{
    int xInitial, yInitial;
    int xFinal, yFinal;
    int borw;

public:
    horse(int n)
    {
        borw = n;
    }
    void find(int x, int y, int n = 99, int m = 99);
    void move();
    void kill();
};

void horse::find(int x, int y, int n, int m)
{
    int count = 0, q, w;
    if(borw == 0)
    {
        q = 11;
        w = 12;
    }
    else
    {
        q = 27;
        w = 28;
    }
    if(n == 99 && m == 99)
    {
        if((x+2<8)&&(y+1<8)&&(board[x+2][y+1]==q ||board[x+2][y+1]==w))
        {
            n=x+2;
            m=y+1;
            count++;
        }
        if(((x-2>-1)&&(y+1<8))&&(board[x-2][y+1]==q ||board[x-2][y+1]==w))
        {
            n=x-2;
            m=y+1;
            count++;
        }
	    if((x+2<8)&&(y-1>-1)&&(board[x+2][y-1]==q ||board[x+2][y-1]==w))
        {
            n=x+2;
            m=y-1;;
            count++;
        }
        if((x-2>-1)&&(y-1>-1)&&(board[x-2][y-1]==q ||board[x-2][y-1]==w))
        {
            n=x-2;
            m=y-1;
            count++;
        }
        if((x+1<8)&&(y+2<8)&&(board[x+1][y+2]==q ||board[x+1][y+2]==w))
        {
            n=x+1;
            m=y+2;
            count++;
        }
        if((x+1<8)&&(y-2>-1)&&(board[x+1][y-2]==q ||board[x+1][y-2]==w))
        {
            n=x+1;
            m=y-2;
            count++;
        }
        if((x-1>-1)&&(y+2<8)&&(board[x-1][y+2]==q ||board[x-1][y+2]==w))
        {
            n=x-1;
            m=y+2;
            count++;
        }
        if((x-1>-1)&&(y-2>-1)&&(board[x-1][y-2]==q ||board[x-1][y-2]==w))
        {
            n=x-1;
            m=y-2;
            count++;
        }
        if(count > 1)
            inv++;
	}
	else if(n!=99)
	{
	    if((board[n][y-1]==q ||board[n][y-1]==w )&&(y-1>-1))
            m=y-1;
	    else if((board[n][y+1]==q ||board[n][y+1]==w )&&(y+1<8))
            m=y+1;
	    else if((board[n][y-2]==q ||board[n][y-2]==w )&&(y-2>-1))
            m=y-2;
	    else if((board[n][y+2]==q ||board[n][y+2]==w)&&(y+2<8))
            m=y+2;
	    else
            inv++;
	}
	else
	{
	    if((board[x-1][m]==q ||board[x-1][m]==w )&&(x-1>-1))
            n=x-1;
	    else if((board[x+1][m]==q ||board[x+1][m]==w )&&(x+1<8))
            n=x+1;
	    else if((board[x-2][m]==q ||board[x-2][m]==w )&&(x-2>-1))
            n=x-2;
	    else if((board[x+2][m]==q ||board[x+2][m]==w )&&(x+2<8))
            n=x+2;
	    else
            inv++;
	}
	if(n==99 ||m==99)
	    inv++;

	    xInitial = n;
	    yInitial = m;
	    xFinal = x;
	    yFinal = y;
}

void horse::move()
{
    if(board[xFinal][yFinal] == 0)
    {
	board[xFinal][yFinal] = board[xInitial][yInitial];
	board[xInitial][yInitial] = 0;
    }
    else inv++;
}

void horse::kill()
{
    bool check;
    if(borw == 0)
        check = board[xFinal][yFinal] > 16;
    else
        check = board[xFinal][yFinal] < 17;
    if((board[xFinal][yFinal]!=0)&&(check == true))
    {
        board[xFinal][yFinal]=0;
        move();
    }
    else inv++;
}

#endif // HORSE_H
