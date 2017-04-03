#include <iostream>
 #include <stdio.h>


#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

using namespace std;
int f[10];     // field
int fr[10];   // free elements
int r[10]; // robot made
int u[10];
string stat = "";

char answer  = '\0';  int a = 0;const int O = 2;const int X = 1;const int Z = 0;

void cls(){system("cls");}
void printField()
{
    // system("cls");
    cout << stat;
    cout << endl;
    for (int i = 1; i <= 9; i++)
    {
        cout << "f[" << i << "] = " << f[i]<< "\t";
        if (i % 3 == 0) cout << endl;
    }
    cout << endl;
}
 void step(int position)
 {
     if (f[position] != 0)
     {
         cout << "! LOL ! try to set "  << position;
     }
     f[position] = 1;
     r[position] = 1;
 }
 void user(int position)
 {
     f[position] = 2;
     u[position] = 2;
 }

void initField()
{
    for (int i = 0; i < 10; i++)
    {
        f[i] = 0;           fr[i] = 1;
        r[i] = 0; u[i] = 0;
    }
}
void turn_table(int angle)
{
    cout << "table turned to " << angle << " deg " << endl;
}
int scan_position(int pos)
{
    return f[pos];
}
void printFree()
{
    cout << endl << "free elements: " << endl;
    for (int i =1 ; i < 10 ; i++)
    {
        cout << " " << fr[i];
        if (i % 3 == 0) cout << endl;
    }
    cout << endl;
}
void printUser()
{
     cout << endl << "user elements: " << endl;
    for (int i =1 ; i < 10 ; i++)
    {
        cout << " " << u[i];
        if (i % 3 == 0) cout << endl;
    }
    cout << endl;
}
void printRobot()
{
 cout << endl << "robot elements: " << endl;
    for (int i =1 ; i < 10 ; i++)
    {
        cout << " " << r[i];
        if (i % 3 == 0) cout << endl;
    }
    cout << endl;
}

void scan_S1()
{
     // cls();
    // user
    if (scan_position(2) == O) {  f[2] = 2; u[2] = 1; r[2] = 0;}
    if (scan_position(4) == O) {  f[4] = 2; u[4] = 1; r[4] = 0;}
    if (scan_position(8) == O) {  f[8] = 2; u[8] = 1; r[8] = 0;}
    if (scan_position(6) == O) {  f[6] = 2; u[6] = 1; r[6] = 0;}
    // robot
    if (scan_position(2) == X) {  f[2] = 1; u[2] = 0; r[2] = 1;}
    if (scan_position(4) == X) {  f[4] = 1; u[4] = 0; r[4] = 1;}
    if (scan_position(8) == X) {  f[8] = 1; u[8] = 0; r[8] = 1;}
    if (scan_position(6) == X) {  f[6] = 1; u[6] = 0; r[6] = 1;}
}
void scan_S2()
{
      //cls();
    // user
    if (scan_position(1) == O) {  f[1] = 2; u[1] = 1; r[1] = 0;}
    if (scan_position(7) == O) {  f[7] = 2; u[7] = 1; r[7] = 0;}
    if (scan_position(9) == O) {  f[9] = 2; u[9] = 1; r[9] = 0;}
    if (scan_position(3) == O) {  f[3] = 2; u[3] = 1; r[3] = 0;}

    if (scan_position(1) == X) {  f[1] = 1; u[1] = 0; r[1] = 1;}
    if (scan_position(7) == X) {  f[7] = 1; u[7] = 0; r[7] = 1;}
    if (scan_position(9) == X) {  f[9] = 1; u[9] = 0; r[9] = 1;}
    if (scan_position(3) == X) {  f[3] = 1; u[3] = 0; r[3] = 1;}
}
void scan_S3()
{
      //cls();
    // if 2 is user then f[2] = 2 // busy
    if (scan_position(5) == O) {  f[5] = 2;u[5] =  1; r[5] = 0;}
    if (scan_position(5) == X) {  f[5] = 1; u[5] = 0; r[5] = 1; }
}
void scanField()
{
    scan_S1();
    scan_S2();
    scan_S3();
}
bool isEmpty(int index)
{
    bool res = false;
    if (f[index] != 1 && f[index] != 2) res = true;
    return   res;
}
int rowFill(int index)
{
    int r = 0;
    if (isEmpty(index*3) ) r++;
    if (isEmpty((index*3)-1) ) r++;
    if (isEmpty((index*3)-2) ) r++;

    return r;
}
int userFill(int index)
{
    int r = 0;
    if (f[(index*3)]==2 ) r++;
    if (f[((index*3)-1)] == 2 ) r++;
    if (f[((index*3)-2)] == 2 ) r++;

    return r;
}
int robotFill(int index)
{
    int r = 0;
    if (f[(index*3)]== 1 ) r++;
    if (f[((index*3)-1)] == 1 ) r++;
    if (f[((index*3)-2)] == 1 ) r++;

    return r;
}
void robot_looses() {cout << endl << "robot looses" << endl;}void robot_wins(){cout << endl << "robot wins " << endl;stat="robot wins";}

int intersect(int index, int value)
{
    //const int value = 2;
    int r = 0,res = 0;
    cout << endl;

    // count in desired column
    r = index % 3;  if (r == 0)  {    r = (index / 3);}  // define what colums: 1,2 or 3

    if (scan_position(r + 0) == value) res++;   // 1 2 3
    if (scan_position(r + 3) == value) res++;   // 4 5 6
    if (scan_position(r + 6) == value) res++;   // 7 8 9

    // count in the desired row
    if (index % 3 != 0) r = (index / 3 + 1);
    else {r = index/3; }

    if (scan_position(3 * r - 2) == value)res++;
    if (scan_position(3 * r - 1) == value)res++;
    if (scan_position(3 * r - 0) == value)res++;

    return res-1;
}

bool call(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9)
{
    bool res = false;
    bool d = false;
    if  (f[1] == p1)
    {
        if (d)cout << "1T" << "\n";
        if (f[2]== p2)
        {
            if (d)cout << "2T" << "\n";
            if (f[3]== p3)
            {
                if (d)cout << "T3" << "\n";
                if (f[4] == p4)
                {
                    if (d)cout << "T4" << "\n";
                    if (f[5] == p5)
                    {
                        if (d)cout << "T5" << "\n";
                        if (f[6] == p6)
                        {
                            if (d)cout << "T6" << "\n";
                            if (f[7] == p7)
                            {
                                if (d)cout << "T7" << "\n";
                                if (f[8] == p8)
                                {
                                    if (d)cout << "T8" << "\n";
                                    if (f[9] == p9)
                                    {
                                        if (d)cout << "T9" << "\n";
                                        res = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }
    }
    return res;
}
int intL(int u)
{
    int r = 0;

    if (f[3] == u)++r;    if (f[5] == u)++r;    if (f[7] == u)++r;

    return r;
}
int intR(int u)
{
    int r = 0;

    if (f[1] == u)++r;    if (f[5] == u)++r;    if (f[9] == u)++r;

    return r;
}

int columnFill(int n,int u)
{
    int r = 0;

    if (f[n + 0] == u)r++;
    if (f[n + 3] == u)r++;
    if (f[n + 6] == u)r++;

    return r;
}
int colRobotFill(int n) { return columnFill(n,1);}
int colUserFill(int n){return columnFill(n, 2);}

void mySteps()
{
    bool d = true;
    if (userFill(1)== 2)
    {
        if (d)cout << "2 at 1 line\n";
        if (isEmpty(1))
        {
            step(1);// 23
        }
        else if (isEmpty(2))
        {
            step(2);
        }
        else if (isEmpty(3))
        {
            step(3);
        }
    }
    if (userFill(2) == 2)
    {
        if (d) cout << "2 at 2 line\n";
        if (isEmpty(4))
        {
            step(4);// 23
        }
        else if (isEmpty(5))
        {
            step(5);
        }
        else if (isEmpty(6))
        {
            step(6);
        }
    }
    if (userFill(3)==2)
    {
         if (d)cout << "2 at 3 line\n";
         if (isEmpty(7))
        {
            step(7);// 23
        }
        else if (isEmpty(8))
        {
            step(8);
        }
        else if (isEmpty(9))
        {
            step(9);
        }
    } // 3

    // columns
    if (colUserFill(1)==2)
    {
        if(d)cout << " col 1 is 2 elem \n";
        if (isEmpty(1))
        {
            step(1);// 23
        }
        else if (isEmpty(4))
        {
            step(4);
        }
        else if (isEmpty(7))
        {
            step(7);
        }
    }
    if (colUserFill(2)==2)
    {
        if(d)cout << " col 2 is 2 elem \n";
        if (isEmpty(2))
        {
            step(2);// 23
        }
        else if (isEmpty(5))
        {
            step(5);
        }
        else if (isEmpty(8))
        {
            step(8);
        }
    }
    if (colUserFill(3)==2)
    {
        if(d)cout << " col 3 is 2 elem \n";
        if (isEmpty(3))
        {
            step(3);// 23
        }
        else if (isEmpty(6))
        {
            step(5);
        }
        else if (isEmpty(9))
        {
            step(9);
        }
    }  // 3

    //diagonals
    if (intR(2)==2)
    {
        if (d) cout << "diagon right is 2\n;"
    }
    if (intL(2) == 2)
    {
        if (d) cout << "diagon left is 2\n;"
    }
}
void analyze()
{
    if (call (0,0,0,0,1,0,0,0,0) )
    {
        step(1);
    }
    if (call (2,0,0,0,1,0,0,0,0) )
    {
        step(3);
    }
if (call (0,2,0,0,1,0,0,0,0) )
    {
        step(7);
    }

    if (call(
        2,0,1,
        0,1,0,
        2,0,0
    ))
    {
        step(4);
    }

    if (call(
        2,0,1,
        2,1,0,
        0,0,0
    ))
    {
        step(7);
        robot_wins();
    }


    mySteps();
}

int main()
{
    initField();
    step(5);

    scanField();

   for (int i = 0 ; (i < 7) || (stat == "robot wins"); i++)
   {
    // cls();
    printField();

    cout << "Your turn: " ;cin >> a; user((int)a) ;
    scanField();
    analyze();
    printField();

    if (stat == "robot wins")
    break;
   }

    return 0;
}
