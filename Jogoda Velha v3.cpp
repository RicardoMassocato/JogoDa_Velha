#include <stdio.h> //entrada e saida; 
#include <stdlib.h> //conversões de números e lógicas;
#include <conio.h> //entrada e saída de dados ms-dos
#include <locale.h> //datas, moedas, número;
#include <windows.h> //Decl. de APIss windows;
#include <iostream>//entrada e saída; 
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
	
	for (contador = 0; contador < 9; contador++){ //Contador relacionadoas 9 opcoes para a demarcação do X ou O;
	
		do{	
			printf("\nJogador %d:", (contador%2) + 1);
			
			printf("\nInsira a sua linha (1 até 3): ");
			scanf("%d", &linha);
			fflush(stdout);
			linha--;
		
			printf("Insira a sua coluna (1 até 3): ");
			scanf("%d", &coluna);
			fflush(stdout);
			coluna--;
			
			if(coluna < 0 || coluna > 2){
				printf("\n Entre com o valor de 1 à 3!");
				Sleep(2500);
				system("cls");
			}
		}while(coluna < 0 || coluna > 2);
		
		putchar('\n');
		
		if(matriz[linha][coluna] == '.'){

			if(contador%2){/*O parâmetro 2 do resto da divisão dará 1 ou 0: Se for 1, equivale a true e entra no if, 
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
			
			if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != '.')|| //condição para vericar se venceu.
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != '.')||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != '.')||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != '.')||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != '.')||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != '.')||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != '.')||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] != '.')){

				printf("\nJogador %d venceu!", (contador%2) + 1);	/*O jogador que deveria ser 0 é acrescido de 1, tornando-se jogador 1*/
				exit(0);						/*O jogador que deveria ser 1 é acrescido de 1, tornando-se jogador 2*/
			}
			
		}
		else{
			printf("\nO Opção de espação já está marcado!\n Repita novamente.\n");
			contador--;
		}
		Sleep(3000);
		//system("cls");
	}
	printf("\nNinguém venceu!");
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
        cout << "  2.  Créditos:\n";
        cout << "\n";
        cout << "  3.  Sair\n";
        cout << "  ====================================\n";
        cout << "  Entre com o valor da opção: ";
        cin >> selection;

        switch (selection){
            case '1':
                cout << "Jogo da Velha. C++\n";
                cout << "\n";
                jogoVelha();
                break;

            case '2':
                cout << "Créditos.\n";
                cout << "\n";
                creditos();
				Sleep(2000);
				system("cls");
				break;
            case '3':
                cout << "Até mais!\n";
                selection = 3;
                Sleep(2000);
				system("cls");
				break;
            default: cout <<selection << " - é um valor não reconhecido pelo menu.\n";

               
        }
        Sleep(2000);
		system("cls");
    }while (selection != 3);

return 3;
}
