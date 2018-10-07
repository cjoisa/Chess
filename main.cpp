#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



//typedef int BOARD[8][8];

void gameprep(int a[8][8], char moves[500][50]);    //Needed in menu.h
char moves[500][50];                                //Stores all moves in the game.
int inv = 0, worb = 0, totMoves = 0;                //inv : invalid move(0 is valid), worb : white or black to play, totMoves : Total moves.
int board[8][8], bCopy[8][8];                     //board : main chess board, bCopy : Copy of board(for undo), mov : number of moves per piece
int UNDO = 1, mov[32];                              //To check if UNDO is used twice in a row

#include "chessinp.h"
#include "menu.h"

/******************************************
->	           CHESS        		     <-
->				                    	 <-
->	        MADE BY:             		 <-
->		            CHAITANYA JOISA		 <-
->			                XII A		 <-
->			                12112		 <-
******************************************/


void print(int a)                       //Print the board.
{
    if(a == 0)
    {
        for(int y = 1; y < 40; y++)
        {
            if(y % 5 == 0)
                cout<<(char)206;
            else
                cout<<(char)205;
        }
    }
    else if(a == 1)
    {
        for(int y = 1; y < 40; y++)
        {
            if(y % 5 == 0)
                cout<<(char)202;
            else
                cout<<(char)205;
        }
    }
    else
    {
        for(int y = 1; y < 40; y++)
        {
            if(y % 5 == 0)
                cout<<(char)203;
            else
                cout<<(char)205;
        }
    }
}
void gamehelp(int a)                    //Prints the pieces.
{
    if(a == 0)
    cout << "  ";
    else if(a <= -1)
	cout << "WQ";
    else if(a < 9)
	cout << "WP";
    else if(a < 11)
	cout << "WB";
    else if(a < 13)
	cout << "WN";
    else if(a < 15)
	cout << "WR";
    else if(a < 16)
	cout << "WQ";
    else if(a < 17)
	cout << "WK";
    if(a < 17);
    else if(a < 25)
	cout << "BP";
    else if(a < 27)
	cout << "BB";
    else if(a < 29)
	cout << "BN";
    else if(a < 31)
	cout << "BR";
    else if(a < 32)
	cout << "BQ";
    else if(a == 32)
	cout << "BK";
    else if(a > 32)
	cout << "BQ";
    else
	cout << "error";
}

void gameprep(int a[8][8], char moves[500][50])//Initializes all the pieces to default.
{
    int c, i, j;
    UNDO = 1;
    totMoves = 0;                               //Total moves.
    for(i = 1; i <= 32; i++)
        mov[i] = 0;                             //Moves per piece.
    for(i = 0; i < 500; i++)
        for(j = 0; j < 50; j++)
            moves[i][j] = '\0';                 //Moves entered.
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            a[i][j] = 0;                        //The board.
    for(i = 1, j = 0; j < 8; j++)
        a[i][j] = j + 1;
    for(i = 6, j = 0, c = 16; j < 8; j++,c++)
        a[i][j] = c + 1;
    a[0][1] = 11;
    a[0][2] = 9;
    a[0][5] = 10;
    a[0][6] = 12;
    a[7][1] = 27;
    a[7][2] = 25;
    a[7][5] = 26;
    a[7][6] = 28;
    a[0][0] = 13;
    a[0][7] = 14;
    a[7][0] = 29;
    a[7][7] = 30;
    a[0][4] = 15;
    a[7][4] = 31;
    a[0][3] = 16;
    a[7][3] = 32;
}

bool invalid()      //Displayed when Player enters an invalid move.
{
    if(inv > 0)
    {
        system("CLS");
        cout << " \t\t\t YOU HAVE ENTERED AN INVALID INPUT " << endl << "\t\t\t    ";
        system("pause");
        inv = 0;
        return false;
    }
    return true;
}

void chessboard()   //Displays the Chess Board.
{
    int n = 7;
    int temp = 1;
    if(totMoves >= 33)
    {
        if(totMoves % 2 != 0)
        {
            n = totMoves - 24;
            temp = (n - 5)/2;
        }
	else
	{
	    n = totMoves - 25;
	    temp = (n - 5)/2;
	}
    }
    cout << "    " << (char) 201; print(-1) ; cout << (char) 187 <<"\t\t      MOVES"<< endl;
    for(int i = 7; i > -1; i--)
    {
	cout << "  " << i + 1;

	for(int j = 7; j > -1; j--)
	{
	    cout << " "<<(char)186<<" ";
	    gamehelp(board[i][j]);
	}
	cout << " "<<(char)186;
	if(totMoves > 0 && moves[n - i][0] != '\0')
    {
	cout << "\t\t    "<< temp << ". "<<moves[n - i]<<"  "<<moves[n - i + 1];
	n++;        //as i also decreases by 1
	temp++;
    }
    cout<<endl;
	if(i > 0)
	{cout << "    "<<(char)204;print(0);cout<<(char)185;n++;
	if(totMoves > 0 && moves[n - i][0] != '\0')
    {
	cout << "\t\t    "<< temp << ". "<<moves[n - i]<<"  "<<moves[n - i + 1];
	n++;        //as i also decreases by 1
	temp++;
    }
	cout << endl;}
	else
	{cout << "    "<<(char)200;print(1);cout<<char(188);n++;
	if(totMoves > 0 && moves[n - i][0] != '\0')
    {
	cout << "\t\t    "<< temp << ". "<<moves[n - i]<<"  "<<moves[n - i + 1];
	temp++;
    }
	cout << endl;}
    }
    cout << "      a    b     c    d    e    f    g    h ";
}

void game(int board[8][8])
{
    int valid;    //checks if the previous move was valid or not
    for(; gameover() == true; worb++)
    {
	system("CLS");
	inp ip;
	valid = invalid();
	if(valid == false)
	    continue;
	chessboard();
	if(worb % 2 == 0)
	    ip.input(0, board);
	else
	    ip.input(1, board);
    }
    cout << "\t\t\t     CONGRAGULATIONS!!!\n\t\t\t         YOU WON !!!";
    getch();
}

int main()
{
    mainMenu();    //From menu.h
    game(board);
    return 0;
}
