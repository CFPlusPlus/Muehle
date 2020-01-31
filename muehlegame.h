/*Diese Header-Datei beinhaltet einige Funktionen für das Spiel Muehle
* (c) Christian Falkner; Januar 2020
*/


void spielfeldclear(int feld[24]){
//Diese Funktion löscht das Spielfeld
//Dieser Funktion muss das Array uebergeben werden!!!  
for(int j = 1; j <= 24; j++){
    feld[j-1]= j;
}
}

int muehlenpruefer(int spieler, int feld[24], bool muehlenabfrage[]){
/*Diese Funktion prueft das Spielfeldarray auf Muehlen des Spielers (3 Steine in einer Reihe)
* Eingabewerte int spieler 1: Spieler 1; 2: Spieler 2
* Rueckgabewerte: 1: Muehle vorhanden; 2: Keine Muehlen
*/

//Eingabe konvertieren
int spielerfeld = 0;

if(spieler == 1){
spielerfeld = 111;
} 
if(spieler == 2){
spielerfeld = 222;
} 

//Horizontale Muehlen
for(int i = 1; i <= 22; i = i + 3){
//Hier wird in 3er Schritten durch das Array gegangen und auf Muehlen geprueft
if((feld[i - 1] == spielerfeld) && (feld[i] == spielerfeld) && (feld[i + 1] == spielerfeld) && !muehlenabfrage[i-1]){
    return i-1;
}    
}

//Vertikale Muehlen
if((feld[0] == spielerfeld) && (feld[9] == spielerfeld) && (feld[21] == spielerfeld) && !muehlenabfrage[8]){
return 8;
}
if((feld[3] == spielerfeld) && (feld[10] == spielerfeld) && (feld[18] == spielerfeld) && !muehlenabfrage[9]){
return 9;
}
if((feld[6] == spielerfeld) && (feld[11] == spielerfeld) && (feld[15] == spielerfeld) && !muehlenabfrage[10]){
return 10;
}
if((feld[1] == spielerfeld) && (feld[4] == spielerfeld) && (feld[7] == spielerfeld) && !muehlenabfrage[11]){
return 11;
}
if((feld[16] == spielerfeld) && (feld[19] == spielerfeld) && (feld[22] == spielerfeld) && !muehlenabfrage[12]){
return 12;
}
if((feld[8] == spielerfeld) && (feld[12] == spielerfeld) && (feld[17] == spielerfeld) && !muehlenabfrage[13]){
return 13;
}
if((feld[5] == spielerfeld) && (feld[13] == spielerfeld) && (feld[20] == spielerfeld) && !muehlenabfrage[14]){
return 14;
}
if((feld[2] == spielerfeld) && (feld[14] == spielerfeld) && (feld[23] == spielerfeld) && !muehlenabfrage[15]){
return 15;
}

//Keine Muehlen vorhanden
return -1;
}

void spielsteinentfernen(int spieler,int feldloeschen, int spielfeld [24]){
//Diese Funktion entfernt einen gegnerischen Spielstein aus dem Array
//Eingabewerte: int spieler: 1: Spieler 1; 2: Spieler 2

//Variablen
int spielerwert = 0;

//Spielerwert
if(spieler == 1){
spielerwert = 222;
}
if(spieler == 2){
spielerwert = 111;
}

if(spielfeld[feldloeschen - 1] == spielerwert){

//Das Spielfeld wird an der Stelle feldloeschen - 1 geloescht
spielfeld[feldloeschen - 1] = feldloeschen;

}


}