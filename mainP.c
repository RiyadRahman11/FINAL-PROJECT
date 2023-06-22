#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "timeMan.h"
#define ENTER 13
#define UP 72
#define DOWN 80
#define SPACE 32
struct STD
{
    char name[100];
    char mail[100];
    char matID[100];
    int pass;
    char course[100];
};

struct COM
{
    char matName[100];
    char matR[100];
};
struct COM h[100];
struct STD a[100];
struct STD b[100];
struct STD ad[100];

int n, m, an, nz;
struct chatST
{
    char user[100];
    char ID[100];
    char myDate[200];
    char text[500];
    long long int Dur;
    char course[100];
};
int i, j, ct, nt;
struct chatST C[100], N[100];
void ENtoN(char *A)
{
    int n = strlen(A);

    for (int i = 0; i < n; i++)
    {
        if (A[i] == '\n')
        {
            A[i] = ' ';
        }
    }
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void undS(char A[])
{
    int i, n = strlen(A);
    for (i = 0; i < n; i++)
    {
        if (A[i] == SPACE)
            A[i] = '_';
    }
}
void spS(char A[])
{
    int i, n = strlen(A);
    for (i = 0; i < n; i++)
    {
        if (A[i] == '_')
            A[i] = SPACE;
    }
}
void chatC21read()
{
    FILE *fp = fopen("chatC21.txt", "r");
    fscanf(fp, "%d", &ct);
    for (i = 0; i < ct; i++)
        fscanf(fp, "%s%s%s%s%lld", C[i].user, C[i].ID, C[i].myDate, C[i].text, &C[i].Dur);
    fclose(fp);
}
void Ntcread()
{
    FILE *fp = fopen("notice.txt", "r");
    fscanf(fp, "%d", &nt);
    for (i = 0; i < nt; i++)
        fscanf(fp, "%s%s%s%s%lld", N[i].user, N[i].ID, N[i].myDate, N[i].text, &N[i].Dur);
    fclose(fp);
}
void chatC21write()
{
    FILE *fp = fopen("chatC21.txt", "w");
    fprintf(fp, "%d\n", ct);
    for (i = 0; i < ct; i++)
        fprintf(fp, "%s\n%s\n%s\n%s\n%lld\n", C[i].user, C[i].ID, C[i].myDate, C[i].text, C[i].Dur);
    fclose(fp);
}
void Ntcwrite()
{
    FILE *fp = fopen("notice.txt", "w");
    fprintf(fp, "%d\n", nt);
    for (i = 0; i < nt; i++)
        fprintf(fp, "%s\n%s\n%s\n%s\n%lld\n", N[i].user, N[i].ID, N[i].myDate, N[i].text, N[i].Dur);
    fclose(fp);
}
void stu_type(struct STD *Z, int y, int c)
{

    chatC21read();
    struct chatST tmp;
    for (i = 0; i < ct; i++)
    {
        for (j = i + 1; j < ct; j++)
        {
            if (C[i].Dur > C[j].Dur)
            {
                tmp = C[i];
                C[i] = C[j];
                C[j] = tmp;
            }
        }
    }
    chatC21write();

    for (i = 0; i < ct; i++)
    {
        spS(C[i].text);
        printf("\t\t\t\t\t\t%s [%s]\n", C[i].user, C[i].ID);
        printf("\t\t\t\t\t\t%s\n", C[i].myDate);

        printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t%s\n\n", C[i].text);
        printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    }
    chatC21read();
    struct chatST XY;

    strcpy(XY.user, Z[y].name);
    strcpy(XY.ID, Z[y].matID);
    printf("\t\t\t\t\t\t%s (%s)\n", XY.user, XY.ID);
    printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    char Date[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(Date, "%02d/%02d/%d(%02d:%02d)", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

    printf("\t\t\t\t\t\t%s\n", Date);
    printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t");
    // scanf("%*c");
    // gets(XY.text);
    scanf(" %[^\n]", XY.text);
    //  scanf("%[^\\n]", XY.text);
    //  ENtoN(XY.text);
    undS(XY.text);
    strcpy(XY.myDate, Date);

    XY.Dur = duR();
    // XY.Dur=235;

    printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t");
    chatC21read();
    C[ct] = XY;
    ct++;
    chatC21write();
    printf("\n\n\n\t\t\t\t\tPress ENTER to return");
    getch();
}

// Notice Section
void Ntc_type(struct STD *Z, int p, int c)
{

    Ntcread();
    struct chatST tmp;
    for (i = 0; i < nt; i++)
    {
        for (j = i + 1; j < nt; j++)
        {
            if (N[i].Dur > N[j].Dur)
            {
                tmp = N[i];
                N[i] = N[j];
                N[j] = tmp;
            }
        }
    }
    Ntcwrite();
    // Ntcread();
    for (i = 0; i < nt; i++)
    {
        spS(N[i].text);
        printf("\t\t\t\t\t\t%s [%s]\n", N[i].user, N[i].ID);
        printf("\t\t\t\t\t\t%s\n", N[i].myDate);

        printf("\t\t\t\t\t\t---------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t%s\n\n", N[i].text);
        printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    }
    // printf("\t\t\t\t\t\t");
    Ntcread();
    struct chatST XY;

    strcpy(XY.user, Z[p].name);
    strcpy(XY.ID, Z[p].matID);
    printf("\t\t\t\t\t\t%s (%s)\n", XY.user, XY.ID);
    printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    char Date[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(Date, "%02d/%02d/%d(%02d:%02d)", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

    printf("\t\t\t\t\t\t%s\n", Date);
    printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t");
    // gets(XY.text);
    scanf(" %[^\n]", XY.text);
    // scanf("%*c");
    // gets(XY.text);
    //   ENtoN(XY.text);
    undS(XY.text);
    strcpy(XY.myDate, Date);

    XY.Dur = duR();

    printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t");
    Ntcread();
    N[nt] = XY;
    nt++;
    Ntcwrite();
    printf("\n\n\n\t\t\t\t\tPress ENTER to return");
    getch();
}
int showNTC(int p)
{
    printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t%50s\n", "Noticeboard");
    printf("\t\t\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t%45s\n", "Department of CSE");
    printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    Ntcread();
    struct chatST tmp;
    for (i = 0; i < nt; i++)
    {
        for (j = i + 1; j < nt; j++)
        {
            if (N[i].Dur > N[j].Dur)
            {
                tmp = N[i];
                N[i] = N[j];
                N[j] = tmp;
            }
        }
    }
    Ntcwrite();
    Ntcread();

    for (i = 0; i < nt; i++)
    {
        spS(N[i].text);
        printf("\t\t\t\t\t\t%s (%s)\n", N[i].user, N[i].ID);
        printf("\t\t\t\t\t\t%s\n", N[i].myDate);

        printf("\t\t\t\t\t\t---------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t%s\n\n", N[i].text);
        printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    }
    printf("\t\t\t\t\t\t");
    getch();
}
int AdminM(int);
int AdmMenu(int);
int ManStu(int);
int ManTeach(int);
int ManCrs(int);
void Sread();
void Tread();
void Adread();
void Swrite();
void Twrite();
void Colour(int a);

void fillS(char A[]);
void arrowF(int Rpos, int arrowP);
int REGISTRATION();

void UsName(struct STD *, int, void(read()), int);

void UsEmail(struct STD *, int, void(read()), int);

void UsID(struct STD *, int, void(read()), int);
void pass(struct STD *, int, int a, void(read()), int);
void studenT(int);

void teacheR(int);

void admiN(int);
int ManStu(int);
int ManTeach(int);
int ManCrs(int);
int ManStu(int);
int ManStuMenu(int);
int AddStu(int);
int RemStu(int);
int ShowStu(int);
int ManTeachMenu(int);
int AddTeach(int);
int RemTeach(int);
int ShowTeach(int);

int StudentM();
int stuMenu(int);
int StuProfile(int);
int chatLogMenu(int);
int chaTlog(int);
int chat_CSE21(struct STD *Z, int, int);
int chat_EEE21(int);
int chat_MATH07(int);
int NoticeB(struct STD *Z, int, int);

int TeacherM(int);
int teaMenu(int);
int TeaProfile(int);

int chaTlog(int);
int chatTea(int);
int courseML(int);
int Cm_CSE21(int);
int Cm_EEE21(int);
int Cm_MATH07(int);

int ShowCM(int p);
int inputCM(int p);
int cseCMread();
int cseCMwrite();
int courseMenu(int p);
int courseMat(int p);

int WELCOME();
int About();
int Credits();
int menuX, menuY;
int main()
{
    ////

     int i,t=10,a=1;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_BLUE );

    for(i=0; i<=6; i++)
    {

        gotoxy(50,7+i);
        printf("|");
        Sleep(t);
    }
    ///A
    for(i=0; i<=6; i++)
    {
        gotoxy(58-i,7+i);
        printf("A");
        Sleep(t);
    }
    for(i=0; i<=6; i++)
    {
        gotoxy(58+i,7+i);
        printf("A");
        Sleep(t);
    }
        for(i=0; i<=4; i++)
    {
        gotoxy(56+i,10);
        printf("A");
        Sleep(t);
    }

    ///M
    for(i=0; i<=6; i++)
    {
        gotoxy(67,7+i);
        printf("M");
        Sleep(t);
    }
    for(i=0; i<5; i++)
    {
        gotoxy(68+i,7+i);
        printf("M");
        Sleep(t);
    }

    for(i=0; i<=4; i++)
    {
        gotoxy(72+i,11-i);
        printf("M");
        Sleep(t);
    }

    for(i=0; i<=6; i++)
    {
        gotoxy(77,7+i);
        printf("M");
        Sleep(t);

    }

    ///S

    for(i=0; i<5; i++)
    {
        gotoxy(80+i,7);
        printf("S");
        Sleep(t);
    }
    for(i=0; i<=2; i++)
    {
        gotoxy(80,7+i);
        printf("S");
        Sleep(t);
    }
    for(i=0; i<5; i++)
    {
        gotoxy(80+i,10);
        printf("S");
        Sleep(t);
    }
    for(i=0; i<=3; i++)
    {
        gotoxy(84,10+i);
        printf("S");
        Sleep(t);
    }
    for(i=0; i<5; i++)
    {
        gotoxy(84-i,13);
        printf("S");
        // getch();
        //SetConsoleTextAttribute(hConsole,256);
        Sleep(t);
    }
    gotoxy(62,13);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    fflush(stdout);

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN );


    gotoxy(43,16);
    printf("WELCOME!TO INTEGRATED ACADEMIC MANAGEMENT SYSTEM");
//printf("400");
    gotoxy(43,20);
    printf("\t\t>>>ENTER");
    getch();



    ////

    int y;
    do
    {
        y = WELCOME();
        if (y == 1)
        {
            About();
        }
        else if (y == 2)
        {
            studenT(1);

        }
        else if (y == 3)
        {
             teacheR(2);
        }
         else if (y == 4)
        {
            admiN(3);
        }
         else if (y == 5)
        {
            Credits();
        }

    } while (y != 6);

    return 0;
}

void Colour(int a)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, a);
}
void fillS(char A[])
{
    int i;
    for (i = 0; A[i]; i++)
    {

        Colour(i);
        printf("%c");
        Sleep(200);
    }
}
void arrowF(int Rpos, int arrowP)
{

    if (Rpos == arrowP)
    {
        Colour(10);
        printf(">>>");
    }

    else
        printf("   ");
}
int WELCOME()
{
    int windowHeight = 45;
    int windowWidth = 160;
    menuX = windowWidth / 2 - 7;    //  horizontal
    menuY = (windowHeight - 5) / 3; //  vertical

    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*******");
        Colour(5);
        printf("        ");
        // Colour(12);
        printf("******");
        gotoxy(68, 10);
        printf("****** ");
        printf("  HOME ");
        printf(" *****");

        gotoxy(68, 11);
        printf("******");
               printf("         ");
        printf("******");

         gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);
        printf("About");

        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("Student");

        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);
        printf("Teacher");

        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("Admin");

        gotoxy(menuX, menuY + 10);
        Colour(3);
        arrowF(5, pos);
        printf("Credits");

         gotoxy(menuX, menuY + 12);
        Colour(3);
        arrowF(6, pos);
        printf("Exit");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 6)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 6;
            else
                pos--;
        }
    }

    // system("clear");

    return pos;
    Colour(12);
}
int About()
{
    Colour(7);
    system("cls");

char A[10000];
    FILE *fp = fopen("About.txt", "r");


        fscanf(fp, " %[^\\]", A);
    fclose(fp);
    printf("\n\n%s",A);

    printf("\n\n\t\t\t\t Press ENTER to return");
    getch();
}

int Credits()
{
 system("cls");

        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("   CREDITS ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        // system("cls");
        gotoxy(68,13);
        Colour(3);
        printf("Developed by:");

        Colour(9);
        gotoxy(68,16);
        printf("Name:Jillur Rahman Riyad");
        gotoxy(68,17);
        printf("ID:C231019");
        gotoxy(68,18);
        printf("1AM(Spring-23)");
         gotoxy(68,19);
        printf("Department of CSE,IIUC)");

         Colour(7);
        gotoxy(68,21);
        printf("Name:Aftakil Hossain Fahim");
        gotoxy(68,22);
        printf("ID:C231034");
        gotoxy(68,23);
        printf("1AM(Spring-23)");
         gotoxy(68,24);
        printf("Department of CSE,IIUC)");

         Colour(5);
        gotoxy(68,26);
        printf("Name:Mainul Islam Mahim");
        gotoxy(68,27);
        printf("ID:C231036");
        gotoxy(68,28);
        printf("1AM(Spring-23)");
         gotoxy(68,29);
        printf("Department of CSE,IIUC)");

         Colour(6);
        gotoxy(68,31);
        printf("Name:Shahrabi Tuhin");
        gotoxy(68,32);
        printf("ID:C231035");
        gotoxy(68,33);
        printf("1AM(Spring-23)");
         gotoxy(68,34);
        printf("Department of CSE,IIUC)");

gotoxy(68,37);
 printf("Press ENTER to return");
    getch();


}
int REGISTRATION(int x)
{
    system("cls");
    // printf("\n\t\t\t------Sign in--------\n");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("   Sign-in ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        // system("cls");
        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);
        printf("1. By Username");
        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("2. By Email");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);
        printf("3. By Matrix ID");
        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("4. Back");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 4)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 4;
            else
                pos--;
        }
    }
    if (x == 1)
        Sread();
    else if (x == 2)
        Tread();
    else if (x == 3)
        Adread();
    system("cls");

    return pos;
}

void UsName(struct STD *A, int sz, void(read()), int x)
{
    Colour(5);
    gotoxy(68, 9);

    printf("*********");
    Colour(5);
    printf("         ");
    // Colour(12);
    printf("*********");
    gotoxy(68, 10);
    printf("****** ");
    printf("   Sign-in ");
    printf("   ******");

    gotoxy(68, 11);
    printf("*********");
    printf("         ");
    printf("*********");
    char N[100];
    int p, f = 0;
    gotoxy(68, 14);
    Colour(3);
    printf("Enter your full name:");
    gets(N);
    // fflush(stdin);
    undS(N);
    read();
    for (i = 0; i < sz; i++)
    {
        if (!strcmp(N, A[i].name))
        {
            f = 1;
            pass(A, sz, i, read, x);
            break;
        }
    }
    if (f != 1)
    {
        Colour(4);
        gotoxy(68, 16);
        printf("Name not found!\n\n");
        Colour(3);
        gotoxy(68, 18);
        printf("Press ENTER for Back>>\n");
        gotoxy(68, 19);
        printf("Press any other key for try again>>\n");
        int y = getch();
        if (y != ENTER)
        {
            system("cls");
            UsName(A, sz, read, x);
            getch();
        }
    }
}
void UsEmail(struct STD *A, int sz, void(read()), int x)
{
    char N[100];
    int p, f = 0;
    Colour(5);
    gotoxy(68, 9);

    printf("*********");
    Colour(5);
    printf("         ");
    // Colour(12);
    printf("*********");
    gotoxy(68, 10);
    printf("****** ");
    printf("   Sign-in ");
    printf("   ******");

    gotoxy(68, 11);
    printf("*********");
    printf("         ");
    printf("*********");
    gotoxy(68, 14);
    Colour(3);
    printf("Enter your email:");
    scanf("%s", N);

    read();
    for (i = 0; i < sz; i++)
    {
        if (!strcmp(N, A[i].mail))
        {
            f = 1;
            pass(A, sz, i, read, x);

            break;
        }
    }
    if (f != 1)
    {
        Colour(4);
        gotoxy(68, 16);
        printf("Email not found!\n\n");
        Colour(3);
        gotoxy(68, 18);
        printf("Press ENTER for Back>>\n");
        gotoxy(68, 19);
        printf("Press any other key for try again>>\n");
        int y = getch();
        if (y != ENTER)
        {
            system("cls");
            UsName(A, sz, read, x);
            getch();
        }
    }
}
void UsID(struct STD *A, int sz, void(read()), int x)
{
    Colour(5);
    gotoxy(68, 9);

    printf("*********");
    Colour(5);
    printf("         ");
    // Colour(12);
    printf("*********");
    gotoxy(68, 10);
    printf("****** ");
    printf("   Sign-in ");
    printf("   ******");

    gotoxy(68, 11);
    printf("*********");
    printf("         ");
    printf("*********");
    char N[100];
    int p, f = 0;
    gotoxy(68, 14);
    Colour(3);
    printf("Enter your ID:");
    scanf("%s", N);
    // printf("%s", N);

    read();
    for (i = 0; i < sz; i++)
    {
        if (!strcmp(N, A[i].matID))
        {
            f = 1;
            pass(A, sz, i, read, x);
            break;
        }
    }
    if (f != 1)
    {
        Colour(4);
        gotoxy(68, 16);
        printf("ID not found!\n\n");
        Colour(3);
        gotoxy(68, 18);
        printf("Press ENTER for Back>>\n");
        gotoxy(68, 19);
        printf("Press any other key for try again>>\n");
        int y = getch();
        if (y != ENTER)
        {
            system("cls");
            UsName(A, sz, read, x);
            getch();
        }
    }
}
void pass(struct STD *A, int sz, int b, void(read()), int x)
{

    int PS;
    gotoxy(68, 16);
    Colour(3);
    printf("Enter your pass:");
    scanf("%d", &PS);
    if (A[b].pass == PS)
    {
        gotoxy(68, 18);
        printf("Successfully Entered\n");
        Sleep(400);
        if (x == 3)
            AdmMenu(b);
        else if (x == 1)
            stuMenu(b);
        else if (x == 2)
            teaMenu(b);

        // getch();
    }
    else
    {
        Colour(4);
        gotoxy(68, 20);
        printf("Password didn't matched!\n\n");
        Colour(3);
        gotoxy(68, 22);
        printf("Press ENTER for Back>>\n");
        gotoxy(68, 23);
        printf("Press any other key for another try>>\n");
        int y = getch();
        if (y != ENTER)
        {
            system("cls");
            Colour(5);
            gotoxy(68, 9);

            printf("*********");
            Colour(5);
            printf("         ");
            // Colour(12);
            printf("*********");
            gotoxy(68, 10);
            printf("****** ");
            printf("   Sign-in ");
            printf("   ******");

            gotoxy(68, 11);
            printf("*********");
            printf("         ");
            printf("*********");
            pass(A, sz, b, read, x);
        }
    }
}
void studenT(int z)
{
    int x;
    do
    {
        x = REGISTRATION(z);
        if (x == 1)
        {
            UsName(a, n, Sread, z);
            REGISTRATION(z);
            break;
        }
        else if (x == 2)
        {
            UsEmail(a, n, Sread, z);
            REGISTRATION(z);
            break;
        }
        else if (x == 3)
        {
            UsID(a, n, Sread, z);
            REGISTRATION(z);
            break;
        }

    } while (x != 4);
}

void teacheR(int z)
{
    int x;
    do
    {
        x = REGISTRATION(z);
        if (x == 1)
        {
            UsName(b, m, Tread, z);
            REGISTRATION(z);
            break;
            // break;
        }
        else if (x == 2)
        {
            UsEmail(b, m, Tread, z);
            REGISTRATION(z);
            break;
        }
        else if (x == 3)
        {
            UsID(b, m, Tread, z);
            REGISTRATION(z);
            break;
        }

    } while (x != 4);
}
void admiN(int z)
{
    int x;
    do
    {
        x = REGISTRATION(z);
        if (x == 1)
        {
            UsName(ad, an, Adread, z);
            REGISTRATION(z);
            break;
            // break;
        }
        else if (x == 2)
        {
            UsEmail(ad, an, Adread, z);
            REGISTRATION(z);
            break;
        }
        else if (x == 3)
        {
            UsID(ad, an, Adread, z);
            REGISTRATION(z);
            break;
        }

    } while (x != 4);
}
void Sread()
{
    FILE *fp = fopen("Stu_info.txt", "r");
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fp, "%s%s%s%d", a[i].name, a[i].mail, a[i].matID, &a[i].pass);
    fclose(fp);
}
void Tread()
{
    FILE *fp = fopen("Teach_info.txt", "r");
    fscanf(fp, "%d", &m);
    for (i = 0; i < m; i++)
        fscanf(fp, "%s%s%s%d%s", b[i].name, b[i].mail, b[i].matID, &b[i].pass, b[i].course);
    fclose(fp);
}
void Adread()
{
    FILE *fp = fopen("Adm_info.txt", "r");
    fscanf(fp, "%d", &an);
    for (i = 0; i < an; i++)
        fscanf(fp, "%s%s%s%d", ad[i].name, ad[i].mail, ad[i].matID, &ad[i].pass);
    fclose(fp);
}

int AdmMenu(int p)
{
    int x;
    do
    {
        x = AdminM(p);
        if (x == 1)
        {
            ManStu(p);
        }
        else if (x == 2)
        {
            ManTeach(p);
        }
        else if (x == 3)
        {
            ManCrs(p);
        }
        else if (x == 4)
        {
            NoticeB(ad, p, 3);
        }

    } while (x != 5);
}
int AdminM(int a)
{

    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  Admin-Menu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");
        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);

        printf("Manage Students\n");
        gotoxy(menuX, menuY + 4);
        Colour(3);

        arrowF(2, pos);

        printf("Manage Teachers\n");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);

        printf("Manage Courses\n");
        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("Noticeboard\n");
        gotoxy(menuX, menuY + 10);
        Colour(3);
        arrowF(5, pos);

        printf("Back to previous page");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 5)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 5;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
}
int ManStu(int a)
{
    int x;
    do
    {
        x = ManStuMenu(a);
        if (x == 1)
        {
            AddStu(a);
        }
        else if (x == 2)
        {
            RemStu(a);
        }
        else if (x == 3)
        {
            ShowStu(a);
        }

    } while (x != 4);
}
int ManStuMenu(int a)
{

    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  Admin-Menu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);
        printf("Add Student");

        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("Remove Student");

        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);
        printf("See Students");

        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("Back");

        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 4)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 4;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
}
void Swrite()
{
    FILE *fp = fopen("Stu_info.txt", "w");
    fprintf(fp, "%d\n", n);
    for (i = 0; i < n; i++)
        fprintf(fp, "%s\n%s\n%s\n%d\n", a[i].name, a[i].mail, a[i].matID, a[i].pass);
    fclose(fp);
}
int AddStu(int d)
{
    // Sread();
    struct STD x;
    gotoxy(68, 13);
    printf("Enter Username: ");
    scanf(" %[^\n]", x.name);
    undS(x.name);
    gotoxy(68, 15);
    printf("Generate a Matrix ID: ");
    scanf("%s", x.matID);
    gotoxy(68, 17);
    printf("Generate a gsuit email: ");
    scanf("%s", x.mail);
    gotoxy(68, 19);
    printf("Generate a user password: ");
    scanf("%d", &x.pass);

gotoxy(68, 22);
    printf("Press \"ENTER\" to return");
    Sread();
    a[n] = x;
    n++;
    Swrite();
    Sread();
    getch();
    // ShowStu(d);
}
int ShowStu(int p)
{
    Sread();
    int i;
    gotoxy(68, 10);
    printf("-------Student List------\n");
    for (i = 0; i < n; i++)
    {

        printf("\t\t\t\t\tName:%s\n", a[i].name);
        printf("\t\t\t\t\tMail:%s\n", a[i].mail);
        printf("\t\t\t\t\tID:%s\n", a[i].matID);
        printf("\t\t\t\t\tpass:%d\n\n", a[i].pass);

    }

    printf("\n\n\t\t\t\t\tPress ENTER to return");
    getch();
}
int RemStu(int p)
{
    int i, f = 0;
    char ID[100];
    gotoxy(68, 10);
    printf("-----Remove Student-----\n");
    gotoxy(68, 13);
    printf("Enter ID: ");
    scanf("%s", ID);

    Sread();

    int ind = -1;
    for (i = 0; i < n; i++)
    {
        if (!strcmp(ID, a[i].matID))
        {
            ind = i;
            f = 1;
            break;
        }
    }

    if (f == 1)
    {
        for (i = ind; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;

        Swrite();
        gotoxy(68, 15);
        printf("\n\n\t\t\t\t\t\t\t\t\t  Succesfully removed");
    }
    else{
         gotoxy(68, 17);
    printf("ID couldn't found");
    }

    gotoxy(68, 18);
    printf("Press ENTER for Back>>");
    if (f != 1)
    {
        gotoxy(68, 19);
        printf("Press any other key for another try>>");
    }
    int y = getch();
    if (y != ENTER)
    {
        system("cls");
        RemStu(p);
    }
}
int ManTeach(int a)
{
    int x;
    do
    {
        x = ManTeachMenu(a);
        if (x == 1)
        {
            AddTeach(a);
        }
        else if (x == 2)
        {
            RemTeach(a);
        }
        else if (x == 3)
        {
            ShowTeach(a);
        }

    } while (x != 4);
}
int ManTeachMenu(int a)
{
    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  Admin-Menu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");
        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);
        printf("Add Teacher");
        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("Remove Teacher");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);
        printf("See Teachers");
        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("Back");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 4)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 4;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
    return pos;
}
void Twrite()
{
    FILE *fp = fopen("Teach_info.txt", "w");
    fprintf(fp, "%d\n", m);
    for (i = 0; i < m; i++)
        fprintf(fp, "%s\n%s\n%s\n%d\n%s\n", b[i].name, b[i].mail, b[i].matID, b[i].pass, b[i].course);
    fclose(fp);
}
int AddTeach(int d)
{

    struct STD x;
      gotoxy(68, 13);
    printf("Enter Username: ");
   scanf(" %[^\n]", x.name);
    undS(x.name);
    undS(x.name);
     gotoxy(68, 15);
    printf("Generate a Teacher ID: ");
    scanf("%s", x.matID);
       gotoxy(68, 17);
    printf("Generate a gsuit email: ");
    scanf("%s", x.mail);
     gotoxy(68, 19);
    printf("Generate a user password: ");
    scanf("%d", &x.pass);
    gotoxy(68, 20);
    printf("Enter the course for the teacher: ");
    scanf("%s", x.course);
    gotoxy(68, 23);
    printf("Press \"ENTER\" to return");
    Sread();
    b[m] = x;
    m++;
    Twrite();
    Tread();
     getch();
}
int ShowTeach(int p)
{
    Tread();
    int i;
     gotoxy(68, 10);
    printf("-------Teacher List------\n");
    for (i = 0; i < m; i++)
    {
        printf("\t\t\t\t\tName:%s\n", b[i].name);
        printf("\t\t\t\t\tMail:%s\n", b[i].mail);
        printf("\t\t\t\t\tID:%s\n", b[i].matID);
        printf("\t\t\t\t\tpass:%d\n", b[i].pass);
        printf("\t\t\t\t\tCourse Title:%s\n\n", b[i].course);
    }
    printf("\n\n\t\t\t\t\tPress ENTER to return");
    getch();
}
int RemTeach(int p)
{
    // int i;
    // char ID[100];
    // printf("-----Delete-----\n");
    // printf("Enter ID: ");
    // scanf("%s", &ID);

    // Tread();

    // int ind = -1;
    // for (i = 0; i < m; i++)
    // {
    //     if (!strcmp(ID, b[i].matID))
    //     {
    //         ind = i;
    //         break;
    //     }
    // }
    // for (i = ind; i < m - 1; i++)
    // {
    //     b[i] = b[i + 1];
    // }
    // m--;

    // Twrite();
    // getch();
     int i, f = 0;
    char ID[100];
    gotoxy(68, 10);
    printf("-----Remove Teacher-----\n");
    gotoxy(68, 13);
    printf("Enter ID: ");
    scanf("%s", ID);

    Tread();

    int ind = -1;
    for (i = 0; i < m; i++)
    {
        if (!strcmp(ID, b[i].matID))
        {
            ind = i;
            f = 1;
            break;
        }
    }

    if (f == 1)
    {
        for (i = ind; i < m - 1; i++)
        {
            b[i] = b[i + 1];
        }
        m--;

        Twrite();
        gotoxy(68, 15);
        printf("\n\n\t\t\t\t\t\t\t\t\t Succesfully removed");
    }
   else{
         gotoxy(68, 17);
    printf("ID couldn't found");
    }
    gotoxy(68, 18);
    printf("Press ENTER for Back>>");
    if (f != 1)
    {
        gotoxy(68, 19);
        printf("Press any other key for another try>>");
    }
    int y = getch();
    if (y != ENTER)
    {
        system("cls");
        RemStu(p);
    }
}
int stuMenu(int p)
{
    int x;
    do
    {
        x = StudentM(p);
        if (x == 1)
        {
            StuProfile(p);
        }
        else if (x == 2)
        {
            chatLogMenu(p);
        }
        else if (x == 3)
        {
            courseMat(p);
        }
        else if (x == 4)
        {
            // NoticeB(a, p, 1);
            showNTC(p);
        }

    } while (x != 5);
}

int StudentM(int a)
{
    system("cls");
    Colour(3);
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  StudentMenu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        // system("cls");
        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);

        printf("Student Profile");
        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("Chat Box");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);

        printf("Course Materials");
        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);

        printf("Noticeboard");
        gotoxy(menuX, menuY + 10);
        Colour(3);
        arrowF(5, pos);

        printf("Back");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 5)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 5;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
}
int StuProfile(int p)
{
    gotoxy(68, 9);
    printf("----------------------------------------");
    gotoxy(68, 10);
    printf("%30s", "Student Profile");
    gotoxy(68, 11);
    printf("----------------------------------------");
    gotoxy(68, 14);
    printf("Student Name  : %s", a[p].name);
    gotoxy(68, 16);
    printf("Student Email : %s", a[p].mail);
    gotoxy(68, 18);
    printf("Student ID    : %s", a[p].matID);

    gotoxy(68, 22);
    printf("Press ENTER to Back!");
    getch();
}
// int courseMat(int p)
// {
//     int x;
//     do
//     {
//         x = courseML(p);
//         if (x == 1)
//         {
//             Cm_CSE21(p);
//         }
//         else if (x == 2)
//         {
//             Cm_EEE21(p);
//         }
//         else if (x == 3)
//         {
//             Cm_MATH07(p);
//         }

//     } while (x != 4);
// }
int courseML(int a)
{

    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  StudentMenu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);

        printf("CSE-1121\n");
        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);

        printf("EEE-1121\n");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);

        printf("MATH-1107\n");
        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("PHY-1101\n");
        gotoxy(menuX, menuY + 10);
        Colour(3);
        arrowF(5, pos);

        printf("Back");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 5)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 5;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
}
int chatLogMenu(int p)
{
    int x;
    do
    {
        x = chaTlog(p);
        if (x == 1)
        {
            chat_CSE21(a, p, 1);
        }
        else if (x == 2)
        {
            chat_EEE21(p);
        }
        else if (x == 3)
        {
            chat_MATH07(p);
        }

    } while (x != 4);
}
int chaTlog(int a)
{

    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  StudentMenu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);
        printf("CSE-1121");

        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("EEE-1121");

        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);
        printf("MATH-1107");

        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);
        printf("Back");

        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 4)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 4;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
}
int chat_CSE21(struct STD *Z, int p, int c)
{
    printf("\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t%70s\n", "CHATBOX:CSE-1121");
    printf("\t\t\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t%65s\n", "Jamil-As-Ad");
    printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    stu_type(Z, p, c);

    getch();
}
int chat_EEE21(int a)
{
}
int chat_MATH07(int a)
{
}
int ManCrs(int a)
{
}
int teaMenu(int p)
{
    int x;
    do
    {
        x = TeacherM(p);
        if (x == 1)
        {
            TeaProfile(p);
        }
        else if (x == 2)
        {
            chatTea(p);
        }
        else if (x == 3)
        {
            courseMat(p);
        }
        else if (x == 4)
        {
            NoticeB(b, p, 2);
        }

    } while (x != 5);
}

int TeacherM(int a)
{
    system("cls");
    Colour(3);
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("*********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("*********");
        gotoxy(68, 10);
        printf("****** ");
        printf("  TeacherMenu ");
        printf("   ******");

        gotoxy(68, 11);
        printf("*********");
        printf("         ");
        printf("*********");

        // system("cls");
        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);

        printf("Teacher Profile");
        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);
        printf("Chat Box");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);

        printf("Course Materials");
        gotoxy(menuX, menuY + 8);
        Colour(3);
        arrowF(4, pos);

        printf("Noticeboard");
        gotoxy(menuX, menuY + 10);
        Colour(3);
        arrowF(5, pos);

        printf("Back");
        keyP = getch();
        if (keyP == DOWN)
        {
            if (pos == 5)
                pos = 1;
            else
                pos++;
        }
        else if (keyP == UP)
        {
            if (pos == 1)
                pos = 5;
            else
                pos--;
        }
    }
    system("cls");

    return pos;
}

int courseMenu(int p)
{
    system("cls");
    int pos = 1;
    int keyP = 0;
    while (keyP != ENTER)
    {
        Colour(5);
        gotoxy(68, 9);

        printf("**********");
        Colour(5);
        printf("         ");
        // Colour(12);
        printf("************");
        gotoxy(68, 10);
        printf("******* ");
        printf("Course-Materials ");
        printf(" *****");

        gotoxy(68, 11);
        printf("**********");
        printf("         ");
        printf("************");

        gotoxy(menuX, menuY + 2);
        Colour(3);
        arrowF(1, pos);

        printf("Enter Materials:\n");
        gotoxy(menuX, menuY + 4);
        Colour(3);
        arrowF(2, pos);

        printf("Show Materials:\n");
        gotoxy(menuX, menuY + 6);
        Colour(3);
        arrowF(3, pos);

        printf("Back");
        keyP = getch();
        if (keyP == DOWN && pos != 3)
            pos += 1;
        else if (keyP == UP && pos != 1)
            pos -= 1;
        else
            pos = pos;
    }
    system("cls");

    return pos;
}
int TeaProfile(int p)
{
    gotoxy(68, 9);
    printf("----------------------------------------");
    gotoxy(68, 10);
    printf("%30s", "Teacher Profile");
    gotoxy(68, 11);
    printf("----------------------------------------");
    gotoxy(68, 14);
    printf("Teacher Name  : %s", b[p].name);
    gotoxy(68, 16);
    printf("Teacher Email : %s", b[p].mail);
    gotoxy(68, 18);
    printf("Teacher ID    : %s", b[p].matID);
    gotoxy(68, 20);
    printf("Course        : %s", b[p].course);

    gotoxy(68, 24);
    printf("Press ENTER to Back!");
    getch();
}
int chatTea(int p)
{
    int c = 2;
    if (!strcmp(b[p].course, "CSE-1121"))
        chat_CSE21(b, p, 2);
}
int NoticeB(struct STD *Z, int p, int c)
{
    printf("\n\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t%s\n", "Noticeboard");
    printf("\t\t\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t%s\n", "Department of CSE");
    printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
    Ntc_type(Z, p, c);
}
int Cm_CSE21(int p)
{
    printf("%30s Under construction");
    getch();
}
int Cm_EEE21(int a)
{
    printf("%30s Under construction");
    getch();
}
int Cm_MATH07(int a)
{
    printf("%30s Under construction");

    getch();
}

int cseCMread()
{
    FILE *fp = fopen("cmCSE11.txt", "r");
    fscanf(fp, "%d", &nz);
    for (i = 0; i < nz; i++)
    {
        fscanf(fp, "%s%s", h[i].matName, h[i].matR);
        // printf("[%s %s]\n",h[i].matName,h[i].matR);
    }

    fclose(fp);
}
int cseCMwrite()
{

    FILE *fp = fopen("cmCSE11.txt", "w");
    fprintf(fp, "%d\n", nz);
    for (i = 0; i < nz; i++)
        fprintf(fp, "%s\n%s\n", h[i].matName, h[i].matR);
    fclose(fp);
}
int ShowCM(int p)
{cseCMread();
    gotoxy(68, 10);
    printf("-------Course Material List------\n\n");
    for (i = 0; i < nz; i++)
       {
         printf("\t\t\t\t\t\t\t\tMaterial Name: %s\n",h[i].matName);
         printf("\t\t\t\t\t\t\t\tSource: %s\n\n",h[i].matR);

       }
   printf("\n\n\t\t\t\t\t\t\t\t Press ENTER to return");

    getch();
}
int inputCM(int p)
{

    gotoxy(68, 9);
    printf("-----Insert-----\n");
    struct COM x;
    gotoxy(68, 13);
    printf("Enter Material: ");
    scanf("%s", x.matName);
    gotoxy(68, 15);
    printf("Enter material source: ");
    scanf("%s", x.matR);

    cseCMread();

    h[nz] = x;
    nz++;

    cseCMwrite();
}
int courseMat(int p)
{
    int x;
    do
    {
        x = courseMenu(p);
        if (x == 1)
        {
            inputCM(p);
        }
        else if (x == 2)
        {
            ShowCM(p);
        }

    } while (x != 3);
}
// void comPr(char A[], struct STD *Z, int c)
// {

//     int k;
//     for (i = 0; i < c; i++; k++)
//     {
//          if (k == 4)
//          printf("Try after showing the records");
//         if (!strcmp(A, Z[i].))

//             printf("Already Exist\nTry Another one");
//            else
//            {
//                printf("You can use this one");
//                Sleep(200);
//                break;
//            }

//     }

//     getch();
// }



