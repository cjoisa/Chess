#ifndef BISHOP_H
#define BISHOP_H
#include<iostream>

class bishop
{
    int xInitial, yInitial;
    int xFinal, yFinal;
    int borw;

public:
    bishop(int bw)
    {
        borw = bw;
    }
    void find(int x, int y);
    bool moveCheck();
    void move();
    void kill();
    void setData(int xi, int yi, int xf, int yf)
    {
        xInitial = xi;
        xFinal = xf;
        yInitial = yi;
        yFinal = yf;
    }
};

bool bishop::moveCheck()
{
    int Initialx = xInitial, Initialy = yInitial;
    int Finalx = xFinal, Finaly = yFinal;
    if(Finalx == xInitial || Finaly == yInitial)
        return false;
    if(Initialx + Initialy != Finalx + Finaly)
	{
	    if(Finalx + Finaly > Initialx + Initialy)
	    {
	        Finalx--;
	        Finaly--;
		    for(int i = Initialx, j = Initialy; i != Finalx && j != Finaly; i++, j++)
		        if(board[i + 1][j + 1] != 0)
                    return false;
	    }
	    else
	    {
	        Finalx++;
	        Finaly++;
		    for(int i = Initialx, j = Initialy; i != Finalx && j != Finaly; i--, j--)
		        if(board[i - 1][j - 1] != 0)
                    return false;
	    }
	}
	else
	{
	    if(Finalx > Initialx)
	     {
	         Finalx--;
	         Finaly++;
		     for(int i = Initialx, j = Initialy; i != Finalx && j != Finaly; i++, j--)
		         if(board[i + 1][j - 1] != 0)
                     return false;
	     }
	     else
	     {
	         Finalx++;
	         Finaly--;
	         for(int i = Initialx, j = Initialy; i != Finalx && j != Finaly; i--, j++)
                 if(board[i - 1][j + 1] != 0)
                     return false;
	     }
	}

	return true;
}

void bishop::find(int x, int y)
{
    int q, w;
    xInitial = 99;

    if(borw == 0)
    {
         q = 9;
         w = 10;
    }
    else
    {
         q = 25;
         w = 26;
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
	    {
		    if(i + j == x + y)
		    if(board[i][j] == q || board[i][j] == w)
		    {
			    xInitial = i;
                yInitial = j;
		    }
	    }
    }

	if(xInitial == 99)
    {
	    for(int i = x, j = y; i > -1 && j > -1; i--, j--)
	    {
	        if(board[i][j] == q || board[i][j] == w)
		    {
			    xInitial = i;
			    yInitial = j;
		    }
        }
    }

	if (xInitial == 99)
    {
	    for(int i = x, j = y; i < 8 && j < 8; i++, j++)
	    {
	        if(board[i][j] == q || board[i][j] == w)
		    {
			    xInitial = i;
			    yInitial = j;
		    }                                          //to find the bishop
        }
    }

	if(xInitial == 99)
        inv++;
    xFinal = x;
    yFinal = y;
}

void bishop::move()
{
    if(board[xFinal][yFinal] != 0 || moveCheck() == false)
    {
        inv++;
        return;
    }
    if(xInitial + yInitial != xFinal + yFinal)
	{
	    if(xFinal + yFinal > xInitial + yInitial)
	    {
	        for(int i = xInitial,j = yInitial; i < xFinal && j < yFinal; i++, j++)
	        {
                if(board[i + 1][j + 1] == 0)
		        {
		            board[i + 1][j + 1] = board[i][j];
		            board[i][j] = 0;
                }
		        else
                {
                    inv++;
		            break;
		        }
	         }
	    }
	    else
	    {
		    for(int i = xInitial, j = yInitial; i > xFinal && j > yFinal; i--, j--)
	        {
                if(board[i - 1][j - 1] == 0)
		        {
		            board[i - 1][j - 1] = board[i][j];
		            board[i][j] = 0;
                }
	        	else
                {
                    inv++;
		            break;
                }
	        }
	    }
	}
	else
	{
	    if(xFinal > xInitial)
	     {
	         for(int i = xInitial, j = yInitial; i < xFinal && j > yFinal; i++, j--)
	         {
	             if(board[i+1][j-1]==0)
                 {
                     board[i+1][j-1]=board[i][j];
                     board[i][j]=0;
                 }
		         else
                 {
                     inv++;
		             break;
                 }
	         }
	     }
	     else
	     {
	         for(int i = xInitial, j = yInitial; i > xFinal && j < yFinal; i--, j++)
	         {
		          if(board[i-1][j+1]==0)
                  {
                      board[i-1][j+1]=board[i][j];
		              board[i][j]=0;
                  }
                  else
                  {
                      inv++;
		              break;
                  }
	          }
	     }
	}
}

void bishop::kill()
{
    bool check;
    if(borw == 0)
        check = board[xFinal][yFinal] > 16;
    else
        check = board[xFinal][yFinal] < 17;
    if(check == true)
    {
        if((board[xFinal][yFinal] != 0) && (moveCheck() == true))
        {
            board[xFinal][yFinal] = 0;
            move();
        }
        else inv++;
    }

}

#endif // BISHOP_H
