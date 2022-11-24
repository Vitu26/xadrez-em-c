#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;

char board[8][8] = {
                    { 'T' , 'C' , 'B' , 'K' , 'Q' , 'B' , 'C' , 'T' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 't' , 'c' , 'b' , 'k' , 'q' , 'b' , 'c' , 't' }
                    };

void display();
void change( int , int , int , int ) ;
void pawn(int , int ) ;
void rook(int , int ) ;
void horse(int , int ) ;
void camel( int , int ) ;
void king( int , int ) ;
void queen( int , int ) ;
void pawnb( int , int ) ;
void player1();
void player2();
int check(int , int ) ;
int check2(int , int ) ;

main()
{
setlocale(LC_ALL,"Portuguese");
int  x = 0 ;
char ch ;

    printf( "\n\tJOGO DE XADREZ" ) ;
    printf ( "\n\tAPERTE ENTER PARA CONTINUAR!");
    

    getch();
    system( "cls" ) ;

 do
 {
 x++ ;
 system( "cls" ) ;
 display();

 if( (x%2) == 0 )
 {
            player2();
 }
 else
 {
     player1();
 }

 printf( " \n\nAperte ENTER pra continuar! \n\n " ) ;

 ch = getch();
 }while( ch == 13 ) ;

}

void display()
{
    int i , j , k ;

    printf( " " ) ;
    for( i=0 ; i<8 ; i++ ) printf( "    %d" , i ) ; printf( "\n" ) ;

    for( k=0 ; k<8 ; k++ )
    {
    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k ) ;

    for( j=0 ; j<8 ; j++ ) { printf( "|| %c " , board[k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;

}

void change( int r1 , int c1 , int r2 , int c2 )
{
    char temp ;

    temp = board[r1][c1] ;
    board[r1][c1] = board[r2][c2] ;
    board[r2][c2] = temp ;

}

void pawn( int r1 , int c1 ) // paido
{
    pwstatus[c1]++;

    printf( "Espaços disponíveis: \n" ) ;

   if( pwstatus[c1] == 1 )
    {
        if( board[r1+1][c1] == ' ' )
        printf( "%d%d , " , r1+1 , c1 ) ;

        if( board[r1+2][c1] == ' ' )
        printf( "%d%d , " , r1+2 , c1 ) ;

    }
    else
    {
        if(board[r1+1][c1] == ' ' )
        printf( "%d%d , " , r1+1 , c1 ) ;

        if( check(r1+1 , c1+1) == 1 )
        printf( "%d%d* , " , r1+1 , c1+1 ) ;

        if( check(r1+1 , c1-1) == 1 )
        printf( "%d%d* , " , r1+1 , c1-1 ) ;
    }

}

void rook( int r1 , int c1 )
{
    int i , j , n ;

    printf( "Espaços disponíveis: \n" ) ;

    n=c1;

    printf( "Horizontal: \n" ) ;

    while( board[r1][n-1] == ' ' )
    {
        if( n == 0 ) { break ; }
        printf( "%d%d , " , r1 , n-1 ) ;
        n-- ;
    }

    n=c1 ;

    while( board[r1][n+1] == ' '  && (n+1) <= 7 )
    {

        printf( "%d%d , " , r1 , n+1 ) ;
        ++n ;
    }

    printf( "\nVertical:\n" ) ;

    n = r1 ;

    while( board[n-1][c1] == ' ' && n > -1 )
    {
        printf( "%d%d , " , n-1 , c1 ) ;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ') && ( (n) <= 7 ) )
    {
        printf( "%d%d , " , n+1 , c1 ) ;
        ++n ;
    }

}

void horse( int r1 , int c1 )
{
    printf( "Espaços disponíveis: " ) ;


    if( board[r1+2][c1+1] == ' ' ) printf( "%d%d, " , r1+2 ,c1+1) ;
    if( board[r1+2][c1-1] == ' ' ) { if( (c1-1) > -1 ) printf( "%d%d, " , r1+2, c1-1 ) ; }

    if( board[r1+1][c1+2] == ' ' ) {  if( (c1+2) != 8 ) printf( "%d%d, " , r1+1 , c1+2 ) ; }
    if( board[r1-1][c1+2] == ' ' ) {  printf( "%d%d, " , r1-1 , c1+2 ) ; }

    if( board[r1-2][c1-1] == ' ' )
    {
        if( (c1-1) != -1 )
        printf( "%d%d, " , r1-2 , c1-1 ) ;
    }

    if( board[r1-2][c1+1] == ' ' ) printf( "%d%d, " , r1-2 , c1+1 ) ;

    if( board[r1+1][c1-2] == ' ' ) printf( "%d%d, " , r1+1 , c1-2 ) ;

    if( board[r1-1][c1-2] == ' ' )
    {
        if( (c1-2) != -1 )
            printf( "%d%d, " , r1-1 , c1-2 ) ;
    }
}


void camel( int r1 , int c1 )
{
    int a , b , c , d ;
    printf( "Espaços disponíveis: \n" ) ;


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        a++ ;
        b++ ;
    }

}

void king( int r1 , int c1 )
{
    printf( "Espaços disponíveis: " ) ;
    if( board[r1][c1+1] == ' ' ) printf( "%d%d , " , r1 , c1+1 ) ;

    if( board[r1][c1-1] == ' ' ) printf( "%d%d , " , r1 , c1-1 ) ;

    if( board[r1+1][c1] == ' ' ) printf( "%d%d , " , r1+1 , c1 ) ;

    if( board[r1-1][c1] == ' ' ) printf( "%d%d , " , r1-1 , c1 ) ;

    if( board[r1+1][c1+1] == ' ' ) printf( "%d%d , " , r1+1 , c1+1 ) ;

    if( board[r1-1][c1-1] == ' ' ) printf( "%d%d , " , r1-1 , c1-1 ) ;

    if( board[r1-1][c1+1] == ' ' ) printf( "%d%d , " , r1-1 , c1+1 ) ;

    if( board[r1+1][c1-1] == ' ' ) printf( "%d%d , " , r1+1 , c1-1 ) ;
}

void queen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b ;
    printf( "Espaços disponíveis: " ) ;

    printf( "Horizontal: " ) ;

    while( board[r1][c1-y] == ' ' )
    {
        if( (c1-y) == -1 ) break ;
        printf( "%d%d , " , r1 , c1-y ) ;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' )
    {
        if( (c1+y) == 8 ) break ;
        printf( "%d%d , " , r1 , c1+y ) ;
        y++ ;
    }

    printf( "Vertical: " ) ;

    x = 1 ;

    while( board[r1-x][c1] == ' ' )
    {
        if( (r1-x) == -1 ) break ;
        printf( "%d%d , " , r1-x , c1 ) ;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' )
    {
        if( (r1+x) == 8 ) break ;
        printf( "%d%d , " , r1+x , c1 ) ;
        x++ ;
    }

    printf( "Diagonal: " ) ;

    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        a++ ;
        b++ ;
    }

}

void pawnb( int r1 , int c1 ) // paido black
{
    pbstatus[c1]++;

    printf( "Espaços disponíveis: \n" ) ;


    if( pbstatus[c1] == 1 )
    {
        if( board[r1-1][c1] == ' ' )
        printf( "%d%d , " , r1-1 , c1 ) ;

        if( board[r1-2][c1] == ' ' )
        printf( "%d%d , " , r1-2 , c1 ) ;
    }
    else
    {
        if(board[r1-1][c1] == ' ' )
        printf( "%d%d , " , r1-1 , c1 ) ;

        if( check2(r1-1 , c1-1) == 1 )
        printf( "%d%d* , " , r1-1 , c1-1 ) ;

        if( check2(r1-1 , c1+1) == 1 )
        printf( "%d%d* , " , r1-1 , c1+1 ) ;
    }

}

void player1()
{
    int p1 , p2 , c1 , r1 , c2 , r2;

    printf( "\nPLAYER 1 - Peças Maiúsculas\n" ) ;
    again1:
    printf( "\nInforme o local da peça que quer mover ( LC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
    {
        case 'P': pawn( r1 , c1 );
                  break ;
        case 'R': rook( r1 , c1 ) ;
                  break ;
        case 'H': horse( r1 , c1 );
                  break ;
        case 'C': camel( r1 , c1 );
                  break ;
        case 'K': king( r1 , c1 ) ;
                  break ;
        case 'Q': queen( r1 , c1 ) ;
                  break ;
        default: printf("Posição invalida ! ") ; goto again1 ;
    }

    printf( "\nEnter Informe para onde quer mover ( LC ): " ) ;
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    change(r1,c1,r2,c2) ;
}

void player2()
{
    int p1 , p2 , c1 , r1 , c2 , r2;

    printf( "\nPLAYER 2 - Peças minusculas \n") ;
    again2:
    printf( "\nEnter Informe a posição da peça que quer mover ( LC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;

    switch( board[r1][c1] )
    {
        case 'p': pawnb( r1 , c1 ) ;
                  break ;
        case 'r': rook( r1 , c1 ) ;
                  break ;
        case 'h': horse( r1 , c1 ) ;
                  break ;
        case 'c': camel( r1 , c1 ) ;
                  break ;
        case 'k': king( r1 , c1 ) ;
                  break ;
        case 'q': queen( r1 , c1 ) ;
                  break ;
        default: printf( "Posição ínvalida ! " ) ; goto again2 ;
    }


    printf( "\nEnter Informe o local para onde quer mover ( LC ): " ) ;
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    change(r1,c1,r2,c2) ;
}

int check(int x , int y )
{
    switch( board[x][y] )
    {
    case 'p':
    case 'r':
    case 'h':
    case 'c':
    case 'k':
    case 'q': return 1 ; break ;
    default: return 0 ;
    }
}

int check2(int x , int y )
{
    switch( board[x][y] )
    {
    case 'P':
    case 'R':
    case 'H':
    case 'C':
    case 'K':
    case 'Q': return 1 ; break ;
    default: return 0 ;
    }
}