//ROBERTO CARLOS GUZM�N CORT�S  ISC
//A01702388
//FUNDAMENTOS DE PROGRAMACI�N
//DR. BENJAM�N VALD�Z AGUIRRE
//S�LO FUNCIONA EN WINDOWS
#include<windows.h>//--------------------------header file for gotoxy
#include <stdio.h>//---------------------------header file for standard input output
COORD coord={0,0};//---------------------------this is global variable
                  //---------------------------center of axis is set to the top left cornor of the screen

int  mat[9][9]; //-----------------------------Declaro mi matriz global para usarla donde se requiera
char mat2[9][9];//-----------------------------Segunda matriz para cuando quiera importar
int  mat[9][9]={
               {(int)NULL,2,6,7,4,1,9,3,8},{9,(int)NULL,3,5,2,8,7,6,1},{8,7,(int)NULL,6,3,9,2,4,5},
               {6,8,2,(int)NULL,5,7,1,9,3},{3,5,9,1,(int)NULL,6,4,2,7},{7,1,4,3,9,(int)NULL,8,5,6},
               {4,6,8,2,1,5,(int)NULL,7,9},{2,9,7,8,6,3,5,(int)NULL,4},{1,3,5,9,7,4,6,8,(int)NULL}
               };

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void despliega_ventana(){
    system("color 7");
    int i;
    for(i=1;i<100;i++){
        gotoxy(i,0); //-------------------------Borde arriba del titulo
        putchar(254); //------------------------Imprime guiones
    }

    for(i=1;i<100;i++){
        gotoxy(i,2);  //------------------------Borde abajo del titulo
        putchar(254); //------------------------Imprime cuadritos
    }

    for(i=1;i<100;i++){
        gotoxy(i,25); //------------------------Borde abajo del titulo
        putchar(254); //------------------------Imprime cuadritos
    }
    for(i=0;i<=25;i++){
        gotoxy(0,i);  //------------------------Borde lateral izquierdo
        putchar(254); //------------------------Imprime cuadritos
    }
    for(i=0;i<=25;i++){
        gotoxy(100,i);//------------------------Borde lateral derecho
        putchar(254); //------------------------Imprime cuadritos
    }

}
void despliega_titulo(char titulo[11]){
    int i;
    SetConsoleTitle("SUDOKU 1.0");//------------Cambio el t�tulo de mi ventana de programa de consola
    for(i=0; i<10;i++){
        gotoxy(45+i,1);
        putchar(titulo[i]);
    }
    printf("\n"); //----------------------------Me sirve para que el mensaje de programa termina no estorbe
}
void despliega_cuadricula(){
    int i, j, k;

    for(i=4;i<44;i+=4){//-----------------------Desplazamiento horizontal
        for(j=3;j<22;j++){//--------------------Desplazamiento vertical
            gotoxy(i,j);
            printf(":");
            if(i==4){   //----------------------Para crear un borde de puro ':'
                gotoxy(i-1,j);
                printf(":");
            }
            if(i==40){  //----------------------Para crear un borde de puro ':'
                gotoxy(i+1,j);
                printf(":");
            }

            if(i==16 || i==28){ //--------------S�lo en la l�nea 16 y 28 requiero este separador
                gotoxy(i,j);
                printf("|");
            }

            if(j%2!=0){ //----------------------Cuando j sea impar dibujar� de dos en dos las ASCII horizontales
                for(k=4; k<40;k+=2){
                    gotoxy(k,j);
                    printf("::");
                    if((k==16 || k==28)&& (j!=21 && j!=3)){ //S�lo en la l�nea 16 y 28 requiero este separador
                        gotoxy(k,j);                        //S�lo en la 3 y 21 no quiero imprimir "|"
                        printf("|");
                    }
                }
                if(j==9 || j==15){ //-----------Cuando j valga esto me sibujar� el separador de cuadrantes
                    for(k=5; k<40;k++){
                        gotoxy(k,j);
                        printf("=");
                    }//-------------------------Llave del for
                }//-----------------------------Llave del if 9,15
            }//---------------------------------Llave del if impar
        }//-------------------------------------Llave primer for "j"
    }//-----------------------------------------Llave segundo for "i"

    j=1;//--------------------------------------Imprimir acotaci�n de coordenadas verticales
    for(i=4;i<=20;i+=2){
        gotoxy(43,i);
        printf("[%i]",j);
        j++;
    }
    j=1;//--------------------------------------Imprimir acotaci�n de coordenadas horizontales
    for(i=5;i<40;i+=4){
        gotoxy(i,1);
        printf("[%i]",j);
        j++;
    }
}
void despliega_instrucciones(){
    gotoxy(50,3);
    printf("0) Para meter numeros aleatorios");
    gotoxy(50,5);
    printf("1) Para ingresar valores ");
    gotoxy(50,7);
    printf("2) Para revisar sudoku ");
    gotoxy(50,9);
    printf("3) Para borrar todo");
    gotoxy(50,11);
    printf("4) Para guardar");
    gotoxy(50,13);
    printf("5) Para importar sudoku");
    gotoxy(50,15);
    printf("6) Para salir ");
    gotoxy(50,17);
    printf("Opcion: ");
    gotoxy(50,19);
    printf("Coordenada x: ");
    gotoxy(50,20);
    printf("Coordenada y: ");
    gotoxy(50,22);
    printf("Entrada(0-9): ");
    gotoxy(50,24);
    printf("*Para borrar una casilla: Entrada=0");
    gotoxy(75,26);
    printf("*No maximizar la ventana,");
    gotoxy(75,27);
    printf(" se descompone la interfaz");
}
void llenar_aleatorio(int mat[9][9]){
    int i,j,a=0, b=0;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            mat[i][j]=1+rand()%9;
        }
    }
    for(i=6;i<=38;i+=4){
        for(j=4;j<=20;j+=2){
            if(a<8){
            gotoxy(i,j);
            printf("%i", mat[a][b]);
            a++;
            }
            else if(a==8){ //-------------------Necesito que a y b avancen como ciclo, por lo cual hago esto
                gotoxy(i,j);//------------------Me ubico en posici�n de consola
                printf("%i", mat[a][b]);//------Primero imprimo y luego modifico a y b como si fuera ciclo,
                                        //------as� lo de mat[a][b] y lo que muestro en consola ya concuerda con sudoku.txt
                b++; //B incrementar� s�lo hasta que a alcance el valor de 8 (novena posici�n 0-8), es decir saltar� a otra fila
                a=0;//--------------------------Columnas reinicio a cero
            }
        }
    }
}

//<-----------------------------------------------------COMPARACI�N L�GICA------------------------------------------------------>
void verificar_sudoku(int mat[9][9]){
    int i;
    if(verificar_columnas(mat)&&verificar_filas(mat)&&verificar_cuadrantes(mat)){//Con esto ya comprobar� si el sudoku
        gotoxy(17,23);                                                           //es correcto por:
        printf("COMPLETADO ");                                                   //*Columna
        gotoxy(0,26);                                                            //*Fila
        system("pause");                                                         //*Cuadrante 3x3
        for(i=1;i<57;i++){
            gotoxy(i,23);//----------------------Limpiar mensaje de status de revis�n del sudoku
            printf(" ");
            gotoxy(i-17,26);//-------------------Limpiar el mensaje que da el pause del sistema
            printf(" ");
        }
        return;
    }
    gotoxy(15,23);
    printf("INCOMPLETO");
    gotoxy(0,26);
    system("pause");
    for(i=14;i<57;i++){
        gotoxy(i,23);//--------------------------Limpiar mensaje de status de revisi�n del sudoku
        printf(" ");
        gotoxy(i-17,26);//-----------------------Limpiar el mensaje que da el pause del sistema
        printf(" ");
    }
    return;
}

int verificar_filas(int mat[9][9]){
    int i,j;
    int contador1=0, contador2=0;
    int contador3=0, contador4=0;
    int contador5=0, contador6=0;
    int contador7=0, contador8=0;
    int contador9=0;


    for(i=0; i<9;i++){
        for(j=0; j<9; j++){
            if(mat[i][j]=='1' || mat[i][j]==1){ //Con esto ir� comprobando la repeticion de cada d�gito
                contador1++;    //----------------por fila, donde i es la fila, j es la columna
            }
            else if(mat[i][j]=='2' || mat[i][j]==2 ){
                contador2++;
            }
            else if(mat[i][j]=='3' || mat[i][j]==3 ){
                contador3++;
            }
            else if(mat[i][j]=='4' || mat[i][j]==4 ){
                contador4++;
            }
            else if(mat[i][j]=='5' || mat[i][j]==5 ){
                contador5++;
            }
            else if(mat[i][j]=='6' || mat[i][j]==6 ){
                contador6++;
            }
            else if(mat[i][j]=='7' || mat[i][j]==7 ){
                contador7++;
            }
            else if(mat[i][j]=='8' ||  mat[i][j]==8 ){
                contador8++;
            }
            else if(mat[i][j]=='9' || mat[i][j]==9 ){
                contador9++;
            }
        }
    }
    if(contador1!=9 || contador2!=9 || contador3!=9 || contador4!=9 || contador5!=9 || contador6!=9 || contador7!=9 || contador8!=9 || contador9!=9){
        return 0;//-------------------------------Debo encontrar s�lo 9 veces cada d�gito
    }
    return 1;
}

int verificar_columnas(int mat[9][9]){
    int i,j;
    int contador1=0, contador2=0;
    int contador3=0, contador4=0;
    int contador5=0, contador6=0;
    int contador7=0, contador8=0;
    int contador9=0;


    for(i=0; i<9;i++){
        for(j=0; j<9; j++){
            if(mat[i][j]=='1' || mat[i][j]==1){ //Con esto ir� comprobando la repeticion de cada d�gito
                contador1++;    //----------------por fila, donde i es la fila, j es la columna
            }
            else if(mat[i][j]=='2' || mat[i][j]==2 ){
                contador2++;
            }
            else if(mat[i][j]=='3' || mat[i][j]==3 ){
                contador3++;
            }
            else if(mat[i][j]=='4' || mat[i][j]==4 ){
                contador4++;
            }
            else if(mat[i][j]=='5' || mat[i][j]==5 ){
                contador5++;
            }
            else if(mat[i][j]=='6' || mat[i][j]==6 ){
                contador6++;
            }
            else if(mat[i][j]=='7' || mat[i][j]==7 ){
                contador7++;
            }
            else if(mat[i][j]=='8' ||  mat[i][j]==8 ){
                contador8++;
            }
            else if(mat[i][j]=='9' || mat[i][j]==9 ){
                contador9++;
            }
        }
    }
    if(contador1!=9 || contador2!=9 || contador3!=9 || contador4!=9 || contador5!=9 || contador6!=9 || contador7!=9 || contador8!=9 || contador9!=9){
        return 0; //------------------------------Debo encontrar s�lo 9 veces cada d�gito
    }
    return 1;
}
                                                //1 ->->->      //4 ->->->      //7 ->->->
int verificar_cuadrantes(int mat[9][9]){          //->->->        //->->->        //->->->
    int i,j, a,b;                                 //->->->        //->->->        //->->->
    int contador1=0, contador2=0;
    int contador3=0, contador4=0;               //2 ->->->      //5 ->->->      //8 ->->->
    int contador5=0, contador6=0;                 //->->->        //->->->        //->->->
    int contador7=0, contador8=0;                 //->->->        //->->->        //->->->
    int contador9=0;
    for(a=0;a<=6;a+=3){                         //3 ->->->      //6 ->->->      //9 ->->->
        for(b=0;b<=6;b+=3){                       //->->->        //->->->        //->->->
            for(i=b;i<b+3;i++){                   //->->->        //->->->        //->->->

                for(j=a;j<a+3;j++){               //-----------ESTE EL ORDEN DE COMPROBACI�N POR CUADRANTES
                    if(mat[i][j]=='1' || mat[i][j]==1){ //-----Con esto ir� comprobando la repeticion de cada d�gito
                        contador1++;                    //-----por fila, donde i es la fila, j es la columna
                    }
                    else if(mat[i][j]=='2' || mat[i][j]==2 ){
                        contador2++;
                    }
                    else if(mat[i][j]=='3' || mat[i][j]==3 ){
                        contador3++;
                    }
                    else if(mat[i][j]=='4' || mat[i][j]==4 ){
                        contador4++;
                    }
                    else if(mat[i][j]=='5' || mat[i][j]==5 ){
                        contador5++;
                    }
                    else if(mat[i][j]=='6' || mat[i][j]==6 ){
                        contador6++;
                    }
                    else if(mat[i][j]=='7' || mat[i][j]==7 ){
                        contador7++;
                    }
                    else if(mat[i][j]=='8' ||  mat[i][j]==8 ){
                        contador8++;
                    }
                    else if(mat[i][j]=='9' || mat[i][j]==9 ){
                        contador9++;
                    }

                }
            }
        }
    }
    if(contador1!=9 || contador2!=9 || contador3!=9 || contador4!=9 || contador5!=9 || contador6!=9 || contador7!=9 || contador8!=9 || contador9!=9){
        return 0; //------------------------------Debo encontrar al menos nueve veces cada d�gito
    }
    return 1;
}
//<----------------------------------------------TERMINA COMPARACI�N L�GICA----------------------------------------------------->

void borrar_todo(int mat[9][9]){
    int i, j, a=0, b=0;

    for(i=0; i<9;i++){
        for(j=0;j<9;j++){
            mat[i][j]=(int)'\0'; //---------------Le indico que guarde un caracter nulo cuando hago reinicio
        }
    }

    for(i=6;i<=38;i+=4){
        for(j=4;j<=20;j+=2){
            gotoxy(i,j);
            printf("%c", mat[a][b]);
            a++;
            if(a==8){
                a=0;
                b++;
            }
        }
    }
}

void guardar(int mat[9][9]){
    FILE *p;
    int i, j;
    p=fopen("sudoku.txt","w");//------------------Le pondr�a por nombre sudoku1.0.txt pero podr�a causar confusi�n
                              //------------------por el uso de puntos
        for(i=0;i<9;i++){
            for(j=0; j<9;j++){
                    fprintf(p,"%i", mat[i][j]);
                    if(j==8 && i<j){
                        fprintf(p,"\n");
                    }
            }
        }
        gotoxy(17,23);
        printf("GUARDADO: 'sudoku.txt'");
        gotoxy(0,26);
        system("pause");
        for(i=17;i<57;i++){
            gotoxy(i,23);//-----------------------Limpiar mensaje de estatus del sudoku
            printf(" ");
            gotoxy(i-17,26);//--------------------Limpiar el mensaje que da el pause del sistema
            printf(" ");
        }
    fclose(p);
}

void importar(char archivo[15], char mat2[9][9]){
    FILE *p;
    char car;
    int i,j;
    int c=0;
    p=fopen(archivo,"r");
    if(p==NULL){//-------------------------------Por si no encuentra el archivo
        gotoxy(57,17);
        printf(" No file ");
        for(i=66;i<120;i++){//-------------------Limpia el nombre del archivo que no existe
            if(i!=100){
                gotoxy(i,17);
                printf(" ");
            }
        }
        gotoxy(0,26);
        system("pause");

        for(i=0;i<60;i++){//---------------------Limpia el msj del system pause
            gotoxy(i,26);
            printf(" ");
        }
        fclose(p);
        return;
    }

    while(!feof(p)){
        for(i=0; i<10;i++){//---------------------Debo que recorrer 10 espacios, puesto que cada linea tiene 9 caracteres
            for(j=0; j<10;j++){//-----------------m�s el null '\0', ser�an 10 caracteres por l�nea
                fscanf(p,"%c",&car);
                c++;
                if(car>='0' && car<='9' || car>=0 && car<=9){
                mat2[i][j]=car;
                }
            }
        }
    }

    for(i=0;i<9;i++){ //--------------------------Debo leer m�s l�neas porque toda cadena guarda un null al final
        for(j=0;j<9;j++){
            mat[i][j]=(int)mat2[i][j]-48; //------Debo hacer la conversi�n en ASCII, es decir,
        }                                 //------1=49 en ASCII cuando lo paso de char a int
    }                                     //------en consecuencia 1 ya valdr� 1
                                          //------as� mat y mat2  ya habr�n intercambiado valores correctamente
    fclose(p);
    llenar(mat2);
}
int llenar(char mat2[9][9]){ //-------------------Si declaro esto como void me arroja un msj de WARNING
    int i,j, a=0, b=0;
    for(i=6;i<=38;i+=4){
        for(j=4;j<=20;j+=2){
            if(a<8){
                 if(mat[a][b]==0){//--------------Si hay un cero, lo mete en la matriz,
                    gotoxy(i,j);  //--------------pero muestra " " en dicha coordenada en consola
                    printf(" ");
                 }
                 else if(mat[a][b]!=0){
                    gotoxy(i,j);
                    printf("%c", mat2[a][b]);
                 }
                 a++;            //---------------Pero siempre hace el incremento correspondiente
            }
            else if(a==8){       //---------------Necesito que a y b avancen como ciclo, por lo cual hago esto
                if(mat[a][b]==0){//---------------Si hay un cero, lo mete en la matriz,
                    gotoxy(i,j); //---------------pero muestra " " en dicha coordenada en consola
                    printf(" ");
                 }
                 else if(mat[a][b]!=0){
                    gotoxy(i,j);             //---Me ubico en posici�n de consola
                    printf("%c", mat2[a][b]);//---Primero imprimo y luego modifico a y b como si fuera ciclo,
                 }                           //---as� lo de mat[a][b] y lo que muestro en consola ya concuerda con sudoku.txt
                 b++; //--------------------------B incrementar� s�lo hasta que a alcance el valor de 8 (novena posici�n 0-8),
                 a=0; //--------------------------Columnas reinicio a cero
            }
        }
    }
}

int vista_principal(int mat[9][9]){  //-----------Con esto despliego la matriz que traer� siempre por default

    int i,j,a=0,b=0;                 //-----------este programa, los las localidades de la matriz mat[n][m]
    for(i=6;i<=38;i+=4){             //-----------se pueden modificar de modo que tenga m�s o menos localidades
            for(j=4;j<=20;j+=2){     //-----------por llenar, es decir, reemplazar los null (o ceros dependiendo)
                if(a<8){             //-----------por valores del 1-9, u otros ceros para "borrar" en consola
                    if(mat[a][b]!=0){
                        gotoxy(i,j);
                        printf("%i", mat[a][b]);
                    }
                    a++;
                }
                else if(a==8){ //-----------------Necesito que a y b avancen como ciclo, por lo cual hago esto
                    if(mat[a][b]!=0){
                        gotoxy(i,j);//------------Me ubico en posici�n de consola
                        printf("%i", mat[a][b]);//Primero imprimo y luego modifico a y b como si fuera ciclo,
                                                //as� lo de mat[a][b] y lo que muestro en consola ya concuerda con sudoku.txt

                    }
                    b++; //-----------------------B incrementar� s�lo hasta que a alcance el valor de 8 (novena posici�n 0-8),
                    a=0;//------------------------Columnas reinicio a cero
                }
            }
        }
}
void limpiar(){
    int i;

    for(i=57;i<=120;i++){//-------------------Limpiar entradas
            if(i!=100){//---------------------S�lo no quiero que se pierda el cuadrito de la "ventana"
                gotoxy(i,17);
                printf(" ");
            }
        }

        gotoxy(100,17);//---------------------Preveer que
        printf("%c",254);//-------------------un cuadrito se pierda cuando leo archivo
                         //-------------------Generalmente se pierde cuando se quiere usar la funci�n importar algo

        for(i=63;i<=93;i++){//----------------Limpiar entradas
            gotoxy(i,19);
            printf(" ");
        }

        for(i=63;i<=93;i++){//----------------Limpiar entradas
            gotoxy(i,20);
            printf(" ");
        }

        for(i=18;i<26;i++){
            gotoxy(0,i);//-----------------------Preveer que los cuadritos
            printf("%c",254);//-------------------udel 18-25 de la cuadr�cula se pierdan
        }

        for(i=63;i<=93;i++){//----------------Limpiar entradas
            gotoxy(i,22);
            printf(" ");
        }
}

int main(){
    char titulo[11]="SUDOKU 1.0";//---------------------------Longitud de cadena vale 11 = 10 + el null
    int valorx, valory, digito;
    int i,j;
    char opc;
    char archivo[15];
    srand(time(NULL));
    system("mode 120,30");//----------------------------------Redimensiono la ventana con comando mode (120 cols x 30 rows)
    despliega_ventana();
    despliega_titulo(titulo);
    despliega_cuadricula();
    despliega_instrucciones();
    vista_principal(mat);
//<-------------------------------------------------------PARTE CONTROL---------------------------------------------------------->
        do{
        gotoxy(57,17);//--------------------------------------Aqu� se va a ubicar para pedirme la opcion a elegir
        scanf("%c%*c", &opc);
        switch(opc){
            case '\n':
                gotoxy(57,18);
                break;
            case '0':
                llenar_aleatorio(mat);
                break;
            case '1':
                gotoxy(63,19);
                scanf("%i%*c", &valorx);
                gotoxy(63,20);
                scanf("%i%*c", &valory);
                if((valorx>=1 && valorx<=9) && (valory>=1 && valory<=9)){
                    gotoxy(63,22);
                    scanf("%i%*c", &digito);
                    if(digito>0 && digito<10){
                        gotoxy((valorx*4)+2,(valory*2)+2);//--Constantes que relacionan el valor de gotoxy con la coordenada y el
                        printf("%i", digito);             //--digito que ingrese el usuario
                        mat[valorx-1][valory-1]=digito;//-----Debo restar uno porque toda matriz empieza por mat[0][0]
                    }                                  //-----Por ello resto 1
                    else if(digito==0){
                        gotoxy((valorx*4)+2,(valory*2)+2);
                        printf(" ");                    //----Imprimir� un espacio en mi cuadr�cula
                        mat[valorx-1][valory-1]=digito; //----Pero si guardar� el cero en la matriz
                    }
                }
                break;
            case '2':
                verificar_sudoku(mat);
                break;
            case '3':
                borrar_todo(mat);
                break;
            case '4':
                guardar(mat);
                break;
            case '5':
                gotoxy(57,17);
                printf(" Archivo: ");
                scanf("%s%*c", archivo);
                importar(archivo, mat2);
                gotoxy(28,28);
                break;
            case '6':

                break;
            default:
                gotoxy(57,17);
                printf(" No option ");
                gotoxy(0,26);
                system("pause");
                for(i=57;i<=107;i++){//------------------------Limpiar entradas si elegiste algo que no estaba contemplado
                    gotoxy(i,17);   //-------------------------como caso del switch
                    printf(" ");
                }
                for(i=0;i<=50;i++){
                    gotoxy(i,26);
                    printf(" ");
                }
                break;
        }
//<-------------------------------------------------TERMINA SWITCH Y CONTROL---------------------------------------------------->

        limpiar();//-------------------------------------------Limpiar las entradas

        }while(opc!=54);//-------------------------------------Si pulso el n�mero 6 se sale 54=6 en ASCII
    gotoxy(0,26);//--------------------------------------------Antes de salir del main escribe un mensaje fuera de la cuadr�cula
    printf("Goodbye");

    return 0;
}

//<------------------------------------------------------------------------------------------------------------------------------>
                                //ESTO ERA PARA HACER UN TEST DE MAT[9][9]
                            /*
                                for(i=0;i<9;i++){
                                                    for(j=0;j<9;j++){
                                                        printf("%i", mat[i][j]);
                                                        if(j==8){
                                                            printf("\n");
                                                        }
                                                    }
                                                }
                            */
