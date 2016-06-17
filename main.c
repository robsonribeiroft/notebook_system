#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    TListaNotebook ml;
    ml.quant = 0;
    int option,save=0;

    FILE *fc;
    fc = fopen("lista.arq", "rb");
    fread(&ml, sizeof(TListaNotebook), 1, fc);
    fread(&cod, sizeof(int), 1, fc);
    fclose(fc);

    do{
        option = selectMenuOption();
        switchOption(option, &ml);
    }while(option);

    saveFile(save, fc, ml);
    printf("\n--- FIM DE APLICATIVO ---\n");

    return 0;
}
