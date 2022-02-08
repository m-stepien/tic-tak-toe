#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count_F(int t[][3], int size, int to_win);
void show_table(int t[][3], int size);
void move(int t[][3], int who);


int main(){
int tab[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int win=0;
int value=1;
while(win==0){
    show_table(tab, 3);
    move(tab, value);
    win=count_F(tab,3, pow(value, 3));
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


void move(int t[][3], int who){
    int x, y, free=0;
    do{
        do{
            printf("\nRow (value in range 1-3):\t");
            scanf("%d", &x);
        }while((x!=1)&&(x!=2)&&(x!=3));
        do{
            printf("Column (value in range 1-3):\t");
            scanf("%d", &y);
        }while((y!=1)&&(y!=2)&&(y!=3));
    if(t[x-1][y-1]==0){
        t[x-1][y-1]=who;
        free=1;
    }
    else printf("\nSorry but this place was already choose please select another\n");
    }while(free==0);

}


int count_F(int t[][3], int size, int to_win){
    int mult=1;
    int i, j, flag=0;
    for(i=0;(i<size)&&(flag==0);i++){
        mult=1;
        for(j=0;j<size;j++){
            mult*=t[i][j];
        }
        if(mult==to_win)flag=1;
    }
    if(flag==0){
        for(i=0;(i<size)&&(flag==0);i++){
            mult=1;
            for(j=0;j<size;j++){
                mult*=t[j][i];
            }
            if(mult==to_win)flag=1;
        }
    }
    if(flag==0){
        mult=1;
        for(i=0;(i<size)&&(flag==0);i++)mult*=t[i][i];
            if(mult==to_win)flag=to_win;
    }
    return flag;
}
