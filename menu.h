#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void fFile();
void tFile(int);
void mainMenu();
int inGameMenu(int);

void fFile()                        //Retrieves information from file.
{
    ifstream ifile("save.CHS");
    for(int i = 0; i < 8 && ifile.eof() == 0; i++)
        for(int j = 0; j < 8 && ifile.eof() == 0; j++)
        ifile >> board[i][j];
    ifile >> worb;                  //Checks if it's white or black to play.
    ifile.close();
    ifstream iffile("moves.CHS");
    iffile >> totMoves;             //The Total Moves taken place.
    for(int q = 0; iffile.eof() == 0; q++)
	iffile >> moves[q];             //Copies the moves.
    iffile.close();
}

void htp(int n)                      //How-To-Play --- Displays information from file.
{
    system("CLS");
    char a[500], b[10] = "cr.txt";
    if(n == 1)
	strcpy(b, "htp.txt");
    ifstream ifile(b);
    for(int i = 0; ifile.eof() == 0; i++)
    {
	ifile.getline(a,500);
	cout << a << endl;
	if(i == 12)
	{
	    cout << endl;
	    cout << "Press any key to read more \n";
	    getch();
	    system("CLS");
            i = 0;
	}
     }
     getch();
}

void tFile(int bw)                     //Saves to the file.
{
    ofstream ofile("save.CHS");
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        ofile << board[i][j]<<endl;
    ofile << bw;                        //White or black to play next.
    ofile.close();
    ofstream offile("moves.CHS");
    offile << totMoves << endl;         //Total moves taken place.
    for(int q = 0;moves[q][0] != '\0';q++)
        offile << moves[q] << endl;     //
    offile.close();
}

void mainMenu()                         //Displayed at the start.
{
    int choice;
    for(;;)
    {
        system("CLS");
        cout << "\t\t\t\t\tCHESS\n" << endl;
        cout << "\t\t\t\t     MAIN MENU\n\n" ;
        cout << "\t\t\t  \t    1.START NEW GAME\n";
        cout << "\t\t\t  \t    2.HOW TO PLAY\n";
        cout << "\t\t\t  \t    3.CHESS RULES\n";
        cout << "\t\t\t  \t    4.OPEN SAVED GAME\n";
        cout << "\t\t\t  \t    5.EXIT\n";
        choice = getch();
        choice -= 48;
        switch(choice)
        {
        case 1 :
            gameprep(board, moves);     //From main.cpp
            worb = 0;
	    return;
        case 2:
	    htp(1);
            break;
        case 3:
            htp(0);
            break;
        case 4:
            fFile();
            return;
        case 5:
            exit(0);
        }
    }
}

int inGameMenu(int bw)
{
    int choice;
    char c;
    for(;;)
    {
        system("CLS");
        cout << "\t\t\t\t\tCHESS\n\n";
        cout << "\t\t\t\t        MENU\n\n";
        cout << "\t\t\t   \t      1.RESUME\n";
        cout << "\t\t\t   \t      2.RESTART\n";
        cout << "\t\t\t   \t      3.SAVE GAME\n";
        cout << "\t\t\t   \t      4.PREVIOUS MOVES\n";
        cout << "\t\t\t   \t      5.EXIT TO MAIN MENU\n";
        choice = getch();
        choice -= 48;
        switch(choice)
        {
        case 1:
            return 0;  // 0 is for same player , -1 is for the other, 1 is for restart / saved game
        case 2:
            gameprep(board, moves);
            worb = -1;
            return 1;
        case 3:
            tFile(bw);
            system("CLS");
            cout << "\t\t\t\t Game Saved.\n";
            getch();
            cout << "\t\t\tPress y to continue the game : ";
            c = getch();
            if(c == 'y' || c == 'Y')
                return 0;
            else
                exit(0);
        case 4:
            if(moves[1][0] == '\0' && moves[0][0] != '\0')
            {
                cout << "1. " << moves[0];
                getch();
                return 0;
            }
	    int i, j;
            for(i = 1, j = 1; moves[i][0] != '\0'; i += 2, j++)
                cout << j << ". " << moves[i - 1] << " " << moves[i] << endl;
	    if(moves[i - 1][0] != '\0')
	    cout << j << ". " << moves[i - 1] << endl;
            getch();
            return 0;
        case 5:
	    system("CLS");
	    cout << "\t\t\t\tSAVE GAME? (y/n)\n";
	    c = getch();
	    if(c == 'y' || c == 'Y')
	    {
	        tFile(bw);
                system("CLS");
                cout << "\t\t\t\t Game Saved.\n";
                getch();
	    }
            mainMenu();
	    return 0;
        }
    }
}

#endif // MENU_H_INCLUDED
