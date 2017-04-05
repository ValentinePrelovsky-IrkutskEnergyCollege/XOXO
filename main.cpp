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
int r[10]; int u[10];// robot and user
string stat = "";bool g = false;bool d = false;
int ok = 0;
char answer  = '\0';  int a = 0;const int O = 2;const int X = 1;
void cls(){system("cls");}
void stepMinFree();
void checkEmpties();

void step(int position)
 {
     if (f[position] != 0)
     {
         cout << "Wrong trying to set "  << position;
         g = false;
         stepMinFree();
     }
     else
     {
         g = true;

         f[position] = 1;
         r[position] = 1;
     }
 }

void printField()
{
    // system("cls");
    cout << endl;
    for (int i = 1; i <= 9; i++)
    {
        cout << "f[" << i << "] = " << f[i]<< "\t";
        if (i % 3 == 0) cout << endl;
    }
    cout << endl;
}
 void stepMinFree()
 {
    for (int i = 1; i < 10; i++)
    {
        if (f[i] == 0)
        {
            step(i);
            return;
        }
    }
    if (d)cout << " no place to step";
 }
 void user(int position)
 {
     if (f[position] != 0)
     {
         cout << "Wrong trying to set "  << position;
     }
     else
     {
        f[position] = 2;
        u[position] = 2;
     }
 }

void initField()
{
    for (int i = 0; i < 10; i++)
    {
        f[i] = 0;           fr[i] = 1;          r[i] = 0; u[i] = 0;
    }
}
int scan_position(int pos) {return f[pos];}

void scan_S1()
{
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
    if (scan_position(5) == O) {  f[5] = 2;u[5] =  1; r[5] = 0;}
    if (scan_position(5) == X) {  f[5] = 1; u[5] = 0; r[5] = 1; }
}
void scanField()
{
    scan_S1();    scan_S2();    scan_S3();
    checkEmpties();
}
bool isEmpty(int index)
{
    bool res = false;
    if ((f[index] != 1) && (f[index] != 2) && (f[index] == 0) )res = true;
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
void robot_looses() {cout << endl << "robot looses" << endl;}
void robot_wins(){cout << endl << "robot wins " << endl;stat="robot wins";}

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

bool isRobotWon()
{
    // is three in any direction
    if
    (
       (intR(1)==3)||(intL(1)==3) ||
       (colRobotFill(1)==3) || (colRobotFill(2)==3) ||
       (colRobotFill(3)==3) ||
       (robotFill(1)==3) || (robotFill(2)==3) || (robotFill(3)==3)
    )robot_wins();
    if (d)
    {
    cout << endl << " JOUR " << endl;
    cout << (intR(1)==3) << "\t";  cout << (intL(1)==3) <<"\t";
    cout<< (colRobotFill(1)==3) << "\t"; cout << (colRobotFill(2)==3) << "\t";cout<< (colRobotFill(3)==3) << "\t";
    cout<< (robotFill(1)==3) <<"\t";cout<< (robotFill(2)==3) <<"\t";cout <<(robotFill(3)==3)<<endl;
    cout << "end JOUR" << endl<<endl;
    }
    return (
       (intR(1)==3)||(intL(1)==3) ||
       (colRobotFill(1)==3) || (colRobotFill(2)==3) ||
       (colRobotFill(3)==3) ||
       (robotFill(1)==3) || (robotFill(2)==3) || (robotFill(3)==3)
    );
}
void engage()
{
    if (d){cout << "\n engaged" << endl;}

    if (intR(1) == 2)
    {
        if (isEmpty(1)){step(1);return;}
        if (isEmpty(5)){step(5);return;}
        if (isEmpty(9)){step(9);return;}
    }
    else if (intL(1)==2)
    {
        if (isEmpty(3)){step(3);return;}
        if (isEmpty(5)){step(5);return;}
        if (isEmpty(7)){step(7);return;}
    }
    if (userFill(3)==0 && isEmpty(7)){step(7);return;}
    else if (userFill(3)==1)
    {
       if(d) cout << "user fill 3 \n";//789
    }
    if (userFill(1)==1)
    {
        if(d)cout << "user fill 1 \n";
    }
    else if (userFill(2)==0 &&(( userFill(2)==1)||(userFill(3)==1)) )
    {
                 if (isEmpty(4)){step(4);return;}
        else if (isEmpty(6)){step(6);return;}
    }
    else if (userFill(1)== 2)
    {
        if (d)cout << "2 at 1 line\n";

                 if (f[1]==0){step(1);return;}
        else if (f[2]==0){step(2);return;}
        else if (f[3]==0){step(3);return;}
    }
    else if (userFill(2) == 2)
    {
        if (d) cout << "2 at 2 line\n";
                 if (isEmpty(4)){step(4);return;}
        else if (isEmpty(5)){step(5);return;}
        else if (isEmpty(6)){step(6);return;}
    }
    else if (userFill(3)==2)
    {
         if (d)cout << "2 at 3 line\n";
                 if (f[7] == 0){step(7);return;}
        else if (f[8] == 0){step(8);return;}
        else if (f[9] == 0){step(9);return;}
    } // 3

    if (colRobotFill(1)==2)
    {
                 if (isEmpty(1)){step(1);return;}
        else if (isEmpty(4)){step(4);return;}
        else if (isEmpty(7)){step(7);return;}
    }
    else if (colRobotFill(2)==2)
    {
                 if (isEmpty(2)){step(2);return;}
        else if (isEmpty(5)){step(5);return;}
        else if (isEmpty(8)){step(8);return;}
    }
    else if (colRobotFill(3)==2)
    {
                 if (isEmpty(3)){step(3);return;}
        else if (isEmpty(6)){step(6);return;}
        else if (isEmpty(9)){step(9);return;}
    }
}
void mySteps()
{
    // columns
    if (colUserFill(1)==2)
    {
        if(d)cout << " col 1 is 2 elem \n";
        if (isEmpty(1))
        {
            step(1);// 23
            return;
        }
        else if (isEmpty(4))
        {
            step(4);
            return;
        }
        else if (isEmpty(7))
        {
            step(7);
            return;
        }
    }
    if (colUserFill(2)==2)
    {
        if(d)cout << " col 2 is 2 elem \n";
        if (isEmpty(2))
        {
            step(2);// 23
            return;
        }
        else if (isEmpty(5))
        {
            step(5);
            return;
        }
        else if (isEmpty(8))
        {
            step(8);
            return;
        }
    }
    if (colUserFill(3)==2)
    {
        if(d)cout << " col 3 is 2 elem \n";
        if (isEmpty(3))
        {
            step(3);// 23
            return;
        }
        else if (isEmpty(6))
        {
            step(5);
            return;
        }
        else if (isEmpty(9))
        {
            step(9);
            return;
        }
    }  // 3

    //diagonals
    if (intR(2)==2)
    {
        if (d) cout << "diagon right is 2\n;";
        if (isEmpty(1) == 2)
        {
            step(1);
            return;
        }
        else if (isEmpty(5) == 2)
        {
            step(5);
            return;
        }
        else if (isEmpty(9) == 2)
        {
            step(9);
            return;
        }
    }
    if (intL(2) == 2)
    {
        if (d) cout << "diagon left is 2\n;";
        if (isEmpty(3) == 2)
        {
            step(3);
            return;
        }
        else if (isEmpty(5) == 2)
        {
            step(5);
            return;
        }
        else if (isEmpty(7) == 2)
        {
            step(7);
            return;
        }
    }     // intL(2)==2
    cout << "end of my steps \n";
    engage();
}   // end mySteps
void analyze()
{
    mySteps();
    isRobotWon();
}


void checkEmpties()
{
    for (int i = 1; i< 10;i++)
    {
        if (f[i] == 0)  ok++;
    }
    if (ok==0)
    {
        stat = "end";
        cout << endl << "Game DRAW";
        if (!d)
        {
            getchar();getchar();
        }
        exit(2);
    }
    ok =0;
}
void firstSteps()
{
    step(5);
    printField();

    cout << "Your turn: " ;cin >> a; user((int)a) ;
    if (isEmpty(7))
    {
        step(7);
    }
    else if (isEmpty(3))
    {
        step(3);
    }
}
int main()
{
    initField();
    firstSteps();
    printField();

   for (int i = 0 ; (i < 6) ||(stat == "end"); i++)
   {
        if (!d)cls();
        printField();
        scanField();

        cout << "Your turn: " ;cin >> a; user((int)a) ;

        scanField();
        analyze();

       printField();

        if (stat == "robot wins")     break;
   }  // end for

    if (!d)
    {
        getchar();
        getchar();
    }
    return 0;
}
