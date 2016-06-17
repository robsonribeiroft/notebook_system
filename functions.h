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
    if(strcmp("", pc.video) == 0) strcpy(pc.video, "ONBOARD");
    else upper(pc.video);

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

void printLabel(){
    printf("COD MARCA      MODELO                    PROCESSADOR                HDD      RAM  PLACA DE VIDEO            USB DVD CART\xc7O TELA S.O.                  PRE\x80O\n");
}

void printDivision(){
    printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
}

void mostraListaNotebook(TListaNotebook *lpc){
    int i;
    printLabel();
    printDivision();
    for(i=0; i<lpc->quant; i++){
        mostraNotebook(lpc->notes[i]);
    }
    printDivision();
}


int buscarCodigo(int c, TListaNotebook *lpc){
    int i;
    for(i=0; i<lpc->quant; i++){
        if(lpc->notes[i].codigo == c) return i;
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
    printLabel();
    printDivision();
    for(i=0; i<lpc->quant; i++){
        if(strcmp(str, lpc->notes[i].marca) == 0) mostraNotebook(lpc->notes[i]);
    }
    printDivision();
}



void buscarProcessador(char str[], TListaNotebook *lpc){
    int i;
    printLabel();
    printDivision();
    for(i=0; i<lpc->quant; i++){
        if(strcmp(str, lpc->notes[i].processador) == 0) mostraNotebook(lpc->notes[i]);
    }
    printDivision();
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
    if(strcmp("", lpc->notes[code].video) == 0) strcpy(lpc->notes[code].video, "ONBOARD");
    else upper(lpc->notes[code].video);

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

int selectMenuOption(){
    int option;
    printf("---- Central de Notebooks para funcion\xa0rios ----\n");
    printf("1 - Inserir novos notebooks no arquivo\n");
    printf("2 - Remover notebooks do arquivo\n");
    printf("3 - Alterar os dados de um notebook\n");
    printf("4 - Consultar a lista de notebooks\n");
    printf("5 - Buscar na lista de notebooks\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Escolha uma op\x87\xc6o: ");
    fflush(stdin);
    scanf("%d%*c", &option);
    printf("\n");
    return option;
}

int selectSubMenuOption4(){
    system("cls");
    int option2;
    printf("---- Lista de notebook's ----\n");
    printf("1 - Ordenado pelo pre\x87o\n");
    printf("2 - Ordenado pela marca\n");
    printf("3 - Ordenado pelo processador\n");
    printf("4 - Ordenado pelo c%cdigo\n",162);
    printf("0 - Voltar ao menu principal\n");
    printf("Escolha uma op\x87\xc6o: ");
    fflush(stdin);
    scanf("%d%*c", &option2);
    printf("\n");
    return option2;
}

int selectSubMenuOption5(){
    system("cls");
    int option2;
    printf("---- Consulta de notebook's ----\n");
    printf("1 - Filtrando pela marca\n");
    printf("2 - Filtrando pelo processador\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Escolha uma op\x87\xc6o: ");
    fflush(stdin);
    scanf("%d%*c", &option2);
    printf("\n");
    return option2;
}
/*
File initFile(TListaNotebook *ml, int *cod){
    FILE *fc;
    fc = fopen("lista.arq", "rb");
    fread(ml, sizeof(TListaNotebook), 1, fc);
    fread(cod, sizeof(int), 1, fc);
    fclose(fc);
    return fc
}
*/

void saveFile(int save, FILE *fc, TListaNotebook ml){
    char answer;
    if(save){
        printf("Lista alterada. Deseja salvar(s/n)?");
        fflush(stdin);
        answer = getchar();
        if(answer=='s' || answer=='S'){
            fc = fopen("lista.arq", "wb");
            fwrite(&ml, sizeof(TListaNotebook), 1, fc);
            fwrite(&cod, sizeof(int), 1, fc);
            fclose(fc);
            printf("\n--- Atualiza\x87%ces salvas ---\n",228);
        }

    }
}

int optionEqualsOne(TListaNotebook *ml){
    TPC net;
    system("cls");
    net = insereNotebook();
    insereNaLista(net, ml);
    printf("---- Notebook salvo! -----\n\n");
    system("pause");
    return 1;
}

int optionEqualsTwo(TListaNotebook *ml){
    char answer;
    int codeToSearch, codeFound, toSave=0;

    system("cls");
    printf("--- Remover Notebook ---\n");
    printf("Deseja ver a lista de notebooks(s/n)? ");
    fflush(stdin);
    answer = getchar();
    printf("--- Remover Notebook ---\n");
    if(answer=='s' || answer=='S'){
        system("cls");
        qsort(ml->notes, ml->quant, sizeof(TPC), cmpCodigo);
        mostraListaNotebook(ml);
    }
    else system("cls");
    printf("Entre com o c%cdigo do notebook a ser removido: ",162);
    scanf("%d", &codeToSearch);
    qsort(ml->notes, ml->quant, sizeof(TPC), cmpCodigo);
    codeFound = buscarCodigo(codeToSearch, ml);
    if(codeFound<0){
        printf("\nC%cdigo n\xc6o encontrado!\n\n",162);
        system("pause");
    }
    else{
        system("cls");
        printf("--- Remover Notebook ---\n");
        printf("\n");
        printLabel();
        printDivision();
        mostraNotebook(ml->notes[codeFound]);
        printDivision();
        printf("Deseja excluir esse notebook(s/n)?\n");
        fflush(stdin);
        answer = getchar();
        if(answer=='s' || answer=='S'){
            removeNotebook(codeFound, ml);
            toSave = 1;
        }
        else{
            printf("\n");
            printf("Opera\x87\xc6o cancelada!\n");
        }
        system("pause");
        printf("\n");
    }
    return toSave;
}

int optionEqualsThree(TListaNotebook *ml){
    char answer;
    int codeToSearch, codeFound, toSave=0;
    system("cls");
    printf("--- Alterar Notebook ---\n");
    printf("Deseja ver a lista de notebooks(s/n)?");
    fflush(stdin);
    answer = getchar();
    if(answer=='s' || answer=='S'){
        system("cls");
        printf("--- Alterar Notebook ---\n");
        qsort(ml->notes, ml->quant, sizeof(TPC), cmpCodigo);
        mostraListaNotebook(ml);
    }
    else{
        system("cls");
        printf("--- Alterar Notebook ---\n");

    }
    printf("C%cdigo do notebook a ser alterado: ",162);
    fflush(stdin);
    scanf("%d", &codeToSearch);
    codeFound = buscarCodigo(codeToSearch, ml);
    if(codeFound<0){
        printf("\nC%cdigo n\xc6o encontrado!\n\n",162);
        system("pause");
        system("cls");
    }
    else{
        system("cls");
        printLabel();
        printDivision();
        mostraNotebook(ml->notes[codeFound]);
        printDivision();
        printf("Deseja alterar esse notebook(s/n)?");
        fflush(stdin);
        answer = getchar();
        if(answer=='s' || answer=='S'){
            printf("\n--- Alterar Notebook ---\n");
            alterarDados(codeFound, ml);
            toSave = 1;
            printf("\nAltera\x87\xc6o completa!\n");
        }
        else{
            system("cls");
            printf("Opera\x87\xc6o cancelada!\n");
        }
        system("pause");
        printf("\n");
    }
    return toSave;
}

void optionEqualsFour(TListaNotebook *ml){
    system("cls");
    int option;
    do{
        option = selectSubMenuOption4();
        system("cls");

        if(option == 1){
            qsort(ml->notes, ml->quant, sizeof(TPC), cmpPreco);
            mostraListaNotebook(ml);
            printf("\n");
            system("pause");
        }
        else if(option == 2){
            qsort(ml->notes, ml->quant, sizeof(TPC), cmpMarca);
            mostraListaNotebook(ml);
            printf("\n");
            system("pause");
        }
        else if(option == 3){
            qsort(ml->notes, ml->quant, sizeof(TPC), cmpProcessador);
            mostraListaNotebook(ml);
            printf("\n");
            system("pause");
        }
        else if(option == 0){
            break;
        }
        else if(option == 4){
            qsort(ml->notes, ml->quant, sizeof(TPC), cmpCodigo);
            mostraListaNotebook(ml);
            printf("\n");
            system("pause");
        }
        else{
            printf("Op\x87\xc6o invalida!\n");
        }
    }while(option);
}

void optionEqualsFive(TListaNotebook *ml){
    system("cls");
    char busca[20];
    int option;
    do{
        option = selectSubMenuOption5();
        system("cls");

        if(option == 1){
            printf("Digite a marca que deseja: ");
            fflush(stdin);
            gets(busca);
            upper(busca);
            printf("\n");
            buscarMarca(busca, ml);
            printf("\n");
            system("pause");
        }
        else if(option == 2){
            printf("Digite o processador que deseja: ");
            fflush(stdin);
            gets(busca);
            upper(busca);
            printf("\n");
            buscarProcessador(busca, ml);
            printf("\n");
            system("pause");
        }
        else if(option == 0){
            break;
        }
        else{
            printf("Op\x87\xc6o invalida!\n");
            system("pause");
        }
    }while(option);
}

int switchOption(int option, TListaNotebook *ml){
    int toSave=0;
    switch(option){
        case 0:
        break;

        case 1:
            toSave = optionEqualsOne(ml);
        break;

        case 2:
            toSave = optionEqualsTwo(ml);
        break;

        case 3:
            toSave = optionEqualsThree(ml);
        break;

        case 4:
            optionEqualsFour(ml);
        break;

        case 5:
            optionEqualsFive(ml);
        break;

        default:
            system("cls");
            printf("Op\x87\xc6o invalida!\n");
        }
    return toSave;
}



