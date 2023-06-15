#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool EntradaValidaHexa(char hex[]) {
    for (int i = 0; hex[i] != '\0'; i++) {
        if (!((hex[i] >= '0' && hex[i] <= '9') ||    // Dígitos de 0 a 9 são válidos
              (hex[i] >= 'A' && hex[i] <= 'F') ||    // Letras maiúsculas de A a F são válidas
              (hex[i] >= 'a' && hex[i] <= 'f'))) {    // Letras minúsculas de a a f são válidas
            return false;
        }
    }
    return true;
}

bool validarStringBinaria(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

int validarEntrada(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return 0; // Caractere inválido encontrado
        }
    }
    return 1; // Entrada válida
}

int binarioParaDecimal(const char* binaria) {
    int decimal = 0, i = 0, restante, tamanho = 0;

    while (binaria[tamanho] != '\0') {
        tamanho++;
    }

    
    for (int i = tamanho - 1; i >= 0; i--) {
        if (binaria[i] == '1') {
            decimal += pow(2, tamanho - 1 - i);
        }
    }
    return decimal;
}

void decimalParaBinario(int decimal) {
    int binario[50];  // abri um vetor para armazenar os dígitos binários
    int i = 0;

    while (decimal > 0) {
        binario[i] = decimal % 2; // a operação decimal % 2 retorna o resto da divisão do número decimal por 2. O resultado será 0 ou 1, pois estamos fazendo uma divisão por 2.
        decimal = decimal / 2;
        i++;
    }

    printf("O número em binário é: ");
    for (int j = i - 1; j >= 0; j--) { // o j inicializa com o valor de i subtraindo 1 para começar com o valor mais alto
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void binarioParaHexadecimal(long long binario) {
    int decimal = 0, i = 0;
    long long resto;   //O tipo "long long" é um tipo de dado inteiro com sinal, o que significa que ele pode representar números negativos e positivos. Ele é geralmente usado quando é necessário armazenar números inteiros maiores do que o intervalo fornecido pelo tipo "int".
    char hexadecimal[50];
	
    while (binario != 0) {     //primeiro transforma binario para decimal
        resto = binario % 10;
        binario /= 10;
        decimal += resto * pow(2, i);
        i++;
    }

    i = 0;
    while (decimal != 0) {     //aqui transforma o decimal transformado la em cima em hexadecimal
        resto = decimal % 16;
        if (resto < 10) {
            hexadecimal[i] = resto + 48;  // Converte para caractere numérico
        } else {
            hexadecimal[i] = resto + 55;  // Converte para caractere alfabético (A-F)
        }
        decimal /= 16;
        i++;
    }
    
    printf("O número em hexadecimal é: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n\n");
}

void hexadecimalParaBinario(char hex[]) {
   int tamanho = strlen(hex);
   char caracter;

    // Verifica cada caractere
    for (int i = 0; i < tamanho; i++) {
        caracter = hex[i];

        // Verifica se o caractere é inválido
        if (!((caracter >= '0' && caracter <= '9') || (caracter >= 'A' && caracter <= 'F') || (caracter >= 'a' && caracter <= 'f'))) {
            printf("\nEntrada inválida! Digite apenas caracteres hexadecimais.\n");
            return; // Encerra a função sem fazer nenhum cálculo  
        }
    }

    printf("O número em binário é: ");
    for (int i = 0; i < tamanho; i++) {
        caracter = hex[i];

        switch (caracter) {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
        }
    }
    printf("\n\n");
}

void decimalParaHexadecimal(int decimal) {
    char hexadecimal[100];
    int i = 0;

    while (decimal > 0) {
        int resto = decimal % 16;
        if (resto < 10) {
            hexadecimal[i] = resto + '0'; // se resto for 0, a expressão resto + '0' resultará em '0', que é o caractere correspondente ao valor 48 na tabela ASCII. 
        } else {
            hexadecimal[i] = resto - 10 + 'A'; // se o valor do resto for 10, a expressão resto - 10 + 'A' se torna 10 - 10 + 'A', o que resulta no valor do caractere 'A'. Se o valor do resto for 15, a expressão se torna 15 - 10 + 'A', o que resulta no valor do caractere 'F'.
        }
        decimal /= 16;
        i++;
    }

    printf("O número em hexadecimal é: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n\n");
}

int hexadecimalParaDecimal(char hex[]) {
    int decimal = 0;
    int tamanho = 0;

    // Calcula o tamanho do número hexadecimal
    while (hex[tamanho] != '\0') {
        tamanho++;
    }

    // Converte cada dígito hexadecimal para decimal
    for (int i = 0; hex[i] != '\0'; i++) {
        tamanho--;

        if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * pow(16, tamanho);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * pow(16, tamanho);
        } else {
            decimal += (hex[i] - '0') * pow(16, tamanho);
        }
    }

    return decimal;
}

void voltarMenu (int voltar) {
	int escolha, decimal = 0, entradaValida = 0, i;
	char numBinario[100];
	bool caracter = false;
   	char binaria[100];
   	char entrada[100];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("__________________________________________\n");
	printf("_______________CALCULADORA________________\n");
	printf("__________________________________________\n\n");
    printf("\tEscolha uma Opção:\n");
    printf("\t1. Operação binário para decimal.\n");
    printf("\t2. Operação decimal para binário.\n");
    printf("\t3. Operação binário para hexadecimal.\n");
    printf("\t4. Operação hexadecimal para binário.\n");
    printf("\t5. Operação decimal para hexadecimal.\n");
    printf("\t6. Operação hexadecimal para decimal.\n\n");
    printf("\tDigite o número correspondente á sua escolha: ");
    
    if(scanf("%d", &escolha) != 1) {
    	printf("\nOpção inválida! Por favor insira um número entre 1 e 6.\n");
    	
    	while(getchar() != '\n');
	}
    
    system("cls");
 
 	switch (escolha) {
        case 1:
           do {
		        if (caracter) {
		            printf("\nNúmero binário inválido! Um número binário corresponde apenas a 0 e 1. Por favor, insira novamente.\n\n");
		        }
		        system("cls");
		        printf("Digite um número em binário: ");
		        scanf("%s", binaria);
		        
		        caracter = true;
		    } while (!validarStringBinaria(binaria) || (binaria[0] != '0' && binaria[0] != '1'));
			
		    if (binaria[0] == '0' && binaria[1] == '\0') {
      		  
		        
		    } else {
		        decimal = binarioParaDecimal(binaria);
		        printf("\nO número em decimal é: %d\n\n", decimal); 
		    }
    
    	   printf("Digite 1 para voltar ao menu: ");
       	   scanf("%d", &voltar);
        	
       	   system("cls");
        	
       	   voltarMenu (voltar);
           break;
            
        case 2:
        	while (!entradaValida) {
		        printf("Digite um número decimal: ");
		        scanf("%s", entrada);
				printf("\n");
				
		        if (validarEntrada(entrada)) {
		            decimal = atoi(entrada); // Converte a entrada para inteiro
		            entradaValida = 1;
		        } else {
		            system("cls");
		            printf("Número inválido! Digite apenas números decimais.\n\n");
		        }
		    }
		
		    decimalParaBinario(decimal);
		
    		printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
    		break;
  		     
        case 3:
        	long long binario;
        	
       	  while (true) {
	        printf("Digite um número binário: ");
	        scanf("%s", numBinario);
	
	        if (validarStringBinaria(numBinario)) {
	            long long binario = atoll(numBinario);
	            binarioParaHexadecimal(binario);
	            
	            if (binario == 0 || binario == 1) {
	                break;
            }
	            
	        } else {
	        	system("cls");
	        	(caracter);
                 printf("\nNúmero binário inválido! Um número binário corresponde apenas a 0 e 1. Por favor, insira novamente.\n\n"); 
                 continue;
	        } 
	        
			printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);	
	    }
			
        case 4:
           char hex[100];

		   while (1) {
	        printf("Digite um número hexadecimal: ");
	        scanf("%s", hex);
	        
	        printf("\n");
	
	        int tamanho = strlen(hex);
	        int valido = 1;
	
	        // Verifica cada caractere
	        for (int i = 0; i < tamanho; i++) {
	            char caracter = hex[i];
	
	            // Verifica se o caractere é inválido
	             
	            if (!((caracter >= '0' && caracter <= '9') || (caracter >= 'A' && caracter <= 'F') || (caracter >= 'a' && caracter <= 'f'))) {
	                printf("Entrada inválida! Digite apenas caracteres hexadecimais.\n\n");
	                valido = 0;
	                break;
	            }
	        }
	        
	        if (valido) {
	            hexadecimalParaBinario(hex);
			    printf("Digite 1 para voltar ao menu: ");
	        	scanf("%d", &voltar);
	        	
	        	system("cls");
	        	
	        	voltarMenu (voltar);
	            break;
	        }
	    }
		    
		case 5:
		    while (!entradaValida) {
		        printf("Digite um número decimal: ");
		        scanf("%s", entrada);
				printf("\n");
				
		        if (validarEntrada(entrada)) {
		            decimal = atoi(entrada); // Converte a entrada para inteiro
		            entradaValida = 1;
		        } else {
		            system("cls");
		            printf("Número inválido! Digite apenas números decimais.\n\n");
		            
		        }
		    }
		    
		    decimalParaHexadecimal(decimal);
		    
		    printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
			break;
			
        case 6:
            char hexadecimal[100];

		    while (true) {
		        printf("Digite um número hexadecimal: ");
		        scanf("%s", hexadecimal);
		
		        if (EntradaValidaHexa(hexadecimal)) {
		            break;
		        }
		
		        printf("\nEntrada inválida! Digite apenas os dígitos hexadecimais (0-9) e letras A-F ou a-f.\n");
		    }
       
       		system("cls");
       
		    decimal = hexadecimalParaDecimal(hexadecimal);
		    
		    printf("O número em decimal é: %d\n\n", decimal); 
			
		    printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
		    
			break;
			 
        default:
        	
        	printf("ERROR 404! Opção Inválida! Por favor digite uma opção de 1 a 6!\n");
        	
        	printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
    }
}

int main() {
    int escolha, decimal = 0, entradaValida = 0, i, voltar = 0;
    char numBinario[100];
    bool caracter = false;
   	char binaria[100];
   	char entrada[100];
    
	setlocale(LC_ALL, "Portuguese");

	printf("__________________________________________\n");
	printf("_______________CALCULADORA________________\n");
	printf("__________________________________________\n\n");
    printf("\tEscolha uma Opção:\n");
    printf("\t1. Operação binário para decimal.\n");
    printf("\t2. Operação decimal para binário.\n");
    printf("\t3. Operação binário para hexadecimal.\n");
    printf("\t4. Operação hexadecimal para binário.\n");
    printf("\t5. Operação decimal para hexadecimal.\n");
    printf("\t6. Operação hexadecimal para decimal.\n\n ");
    printf("\tDigite o número correspondente à sua escolha: ");
    
    if(scanf("%d", &escolha) != 1) {
    	printf("\nOpção inválida! Por favor insira um número entre 1 e 6.\n");
    	   //limpa o buffer do teclado
    	while(getchar() != '\n'); //é necessário para evitar caracteres inválidos
	}
	
	system("cls");
 
    switch (escolha) {
        case 1:
            do {
            	system("cls");
		        if (caracter) {
		            printf("\nNúmero binário inválido! Um número binário corresponde apenas a 0 e 1. Por favor, insira novamente.\n\n");
		        }
		        printf("Digite um número em binário: ");
		        scanf("%s", binaria);
		        
		        caracter = true;
		        
		    } while (!validarStringBinaria(binaria) || (binaria[0] != '0' && binaria[0] != '1'));
			
		    if (binaria[0] == '0' && binaria[1] == '\0') {
             
		    } else {
		        decimal = binarioParaDecimal(binaria);
		        printf("\nO número em decimal é: %d\n\n", decimal);
		    }
    
    	   printf("Digite 1 para voltar ao menu: ");
       	   scanf("%d", &voltar);
        	
       	   system("cls");
        	
       	   voltarMenu (voltar);
           break;
            
        case 2:
        	 while (!entradaValida) {
		        printf("Digite um número decimal: ");
		        scanf("%s", entrada);
				printf("\n");
				
		        if (validarEntrada(entrada)) {
		            decimal = atoi(entrada); // Converte a entrada para inteiro
		            entradaValida = 1;
		        } else {
		            system("cls");
		            printf("Número inválido! Digite apenas números decimais.\n\n");
		        }
		    }
		
		    decimalParaBinario(decimal);
		
    		printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
    		break;
  		     
        case 3:
        	long long binario;
        	
        	while (true) {
	        printf("Digite um número binário: ");
	        scanf("%s", numBinario);
	        
	        printf("\n");
	
	        if (validarStringBinaria(numBinario)) {
	            long long binario = atoll(numBinario);
	            binarioParaHexadecimal(binario);
	            
	            if (binario == 0 || binario == 1) {
	                break;
	            }
	        } else {
	        	system("cls");
	        	(caracter);
                 printf("\nNúmero binário inválido! Um número binário corresponde apenas a 0 e 1. Por favor, insira novamente.\n\n"); 
                 continue;
	        } 
			printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
	    }
 	 	    
        case 4:
        	char hex[100];

		   while (1) {
        printf("Digite um número hexadecimal: ");
        scanf("%s", hex);
        
        printf("\n");
		
        int tamanho = strlen(hex);
        int valido = 1;

        // Verifica cada caractere
        for (int i = 0; i < tamanho; i++) {
            char caracter = hex[i];
            
            // Verifica se o caractere é inválido
             
            if (!((caracter >= '0' && caracter <= '9') || (caracter >= 'A' && caracter <= 'F') || (caracter >= 'a' && caracter <= 'f'))) {
                printf("Entrada inválida! Digite apenas caracteres hexadecimais.\n\n");
                valido = 0;
                break;
            }
        }
		
        if (valido) {
        	
            hexadecimalParaBinario(hex);
		    printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
            break;
        }
    }
		    
		case 5:
			while (!entradaValida) {
		        printf("Digite um número decimal: ");
		        scanf("%s", entrada);
				printf("\n");
				
		        if (validarEntrada(entrada)) {
		            decimal = atoi(entrada); // Converte a entrada para inteiro
		            entradaValida = 1;
		        } else {
		            system("cls");
		            printf("Número inválido! Digite apenas números decimais.\n\n");
		        }
		    }
		    
		    decimalParaHexadecimal(decimal);
		    
		    printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
			break;
			
        case 6:
		     char hexadecimal[100];

		     while (true) {
		        printf("Digite um número hexadecimal: ");
		        scanf("%s", hexadecimal);
		
		        if (EntradaValidaHexa(hexadecimal)) {
		            break;
		        }
		
		        printf("\nEntrada inválida! Digite apenas os dígitos hexadecimais (0-9) e letras A-F ou a-f.\n\n");
		    }
		    
		    decimal = hexadecimalParaDecimal(hexadecimal);
		    
            printf("O número em decimal é: %d\n\n", decimal); 
		    
		    printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
        	
			break;
			 
        default:
        	
        	printf("ERROR 404! Opção Inválida! Por favor digite uma opção de 1 a 6!\n");
        	
        	printf("Digite 1 para voltar ao menu: ");
        	scanf("%d", &voltar);
        	
        	system("cls");
        	
        	voltarMenu (voltar);
        
        return 0;
    }
}
