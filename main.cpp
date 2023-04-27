#include <iostream>
#include <fstream>
#include <TXLib.h>


using namespace std;


int main()
{
    string ask;
    string str;
    int pos1;
    string part1;
    int pos2;
    string part2;
    int pos5;
    string part5;
    int pos4;
    string part4;
    int pos3;
    string part3;
    int i = 0;
    int a;

    int point = 0;
    int point_no = 0;

    char str1[100];

    HDC fon1[10];
    fon1[0] = txLoadImage ("1.bmp");
    fon1[1] = txLoadImage ("2.bmp");
    fon1[2] = txLoadImage ("3.bmp");
    fon1[3] = txLoadImage ("4.bmp");
    fon1[4] = txLoadImage ("5.bmp");
    fon1[5] = txLoadImage ("6.bmp");
    fon1[6] = txLoadImage ("7.bmp");
    fon1[7] = txLoadImage ("8.bmp");
    fon1[8] = txLoadImage ("9.bmp");
    fon1[9] = txLoadImage ("10.bmp");
    HDC fon = txLoadImage("fon.bmp");
    HDC knop = txLoadImage("knop.bmp");
    HDC fon2 = txLoadImage("fon2.bmp");

    int y = 247;
    int n = 1;

    txCreateWindow(800, 600);

    std::ifstream in("test.txt"); // окрываем файл для чтения
    while (in.good())
    {
        getline(in, str);
        txBitBlt (txDC(), 0, 0, 800, 600, fon1[i]);
        i+=1;
        if(i == 10)
        {
            i = 0;
        }
        txTransparentBlt (txDC(), 0, 0, 800, 600, fon, 0, 0, TX_WHITE);

        pos1 = str.find(",", 0);
        part1 = str.substr(0, pos1);
        pos2 = str.find(",", pos1+1);
        part2 = str.substr(pos1+1, pos2-(pos1+1));
        pos3 = str.find(",", pos2+1);
        part3= str.substr(pos2+1, pos3-(pos2+1));
        pos4 = str.find(",", pos3+1);
        part4 = str.substr(pos3+1, pos4-(pos3+1));



        txSetColor(TX_BLACK);
        txSelectFont("Times New Roman", 25);
        txDrawText(7, 40, 787, 173, part1.c_str());
        txDrawText(178, y, 567, y + 45, part2.c_str());
        txDrawText(178, y + 76, 567, y + 130, part3.c_str());
        txDrawText(178, y + 163, 567, y + 213, part4.c_str());

        a = 0;

        pos5 = str.find(",", pos4+1);
        part5 = str.substr(pos4+1, pos5-(pos4+1));

        while(a != 1)

        {
            if(txMouseX() > 178 and txMouseX() < 567 and txMouseY() > y and txMouseY() < y + 45 and txMouseButtons() == 1)
            {
                ask = "a";
                a = 1;
            }
            if(txMouseX() > 178 and txMouseX() < 567 and txMouseY() > y + 76 and txMouseY() < y + 130 and txMouseButtons() == 1)
            {
                ask = "b";
                a = 1;
            }
            if(txMouseX() > 178 and txMouseX() < 567 and txMouseY() > y + 163 and txMouseY() < y + 213 and txMouseButtons() == 1)
            {
                ask = "c";
                a = 1;
            }
        }
        txSleep(200);
        if(ask == part5)
        {
            txPlaySound("win.wav");
            point++;
        }
        else
        {
            point_no++;
        }



    }
    in.close();
    txBitBlt (txDC(), 0, 0, 800, 600, fon1[0]);
    txTransparentBlt (txDC(), 0, 0, 800, 600, fon2, 0, 0, TX_WHITE);
    txDrawText(7, 40, 787, 173, "Поздравляю за успешное прохождения теста! \n" "Ваши результаты:");
    sprintf(str1, "Правильных очков: %d", point);
    txDrawText(26, 275, 414, 324, str1);
    sprintf(str1, "Неправильных очков: %d", point_no);
    txDrawText(26, 383, 414, 429, str1);
    txSleep(2500);


    return 0;
}
