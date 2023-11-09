#include <stdio.h>
#include <locale.h>
#include <string.h>

char op;
char ncliente[10][100], npet[10][100], tel[10][100], agendamentos[10][100], consultas[10][100];
int total_clientes = 0, total_agend = 0, total_consult = 0;
char mededata[100]; 

void nomepet();
void menu();
void Lara();
void banhoOUtosa();
void Consultas();
void relatorio();
void sair();

void nomepet() {
    printf("PetsuperLara-bcc\n\n");
}

void menu() {
    printf("Digite a opção desejada: \n\n 1- Cadastrar cliente \n 2- Agendar banho ou tosa \n 3- Consultas \n 4- Imprimir relatório geral \n 5- Sair\n");
    scanf(" %c", &op);

    switch(op) {
        case '1':
            nomepet();
            printf("Cadastro de cliente\n");
            Lara();
            break;
        case '2':
            nomepet();
            printf("Agendamentos de banho ou tosa\n");
            banhoOUtosa();
            break;
        case '3':
            nomepet();
            printf("Consultas\n");
            Consultas();
            break;
        case '4':
            nomepet();
            printf("Relatório\n");
            relatorio();
            break;
        case '5':
            sair();
            break;
        default:
            printf("opção incorreta. Tente novamente.\n");
            menu();
    }
}

void Lara() {
    if (total_clientes < 10) {
        printf("Digite o nome do cliente: ");
        scanf("%s", ncliente[total_clientes]);

        printf("Qual o nome do animazinho: ");
        scanf("%s", npet[total_clientes]);

        printf("Digite o telefone do cliente: ");
        scanf("%s", tel[total_clientes]);

        total_clientes++;
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Limite de clientes cadastrados atingidos.\n");
    }
    system("cls");
    menu();
}

void banhoOUtosa() {
    int pet, opb;

    if (total_agend < 10) {
        printf("Qual animalzinho? Escolha (1 a 10): ");
        scanf("%d", &pet);

        if (pet >= 1 && pet <= 10 && strlen(agendamentos[pet-1]) == 0) {
            printf("Pet: %s\n", npet[pet-1]);

            printf("O que deseja marcar?:\n\n 1- Banho\n 2- Tosa\n 3- Banho e tosa\n");
            scanf("%d", &opb);

            total_agend++;
            printf("Agendamento feito!\n");
        } else {
            printf("opção inválida\n");
        }
    } else {
        printf("Limite de agendamentos alcançados.\n");
    }
    
    system("cls");
    menu();
}

void Consultas() {
    int cliente;

    if (total_consult < 10) {
        printf("Clientes cadastrados: \n");
        for (int i = 0; i < total_clientes; i++) {
            printf("%d - %s\n", i+1, ncliente[i]);
        }

        printf("Qual cliente deseja marcar? (1 a %d): ", total_clientes);
        scanf("%d", &cliente);

        if (cliente >= 1 && cliente <= total_clientes) {
            int data;
            printf("Escolha o dia da consulta:\n 1- Quarta (Dra. Lara)\n 2- Sábado (Dr. Fabiano)\n");
            scanf("%d", &data);

            switch (data) {
                case 1:
                    strcpy(mededata, "Dra. Lara, Quarta-Feira\n");
                    break;
                case 2:
                    strcpy(mededata, "Dr. Fabiano, Sábado\n");
                    break;
                default:
                    printf("Opção incorreta. Tente novamente.\n");
            }
            total_consult++;
        } else {
            printf("Escolha inválida.\n");
        }
    } else {
        printf("Limite de consultas obtidas.\n");
    }

    system("cls");
    menu();
}

void relatorio() {
    printf("===========================\n");
    printf("Clientes cadastrados:\n");

    for (int i = 0; i < total_clientes; i++) {
        printf("%d - %s\n", i+1, ncliente[i]);
    }
    printf("===========================\n");
    
    printf("Agendamentos cadastrados:\n");
    for (int i = 0; i < total_agend; i++) {
        printf("Pet: %s\n", npet[i]);
    }
    printf("===========================\n");
    printf("Consultas cadastradas:\n");
    for (int i = 0; i < total_consult; i++) {
        printf("Cliente: %s, Data e médico: %s\n", ncliente[i], mededata);
    }
    system("pause");
    system("cls");
    menu();
}

void sair() {
    printf("PetsuperLara-bcc\n\n\n\n");
    system("pause");
    system("cls");
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    char senhaCorreta[] = "patinha";
    char senhaDigitada[100];

    while (1) {
        nomepet();
        printf("Seja bem vindo(a)\n");
        printf("Digite a senha: \n");
        scanf("%s", senhaDigitada);

        if (strcmp(senhaDigitada, senhaCorreta) == 0) {
            printf("Bem-vindo ao sistema.\n\n");
            menu();
        } else {
            nomepet();
            printf("Senha incorreta. Tente novamente.\n\n");
            system("pause");
            system("cls");
        }
    }

    return 0;
}
