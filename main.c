#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<locale.h>

#define WIDTH 640
#define HEIGHT 480



char xadrez[9][9] = {
	{' ', '1', '2', '3', '4', '5', '6', '7', '8'},
	{'1', 'T', 'C', 'B', 'K', 'Q', 'B', 'C', 'T'},
	{'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{'8', 't', 'c', 'b', 'q', 'k', 'b', 'c', 't'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}


};

int pintarTelaTexto();
int moverPeca();
int menu();




int main(){
    int x = 0;
    char ch;
    int aux, sair;

    int linOri, linDes, colOri, colDes;
    printf( "\n\tJOGO DE XADREZ" ) ;
    printf ( "\n\tAPERTE ENTER PARA CONTINUAR!");


    getch();
    system( "cls" ) ;

    printf( "\n\tPEÇAS MAIUSCULAS COMEÇAM" ) ;
    printf ( "\n\tAPERTE ENTER PARA CONTINUAR!");

    getch();
    system( "cls" ) ;
      do {
    aux = menu();
    if (aux == 1) {
        pintarTelaTexto();
        printf("\n");
        printf("Jogador 1(Maiúsculas) \n");
        printf("Informe a linha e coluna de origem: ");
        scanf("%d %d",&linOri, &colOri );
        printf("\nInforme a linha e coluna de destino: ");
        scanf("%d %d",&linDes, &colDes );
        system("cls");
        int resultado = moverPeca(linOri, colOri, linDes, colDes);
        if( resultado != 1){
        switch( resultado ) {
            case 9:
                printf("\n ERRO: Pe?a n?o pode ser movida deste jeito!");
                getch();
                break;
            case 0:
                printf("\nERRO : Coordenadas inv?lidas!");
                getch();
                break;
            case 1:
                break;
        }
      }

    } else
        if (aux == 2) {
           pintarTelaTexto();
           printf("\n");
           printf("Jogador 2 \n");
           printf("Informe a linha e coluna de origem: ");
           scanf("%d %d",&linOri, &colOri );
           printf("\nInforme a linha e coluna de destino: ");
           scanf("%d %d",&linDes, &colDes );
           system("cls");
           int resultado = moverPeca(linOri, colOri, linDes, colDes);
           if( resultado != 1){
           switch( resultado ) {
            case 9:
                printf("\n ERRO: Pe?a n?o pode ser movida deste jeito!");
                getch();
                break;
            case 0:
                printf("\nERRO : Coordenadas inv?lidas!");
                getch();
                break;
            case 1:
                break;
        }
      }


        } else
            if (aux == 3) {                  //acabar o jogo
              printf("\t ===================================\n");
              printf("\t |    OBRIGADO POR JOGAR !!!! =)   |\n");
              printf("\t ===================================");
              printf("\n\n\n");
              sair = 1;
            }

  }while(sair == 0);



  printf("\n\n\n\n");
  return 0;
}


int menu(){
      int opc;                    //OPÇÃO DO MENU
    printf("\n\n");
	printf ("============ MENU =========");
	printf ("\n\t1 - MOVER AS PEÇAS MAIÚSCULAS"); //JOGADOR 1
	printf ("\n\t2 - MOVER AS PEÇAS MINÚSCULAS");   // JOGADOR 2
	printf ("\n\t3 - ACABAR O JOGO");
	printf ("\n\n");

	scanf("%d", &opc);

  system("cls");

	return opc;
}




int pintarTelaTexto(){
    system("CLS");
    int lin, col, r;
    for(lin = 0; lin < 9; lin++){
        for(r = 0; r < 3; r++){//pintando 5 colunas e 3 linhas
            for(col = 0; col < 9; col++){
                char peca = xadrez[lin][col];//caracter que põe as peças na casinha certa
                char letra = ((lin + col) %2 == 0) ? '\xB2' : ' ';//conten celula preenchida ou espaço em branco
                letra = (r == 1 && peca != ' ') ? peca : letra;//para deixar a letra no centro da casa
                if((lin + col) %2 == 0){//detecta a celula que está pintando se é preenchuda ou vazia
                printf("\xB2\xB2%c\xB2\xB2",letra);
                }else{
                printf("  %c  ",letra);
                }
            }
            printf("\n");
        }
    }
}

int moverPeca( int linOri, int colOri, int linDes, int colDes) {
    int mover = 0;
    char peca;
    int dV = abs(linDes - linOri);//deslocamento vertical
    int dH = abs (colDes - colOri);//descolamento horizontal
    if((linOri >= 0 && linOri <= 8 && colOri >= 0 && colOri <= 8 ) &&
       (linDes >= 0 && linDes <= 8 && colDes >= 0 && colDes <= 8 )){
       peca = xadrez[linOri][colOri];

	   //movimento das torres
	   if((peca == 'T' || peca == 't') &&
           (dV == 0  || dH == 0)){
            mover = 1;
       }

       //movimento dos bispos
       if((peca == 'B' || peca == 'b') && (dV == dH) )
           {
            mover = 1;
       }

       //movimento dos cavalos
       if((peca == 'C' || peca == 'c') &&
           ((dV == 1 && dH == 2) || (dV == 2 && dH == 1) )){
            mover = 1;
       }

       //movimento da rainha
       if((peca == 'Q' || peca == 'q') &&
           ((dV == dV) || (dH == 0) || (dH == 0))){
            mover = 1;
       }

       //movimento do rei
       if((peca == 'K' || peca == 'k') &&
           ((dV >= 0 && dV <=1) && (dH >=0 && dH <=1))){
            mover = 1;
       }

       //movimento dos peao P
       if((peca == 'P') && ((linDes - linOri == 1) && (dH == 0)) && (linDes != ' ')){
            mover = 9;
        }else if ((peca == 'P') && ((linDes - linOri == 2) && (dH == 0)) && (linOri == 2)){
            mover = 1;
        }
        else if((peca == 'P') && ((linDes - linOri == 1) && (dH == 0))){
                mover = 1;
        }else if((peca == 'P') && (linDes != ' ') && ((linDes - linOri == 1) && (dH == dV))){
                mover = 1;
        }else{
            mover = 9;
        }

       //movimento do peao p
	   if((peca == 'p') && ((linOri - linDes == 1) && (dH == 0)) && (linDes != ' ')){
       	mover = 9;
       }else if((peca == 'p') && ((linOri - linDes == 2) && (dH == 0)) && (linOri == 7)){
           mover = 1;
       }else if((peca == 'p') && ((linOri - linDes == 1) && (dH == 0))){
            mover = 1;
       }else if((peca == 'P') && (linDes != ' ') && ((linOri - linDes == 1) && (dH == dV))){
                mover = 1;
       }else{
        mover = 9;
       }


        if(mover){
        xadrez[linDes][colDes] = xadrez[linOri][colOri];
        xadrez[linOri][colOri] = ' ';
        return 1;//movimento realizado
        }else{
        return 9;//pe?a n?o pode ser movida deste jeito
        }
    }else{
        return 0;
    }

}
