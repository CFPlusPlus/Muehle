//Das Spiel Muehle in C
//Jakob Graf, Christian Falkner; Januar 2020

//Headerfiles Einbinden
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "muehlegame.h"
#include "ausgabe.h"

//Globales Spielfeldarray    
int spielfeld[24] = {0};
bool muehlenabfrage[16] ;

//Zur Compilerberuhigung
//Damit die Funktionen dem Copiler vorher bekannt sind, da die Funktionen erst nch der main-Funktion definiert sind
void spielereingabe_setzen(int spieler);


int main()
{
//Startscreen


//Spielbeginn
//Werte in Spielfeld schreiben
spielfeldclear(spielfeld);

//1. Spielphase Setzen
for(int i = 1; i <= 18; i++){

    //Spieler 1
    if((i % 2) == 1){
        spielereingabe_setzen(1);
    }
        //Spieler 2
    if((i % 2) == 0){
        spielereingabe_setzen(2);
    }
}

spielfeldausgabe(spielfeld);
getchar();

return 0;    
}

void spielereingabe_setzen(int spieler){
/*Diese Funktion fragt den Spieler nach seinem Feld ab und speichert die Position ab.
* Array-Werte: Spieler 1 =  111; Spieler 2 = 222
* int spieler: 1 = Spieler 1; 2 = Spieler 2
*/

//Variablen
int eingabe = 0;

//Spielfeld ausgeben
spielfeldausgabe(spielfeld);

AbfrageSpieler :
if(spieler == 1){
printf("\e[1;35m Spieler 1 \e[0m : Bitte Spielfeld eingeben:\n");
}
else{
printf("\e[1;36m Spieler 2 \e[0m : Bitte Spielfeld eingeben:\n");    
}
scanf("%d", &eingabe);

//Hiermit wird ueberpueft, ob das Spielfeld schon belegt ist
if(spielfeld[eingabe - 1] == eingabe)
{
    if(spieler == 1){
    //Spielerzeichen (111) Spieler 1 in Array schreiben
    spielfeld[eingabe - 1]  = 111;
    }
    if(spieler == 2){
    //Spielerzeichen (222) Spieler 2 in Array schreiben
    spielfeld[eingabe - 1]  = 222;
    }
}
else
{
    printf("Spielfeld ist schon belegt!\n");
    goto AbfrageSpieler;
}

//Wenn der Spieler eine Muehle erstellt, darf ein gegnerischer Stein entfernt werden
if(muehlenpruefer(spieler, spielfeld, muehlenabfrage) >= 0){
    muehlenabfrage[muehlenpruefer(spieler, spielfeld, muehlenabfrage)] = true;
    printf("Muehle!, Du darfst einen gegnerischen Stein entfernen.\n");

//Abfrage fuer Spieler 1 und 2
if(spieler == 1){
printf("\e[1;35m Spieler 1 \e[0m : Welcher Spielstein darf entfernt werden?:\n");
}
else{
    printf("\e[1;36m Spieler 2 \e[0m : Welcher Spielstein darf entfernt werden?:\n");
}
scanf("%d", &eingabe);

if(spieler == 1){
    spielsteinentfernen(1, eingabe, spielfeld);
}
else if(spieler == 2){
    spielsteinentfernen(2, eingabe, spielfeld);
}
}
system("cls");
}





