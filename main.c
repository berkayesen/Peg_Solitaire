#include <stdio.h>
#include <stdlib.h>

void setmatrix(int array[7][7]){
int x,y;
for(y=0;y<7;y++){
    for(x=0;x<7;x++){
    if((x==0 || x==1 || x==5 || x==6)&&(y==0 || y==1 || y==5 || y==6))
            array[x][y]=2;

    else if(x==3 && y==3)
        array[x][y]=0;

    else
        array[x][y]=1;
    }

}

}

void printmatrix(int array[7][7]){
int x,y;
for(y=0;y<7;y++){
    printf(" [%d]  ",y);
    for(x=0;x<7;x++){
        if(array[x][y]==2)
            printf("    ");
        if(array[x][y]==1)
        printf("O   ");
        if(array[x][y]==0)
            printf(".   ");


    }

    printf("\n");
}
printf("\n     [0] [1] [2] [3] [4] [5] [6]\n");
printf("Kalan tas: %d \n",tassay(array));
printf("Oynanabilecek hamle sayisi : %d\n",hamlekontrol(array));

}

int tassay(int tahta[7][7] ){
int sayac=0;
for(int x=0;x<7;x++){
    for(int y=0;y<7;y++){
        if(tahta[x][y]==1)
            sayac++;
    }
}


return sayac;
}
int hamlekontrol(int tahta[7][7]){
int sayac=0;
for(int x=0;x<7;x++){
    for(int y=0;y<7;y++){
        if(tahta [x][y]==1 && tahta[x][y-1]==1 && tahta[x][y-2]==0)
            sayac++;
        if(tahta [x][y]==1 && tahta[x][y+1]==1 && tahta[x][y+2]==0)
            sayac++;
        if(tahta [x][y]==1 && tahta[x-1][y]==1 && tahta[x-2][y]==0)
            sayac++;
        if(tahta [x][y]==1 && tahta[x+1][y]==1 && tahta[x+2][y]==0)
            sayac++;
    }

}

return sayac;
}


int main()
{
int tahta[7][7];

setmatrix(tahta);

printmatrix(tahta);

while(hamlekontrol(tahta)!=0){
int x2,x1,y2,y1;

printf("lutfen hareket etmek istediginiz tasin konumunu girin\n");

scanf("%d%d",&x1,&y1);

printf("lutfen koymak istedginiz hedefin konumunu girin\n");

scanf("%d%d",&x2,&y2);


    if (x1==x2)
    {
        if (y2-y1==2)
        {
            tahta[x2][y2]=1;
            tahta[x1][y1]=0;
            tahta[x1][y1+1]=0;
        }
        else if (y1-y2==2)
        {
            tahta[x2][y2]=1;
            tahta[x1][y1]=0;
            tahta[x1][y1-1]=0;
        }
    }
    else if (y1==y2)
    {
        if (x1-x2==2)
        {
            tahta[x2][y2]=1;
            tahta[x1][y1]=0;
            tahta[x1-1][y2]=0;
        }
        else if (x2-x1==2)
        {
            tahta[x2][y2]=1;
            tahta[x1][y1]=0;
            tahta[x1+1][y2]=0;
        }
    }
//    if(tahta[x1][y1]==1 && tahta[x2][y2]==0 && tahta[x1][y2+1]==1 && y2>y1 && y2-y1==2){//tasi asagi alma kontol
//    tahta[x2][y2]=1;
//    tahta[x1][y1]=0;
//    tahta[x1][y1+1]=0;}
//
//    else if(tahta[x1][y1]==1 && tahta[x2][y2]==0 && tahta[x1][y2-1]==1 && y1>y2 && y1-y2==2 ){//tasi yukari alma kontrol
//    tahta[x2][y2]=1;
//    tahta[x1][y1]=0;
//    tahta[x1][y1-1]=0;
//    }
//
//    else if(tahta[x1][y1]==1 && tahta[x2][y2]==0 && tahta[x2+1][y1]==1 && x1>x2 && x1-x2==2){ //tasi sola alma kontrol
//    tahta[x2][y2]=1;
//    tahta[x1][y1]=0;
//    tahta[x1-1][y2]=0;
//    }
//
//    else if(tahta[x1][y1]==1 && tahta[x2][y2]==0 && tahta[x2-1][y1]==1 && x2>x1 && x2-x1==2){  //tasi saga alma kontrol
//    tahta[x2][y2]=1;
//    tahta[x1][y1]=0;
//    tahta[x1+1][y2]=0;
//    }

system("cls");
printmatrix(tahta);


}

return 0;
}



