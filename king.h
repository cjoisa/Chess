#ifndef KING_H
#define KING_H

bool gameover()
{
    int count = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == 16 || board[i][j] == 32)
            count++;
        }
    if(count == 2)
            return true;
    else
            return false;
}

class king
{
    int xInitial, yInitial;
    int xFinal, yFinal;
    int borw;

public:
    king(int n)
    {
        borw = n;
    }
    void find(int x, int y);
    void move();
    void kill();
    void castle(int n);
};

void king::find(int x, int y)
{
    xFinal = x;
    yFinal = y;
    int q;
    if(borw == 0)
        q = 16;
    else
        q = 32;
    if((x-1>-1 )&&(board[x-1][y]==q))
    {xInitial=x-1;
     yInitial=y;}
    else if((y-1>-1)&&(board[x][y-1]==q))
    {
        xInitial=x;
        yInitial=y-1;
    }
    else if((x+1<8)&&(board[x+1][y]==q))
    {
        xInitial=x+1;
        yInitial=y;
    }
    else if((y+1<8)&&(board[x][y+1]==q))
    {
        xInitial=x;
        yInitial=y+1;
    }
    else if((y+1<8)&&(x+1<8)&&(board[x+1][y+1]==q))
    {
        xInitial=x+1;
        yInitial=y+1;
    }
    else if((y+1<8)&&(x-1>-1)&&(board[x-1][y+1]==q))
    {
        xInitial=x-1;
        yInitial=y+1;
    }
    else if((y-1>-1)&&(x+1<8)&&(board[x+1][y-1]==q))
    {
        xInitial=x+1;
        yInitial=y-1;
    }
    else if((y-1>-1)&&(x-1>-1)&&(board[x-1][y-1]==q))
    {
        xInitial=x-1;
        yInitial=y-1;
    }
    else
        inv++;
}

void king::move()
{
    if(xFinal == xInitial + 1 || yFinal == yInitial + 1 || xFinal == xInitial - 1 || yFinal == yInitial -1)
    {
        if(board[xFinal][yFinal]==0)
        {
            board[xFinal][yFinal]=board[xInitial][yInitial];
            board[xInitial][yInitial]=0;
            mov[board[xFinal][yFinal]]++;
        }
        else
            inv++;
    }
}

void king::kill()
{
    if(xFinal == xInitial + 1 || yFinal == yInitial + 1 || xFinal == xInitial - 1 || yFinal == yInitial -1)
    {
        if(borw == 0)
        {
            if(board[xFinal][yFinal] > 16)
            {
                board[xFinal][yFinal] = board[xInitial][yInitial];
                board[xInitial][yInitial] = 0;
                mov[board[xFinal][yFinal]]++;
            }
            else
                inv++;
        }
        else
        {
            if(board[xFinal][yFinal] < 16 && board[xFinal][yFinal] != 0)
            {
                board[xFinal][yFinal] = board[xInitial][yInitial];
                board[xInitial][yInitial] = 0;
                mov[board[xFinal][yFinal]]++;
            }
            else
                inv++;
        }
    }
}

void king::castle(int n)
{
    if(borw == 0)
    {
        if(mov[16]==0)
        {
            if(n==0)
            {
                if(mov[13]==0)
                {
                    if((board[0][2]==0)&&(board[0][1]==0))
                    {
                        board[0][1]=board[0][3];
                        board[0][3]=0;
                        board[0][2]=board[0][0];
                        board[0][0]=0;
                    }
                    else
                        inv++;
                }
                else
                    inv++;
            }
            else
            {
                if(mov[14]==0)
                {
                    if((board[0][4]==0)&&(board[0][5]==0)&&(board[0][6]==0))
                    {
                        board[0][5]=board[0][3];
                        board[0][3]=0;
                        board[0][4]=board[0][7];
                        board[0][7]=0;
                    }
                else
                    inv++;
                }
            }
        }
        else
            inv++;
    }
    else
    {
        if(mov[32]==0)
        {
            if(n==0)
            {
                if(mov[29]==0)
                {
                    if((board[7][2]==0)&&(board[7][1]==0))
                    {
                        board[7][1]=board[7][3];
                        board[7][3]=0;
                        board[7][2]=board[7][0];
                        board[7][0]=0;}
                    else
                        inv++;
                }
                else
                    inv++;
            }
            else
            {
                if(mov[30]==0)
                {
                    if((board[7][4]==0)&&(board[7][5]==0)&&(board[7][6]==0))
                    {
                        board[7][5]=board[7][3];
                        board[7][3]=0;
                        board[7][4]=board[7][7];
                        board[7][7]=0;
                    }
                else
                    inv++;
                }
            }
        }
        else
            inv++;
    }
}

#endif // KING_H


