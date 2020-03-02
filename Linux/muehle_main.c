/*Das Spiel Muehle in C (Linux-Version)
* Jakob Graf, Christian Falkner; 2020
* Stand 28.02.2020
*/

//Headerfiles Einbinden
#include <stdio.h>
#include <stdlib.h>
#include "muehlegame.h"
#include "ausgabe.h"

//Zur Compilerberuhigung
//Damit die Funktionen dem Copiler vorher bekannt sind, da die Funktionen erst nch der main-Funktion definiert sind
void spielereingabe_setzen(int spieler);
void spielereingabe_zug(int spieler);
void spielereingabe_sprung(int spieler);

//Globales Spielfeldarray
int spielfeld[24] = {0};

int main()
{
    //Variablen
    char neueRunde;

    do
    {
        system("clear");
        //Startscreen
        startscreen();

        //Spielbeginn

        //Werte in Spielfeld schreiben
        spielfeldclear(spielfeld);

        //1. Spielphase (Setzen)
        for (int i = 1; i <= 18; i++)
        {

            //Spieler 1
            if ((i % 2) == 1)
            {
                spielereingabe_setzen(1);
            }
            //Spieler 2
            if ((i % 2) == 0)
            {
                spielereingabe_setzen(2);
            }
        }

        //2. und 3. Spielphase (Zugphase und Sprungphase)
        do
        {
            //Prueft, ob Spieler 1 ziehen kann
            if ((zugmoeglich(1, spielfeld) == 2) || (spielsteinanzaehler(spielfeld, 1) == 2))
            {
                break;
            }
            //Spieler 1 Zug
            if (spielsteinanzaehler(spielfeld, 1) == 3)
            {
                //Hier beginnt die Sprungphase fuer Spieler 1
                spielereingabe_sprung(1);
            }
            else
            {
                spielereingabe_zug(1);
            }

            //Prueft, ob Spieler 2 ziehen kann
            if ((zugmoeglich(2, spielfeld) == 2) || (spielsteinanzaehler(spielfeld, 2) == 2))
            {
                break;
            }
            //Spieler 2 Zug
            if (spielsteinanzaehler(spielfeld, 2) == 3)
            {
                //Hier beginnt die Sprungphase fuer Spieler 2
                spielereingabe_sprung(2);
            }
            else
            {
                spielereingabe_zug(2);
            }

        } while ((spielsteinanzaehler(spielfeld, 1) > 3) || (spielsteinanzaehler(spielfeld, 2) > 3));

        //system("clear");
        //Spielende
        endscreen();

        //Spielende Abfrage
        printf("\nNoch mal? (Y/N)\n");

        neueRunde = getchar();

        if (neueRunde == 'n' || neueRunde == 'N')
        {
            break;
        }

    } while (1);

    return 0;
}

void spielereingabe_setzen(int spieler)
{
    /*Diese Funktion fragt den Spieler nach seinem Feld ab und speichert die Position ab.
* Array-Werte: Spieler 1 =  111; Spieler 2 = 222
* int spieler: 1 = Spieler 1; 2 = Spieler 2
*/

    //Variablen
    int eingabe = 0;

    //Spielfeld ausgeben
    spielfeldausgabe(spielfeld);

AbfrageSpieler:
    if (spieler == 1)
    {
        printf("\e[1;35m Spieler 1 \e[0m : Bitte Spielfeld eingeben:\n");
    }
    else
    {
        printf("\e[1;36m Spieler 2 \e[0m : Bitte Spielfeld eingeben:\n");
    }

    scanf("%d", &eingabe);

    //Hiermit wird ueberpueft, ob das Spielfeld schon belegt ist
    if (spielfeld[eingabe - 1] == eingabe)
    {
        if (spieler == 1)
        {
            //Spielerzeichen (111) Spieler 1 in Array schreiben
            spielfeld[eingabe - 1] = 111;
        }
        if (spieler == 2)
        {
            //Spielerzeichen (222) Spieler 2 in Array schreiben
            spielfeld[eingabe - 1] = 222;
        }
    }
    else
    {
        printf("Spielfeld ist schon belegt!\n");
        goto AbfrageSpieler;
    }

    //Wenn der Spieler eine Muehle erstellt, darf ein gegnerischer Stein entfernt werden
    if (muehleschliessen(eingabe, spielfeld, spieler) == 1)
    {

        system("clear"); //Entfernt den Bug, dass das Spielfeld erst spaeter ausgegeben wird

        spielfeldausgabe(spielfeld);

        printf("Mühle!, Du darfst einen gegnerischen Stein entfernen.\n");

    abfrage:
        //Abfrage fuer Spieler 1 und 2
        if (spieler == 1)
        {
            printf("\e[1;35m Spieler 1 \e[0m : Welcher Spielstein darf entfernt werden?:\n");
        }
        else
        {
            printf("\e[1;36m Spieler 2 \e[0m : Welcher Spielstein darf entfernt werden?:\n");
        }
        scanf("%d", &eingabe);

        if (spieler == 1)
        {
            //Ueberprüfen ob Stein in Muehle liegt und ob kein eigener Stein entfernt wird
            if (((muehleschliessen(eingabe, spielfeld, 2) == 2) && !(spielfeld[eingabe - 1] == 111) && !(spielfeld[eingabe - 1] == eingabe)) || (allesteineinmuehle(spielfeld, 2) == 1))
            {
                spielsteinentfernen(1, eingabe, spielfeld);
            }
            else
            {
                printf("Spielzug nicht moeglich!\n");
                goto abfrage;
            }
        }
        if (spieler == 2)
        {
            //Ueberprüfen ob Stein in Muehle liegt und ob kein eigener Stein entfernt wird
            if (((muehleschliessen(eingabe, spielfeld, 1) == 2) && !(spielfeld[eingabe - 1] == 222) && !(spielfeld[eingabe - 1] == eingabe)) || (allesteineinmuehle(spielfeld, 1) == 1))
            {
                spielsteinentfernen(2, eingabe, spielfeld);
            }
            else
            {
                printf("Spielzug nicht moeglich!\n");
                goto abfrage;
            }
        }
    }
    system("clear");
}

void spielereingabe_zug(int spieler)
{
    /*(Zugphase) Diese Funktion fragt den Spieler nach seinem Feld ab und speichert die Position ab.
* Array-Werte: Spieler 1 =  111; Spieler 2 = 222
* int spieler: 1 = Spieler 1; 2 = Spieler 2
*/

    //Variablen der Funktion
    int spielstein = 0;
    int steinposition = 0;
    int eingabe2 = 0;

    //konsole clear
    system("clear");
    //Spielfeld ausgeben
    spielfeldausgabe(spielfeld);

AbfrageSpieler:
    //Spielstein Abfrage
    if (spieler == 1)
    {
        printf("\e[1;35m Spieler 1 \e[0m : Welcher Spielstein soll geschoben werden?:\n");
    }
    else
    {
        printf("\e[1;36m Spieler 2 \e[0m : Welcher Spielstein soll geschoben werden?:\n");
    }
    scanf("%d", &spielstein);

    //Steinposition Abfrage
    if (spieler == 1)
    {
        printf("\e[1;35m Spieler 1 \e[0m : Wohin soll der Stein geschoben werden?:\n");
    }
    else
    {
        printf("\e[1;36m Spieler 2 \e[0m : Wohin soll der Stein geschoben werden?:\n");
    }
    scanf("%d", &steinposition);

    //Hiermit wird ueberpueft, ob der Spielzug erlaubt ist:
    //Erfordert: Spielzug ist erlaubt, Platz muss frei sein auf dem Stein geschoben wird
    if ((zugisterlaubt(spielstein, steinposition) == 1) && (spielfeld[steinposition - 1] == steinposition))
    {
        //Pruefen ob eigener Spielstein
        if ((spieler == 1) && (spielfeld[spielstein - 1] == 111))
        {
            //Spielerzeichen (111) Spieler 1 in Array schreiben
            spielfeld[steinposition - 1] = 111;

            //Alten Spielstein aus Array loeschen
            spielfeld[spielstein - 1] = spielstein;
        }
        else if ((spieler == 2) && (spielfeld[spielstein - 1] == 222))
        {
            //Spielerzeichen (222) Spieler 2 in Array schreiben
            spielfeld[steinposition - 1] = 222;

            //Alten Spielstein aus Array loeschen
            spielfeld[spielstein - 1] = spielstein;
        }

        else
        {
            printf("Spielzug ist nicht erlaubt!\n");
            goto AbfrageSpieler;
        }
    }

    else
    {
        printf("Spielzug ist nicht erlaubt!\n");
        goto AbfrageSpieler;
    }

    //Wenn der Spieler eine Muehle erstellt, darf ein gegnerischer Stein entfernt werden
    if (muehleschliessen(steinposition, spielfeld, spieler) == 1)
    {

        system("clear"); //Entfernt den Bug, dass das Spielfeld erst spaeter ausgegeben wird

        spielfeldausgabe(spielfeld);

        printf("Mühle!, Du darfst einen gegnerischen Stein entfernen.\n");

    abfrage2:
        //Abfrage fuer Spieler 1 und 2
        if (spieler == 1)
        {
            printf("\e[1;35m Spieler 1 \e[0m : Welcher Spielstein darf entfernt werden?:\n");
        }
        else
        {
            printf("\e[1;36m Spieler 2 \e[0m : Welcher Spielstein darf entfernt werden?:\n");
        }
        scanf("%d", &eingabe2);

        if (spieler == 1)
        {
            //Ueberprüfen ob Stein in Muehle liegt oder alle gegnerischen Steine in Muehln liegen
            if (((muehleschliessen(eingabe2, spielfeld, 2) == 2) && !(spielfeld[eingabe2 - 1] == eingabe2) && (spielfeld[eingabe2 - 1] != 111)) || (allesteineinmuehle(spielfeld, 2) == 1))
            {
                spielsteinentfernen(1, eingabe2, spielfeld);
            }
            else
            {
                printf("Spielzug nicht moeglich!\n");
                goto abfrage2;
            }
        }
        if (spieler == 2)
        {
            //Ueberprüfen ob Stein in Muehle liegt oder alle gegnerischen Steine in Muehln liegen
            if (((muehleschliessen(eingabe2, spielfeld, 1) == 2) && !(spielfeld[eingabe2 - 1] == eingabe2) && (spielfeld[eingabe2 - 1] != 222)) || (allesteineinmuehle(spielfeld, 1) == 1))
            {
                spielsteinentfernen(2, eingabe2, spielfeld);
            }
            else
            {
                printf("Spielzug nicht moeglich!\n");
                goto abfrage2;
            }
        }
    }
}

void spielereingabe_sprung(int spieler)
{
    /*(Springphase) Diese Funktion fragt den Spieler nach seinem Feld ab und speichert die Position ab.
* Array-Werte: Spieler 1 =  111; Spieler 2 = 222
* int spieler: 1 = Spieler 1; 2 = Spieler 2
*/

    //konsole clear
    system("clear");
    //Spielfeld ausgeben
    spielfeldausgabe(spielfeld);

    //Deklaration der Sprungvariablen innerhalb der Funktion sprung
    int spielstein2, steinposition2;

//Goto
abfrage3:

    //Auswahl des Sprungsteins
    if (spieler == 1)
    {
        printf("\e[1;35m Spieler 1 \e[0m : Mit welchem Spielstein soll gesprungen werden?:\n");
    }
    else
    {
        printf("\e[1;36m Spieler 2 \e[0m : Mit welchem Spielstein soll gesprungen werden?:\n");
    }
    scanf("%d", &spielstein2);

    //Auswahl der Sprungposition
    if (spieler == 1)
    {
        printf("\e[1;35m Spieler 1 \e[0m : Wohin soll gesprungen werden?:\n");
    }
    else
    {
        printf("\e[1;36m Spieler 2 \e[0m : Wohin soll gesprungen werden?:\n");
    }
    scanf("%d", &steinposition2);

    //Ueberpruefen ob Spieler 1 seinen Spielstein bewegt und ob Spielfeld frei ist
    if ((spieler == 1) && (spielfeld[spielstein2 - 1] == 111) && (spielfeld[steinposition2 - 1] == steinposition2))
    {
        //in neues Spielfeldspeichern
        spielfeld[steinposition2 - 1] = 111;

        //altest Spielfeld löschen
        spielfeld[spielstein2 - 1] = spielstein2;
    }

    //Ueberpruefen ob Spieler 1 seinen Spielstein bewegt und ob Spielfeld frei ist
    if ((spieler == 2) && (spielfeld[spielstein2 - 1] == 222) && (spielfeld[steinposition2 - 1] == steinposition2))
    {
        //in neues Spielfeldspeichern
        spielfeld[steinposition2 - 1] = 222;

        //altest Spielfeld löschen
        spielfeld[spielstein2 - 1] = spielstein2;
    }
    else
    {
        printf("Spielzug nicht moeglich!\n");
        goto abfrage3;
    }
}