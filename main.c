#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count_F(int t[][3], int size, int to_win, int []);
void show_table(int t[][3], int size);
int * move(int t[][3], int who);


int main(){
int tab[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int win=0;
int value=1;
int *tb_mv;
int wait;
show_table(tab, 3);
while(win==0){
    tb_mv = move(tab, value);
    win=count_F(tab,3, pow(value, 3), tb_mv);
    show_table(tab, 3);
    if(value==1)value=2;
    else value=1;
    }
printf("The winner is player%d Congratulation", win);
return 0;
}


void show_table(int t[][3], int size){
    int i,j;
    char c;
    system("cls");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(t[i][j]==2)
                c='O';
            else if(t[i][j]==1)c='X';
            else c=' ';
            printf("%c", c);
            if(j<2) printf("|");
        }
        if(i<2) printf("\n------\n");
    }
    printf("\n");
}


int * move(int t[][3], int who){
    static int mv[2];
    int free=0;
    do{
        do{
            printf("\nRow (value in range 1-3):\t");
            scanf("%d", &mv[0]);
        }while((mv[0]!=1)&&(mv[0]!=2)&&(mv[0]!=3));
        do{
            printf("Column (value in range 1-3):\t");
            scanf("%d", &mv[1]);
        }while((mv[1]!=1)&&(mv[1]!=2)&&(mv[1]!=3));
    if(t[mv[0]-1][mv[1]-1]==0){
        t[mv[0]-1][mv[1]-1]=who;
        free=1;
    }
    else printf("\nSorry but this place was already choose please select another\n");
    }while(free==0);
return &mv[0];
}


int count_F(int t[][3], int size, int to_win, int mv_t[]){
    int mult=1;
    int i, j, flag=0;

    mult=1;
    for(j=0;j<size;j++){
        mult*=t[mv_t[0]-1][j];
    }
        if(mult==to_win)flag=1;
    if(flag==0){
            mult=1;
            for(j=0;j<size;j++){
                mult*=t[j][mv_t[1]-1];
            }
            if(mult==to_win)flag=1;
        }

    if(flag==0){
        mult=t[0][0]*t[1][1]*t[2][2];
        if(mult==to_win)flag=to_win;
        else{
            mult=t[0][2]*t[1][1]*t[2][0];
            if(mult==to_win)flag=to_win;

        }

    }
    return flag;
}
