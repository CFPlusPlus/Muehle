//Diese Header-Datei beinhaltet einige Ausgaben für das Spiel Muehle
//(c)Jakob Graf; Januar 2020

//Startscreenausgabe 
void startscreen()
{
    printf("##############################################################\n");
    printf("#                                                            #\n");
    printf("#                         M \x9A H L E                          #\n");
    printf("#                                                            #\n");
    printf("#    Entwicklung: Christian Falkner und Jakob Graf; 2020     #\n");
    printf("#                                                            #\n");
    printf("##############################################################\n");
}

//Spielfeldausgabe
void spielfeldausgabe(int spielfeldzahl[24])
{
    //2D-Array
    //Grundkonstrukt
    char spielfeldfix [13] [13] =
    {
        {'\0','-','-','-','-','-','\0','-','-','-','-','-','\0'},       
        {'|','n','n','n','n','n','|','n','n','n','n','n','|'},          
        {'|','n','\0','-','-','-','\0','-','-','-','\0','n','|'},
        {'|','n','|','n','n','n','|','n','n','n','|','n','|'},
        {'|','n','|','n','\0','-','\0','-','\0','n','|','n','|'},
        {'|','n','|','n','|','n','n','n','|','n','|','n','|'},
        {'\0','-','\0','-','\0','n','n','n','\0','-','\0','-','\0'},
        {'|','n','|','n','|','n','n','n','|','n','|','n','|'},
        {'|','n','|','n','\0','-','\0','-','\0','n','|','n','|'},
        {'|','n','|','n','n','n','|','n','n','n','|','n','|'},
        {'|','n','\0','-','-','-','\0','-','-','-','\0','n','|'},
        {'|','n','n','n','n','n','|','n','n','n','n','n','|'},
        {'\0','-','-','-','-','-','\0','-','-','-','-','-','\0'}
    };
    
    //C = Zaehlervariable des 1D-Arrays (Spielfeldzahlarray)
    int c = 0;
        //senkrecht
        for(int i = 0; i <= 12; i++)
        {
            //waagrecht
            for(int j = 0; j <= 12; j++)
            {
                //Wenn kein Fixzeichen, dann ...
                if(spielfeldfix[i][j] == '\0'){
                    
                    //gehoert das Feld Spieler1
                    if(spielfeldzahl[c]== 111){
                        printf("[\e[0;35m o\e[0m]");
                    //gehört das Feld Spieler2
                    }
                    else if(spielfeldzahl[c] == 222){ 
                        printf("[\e[0;36m o\e[0m]");                                        
                    }
                    else{
                    //Feld neutral/nicht besetzt
                    if(spielfeldzahl[c] <= 9){
                        printf("[0%d]", spielfeldzahl[c]);
                    }
                    else{
                            printf("[%2.d]", spielfeldzahl[c]);
                    }
                    
                    }
                    c++; 
                }
                //Spielfeldfixausgabe leere Felder
                else if(spielfeldfix[i][j] == 'n'){
                    printf("    ");
                }
                else{
                    if(spielfeldfix[i][j] == '-'){
                        printf("----");
                        }
                        else{
                             //Spielfeldfixausgabe
                            printf(" %c  ",spielfeldfix [i] [j]);
                        }
               
                }
            } 
            printf("\n");
        }      

}

//Spielsteinanzahl
int spielsteinanzaehler(int spielfeld[24], int spieler)
{
    int zaehler = 0;
    int welcher_spieler;

    if(spieler == 1){
        welcher_spieler = 111;
    }
    else{
        welcher_spieler = 222;
    }

    for(int i = 0; i <= 24; i++){
        if(spielfeld[i] == welcher_spieler){
        zaehler++;
        }
    }
    return zaehler;

}