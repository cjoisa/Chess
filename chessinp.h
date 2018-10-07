#ifndef CHESSINP_H
#define CHESSINP_H

#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

#define check_invalid {if(inv > 0) return;}     //Checks if invalid.

#include "pawn.h"
#include "bishop.h"
#include "horse.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "menu.h"
#include "RandomGenerator.h"

int tonum(char ch)          //Converts the character row numbers into numbers(integer).
{
    char a = '1', b = '2', c = '3', d = '4';
    char e = '5', f = '6', g = '7', h = '8';
    if(ch == a)             //Row 1.
	return 0;
    else if(ch == b)        //Row 2.
	return 1;
    else if(ch == c)        //Row 3.
	return 2;
    else if(ch == d)        //Row 4.
	return 3;
    else if(ch == e)        //Row 5.
	return 4;
    else if(ch == f)        //Row 6.
	return 5;
    else if(ch == g)        //Row 7.
	return 6;
    else if(ch == h)        //Row 8.
	return 7;
    else
	return 99;
}
int tonum1(char ch)         //Converts the character column names given by the user into numbers.
{
    if(ch == 'a')           //a column.         //Reverse as arrays don't follow x-y coordinates.
	return 7;
    else if(ch == 'b')      //b column.
	return 6;
    else if(ch == 'c')      //c column.
	return 5;
    else if(ch == 'd')      //d column.
	return 4;
    else if(ch == 'e')      //e column.
	return 3;
    else if(ch == 'f')      //f column.
	return 2;
    else if(ch == 'g')      //g column.
	return 1;
    else if(ch == 'h')      //h column.
	return 0;
    else if(ch == 'x')      //For killing.
	return 9;
    else if(ch == 'B')      //Bishop.
	return 10;
    else if(ch == 'N')      //Knight.
	return 11;
    else if(ch == 'Q')      //Queen.
	return 12;
    else if(ch == 'R')      //Rook.
	return 13;
    else if(ch == 'K')      //King.
	return 14;
    else
	return 99;
}

void undo()
{
    for(int q = 0; q < 8; q++)
        for(int w = 0; w < 8; w++)
           board[q][w] = bCopy[q][w];     //Copies the temporary board onto the actual board.
    moves[totMoves - 1][0] = '\0';        //Erases the move stored.
    totMoves--;                           //Reduces the total number of moves by one.
}

void cheat(int bw)                        //Converts all pawns into Queens.
{
     if(bw == 0)
     {
         for(int g=0;g<8;g++)
    for(int h=0;h<8;h++)
    if(board[g][h]<9&&board[g][h]>0)
       {board[g][h]=15;}
     }
     else
     {
         for(int g=0;g<8;g++)
    for(int h=0;h<8;h++)
    if(board[g][h]<25&&board[g][h]>16)
       board[g][h]=31;
     }
 }

class inp
{
    int n, m;               //Stores the x and y coordinates.
    int bw, x;              //bw tells whose turn it is.(0 -> white , 1 -> black).
    char fh, xe;            //Temporary variables for sending to functions.
    int p;                  //Tells which piece to use.
    void length2();         //If length of user's input is two.
    void length3(int p);    //If length of user's input is three.
    void length4(int p);    //If length of user's input is four.
    void length5(int p);    //If length of user's input is five.
    void length6(int p);    //If length of user's input is six.

public:
    void input(int borw, int a[8][8]);  //Gets the user's input.
};
void inp::length2()
{
    pawn w(0),b(1);

    if(n!=1)
    {
         if(bw == 0)
         {
              w.findp(n, m, board);
              check_invalid;
              w.movep(board);
         }
         else
         {
              b.findp(n, m, board);
              check_invalid;
              b.movep(board);
         }
     }
     else inv++;
}

void inp::length3(int p)
{
    bishop wb(0), bb(1);
    horse wh(0), bh(1);
    rook wr(0), br(1);
    queen wq(0), bq(1);
    king wk(0), bk(1);

    if(p == 10)
	   {
	       if(bw == 0)
           {
               wb.find(n, m);
               check_invalid;
               wb.move();
           }
           else
           {
               bb.find(n, m);
               check_invalid;
               bb.move();
           }
	   }
    else if(p == 11)
    {
        if(bw == 0)
        {
            wh.find(n, m);
            check_invalid;
            wh.move();
        }
        else
        {
            bh.find(n, m);
            check_invalid;
            bh.move();
        }
    }
    else if(p == 12)
    {
        if(bw == 0)
        {
            wq.find(n, m);
            check_invalid;
            wq.move();
        }
        else
        {
            bq.find(n, m);
            check_invalid;
            bq.move();
        }
    }
    else if(p == 13)
    {
        if(bw == 0)
        {
            wr.find(n, m);
            check_invalid;
            wr.move();
        }
        else
        {
            br.find(n, m);
            check_invalid;
            br.move();
        }
    }
    else if(p == 14)
    {
        if(bw == 0)
        {
            wk.find(n, m);
            check_invalid;
            wk.move();
        }
        else
        {
            bk.find(n, m);
            check_invalid;
            bk.move();
        }
    }
    else inv++;
}

void inp::length4(int p)
{
    pawn wp(0), bp(1);
    bishop wb(0), bb(1);
    horse wh(0), bh(1);
    rook wr(0), br(1);
    queen wq(0), bq(1);
    king wk(0), bk(1);

    if(p == 10 && x == 9)
    {
        if(bw == 0)
        {
            wb.find(n, m);
            check_invalid;
            wb.kill();
        }
        else
        {
            bb.find(n, m);
            check_invalid;
            bb.kill();
        }
    }
    else if(p == 11)
    {
        if(x == 9)
        {
            if(bw == 0)
            {
            wh.find(n, m);
            check_invalid;
            wh.kill();
            }
            else
            {
            bh.find(n, m);
            check_invalid;
            bh.kill();
            }

        }
        else if(x != 99)
        {
            if(bw == 0)
            {
            wh.find(n, m, 99, x);
            check_invalid;
            wh.move();
            }
            else
            {
            bh.find(n, m, 99, x);
            check_invalid;
            bh.move();
            }
        }
        else if(tonum(fh) != 99)
        {
            if(bw == 0)
            {
            wh.find(n, m, tonum(fh), 99);
            check_invalid;
            wh.move();
            }
            else
            {
            bh.find(n, m, tonum(fh), 99);
            check_invalid;
            bh.move();
            }
        }
        else
            inv++;
    }
    else if(p == 12)
    {
        if(x == 9)
        {
            if(bw == 0)
            {
            wq.find(n, m);
            check_invalid;
            wq.kill();
            }
            else
            {
            bq.find(n, m);
            check_invalid;
            bq.kill();
            }

        }
        else if(x != 99)
        {
            if(bw == 0)
            {
            wq.find(n, m, 99, x);
            check_invalid;
            wq.move();
            }
            else
            {
            bq.find(n, m, 99, x);
            check_invalid;
            bq.move();
            }
        }
        else if(tonum(fh) != 99)
        {
            if(bw == 0)
            {
            wq.find(n, m, tonum(fh), 99);
            check_invalid;
            wq.move();
            }
            else
            {
            bq.find(n, m, tonum(fh), 99);
            check_invalid;
            bq.move();
            }
        }
        else
            inv++;
    }
    else if(p == 13)
    {
        if(x == 9)
        {
            if(bw == 0)
        {
            wr.find(n, m);
            check_invalid;
            wr.kill();
        }
        else
        {
            br.find(n, m);
            check_invalid;
            br.kill();
        }
        }
        else
        {
        if(x != 99)
        {
            if(bw == 0)
            {
            wr.find(n, m, 99, x);
            check_invalid;
            wr.move();
            }
            else
            {
            br.find(n, m, 99, x);
            check_invalid;
            br.move();
            }
        }
        else if(tonum(fh) != 99)
        {
            if(bw == 0)
            {
            wr.find(n, m, tonum(fh), 99);
            check_invalid;
            wr.move();
            }
            else
            {
            br.find(n, m, tonum(fh), 99);
            check_invalid;
            br.move();
            }
        }
        }
    }
    else if(p == 14)
    {
        if(x == 9)
        {
            if(bw == 0)
        {
            wk.find(n, m);
            check_invalid;
            wk.kill();
        }
        else
        {
            bk.find(n, m);
            check_invalid;
            bk.kill();
        }
        }
    }
    else if(x == 9)
    {
        if(bw == 0)
        {
            wp.findp(n, p, board);
            check_invalid;
            wp.kill(m, board);
        }
        else
        {
            bp.findp(n, p, board);
            check_invalid;
            bp.kill(m, board);
        }

    }
    else inv++;
}

void inp::length5(int p)
{
    horse wh(0), bh(1);
    rook wr(0), br(1);
    queen wq(0), bq(1);

    if(p == 11)
    {
        if(x == 9)
        {
            if(tonum(fh) != 99)
            {
                if(bw == 0)
                {
                    wh.find(n, m, tonum(fh));
                    check_invalid;
                    wh.kill();
                }
                else
                {
                    bh.find(n, m, tonum(fh));
                    check_invalid;
                    bh.kill();
                }
            }
            else if(tonum1(fh) != 99)
            {
                if(bw == 0)
                {
                    wh.find(n, m, 99, tonum1(fh));
                    check_invalid;
                    wh.kill();
                }
                else
                {
                    bh.find(n, m, 99, tonum1(fh));
                    check_invalid;
                    bh.kill();
                }
            }
            else
                inv++;
        }
        else if(x != 99)
        {
            inv++;
            return;
        }
        else if(tonum1(fh) != 99)
        {
            if(tonum(xe) == 99)
                return;
            if(bw == 0)
                {
                    wh.find(n, m, tonum(xe), tonum1(fh));
                    check_invalid;
                    wh.move();
                }
                else
                {
                    bh.find(n, m, tonum(xe), tonum1(fh));
                    check_invalid;;
                    bh.move();
                }
        }
        else
            inv++;
    }

    if(p == 12)
    {
        if(x == 9)
        {
            if(tonum(fh) != 99)
            {
                if(bw == 0)
                {
                    wq.find(n, m, tonum(fh));
                    check_invalid;
                    wq.kill();
                }
                else
                {
                    bq.find(n, m, tonum(fh));
                    check_invalid;
                    bq.kill();
                }
            }
            else if(tonum1(fh) != 99)
            {
                if(bw == 0)
                {
                    wq.find(n, m, 99, tonum1(fh));
                    check_invalid;
                    wq.kill();
                }
                else
                {
                    bq.find(n, m, 99, tonum1(fh));
                    check_invalid;
                    bq.kill();
                }
            }
            else
                inv++;
        }
        else if(x != 99)
        {
            inv++;
            return;
        }
        else if(tonum1(fh) != 99)
        {
            if(tonum(xe) == 99)
                return;
            if(bw == 0)
                {
                    wq.find(n, m, tonum(xe), tonum1(fh));
                    check_invalid;
                    wq.move();
                }
                else
                {
                    bq.find(n, m, tonum(xe), tonum1(fh));
                    check_invalid;
                    bq.move();
                }
        }
        else
            inv++;
    }
    else if(p == 13)
    {
        if(x == 9)
        {
            if(tonum(fh) != 99)
            {
                if(bw == 0)
                {
                    wr.find(n, m, tonum(fh));
                    check_invalid;
                    wr.kill();
                }
                else
                {
                    br.find(n, m, tonum(fh));
                    check_invalid;
                    br.kill();
                }
            }
            else if(tonum1(fh) != 99)
            {
                if(bw == 0)
                {
                    wr.find(n, m, 99, tonum1(fh));
                    check_invalid;
                    wr.kill();
                }
                else
                {
                    br.find(n, m, 99, tonum1(fh));
                    check_invalid;
                    br.kill();
                }
            }
        }
        else if(x != 99)
        {
            inv++;
            return;
        }
        else if(tonum1(fh) != 99)
        {
            if(tonum(xe) == 99)
                return;
            if(bw == 0)
                {
                    wr.find(n, m, tonum(xe), tonum1(fh));
                    check_invalid;
                    wr.move();
                }
                else
                {
                    br.find(n, m, tonum(xe), tonum1(fh));
                    check_invalid;
                    br.move();
                }
        }
    }
    else inv++;
}

void inp::length6(int p)
{
    queen wq(0), bq(1);

    if(p == 12)
    {
        if(tonum(xe) != 99 && tonum1(fh) != 99 && x == 9)
        {
            if(bw == 0)
            {
                wq.find(n, m, tonum(xe), tonum1(fh));
                check_invalid;
                wq.kill();
            }
            else
            {
                bq.find(n, m, tonum(xe), tonum1(fh));
                check_invalid;
                bq.kill();
            }
        }
        else
            inv++;
    }
    else
        inv++;
}

void inp::input(int borw, int board[8][8])
{
    king wk(0), bk(1);
    bw = borw;
    char inp[50], ch;//, es;            //ch is a temporary variable.

    if(bw == 0)
            std::cout << std::endl << std::endl << " \t\tWHITE ENTER THE MOVE  " << std::endl;
    //else
            //std::cout << std::endl << std::endl << " \t\tBLACK ENTER THE MOVE  " << std::endl;
    else
    {
        int Check;
        Player P;
        cout << "\n\n \t\t THINKING...\n";
        Check = P.Move();
        cout << "\a";
        //cout << endl << P.xFinal << P.yFinal << "\a";
        //getch();
        if(Check == 0)
            return;
    }
        /*es = getche();                //
        if(es == 27)                    //Checks if esc key was pressed.
        {                               //If yes then displays the in-game-menu
        int a;
        a = inGameMenu(bw);
        if(a == 0)
        {
            --worb;
            return;
        }
        else if(a == 1)
            return;
        }*/
    fflush(stdin);
    std::cin.getline(inp,50);
    //for(int t = 49; t > -1; t--)
    //    inp[t + 1] = inp[t];              //To reattach the first character
    //inp[0] = es;
    if(strcmp(inp, "exit") == 0)           //To exit the game at any point.
        exit(0);
    if(strcmp(inp, "queen" )== 0)           //To cheat.
    {
        cheat(bw);
        return;
    }
    if(strcmp(inp, "menu") == 0)            //To call the in-game-menu.
    {
        int a;
	a = inGameMenu(bw);
	if(a == 0)
	{
	--worb;
	return;
	}
	else if(a == 1)
	    return;
    }
    if(strcmp(inp, "undo") == 0)           //To undo the move.
    {
        if(UNDO == 1)                       //Can't undo twice in a row.
        {
            inv++;
            return;
        }
        undo();
        UNDO = 1;
        return;
    }
    UNDO = 0;

    for(int e = 0; e < 8; e++)              //For Undo();
        for(int r = 0; r < 8; r++)          //Copies the actual board onto a copy board.
            bCopy[e][r] = board[e][r];

    int len = strlen(inp);
    if(len == 1 || len > 6)                 //
	        inv++;

	ch = inp[len - 1];
	n = tonum(ch);                          //Row where the piece should move.
    ch = inp[len - 2];
    m = tonum1(ch);                         //Column where the piece should move.

    if(strcmp("O-O", inp) == 0)             //King-side castle.
    {
        if(bw == 0)
        {
            wk.castle(0);
            return;
        }
        else
        {
            bk.castle(0);
            return;
        }
    }
    if(strcmp("O-O-O", inp) == 0)           //Queen-side castle.
    {
        if(bw == 0)
        {
            wk.castle(1);
            return;
        }
        else
        {
            bk.castle(1);
            return;
        }
    }

    if((m < 9) && (m > -1) && (n < 9) && (n > -1))
    {
        if(len == 2)                //Note : p -> piece number(check tonum1), x -> is 9 when the piece is killing.
            length2();
        if(len == 3)
        {
            ch = inp[len - 3];
            p = tonum1(ch);
            length3(p);
        }
        if(len == 4)
        {
            ch = inp[len - 4];
            p = tonum1(ch);
            ch = inp[len - 3];
            x = tonum1(ch);
            fh = inp[len - 3];      //fh is the column / row the horse/queen/rook is currently at.
            length4(p);
        }
        if(len == 5)
        {
            ch = inp[len - 3];
            xe = ch;                //For checking if an invalid character was entered.
            x = tonum1(ch);         //If the piece is not killing, x is the column and fh is the row.
            fh = inp[len - 4];      //Again fh is the column/row the piece is at(when the piece is about to kill).
            ch = inp[len - 5];
            p = tonum1(ch);
            length5(p);
        }
        if(len == 6)
        {
            ch = inp[3];
            x = tonum1(ch);
            fh = inp[1];            //fh is the column the piece is currently at.
            xe = inp[2];            //xe is the row the piece is currently at.
            ch = inp[0];
            p = tonum1(ch);
            length6(p);
        }
    }
    else inv++;
    if(inv == 0)
    {
        strcpy(moves[totMoves], inp);//Copies the new moves into the move array to store and display.
        totMoves++;
    }
}


#endif // CHESSINP_H
