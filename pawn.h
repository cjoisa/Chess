#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

class pawn
{
    int borw;
    int xp;
    int yp;
    int tomov;

public:
    pawn(int a)
    {
        borw = a;
    }
    void findp(int x, int y ,int a[8][8]);
    void movep(int a[8][8]);
    void kill(int ko , int board[8][8]);
};

void pawn::findp(int x, int y, int a[8][8])
{
    int i;
    if(borw==0)
    {
        for(i=x; i>=0;i--)
            if(a[i][y]<9 && a[i][y]>0)
            break;
    }
    else
    {
        for(i=x;i<8;i++)
            if(a[i][y]<=24 && a[i][y]>16)
            break;
    }
   xp=i;
   tomov=x;
   yp=y;
   }

void pawn::movep(int a[8][8])
{
int count = 0;
if(borw==0)
{
    for(int i=xp+1;i<=tomov;i++)
    {
        count++;
        if(a[i][yp]!=0)
            {inv++;
        return;}
    }
}
else
{
    for(int i=xp-1;i>=tomov;i--)
    {
        count++;
        if(a[i][yp]!=0)
            {inv++;
        return;}

    }
}
if(count < 3)
    {
        if(count == 2 && (xp == 1 || xp == 6))
        {
            a[tomov][yp]=a[xp][yp];
            a[xp][yp]=0;
            if(tomov == 7 || tomov == 0)
            {
                if(borw == 0)
                    a[tomov][yp] = 15;
                else
                    a[tomov][yp] = 31;
            }
        }
        else if(count == 1)
        {
            a[tomov][yp]=a[xp][yp];
            a[xp][yp]=0;
            if(tomov == 7 || tomov == 0)
            {
                if(borw == 0)
                    a[tomov][yp] = 15;
                else
                    a[tomov][yp] = 31;
            }
        }
        else inv++;

    }
    else inv++;
}

void pawn:: kill(int ko , int board[8][8])
{
if(ko==yp+1 ||ko==yp-1)
    { if(borw==0)
        {if((board[xp+1][ko]!=0) && (board[xp][yp]!=0) && (board[xp+1][ko]>16) &&(board[xp][yp]<9))
	         {board[xp+1][ko]=board[xp][yp];
	          board[xp][yp]=0;
	          if(xp + 1 == 7 )
                    board[xp + 1][ko] = 15;
		      }
    else
	inv++;}
	else {
        if(board[xp-1][ko]!=0 && board[xp][yp]<25 && board[xp][yp]>16 && board[xp-1][ko]<17)
	{board[xp-1][ko]=board[xp][yp];
	board[xp][yp]=0;
	   if(xp - 1 == 0 )
            board[xp - 1][ko] = 31;
        }
		else
                inv++;}}
	else
	    inv++;
}
#endif // PAWN_H_INCLUDED
