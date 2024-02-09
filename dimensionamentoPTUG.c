#include <stdio.h>
#include <stdlib.h>

int calculaP_5m(float perimetro, float *r, int *qtddPontos){
    int ptug = perimetro/5;
    *r = perimetro - ptug*5;    //porque ptug é inteiro
    *qtddPontos = perimetro/5;
    if(*r != 0){
        ptug++;
    }
    return ptug;
}

int calculaP_3ponto5m(float perimetro, float *r, int *qtddPontos){
    int ptug = perimetro/3.5;
    *r = perimetro - ptug*3.5;
    *qtddPontos = perimetro/3.5;
    if(*r != 0){
        ptug++;
    }
    return ptug;
}

int main(){
  
    float d;          //dimensão
    float resto;      //variável p/ ser usada como referência
    int qtdd_pontos;  //variável p/ ser usada como referência
    float perimetro = 0;
    int potenciaVA = 0;
    int total;
    int resposta, resp;

    printf("---- DIMENSIONAMENTO DE PTUG'S ----\n\n");
    printf("\nSelecione:\n\n( 1 ) Banheiro");
    printf("\n( 2 ) Copa");
    printf("\n( 3 ) Area de servico");
    printf("\n( 4 ) Lavanderia (semelhantes)");
    printf("\n( 5 ) Cozinha");
    printf("\n( 6 ) Copa-cozinha");
    printf("\n( 7 ) Sala");
    printf("\n( 8 ) Quarto/Dormitorio\n\nDigite: ");
    scanf("%d", &resposta);

    if(resposta < 1 || resposta > 8){
      printf("\nComodo não encontrado, por favor reinicie o programa e tente novamente.");
      exit(1);
    }

    printf("\nQuantas dimensoes o comodo possui? ");
    scanf("%d", &resp);
    printf("\nDigite, em metros, o tamanho das dimenoes abaixo:\n");
      
    for(int i=0; i<resp; i++){
      printf("\n. Dimensao %d: ", i+1);
      scanf("%f", &d);
      perimetro += d;
    }

    switch(resposta){ 
      case 1: //potência de PTUG de banheiros (exceção)
        printf("\n---------------------------------------------------\n");
        printf("\nO numero de PTUG's sera de 1: \n");
        printf("\n\tPerimetro total: %.2f m \n", perimetro);
        printf("\n---------------------------------------------------\n");
        potenciaVA = 600; 
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6: 
        //recebe o nº de PTUG's
        total = calculaP_3ponto5m(perimetro,&resto,&qtdd_pontos); 
            
        printf("\n---------------------------------------------------\n");
        printf("\nO numero de PTUG's sera de %d: \n", total);
        printf("\n\tPerimetro total: %.2f m \n", perimetro);
        printf("\n\tSerao %d pontos separados a cada 3.5m\n", qtdd_pontos);
          if(resto != 0){
            printf("\n\tE com 1 ponto referente aos %.2f m restantes\n", resto);     
          } 
          printf("\n---------------------------------------------------\n");
            
          //calcula a potência
          for(int i=1;i<=total;i++){
            if(i<=3)
              potenciaVA += 600;
            else 
              potenciaVA += 100;    
          } 
           break;
        case 7:
        case 8:
          //recebe o nº de PTUG's
          total = calculaP_5m(perimetro,&resto,&qtdd_pontos);
            
          printf("\n---------------------------------------------------\n");
          printf("\nO numero de PTUG's sera de %d: \n", total);
          printf("\n\tPerimetro total: %.2f m \n", perimetro);
          printf("\n\tSerao %d pontos separados a cada 5m\n", qtdd_pontos);
          if(resto != 0){ 
               printf("\n\tE com 1 ponto referente aos %.2f m restantes\n", resto);
          } 
          printf("\n---------------------------------------------------\n");
            
          //calcula a potência
          for(int i=1;i<=total;i++){
            potenciaVA += 100;
          }
          break;
    }
  
    printf("\nPotencia Total do comodo (para PTUG's): %d VA", potenciaVA);
    printf("\n\n---------------------------------------------------\n");
    printf("\n\n\n*OBS.: calculos realizados conforme o Manual da Prysmian.\n");
  
    return 0; 
}