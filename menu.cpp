#include "menu.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#include "pawn.h"
#include "bishop.h"
#include "horse.h"
#include "rook.h"
#include "king.h"
#include "chessinp.h"

using namespace std;

void menu::fFile()
{
    ifstream ifile("save.CHESS");
    for(int i = 0; i < 8 && ifile.eof() == 0; i++)
        for(int j = 0; j < 8 && ifile.eof() == 0; j++)
        ifile >> board[i][j];
    ifile >> worb;
    ifile.close();
}

void menu::tFile(int bw)
{
    ofstream ofile("save.CHESS");
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        ofile << board[i][j] << "\n";
    ofile << bw;
    ofile.close();
}

int menu::mainMenu()
{
    int choice;
    for(;;)
    {
        system("CLS");
        cout << "\t\t\t\t CHESS\n" << endl;
        cout << "\t\t\t       MAIN MENU\n\n" ;
        cout << "\t\t\t   1.START GAME\n";
        cout << "\t\t\t   2.HOW TO PLAY\n";
        cout << "\t\t\t   3.CHESS RULES\n";
        cout << "\t\t\t   4.OPEN SAVED GAME\n";
        cout << "\t\t\t   5.EXIT\n";
        cin >> choice;
        switch(choice)
        {
        case 1 :
            return 0;
        case 2:
            break;
        case 3:
            break;
        case 4:
            fFile();
            return 1;
        case 5:
            exit(0);
        }
    }
}

int menu::inGameMenu(int bw)
{
    int choice;
    for(;;)
    {
        system("CLS");
        cout << "\t\t\t\t CHESS\n\n";
        cout << "\t\t\t       MENU\n";
        cout << "\t\t\t   1.RESUME\n";
        cout << "\t\t\t   2.RESTART\n";
        cout << "\t\t\t   3.SAVE GAME\n";
        cout << "\t\t\t   4.PREVIOUS MOVES\n";
        cout << "\t\t\t   5.EXIT\n";
        cin >> choice;
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
            return 1;
        case 4:
            for(int i = 0; moves[i] != '\0'; i++)
                cout << moves[i];
            return 0;
        case 5:
            exit(0);
        }
    }
}
