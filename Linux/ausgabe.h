//(Linux-Version)
//Diese Header-Datei beinhaltet einige Ausgaben für das Spiel Muehle
//(c)Jakob Graf; Januar 2020
//Stand 28.02.2020

//Startscreenausgabe
void startscreen()
{
    printf("\t\t\tLINUX-Version\n");
    printf("##############################################################\n");
    printf("#                                                            #\n");
    printf("#                         M Ü H L E                          #\n");
    printf("#                                                            #\n");
    printf("#    Entwicklung: Christian Falkner und Jakob Graf; 2020     #\n");
    printf("#                                                            #\n");
    printf("##############################################################\n");

    //Spielstart bei Drücken der Entertaste
    printf("\nPress Enter to Start\n ");
    getchar();

    //Konsole clear
    system("clear");
}

//Spielfeldausgabe
//Das Mühlespielfeld wird ausgegeben
void spielfeldausgabe(int spielfeldzahl[24])
{
    //2D-Array
    //Grundkonstrukt
    char spielfeldfix[13][13] =
        {
            {'\0', '-', '-', '-', '-', '-', '\0', '-', '-', '-', '-', '-', '\0'},
            {'|', 'n', 'n', 'n', 'n', 'n', '|', 'n', 'n', 'n', 'n', 'n', '|'},
            {'|', 'n', '\0', '-', '-', '-', '\0', '-', '-', '-', '\0', 'n', '|'},
            {'|', 'n', '|', 'n', 'n', 'n', '|', 'n', 'n', 'n', '|', 'n', '|'},
            {'|', 'n', '|', 'n', '\0', '-', '\0', '-', '\0', 'n', '|', 'n', '|'},
            {'|', 'n', '|', 'n', '|', 'n', 'n', 'n', '|', 'n', '|', 'n', '|'},
            {'\0', '-', '\0', '-', '\0', 'n', 'n', 'n', '\0', '-', '\0', '-', '\0'},
            {'|', 'n', '|', 'n', '|', 'n', 'n', 'n', '|', 'n', '|', 'n', '|'},
            {'|', 'n', '|', 'n', '\0', '-', '\0', '-', '\0', 'n', '|', 'n', '|'},
            {'|', 'n', '|', 'n', 'n', 'n', '|', 'n', 'n', 'n', '|', 'n', '|'},
            {'|', 'n', '\0', '-', '-', '-', '\0', '-', '-', '-', '\0', 'n', '|'},
            {'|', 'n', 'n', 'n', 'n', 'n', '|', 'n', 'n', 'n', 'n', 'n', '|'},
            {'\0', '-', '-', '-', '-', '-', '\0', '-', '-', '-', '-', '-', '\0'}};

    //C = Zaehlervariable des 1D-Arrays (Spielfeldzahlarray)
    int c = 0;
    //senkrecht
    for (int i = 0; i <= 12; i++)
    {
        //waagrecht
        for (int j = 0; j <= 12; j++)
        {
            //Wenn kein Fixzeichen, dann ...
            if (spielfeldfix[i][j] == '\0')
            {

                //gehoert das Feld Spieler1
                if (spielfeldzahl[c] == 111)
                {
                    printf("[\e[0;35m o\e[0m]");
                    //gehoert das Feld Spieler2
                }
                else if (spielfeldzahl[c] == 222)
                {
                    printf("[\e[0;36m o\e[0m]");
                }
                else
                {
                    //Feld neutral/nicht besetzt
                    if (spielfeldzahl[c] <= 9)
                    {
                        printf("[0%d]", spielfeldzahl[c]);
                    }
                    else
                    {
                        printf("[%2.d]", spielfeldzahl[c]);
                    }
                }
                c++;
            }
            //Spielfeldfixausgabe leere Felder
            else if (spielfeldfix[i][j] == 'n')
            {
                printf("    ");
            }
            else
            {
                if (spielfeldfix[i][j] == '-')
                {
                    printf("----");
                }
                else
                {
                    //Spielfeldfixausgabe
                    printf(" %c  ", spielfeldfix[i][j]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void endscreen()
{
    printf("##############################################################\n");
    printf("#                                                            #\n");
    printf("#                                                            #\n");
    printf("#                      S P I E L E N D E                     #\n");
    printf("#                                                            #\n");
    printf("#                                                            #\n");
    printf("##############################################################\n");
}