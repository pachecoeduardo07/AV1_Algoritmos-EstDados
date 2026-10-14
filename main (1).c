#include <stdio.h>

int main () {
    float resistor;
    float vetor[10];
    int quantidade = 0;
    int opcao = 0;
    float resistorbusca = 0;
    int indice;
    int encontrado = 0;
    float resistoralterado;
    int ver_cores;
    int qtd_adicionar;
    do {
        printf("\nMenu para armazenar resistores");
        printf("\nAdicionar os resistores(1)");
        printf("\nBuscar(2)");
        printf("\nMudar(3)");
        printf("\nDeletar(4)");
        printf("\nEncerrar(5)\n");
        
        
        if (scanf("%d", &opcao) != 1) {
            printf("ERRO: Entrada invalida! Por favor, digite apenas numeros.\n");
            while (getchar() != '\n'); 
            continue; 
        }
       
       if(opcao == 1){
            if (quantidade >= 10) {
                printf("\nERRO: O sistema ja atingiu o limite maximo de 10 resistores!\n");
                continue;
            }

            printf("\nQuantos resistores deseja adicionar agora? (Espacos livres: %d): ", 10 - quantidade);
            if (scanf("%d", &qtd_adicionar) != 1) {
                printf("\nERRO: Entrada invalida! Use apenas numeros.\n");
                while (getchar() != '\n');
                continue;
            }

            if (qtd_adicionar <= 0 || (quantidade + qtd_adicionar) > 10) {
                printf("\nERRO: Quantidade invalida! Voce pode adicionar entre 1 e %d resistores.\n", 10 - quantidade);
                continue;
            }

            int adicionados_agora = 0;
            
            while (adicionados_agora < qtd_adicionar) {
                printf("\nDigite o valor do resistor %d (em kohm, max 10): ", quantidade + 1);
                
                if (scanf("%f", &resistor) != 1) {
                    printf("\nERRO: Entrada invalida! Use apenas numeros.\n");
                    while (getchar() != '\n');
                    continue; 
                }
               
                if (resistor > 10.0) {
                    printf("\nERRO: O valor limite e de 10 kohm! Tente novamente.\n");
                    continue; 
                }
                if (resistor < 0.0) {
                    printf("\nERRO: O valor nao pode ser negativo! Tente novamente.\n");
                    continue;
                }
               
                vetor[quantidade] = resistor;
                quantidade++;
                adicionados_agora++;
            }
            
            printf("\nOs valores dos resistores sao: ");
            for(int i=0; i < quantidade; i++) {
                printf("%.1f kohm ", vetor[i]);
            }
        }
    
        else if (opcao == 2){
            encontrado = 0;
           
            printf("\nDigite o resistor a ser buscado (em kohm): ");
            
            if (scanf("%f", &resistorbusca) != 1) {
                printf("\nERRO: Entrada invalida! Operacao cancelada.\n");
                while (getchar() != '\n');
                continue;
            }
           
            for(int i=0; i < quantidade; i++){
                if(vetor[i] == resistorbusca){
                    printf("\nO resistor %.2f kohm foi encontrado na posicao %d", resistorbusca, i);
                    encontrado = 1;
                    
                    printf("\nDeseja checar a sequencia de cores desse resistor? (1 - Sim / 0 - Nao): ");
                    
                    if (scanf("%d", &ver_cores) != 1) {
                        printf("\nEntrada invalida! Assumindo 'Nao'.\n");
                        while (getchar() != '\n');
                        ver_cores = 0;
                    }
                    
                    if (ver_cores == 1) {
                        int valor_ohms = (int)(vetor[i] * 1000.0 + 0.5);
                        int cor1, cor2, multiplicador;

                        if (valor_ohms >= 10000) { 
                            cor1 = 1; cor2 = 0; multiplicador = 3; 
                        } else if (valor_ohms >= 1000) { 
                            cor1 = valor_ohms / 1000;          
                            cor2 = (valor_ohms / 100) % 10;    
                            multiplicador = 2;                 
                        } else if (valor_ohms >= 100) { 
                            cor1 = valor_ohms / 100;           
                            cor2 = (valor_ohms / 10) % 10;     
                            multiplicador = 1;                 
                        } else { 
                            cor1 = valor_ohms / 10;            
                            cor2 = valor_ohms % 10;            
                            multiplicador = 0;                 
                        }

                        printf("\n Cores: ");
                        for (int j = 0; j < 3; j++) {
                            int cor_atual;
                            if (j == 0) cor_atual = cor1;
                            else if (j == 1) cor_atual = cor2;
                            else cor_atual = multiplicador;
                            
                            if (cor_atual == 0) printf("Preto");
                            else if (cor_atual == 1) printf("Marrom");
                            else if (cor_atual == 2) printf("Vermelho");
                            else if (cor_atual == 3) printf("Laranja");
                            else if (cor_atual == 4) printf("Amarelo");
                            else if (cor_atual == 5) printf("Verde");
                            else if (cor_atual == 6) printf("Azul");
                            else if (cor_atual == 7) printf("Violeta");
                            else if (cor_atual == 8) printf("Cinza");
                            else if (cor_atual == 9) printf("Branco");
                            
                            if (j < 3) printf(" | ");
                        }
                    }
                    break;
                }
            }
            if(!encontrado){
                printf("\nNao ha esse resistor no sistema!");
            }
        }
       else if(opcao == 3){
            if (quantidade == 0) {
                printf("\nNao ha resistores para mudar!\n");
            } else {
                printf("\nResistores armazenados:\n");
                for(int i = 0; i < quantidade; i++){
                    printf("Indice [%d] -> %.1f kohm\n", i, vetor[i]);
                }
                
                printf("\nDigite o indice do resistor que deseja mudar (0 a %d): ", quantidade - 1);
                if (scanf("%d", &indice) != 1) {
                    printf("\nERRO: Entrada invalida! Operacao cancelada.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                if (indice >= 0 && indice < quantidade) {
                    printf("Digite o valor do novo resistor (em kohm, max 10): ");
                    
                    if (scanf("%f", &resistoralterado) != 1) {
                        printf("\nERRO: Entrada invalida! Operacao cancelada.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    
                    if (resistoralterado > 10.0) {
                        printf("\nERRO: O valor limite e de 10 kohm! Operacao cancelada.\n");
                        continue; 
                    }
                    if (resistoralterado < 0.0) {
                        printf("\nERRO: O valor nao pode ser negativo! Operacao cancelada.\n");
                        continue;
                    }
                    
                    vetor[indice] = resistoralterado;
                    
                    printf("\nResistor alterado com sucesso!\n");
                    printf("Os novos valores dos resistores sao: ");
                    for(int i = 0; i < quantidade; i++){
                        printf("%.1f kohm ", vetor[i]);
                    }
                    printf("\n");
                } else {
                    printf("\nERRO: Indice invalido!\n");
                }
            }
        }
       else if(opcao == 4){
            if (quantidade == 0) {
                printf("\nNao ha resistores para deletar!\n");
            } else {
                printf("\nResistores armazenados:\n");
                for(int i = 0; i < quantidade; i++){
                    printf("Indice [%d] -> %.1f kohm\n", i, vetor[i]);
                }
                
                printf("\nDigite o indice do resistor a ser deletado (0 a %d): ", quantidade - 1);
                if (scanf("%d", &indice) != 1) {
                    printf("\nERRO: Entrada invalida! Operacao cancelada.\n");
                    while (getchar() != '\n');
                    continue;
                }
               
                if(indice >= 0 && indice < quantidade){
                    for(int i = indice; i < quantidade - 1; i++){
                        vetor[i] = vetor[i + 1];
                    }
                    quantidade--;
                    printf("\nResistor deletado com sucesso!\n");
                    printf("Os valores restantes sao: ");
                    if(quantidade == 0){
                         printf("Vazio.\n");
                    } else {
                         for(int i = 0; i < quantidade; i++){
                             printf("%.1f kohm ", vetor[i]);
                         }
                         printf("\n");
                    }
                } else {
                    printf("\nERRO: Indice invalido!\n");
                }
            }
        }
       
    } while( opcao != 5);
    
    return 0;  
}