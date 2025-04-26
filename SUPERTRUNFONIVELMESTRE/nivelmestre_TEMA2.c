#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (){
    //Declaração de variáveis principais
    char estado[5], ESTADO[5], codigo[25], CODIGO[25], nome[25], NOME[25];
    int populacao, POPULACAO, pontosturisticos, PONTOSTURISTICOS;
    float area, AREA, pib, PIB;
    //Menu inicial
    printf("### BEM VINDO AO SUPER TRUNFO *------* ####\n");
    int opcao;
    printf("Deseja Iniciar o Jogo?\n1. Sim\n2. Não\n");
    //Apresenta o menu e guarda a escolha do utilizador na variável opcao
    scanf("%d", &opcao);
    //Switch-case para controle do jogo
    switch (opcao){ //O switch permite executar diferentes blocos dependendo da escolha do utilizador para iniciar ou não o jogo.
    case 1:
    printf("VAMOS COMEÇAR! *-----* \n");
    //Entrada de Dados para primeira carta
    printf("DIGITE OS DADOS DA CIDADE PARA PRIMEIRA CARTA:\n");
    printf("Estado: ");
    scanf("%2s", estado);
    printf("Código: ");
    scanf("%s", codigo);
    getchar(); //Getchar para ler um caractere no teclado
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin); //Uso de scanf, fgets e strcspn para remover o \n
    nome[strcspn(nome, "\n")] = 0;
    printf("População: ");
    scanf("%d", &populacao);
    printf("Área por km²: ");
    scanf("%f", &area);
    printf("PIB: ");
    scanf("%f" , &pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosturisticos);
    //Entrada de Dados para segunda carta
    printf("\nDIGITE OS DADOS DA CIDADE PARA SEGUNDA CARTA:\n");
    printf("Estado: ");
    scanf("%2s", ESTADO);
    printf("Código: ");
    scanf("%s", CODIGO);
    getchar(); //Getchar para ler um caractere no teclado
    printf("Nome: ");
    fgets(NOME, sizeof(NOME), stdin); //Uso de scanf, fgets e strcspn para remover o \n
    NOME[strcspn(NOME, "\n")] = 0;
    printf("População: ");
    scanf("%d", &POPULACAO);
    printf("Área por km²: ");
    scanf("%f", &AREA);
    printf("PIB: ");
    scanf("%f" , &PIB);
    printf("Pontos Turísticos: ");
    scanf("%d", &PONTOSTURISTICOS);
    //Calculo automatico de densidade demográfica e PIB per capita com base nos dados introduzidos.
    float densidade = populacao / area;
    float DENSIDADE = POPULACAO / AREA;
    float percapita = pib / populacao;
    float PERCAPITA = PIB / POPULACAO;
    //Guarda os valores de forma organizada em arrays. O índice será usado para acesso rápido e comparação.
    float valorcarta1[7] = {populacao, area, pib, pontosturisticos, densidade, percapita, populacao + area + pib + pontosturisticos + densidade + percapita};
    float valorcarta2[7] = {POPULACAO, AREA, PIB, PONTOSTURISTICOS, DENSIDADE, PERCAPITA, POPULACAO + AREA + PIB + PONTOSTURISTICOS + DENSIDADE + PERCAPITA};
    //Arrays para nomes de cada propriedade para apresentar
    char *nomes[7] = {"Populacao", "Area", "Pib", "Pontos Turisticos", "Densidade Demografica", "PIB Percapita", "Super Poder"};

   
    printf("\nRESULTADO DE CADA PROPRIEDADE PARA CARTA 1\n");
    //Apresentação dos valores carta 1.  Mostra os atributos e os seus valores para cada carta.
    for (int i = 0; i < 7; i++) {
        printf("%s: %.2f\n", nomes[i], valorcarta1[i] );
    }

    printf("\nRESULTADO DE CADA PROPRIEDADE PARA CARTA 2\n");
    //Apresentação dos valores carta 2.  Mostra os atributos e os seus valores para cada carta.
    for(int i = 0; i < 7; i++){
        printf("%s: %.2f\n" , nomes[i], valorcarta2[i]);
    }
    printf("\n");
    // Escolha de dois atributos para comparar
     int atb1 , atb2;
     
     printf("Escolha um atributo:\n");
     for(int i = 0; i < 7; i++){
        printf("%d. %s\n" , i+1, nomes[i]);
     }
     scanf("%d", &atb1);
     atb1--;

     printf("Escolha um atributo:\n");
     for(int i = 0; i < 7; i++){
        if(i != atb1){  // Garante que o segundo atributo seja diferente
        printf("%d. %s\n" , i+1, nomes[i]);
       }
     } 
     scanf("%d", &atb2);
     atb2--;
     // Armazena os valores dos atributos escolhidos para as duas cartas
    float v1a = valorcarta1[atb1], v1b = valorcarta2[atb1]; // valores do primeiro atributo
    float v2a = valorcarta1[atb2], v2b = valorcarta2[atb2]; // valores do segundo atributo
    // Verifica se os atributos são válidos
    if (atb1 == atb2 || atb1 < 0 || atb1 > 6 || atb2 < 0 || atb2 > 6 )
    {
        printf("Atributo escolhido inválido! Saindo do Jogo...");
        return 1;
    }

   printf("\n*----- SOMANDO E COMPARANDO AS CARTAS -----*\n");
   //Soma dos dois atributos
   float soma1 = v1a + v2a;
   float soma2 = v1b + v2b;
   //Resultado das somas
   printf("%s: %s = %.2f | %s = %.2f / Resultado de Soma = %.2f\n" ,nome, nomes[atb1], v1a, nomes[atb2], v2a, soma1);
   printf("%s: %s = %.2f | %s = %.2f / Resultado de Soma = %.2f\n" ,NOME, nomes[atb1], v1b, nomes[atb2], v2b, soma2);
 // Verifica quem venceu
   if(soma1 > soma2){
    printf("%s VENCEU *-----*\n" , nome);
   } else if (soma2 > soma1){ 
    printf("%s VENCEU *-----*\n", NOME);
   } else {
    printf("EMPATE *#####*\n");
   }
   // Opção de comparar apenas um único atributo
   int escolha;
   printf("Deseja comparar um único Atributo?\n");
   printf("1. Sim\n2. Não\n");
   scanf("%d", &escolha);

   int atributo;
   if(escolha == 1){
    printf("Muito bem! Escolha um atributo abaixo...\n");
    for(int i = 0; i < 7; i++){
        printf("%d. %s\n", i+1, nomes[i]);
    }
    scanf("%d", &atributo);
    atributo--;

   if (atributo < 0 || atributo > 6){
    printf("\nAtributo inválido! Encerrando...\n");
    return 1;
    }
 }
   // Mostra a comparação individual
   printf("\n*----- Comparaçao por %s -----*\n" , nomes[atributo]);
   printf("%s : %s = %.2f | %s : %s = %.2f\n" , nome , nomes[atributo], valorcarta1[atributo], NOME, nomes[atributo], valorcarta2[atributo]);
   // Se for densidade, menor vence
   if(atributo == 4){
    if(valorcarta1[atributo] < valorcarta2[atributo]){
        printf("%s Venceu! (menor densidade) *-----*\n" , nome);
    }else if (valorcarta2[atributo] < valorcarta1[atributo]){
        printf("%s Venceu! (menor densidade) *-----*\n", NOME);
    } else{
      printf("Empate!\n");
      }
    }else {
        // Para os outros atributos, maior vence
        if(valorcarta1[atributo] > valorcarta2[atributo]){
            printf("%s Venceu! *------*\n" , nome);
        } else if(valorcarta2[atributo] > valorcarta1[atributo]){
            printf("%s Venceu! *------*\n" , NOME);
        } else {
            printf("Empate! \n");
        }
    }
    break;

    case 2:
    // Sai do jogo se o jogador escolheu 2
    printf("Saindo do jogo...\n");
    break;
    default:
    // Opção inválida no menu
     printf("Opção inválida!");
    break;
}
  //Finaliza
  return 0;
}