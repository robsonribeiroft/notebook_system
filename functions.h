#include <string.h>

struct notebook{
    char so[15];
    char marca[10];
    char modelo[25];
    char processador[25];
    char video[25];
    char dvd;
    char cartao;
    int codigo;
    int hd;
    int ram;
    int entradas;
    float tela;
    float preco;
};
typedef struct notebook TPC;

struct listaNotebook{
    unsigned quant;
    TPC notes[30];
};
typedef struct listaNotebook TListaNotebook;

int cod = 1;

void upper(char str[]){
    int i=0;
    while(str[i]){
        if(str[i]>96 && str[i]<123)
            str[i] -= 32;
        i++;
    }
}


TPC insereNotebook(){
    TPC pc;
    pc.codigo = cod;
    cod++;

    printf("----- Novo Notebook -----\n");
    printf("Marca: ");
    fflush(stdin);
    gets(pc.marca);
    upper(pc.marca);

    printf("Modelo: ");
    fflush(stdin);
    gets(pc.modelo);
    upper(pc.modelo);

    printf("Processador: ");
    fflush(stdin);
    gets(pc.processador);
    upper(pc.processador);

    printf("Capacidade do HD(GB): ");
    fflush(stdin);
    scanf("%d", &pc.hd);


    printf("Mem\xa2ria RAM(GB): ");
    fflush(stdin);
    scanf("%d", &pc.ram);

    printf("Placa de video: ");
    fflush(stdin);
    gets(pc.video);
    if(strcmp("", pc.video) == 0)
        strcpy(pc.video, "ONBOARD");
    else
        upper(pc.video);

    printf("Numero de entradas USB: ");
    fflush(stdin);
    scanf("%d", &pc.entradas);

    printf("Leitor de DVD(s/n): ");
    fflush(stdin);
    pc.dvd = getchar();

    printf("Leitor de cart\xc6o SD(s/n): ");
    fflush(stdin);
    pc.cartao = getchar();

    printf("Tamanho da tela(em polegadas): ");
    fflush(stdin);
    scanf("%f", &pc.tela);

    printf("Sistema Operacional: ");
    fflush(stdin);
    gets(pc.so);
    upper(pc.so);

    printf("Pre\x87o: ");
    fflush(stdin);
    scanf("%f", &pc.preco);
    printf("\n");

    return pc;
}

void insereNaLista(TPC pc, TListaNotebook *lis){
    lis->notes[lis->quant++] = pc;
}


void mostraNotebook(TPC pc){
    printf("%03d %-10s %-25s %-25s %5dGB %4dGB %-25s %3d %-3c %-6c %2.1f\x22 %-20s  R$ %.2f\n",
           pc.codigo,
           pc.marca,
           pc.modelo,
           pc.processador,
           pc.hd,
           pc.ram,
           pc.video,
           pc.entradas,
           pc.dvd,
           pc.cartao,
           pc.tela,
           pc.so,
           pc.preco);
}

void mostraListaNotebook(TListaNotebook *lpc){
    int i;
    printf("COD MARCA      MODELO                    PROCESSADOR                HDD      RAM  PLACA DE VIDEO            USB DVD CART\xc7O TELA S.O.                  PRE\x80O\n");
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
    for(i=0; i<lpc->quant; i++){
        mostraNotebook(lpc->notes[i]);
    }
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");

}


int buscarCodigo(int c, TListaNotebook *lpc){
    int i;
    for(i=0; i<lpc->quant; i++){
        if(lpc->notes[i].codigo == c)
            return i;
    }
    return -1;
}


void removeNotebook(int code, TListaNotebook *lpc){
        int i;
        for(i=code; i<lpc->quant; i++){
            lpc->notes[i] = lpc->notes[i+1];
        }
        lpc->quant--;
        printf("\n --- Remo\x87\xc6o Completa ---\n\n");
}


void buscarMarca(char str[], TListaNotebook *lpc){
    int i;
    printf("COD MARCA      MODELO                    PROCESSADOR                HDD      RAM  PLACA DE VIDEO            USB DVD CART\xc7O TELA S.O.                  PRE\x80O\n");
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
    for(i=0; i<lpc->quant; i++){
        if(strcmp(str, lpc->notes[i].marca) == 0){
            mostraNotebook(lpc->notes[i]);
        }
    }
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
}



void buscarProcessador(char str[], TListaNotebook *lpc){
    int i;
    printf("COD MARCA      MODELO                    PROCESSADOR                HDD      RAM  PLACA DE VIDEO            USB DVD CART\xc7O TELA S.O.                  PRE\x80O\n");
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
    for(i=0; i<lpc->quant; i++){
        if(strcmp(str, lpc->notes[i].processador) == 0){
            mostraNotebook(lpc->notes[i]);
        }
    }
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
}

int cmpPreco(const void *a, const void *b){
    TPC *ia = (TPC *)a;
    TPC *ib = (TPC *)b;
    return ia->preco - ib->preco;
}

int cmpCodigo(const void *a, const void *b){
    TPC *ia = (TPC *)a;
    TPC *ib = (TPC *)b;
    return ia->codigo - ib->codigo;
}

int cmpMarca(const void *a, const void *b){
    TPC *ia = (TPC *)a;
    TPC *ib = (TPC *)b;
    return strcmp(ia->marca, ib->marca);
}

int cmpProcessador(const void *a, const void *b){
    TPC *ia = (TPC *)a;
    TPC *ib = (TPC *)b;
    return strcmp(ia->processador, ib->processador);
}

void alterarDados(int code, TListaNotebook *lpc){
    printf("Marca: ");
    fflush(stdin);
    gets(lpc->notes[code].marca);
    upper(lpc->notes[code].marca);

    printf("Modelo: ");
    fflush(stdin);
    gets(lpc->notes[code].modelo);
    upper(lpc->notes[code].modelo);

    printf("Processador: ");
    fflush(stdin);
    gets(lpc->notes[code].processador);
    upper(lpc->notes[code].processador);

    printf("Capacidade do HD: ");
    fflush(stdin);
    scanf("%d", &lpc->notes[code].hd);

    printf("Mem\xa2ria RAM: ");
    fflush(stdin);
    scanf("%d", &lpc->notes[code].ram);

    printf("Placa de video: ");
    fflush(stdin);
    gets(lpc->notes[code].video);
    if(strcmp("", lpc->notes[code].video) == 0)
        strcpy(lpc->notes[code].video, "ONBOARD");
    else
        upper(lpc->notes[code].video);

    printf("Numero de entradas USB: ");
    fflush(stdin);
    scanf("%d", &lpc->notes[code].entradas);

    printf("Leitor de DVD(s/n): ");
    fflush(stdin);
    lpc->notes[code].dvd = getchar();

    printf("Leitor de cart\xc6o SD: ");
    fflush(stdin);
    lpc->notes[code].cartao = getchar();

    printf("Tamanho da tela(em polegadas): ");
    fflush(stdin);
    scanf("%f", &lpc->notes[code].tela);

    printf("Sistema Operacional: ");
    fflush(stdin);
    gets(lpc->notes[code].so);
    upper(lpc->notes[code].so);

    printf("Pre\x87o: ");
    fflush(stdin);
    scanf("%f", &lpc->notes[code].preco);
    printf("\n --- altera\x87\xc6o completa ---\n");
}

