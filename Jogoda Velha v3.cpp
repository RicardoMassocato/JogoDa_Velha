#include <stdio.h> //entrada e saida; 
#include <stdlib.h> //convers�es de n�meros e l�gicas;
#include <conio.h> //entrada e sa�da de dados ms-dos
#include <locale.h> //datas, moedas, n�mero;
#include <windows.h> //Decl. de APIss windows;
#include <iostream>//entrada e sa�da; 
using namespace std;

int jogoVelha ( ){
	int i, j, linha, coluna, contador;
	char matriz[3][3];
	setlocale(LC_ALL,"portuguese"); 

	for(i = 0; i < 3; i++){
		putchar('\n');
		for(j = 0; j < 3; j++){
			putchar('\t');
			matriz[i][j] = '.';
			printf("%c", matriz[i][j]);
		}
		putchar('\n');
		putchar('\n');
	}
	system("cls");
	
	for (contador = 0; contador < 9; contador++){ //Contador relacionadoas 9 opcoes para a demarca��o do X ou O;
	
		do{	
			printf("\nJogador %d:", (contador%2) + 1);
			
			printf("\nInsira a sua linha (1 at� 3): ");
			scanf("%d", &linha);
			fflush(stdout);
			linha--;
		
			printf("Insira a sua coluna (1 at� 3): ");
			scanf("%d", &coluna);
			fflush(stdout);
			coluna--;
			
			if(coluna < 0 || coluna > 2){
				printf("\n Entre com o valor de 1 � 3!");
				Sleep(2500);
				system("cls");
			}
		}while(coluna < 0 || coluna > 2);
		
		putchar('\n');
		
		if(matriz[linha][coluna] == '.'){

			if(contador%2){/*O par�metro 2 do resto da divis�o dar� 1 ou 0: Se for 1, equivale a true e entra no if, 
			                *se for 0 equivale a false e entra no else*/
				matriz[linha][coluna] = 'O';
			} 
			else{
				matriz[linha][coluna] = 'X';
			}
			
			for(i = 0; i < 3; i++){
				putchar('\n');
				for(j = 0; j < 3; j++){
					putchar('\t');
					printf("%c", matriz[i][j]);
				}
				putchar('\n');
				putchar('\n');
			}
			
			if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != '.')|| //condi��o para vericar se venceu.
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != '.')||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != '.')||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != '.')||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != '.')||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != '.')||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != '.')||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] != '.')){

				printf("\nJogador %d venceu!", (contador%2) + 1);	/*O jogador que deveria ser 0 � acrescido de 1, tornando-se jogador 1*/
				exit(0);						/*O jogador que deveria ser 1 � acrescido de 1, tornando-se jogador 2*/
			}
			
		}
		else{
			printf("\nO Op��o de espa��o j� est� marcado!\n Repita novamente.\n");
			contador--;
		}
		Sleep(3000);
		//system("cls");
	}
	printf("\nNingu�m venceu!");
	exit(0);
}

int creditos(){
	cout << "Este jogo foi produzido por: #Eu_Mesmo_:D";
}


/*Teste sem menu:

int main(void){
	jogoVelha();
}*/

int main(){
    char selection;
	setlocale(LC_ALL,"portuguese"); 
    
	do{
        cout << "  Bem vindo ao Menu\n";
        cout << "  ====================================\n";
        cout << "  1.  Jogar o jogo da velha.\n";
        cout << "  2.  Cr�ditos:\n";
        cout << "\n";
        cout << "  3.  Sair\n";
        cout << "  ====================================\n";
        cout << "  Entre com o valor da op��o: ";
        cin >> selection;

        switch (selection){
            case '1':
                cout << "Jogo da Velha. C++\n";
                cout << "\n";
                jogoVelha();
                break;

            case '2':
                cout << "Cr�ditos.\n";
                cout << "\n";
                creditos();
				Sleep(2000);
				system("cls");
				break;
            case '3':
                cout << "At� mais!\n";
                selection = 3;
                Sleep(2000);
				system("cls");
				break;
            default: cout <<selection << " - � um valor n�o reconhecido pelo menu.\n";

               
        }
        Sleep(2000);
		system("cls");
    }while (selection != 3);

return 3;
}
