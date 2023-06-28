#include <stdio.h>

void calcularPedido(int numero);
void formaPagamento(int numero);

int qtdeItens = 0;
double acumularPedido = 0, valorPagamento = 0;

int main(){

    int resposta = 1, pedido, formaDePagamento;
    double nota, troco, taxa; 

    printf("-------------------------------------------------------\n");
    printf("          SEJA BEM VINDO AS COXINHAS DOURADAS\n");
    printf("-------------------------------------------------------\n\n");
    printf("                      CARDAPIO:\n\n");
    
    printf("-------------------------------------------------------\n");
    printf("                      SALGADOS                         \n");
    printf("-------------------------------------------------------\n\n");
    printf("|         SABORES                | VALOR | |   CODIGO  |\n");
    printf("|Coxinha de frango:               R$6,50 ->     [1]    |\n");
    printf("|Enrolado de presunto e queijo:   R$6,50 ->     [2]    |\n");
    printf("|Coxinha de frango com catupiry:  R$8,80 ->     [3]    |\n");
    printf("|Coxinha de brocolis com catupiry R$8,80 ->     [4]    |\n");
    printf("|Coxinha de camarao:              R$9,60 ->     [5]    |\n");
    printf("|Coxinha de queijo com catupiry:  R$6,50 ->     [6]    |\n\n");
    printf("-------------------------------------------------------\n");
    printf("                      BEBIDAS                          \n");
    printf("-------------------------------------------------------\n\n");
    printf("|         TIPOS                  | VALOR | |  CODIGO   |\n");
    printf("|Agua:                            R$3,00 ->     [7]    |\n");
    printf("|Agua com gas:                    R$3,50 ->     [8]    |\n");
    printf("|Refrigerante:                    R$5,00 ->     [9]    |\n");
    printf("|Suco (lata):                     R$7,50 ->     [10]   |\n");
    printf("|Cerveja:                         R$5,00 ->     [11]   |\n\n");                   

    while (resposta == 1){
        
        printf("Codigo do pedido: ");
        scanf("%d", &pedido);
        
        qtdeItens += 1;
        calcularPedido(pedido);
        
        printf("Pressione [1] para adicionar mais itens ao pedido\nPressione [0] para encerrar o pedido\n");
        printf("-> ");
        scanf("%d", &resposta);

        while(resposta != 1 && resposta != 0){
            printf("Por favor, pressione apenas um dos numeros aceitos!\n");
            printf("[1] para adicionar mais itens ao pedido\n[0] para encerrar o pedido\n");
            printf("-> ");
            scanf("%d", &resposta);
        }
    }
    
    printf("\nSeu pedido deu o total de R$%.2lf!\n\n", acumularPedido);

    printf("---------------------------------------------------------------------------\n");
    printf("                      FORMAS DE PAGAMENTO:\n");
    printf("---------------------------------------------------------------------------\n\n");
    printf("|          FORMAS            |           TAXAS         |       CODIGO    |\n");
    printf("|Em dinheiro:                Sem acrescimo no valor.     ->     [1]      |\n");
    printf("|No cartao de debito:        3%% de acrescimo no valor.   ->     [2]      |\n");
    printf("|No cartao de credito:       5%% de acrescimo no valor.   ->     [3]      |\n");
    printf("|No cartao de credito em 2x: 10%% de acrescimo no valor.  ->     [4]      |\n");
    printf("---------------------------------------------------------------------------\n\n");
    
    printf("Codigo de pagamento: ");
    scanf("%d", &formaDePagamento);

    while(formaDePagamento < 1 || formaDePagamento > 4){
        printf("Por favor, insira apenas um dos codigos sugeridos na tabela!\n");
        printf("-> ");
        scanf("%d", &formaDePagamento);
    }

    formaPagamento(formaDePagamento);

    if(formaDePagamento == 1){
        printf("\nInforme a nota a ser entregue: ");
        scanf("%lf", &nota);
        troco = nota - acumularPedido;
        printf("\n-----------------------------------------------------------------------\n");
        printf("Seu pedido contem um total de %d item(s)\n", qtdeItens);
        printf("O valor total do pedido foi de R$%.2lf\n", acumularPedido);
        printf("De acordo com a forma do seu pagamento, voce devera pagar: R$%.2lf\n", valorPagamento);
        printf("Alem disso, voce recebera uma quantia de R$%.2lf de troco!\n", troco);
        printf("-----------------------------------------------------------------------\n");
    }else{
        taxa = valorPagamento - acumularPedido;
        printf("\n-----------------------------------------------------------------------\n");
        printf("Seu pedido contem um total de %d item(s)\n", qtdeItens);
        printf("O valor total do pedido foi de R$%.2lf\n", acumularPedido);
        printf("De acordo com a forma do seu pagamento, foi imposta uma taxa de R$%.2lf\n", taxa);
        printf("Voce devera pagar a quantia de R$%.2lf\n", valorPagamento);
        printf("-----------------------------------------------------------------------\n\n");
    }

    printf("\nMuito obrigado por consumir nas Coxinhas Douradas, volte sempre! :)\n");

    return 0;
}

void calcularPedido(int numero){
    switch (numero){
        case 1:
            acumularPedido += 6.50;
            break;
        case 2:
            acumularPedido += 6.50;
            break;
        case 3:
            acumularPedido += 8.80;
            break;
        case 4:
            acumularPedido += 8.80;
            break;
        case 5:
            acumularPedido += 9.60;
            break;
        case 6:
            acumularPedido += 6.50;
            break;
        case 7: 
            acumularPedido += 3.00;
            break;
        case 8:
            acumularPedido += 3.50;
            break;
        case 9:
            acumularPedido += 5.00;
            break;
        case 10:
            acumularPedido += 7.50;
            break;
        case 11:
            acumularPedido += 5.00;
            break;
        default:
            break;
    }
}

void formaPagamento(int numero){
    switch(numero){
        case 1:
            valorPagamento = acumularPedido;
            break;
        case 2:
            valorPagamento = acumularPedido + (0.03 * acumularPedido);
            break;
        case 3:
            valorPagamento = acumularPedido + (0.05 * acumularPedido);
            break;
        case 4:
            valorPagamento = acumularPedido + (0.10 * acumularPedido);
            break;
        default:
            break;
    }
}