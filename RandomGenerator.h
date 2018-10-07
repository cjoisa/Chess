#ifndef RANDOMGENERATOR_H_INCLUDED
#define RANDOMGENERATOR_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <random>

//#include "queen.h"
//#include "rook.h"
//#include "bishop.h"
//#include "horse.h"
//#include "pawn.h"
//#include "king.h"

#define reset_invalid {if(inv > 0) inv = 0; else return 0;}
#define cInvalid {if(inv > 0) {inv = 0;continue;}}

class Player
{
    //int CopyOfBoard[8][8];
    int xInitial, yInitial;
    time_t seed;
    long int a;
    int ChoosePiece;
    int Random;
public:
        int xFinal, yFinal;
    Player()
    {    seed = time(&seed);
    a  = seed;
        //for(int i = 0; i < 8; i++)
           // for(int j = 0; j < 8; j++)
            //CopyOfBoard[i][j] = board[i][j];
    }
    int FindRandom();
    int Move();
};


int Player::FindRandom()
{
    //Sleep(1);
    srand(a);
    a = a +157;
    Random = rand() % 8;
    //cout << Random;
    /*const int range_from  = 0;
    const int range_to    = 8;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    Random = distr(generator);
    func();*/
    cout << Random << " ";
    return Random;
}

long int hsh(long int key)
{
    long int sum = 0, temp;
    while(key > 0)
    {
        temp = (sum % 17 + 1) * (((key % 100 * key % 100 * 1767) % 139783)/ tan(key % 100) * sin(key % 100));
        if(temp < 0)
            temp *= -1;
        key /= 100;
        sum = sum + temp;
    }

    if(sum > 9999999)
    {
        while(sum > 9999999)
        {
            sum = sum - (sum / 10);
        }
    }
    else if(sum < 1000000)
    {
        while(sum < 1000000)
        {
            sum = sum + (sum /10);
        }
    }
    //cout << sum % 8 << " ";
    return sum % 8;
}


int Player::Move()
{
    pawn p(1);
    horse h(1);
    bishop b(1);
    rook r(1);
    queen q(1);
    king k(1);
    int qw = a;
    for(;;){
    xFinal      = hsh(qw);
    qw++;
    yFinal      = hsh(qw);
    qw++;
    ChoosePiece = hsh(qw);
    qw++;
    if(inv != 0)
        return -1;
    else inv = 0;
    if(ChoosePiece == 0)
    {
        k.find(xFinal, yFinal);
        cInvalid;
        if(board[xFinal][yFinal] != 0)
            k.kill();
        else
            k.move();
        reset_invalid;
    }
    else if(ChoosePiece == 1)
    {
        h.find(xFinal, yFinal);
        cInvalid;
        if(board[xFinal][yFinal] != 0)
            h.kill();
        else
            h.move();
        reset_invalid;
    }
    else if(ChoosePiece == 2)
    {
        b.find(xFinal, yFinal);
        cInvalid;
        if(board[xFinal][yFinal] != 0)
            b.kill();
        else
            b.move();
        reset_invalid;
    }
    else if(ChoosePiece == 3)
    {
        r.find(xFinal, yFinal);
        cInvalid;
        if(board[xFinal][yFinal] != 0)
            r.kill();
        else
            r.move();
        reset_invalid;
    }
    else if(ChoosePiece == 4)
    {
        q.find(xFinal, yFinal);
        cInvalid;
        if(board[xFinal][yFinal] != 0)
            q.kill();
        else
            q.move();
        reset_invalid;
    }
    else
    {
        p.findp(xFinal,yFinal,board);
        cInvalid;
        if(board[xFinal][yFinal] != 0)
            p.kill(yFinal, board);
        else
            p.movep(board);
        reset_invalid;
    }
    a = a/1000;
    }
}
#endif // RANDOMGENERATOR_H_INCLUDED
