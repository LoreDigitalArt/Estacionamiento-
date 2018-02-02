#include <stdio.h>
#include <stdlib.h>
int imest(int LUG[10][10]);
int entrada(int LG[10][10]);
int salida(int LG[10][10]);

int main()
{
    int LG[10][10], i,j,op;
    for(i=0;i<10; i++){
        for(j=0;j<10;j++){
            LG[i][j]=0;
        }
    }
    printf("Bienvenido al estacionamiento ''LORES''\n");
    printf("Los lugares señalados con O estan ocupados y los representados con L estan desocupados\n");
    imest(LG);
    continua:

        printf("\nIngresa un auto 1. \t\tSale un auto 2.\t\tNingun movimiento 3. \nSeleccione una opcion: ");
        scanf("%d",&op);
        system("cls");
        if(op==1){

            entrada(LG);
            system("pause");
            system("cls");
        }
        else if(op==2){

            salida(LG);
            system("pause");
            system("cls");
        }
        else if(op==3){
            return 0;
        }

        goto continua;

    return 0;
}
int imest(int LUG[10][10]){
    int i,j;
    for(i=0;i<10; i++){
            for(j=0;j<10;j++){
                if(LUG[i][j]==0){
                    printf("L");
                }
                else{
                    printf("o");
                }
                printf("\t");
            }
            printf("\n\n");
        }
    return 0;
}
int entrada(int LG[10][10]){
    int F,C;
    printf("\nSeleccione un lugar donde desea colocar su automovil \n");
    datain:
        printf("Columna: ");
        scanf("%d",&C);
        printf("Fila: ");
        scanf("%d",&F);
        if(C>10){
            printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(F>10){
             printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(C<0){
            printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(F<0){
             printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(LG[F-1][C-1]==1){
            printf("\nLugar ocupado");
        }
        else {
            LG[F-1][C-1]=1;
            imest(LG);
        }
}
int salida(int LG[10][10]){
    int C,F, tiem;
    float cost;
    printf("\nIngrese el lugar donde se encuentra su automovil\n");
    datain:
        printf("Columna: ");
        scanf("%d",&C);
        printf("Fila: ");
        scanf("%d",&F);
        if(C>10){
            printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(F>10){
             printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(C<0){
            printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(F<0){
             printf("Error, posicion fuera del estacionamiento!!!!\n\nIngrese datos correctos porfavor\n");
            goto datain;
        }
        else if(LG[F-1][C-1]==0){
            printf("\nEse lugar esta vacio, seleccione el lugar correcto:");
            goto datain;
        }
        else {
            LG[F-1][C-1]=0;
            imest(LG);
            printf("Ingrese la cantidad de tiempo que se quedo en minutos\n");
            printf("Costos\nMenos de 30 min\t$5\nDe 30 a 60 min\t$10\nMas de una hora\t$10\nIngrese la cantidad de tiempo que estuvo en el estacionamiento en minutos: ");
            scanf("%d", &tiem);
            if((tiem>0)&(tiem<30)){
                cost=5;
            }
            else if((tiem>30)&(tiem<60)){
                cost=10;
            }
            else if(tiem>60){
                cost=(tiem/6);
            }
            printf("\nTiempo de estadia:\t %d minutos\nCosto de estadia:\t$%.2f\n\n",tiem,cost);


        }

        return 0;

}

