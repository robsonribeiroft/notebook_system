#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    TPC net;
    char answer;
    TListaNotebook ml;
    ml.quant = 0;
    int option = 1, option2 = 1, resp, save=0, found;
    char busca[20];

    FILE *fc;
    fc = fopen("lista.arq", "rb");
    fread(&ml, sizeof(TListaNotebook), 1, fc);
    fread(&cod, sizeof(int), 1, fc);
    fclose(fc);
    while(option){
        printf("\n");
        printf("---- Central de Notebooks para funcion\xa0rios ----\n");
        printf("1 - Inserir novos notebooks no arquivo\n");
        printf("2 - Remover notebooks do arquivo\n");
        printf("3 - Alterar os dados de um notebook\n");
        printf("4 - Consultar a lista de notebooks\n");
        printf("5 - Buscar na lista de notebooks\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Escolha uma op\x87\xc6o: ");
        scanf("%d%*c", &option);
        printf("\n");

        switch(option){
        case 0:
        break;

        case 1:
            system("cls");
            net = insereNotebook();
            insereNaLista(net, &ml);
            save++;
            printf("---- Notebook salvo! -----\n\n");
            system("pause");
            system("cls");

        break;

        case 2:
            system("cls");
            printf("--- Remover Notebook ---\n");
            printf("Deseja ver a lista de notebooks(s/n)? ");
            fflush(stdin);
            answer = getchar();
            if(answer=='s' || answer=='S'){
                system("cls");
                printf("--- Remover Notebook ---\n");
                qsort(ml.notes, ml.quant, sizeof(TPC), cmpCodigo);
                mostraListaNotebook(&ml);
            }
            else{
                system("cls");
                printf("--- Remover Notebook ---\n");

            }
            printf("Entre com o c%cdigo do notebook a ser removido: ",162);
            scanf("%d", &resp);
            qsort(ml.notes, ml.quant, sizeof(TPC), cmpCodigo);
            found = buscarCodigo(resp, &ml);
            if(found<0){
                printf("\nC%cdigo n\xc6o encontrado!\n\n",162);
                system("pause");
                system("cls");
            }
            else{
                system("cls");
                printf("--- Remover Notebook ---\n");
                printf("\n");
                printf("COD MARCA      MODELO                    PROCESSADOR                HDD      RAM  PLACA DE VIDEO            USB DVD CART\xc7O TELA  S.O.                  PRE\x80O\n");
                printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
                mostraNotebook(ml.notes[found]);
                printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
                printf("Deseja excluir esse notebook(s/n)?\n");
                fflush(stdin);
                answer = getchar();
                if(answer=='s' || answer=='S'){
                    removeNotebook(found, &ml);
                    save++;
                }
                else{
                    system("cls");
                    printf("Opera\x87\xc6o cancelada!\n");
                }
                system("pause");
                printf("\n");
                system("cls");
            }
        break;

        case 3:
            system("cls");
            printf("--- Alterar Notebook ---\n");
            printf("Deseja ver a lista de notebooks(s/n)?");
            fflush(stdin);
            answer = getchar();
            if(answer=='s' || answer=='S'){
                system("cls");
                printf("--- Alterar Notebook ---\n");
                qsort(ml.notes, ml.quant, sizeof(TPC), cmpCodigo);
                mostraListaNotebook(&ml);
            }
            else{
                system("cls");
                printf("--- Alterar Notebook ---\n");

            }
            printf("C%cdigo do notebook a ser alterado: ",162);
            fflush(stdin);
            scanf("%d", &resp);
            found = buscarCodigo(resp, &ml);
            if(found<0){
                printf("\nC%cdigo n\xc6o encontrado!\n\n",162);
                system("pause");
                system("cls");
            }
            else{
                system("cls");
                printf("COD MARCA      MODELO                    PROCESSADOR                HDD      RAM  PLACA DE VIDEO            USB DVD CART\xc7O TELA S.O.                  PRE\x80O\n");
                printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
                mostraNotebook(ml.notes[found]);
                printf("--- ---------- ------------------------- -------------------------- -------- ---- ------------------------- --- --- ------ ---- --------------------- ----------\n");
                printf("Deseja alterar esse notebook(s/n)?");
                fflush(stdin);
                answer = getchar();
                if(answer=='s' || answer=='S'){
                    printf("\n--- Alterar Notebook ---\n");
                    alterarDados(found, &ml);
                    save++;
                    printf("\nAltera\x87\xc6o completa!\n");
                }
                else{
                    system("cls");
                    printf("Opera\x87\xc6o cancelada!\n");
                }
                system("pause");
                printf("\n");
                system("cls");
            }
        break;

        case 4:
            while(option2){
                system("cls");
                printf("---- Lista de notebook's ----\n");
                printf("1 - Ordenado pelo pre\x87o\n");
                printf("2 - Ordenado pela marca\n");
                printf("3 - Ordenado pelo processador\n");
                printf("4 - Ordenado pelo c%cdigo\n",162);
                printf("0 - Voltar ao menu principal\n");
                printf("Escolha uma op\x87\xc6o: ");
                scanf("%d%*c", &option2);
                printf("\n");

                if(option2 == 1){
                    system("cls");
                    qsort(ml.notes, ml.quant, sizeof(TPC), cmpPreco);
                    mostraListaNotebook(&ml);
                    printf("\n");
                    system("pause");
                }
                else if(option2 == 2){
                    system("cls");
                    qsort(ml.notes, ml.quant, sizeof(TPC), cmpMarca);
                    mostraListaNotebook(&ml);
                    printf("\n");
                    system("pause");
                }
                else if(option2 == 3){
                    system("cls");
                    qsort(ml.notes, ml.quant, sizeof(TPC), cmpProcessador);
                    mostraListaNotebook(&ml);
                    printf("\n");
                    system("pause");
                }
                else if(option2 == 0){
                    printf("\n");
                    system("cls");
                    break;
                }
                else if(option2 == 4){
                    system("cls");
                    qsort(ml.notes, ml.quant, sizeof(TPC), cmpCodigo);
                    mostraListaNotebook(&ml);
                    printf("\n");
                    system("pause");
                }
                else{
                    system("cls");
                    printf("Op\x87\xc6o invalida!\n");
                }
            }
            option2 = 1;
        break;

        case 5:
            while(option2){
                system("cls");
                printf("---- Consulta de notebook's ----\n");
                printf("1 - Filtrando pela marca\n");
                printf("2 - Filtrando pelo processador\n");
                printf("0 - Voltar ao menu principal\n");
                printf("Escolha uma op\x87\xc6o: ");
                scanf("%d%*c", &option2);
                printf("\n");

                if(option2 == 1){
                    system("cls");
                    printf("Digite a marca que deseja: ");
                    gets(busca);
                    fflush(stdin);
                    upper(busca);
                    printf("\n");
                    buscarMarca(busca, &ml);
                    printf("\n");
                    system("pause");
                }
                else if(option2 == 2){
                    system("cls");
                    printf("Digite o processador que deseja: ");
                    gets(busca);
                    fflush(stdin);
                    upper(busca);
                    printf("\n");
                    buscarProcessador(busca, &ml);
                    printf("\n");
                    system("pause");
                }
                else if(option2 == 0){
                    system("cls");
                    break;
                }
                else{
                    system("cls");
                    printf("Op\x87\xc6o invalida!\n");
                    system("pause");
                }
            }
            option2 = 1;
        break;

        default:
            system("cls");
            printf("Op\x87\xc6o invalida!\n");
        }
    }

    if(save){
        printf("Lista alterada. Deseja salvar(s/n)?");
        answer = getchar();
        fflush(stdin);
        if(answer=='s' || answer=='S'){
            fc = fopen("lista.arq", "wb");
            fwrite(&ml, sizeof(TListaNotebook), 1, fc);
            fwrite(&cod, sizeof(int), 1, fc);
            fclose(fc);
            printf("\n--- Atualiza\x87%ces salvas ---\n",228);
        }

    }
    printf("\n--- FIM DE APLICATIVO ---\n");

    return 0;
}
