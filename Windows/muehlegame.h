/*Diese Header-Datei beinhaltet einige Funktionen für das Spiel Muehle
* Jakob Graf, Christian Falkner; 2020
* Stand 02.03.2020
*/

void spielfeldclear(int feld[24])
{
    //Diese Funktion löscht das Spielfeld
    //Dieser Funktion muss das Array uebergeben werden!!!
    for (int j = 1; j <= 24; j++)
    {
        feld[j - 1] = j;
    }
}

int muehleschliessen(int steinpos, int feld[24], int spieler)
{
    /*Dies Funktion gibt 1 zurueck wenn der Spieler eine Muehle geschlossen hat
* Eingabewerte int spieler 1: Spieler 1; 2: Spieler 2
* Rueckgabewerte: 1: Muehle geschlossen; 2: Muehle nicht geschlossen
*/

    //Eingabe konvertieren
    int spielerfeld = 0;

    if (spieler == 1)
    {
        spielerfeld = 111;
    }
    if (spieler == 2)
    {
        spielerfeld = 222;
    }

    if (((steinpos == 1) && (feld[1] == spielerfeld) && (feld[2] == spielerfeld)) || ((steinpos == 1) && (feld[9] == spielerfeld) && (feld[21] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 2) && (feld[0] == spielerfeld) && (feld[2] == spielerfeld)) || ((steinpos == 2) && (feld[4] == spielerfeld) && (feld[7] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 3) && (feld[1] == spielerfeld) && (feld[0] == spielerfeld)) || ((steinpos == 3) && (feld[14] == spielerfeld) && (feld[23] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 4) && (feld[4] == spielerfeld) && (feld[5] == spielerfeld)) || ((steinpos == 4) && (feld[10] == spielerfeld) && (feld[18] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 5) && (feld[1] == spielerfeld) && (feld[7] == spielerfeld)) || ((steinpos == 5) && (feld[3] == spielerfeld) && (feld[5] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 6) && (feld[3] == spielerfeld) && (feld[4] == spielerfeld)) || ((steinpos == 6) && (feld[13] == spielerfeld) && (feld[20] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 7) && (feld[11] == spielerfeld) && (feld[15] == spielerfeld)) || ((steinpos == 7) && (feld[7] == spielerfeld) && (feld[8] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 8) && (feld[1] == spielerfeld) && (feld[4] == spielerfeld)) || ((steinpos == 8) && (feld[6] == spielerfeld) && (feld[8] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 9) && (feld[6] == spielerfeld) && (feld[7] == spielerfeld)) || ((steinpos == 9) && (feld[12] == spielerfeld) && (feld[17] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 10) && (feld[0] == spielerfeld) && (feld[21] == spielerfeld)) || ((steinpos == 10) && (feld[10] == spielerfeld) && (feld[11] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 11) && (feld[9] == spielerfeld) && (feld[11] == spielerfeld)) || ((steinpos == 11) && (feld[3] == spielerfeld) && (feld[18] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 12) && (feld[9] == spielerfeld) && (feld[10] == spielerfeld)) || ((steinpos == 12) && (feld[6] == spielerfeld) && (feld[15] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 13) && (feld[8] == spielerfeld) && (feld[17] == spielerfeld)) || ((steinpos == 13) && (feld[13] == spielerfeld) && (feld[14] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 14) && (feld[5] == spielerfeld) && (feld[20] == spielerfeld)) || ((steinpos == 14) && (feld[12] == spielerfeld) && (feld[14] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 15) && (feld[12] == spielerfeld) && (feld[13] == spielerfeld)) || ((steinpos == 15) && (feld[2] == spielerfeld) && (feld[23] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 16) && (feld[6] == spielerfeld) && (feld[11] == spielerfeld)) || ((steinpos == 16) && (feld[16] == spielerfeld) && (feld[17] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 17) && (feld[15] == spielerfeld) && (feld[17] == spielerfeld)) || ((steinpos == 17) && (feld[19] == spielerfeld) && (feld[22] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 18) && (feld[15] == spielerfeld) && (feld[16] == spielerfeld)) || ((steinpos == 18) && (feld[8] == spielerfeld) && (feld[12] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 19) && (feld[3] == spielerfeld) && (feld[10] == spielerfeld)) || ((steinpos == 19) && (feld[19] == spielerfeld) && (feld[20] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 20) && (feld[18] == spielerfeld) && (feld[20] == spielerfeld)) || ((steinpos == 20) && (feld[16] == spielerfeld) && (feld[22] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 21) && (feld[18] == spielerfeld) && (feld[19] == spielerfeld)) || ((steinpos == 21) && (feld[5] == spielerfeld) && (feld[13] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 22) && (feld[0] == spielerfeld) && (feld[9] == spielerfeld)) || ((steinpos == 22) && (feld[22] == spielerfeld) && (feld[23] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 23) && (feld[21] == spielerfeld) && (feld[23] == spielerfeld)) || ((steinpos == 23) && (feld[16] == spielerfeld) && (feld[19] == spielerfeld)))
    {
        return 1;
    }
    if (((steinpos == 24) && (feld[21] == spielerfeld) && (feld[22] == spielerfeld)) || ((steinpos == 24) && (feld[2] == spielerfeld) && (feld[14] == spielerfeld)))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void spielsteinentfernen(int spieler, int feldloeschen, int spielfeld[24])
{
    //Diese Funktion entfernt einen gegnerischen Spielstein aus dem Array
    //Eingabewerte: int spieler: 1: Spieler 1; 2: Spieler 2

    //Variablen
    int spielerwert = 0;

    //Spielerwert
    if (spieler == 1)
    {
        spielerwert = 222;
    }
    if (spieler == 2)
    {
        spielerwert = 111;
    }

    if (spielfeld[feldloeschen - 1] == spielerwert)
    {
        //Das Spielfeld wird an der Stelle feldloeschen - 1 geloescht
        spielfeld[feldloeschen - 1] = feldloeschen;
    }
}

int spielsteinanzaehler(int spielfeld[24], int spieler)
{
    //Spielsteinanzahl
    //Die Spielsteine werden pro Spieler gezaehlt
    //Rueckgabewert entspricht der Anzahl der Spielsteine des Spielers

    int zaehler = 0;
    int welcher_spieler;

    if (spieler == 1)
    {
        welcher_spieler = 111;
    }
    if (spieler == 2)
    {
        welcher_spieler = 222;
    }

    for (int i = 0; i <= 24; i++)
    {
        //Hier wird durch das Spielfeldarray gegangen und zahler um eins erhoet, wenn ein Spielstein gefunden wird
        if (spielfeld[i] == welcher_spieler)
        {
            zaehler++;
        }
    }
    return zaehler;
}

int zugisterlaubt(int spielstein, int steinposition)
{
    /*Diese Funktion ueberprueft ob, der Zug erlaubt ist
* spielstein = Welcher Spielstein soll verschoben werden?
* speinposition = Wohin soll der Spielstein bewegt werden?
* Rueckgabewert: 1 = Zug ist moeglich, 2  = Zug ist nicht moeglich
*/

    if ((spielstein == 1) && ((steinposition == 2) || (steinposition == 10)))
    {
        return 1;
    }
    if ((spielstein == 2) && ((steinposition == 1) || (steinposition == 3) || (steinposition == 5)))
    {
        return 1;
    }
    if ((spielstein == 3) && ((steinposition == 2) || (steinposition == 15)))
    {
        return 1;
    }
    if ((spielstein == 4) && ((steinposition == 5) || (steinposition == 11)))
    {
        return 1;
    }
    if ((spielstein == 5) && ((steinposition == 2) || (steinposition == 4) || (steinposition == 6) || (steinposition == 8)))
    {
        return 1;
    }
    if ((spielstein == 6) && ((steinposition == 5) || (steinposition == 14)))
    {
        return 1;
    }
    if ((spielstein == 7) && ((steinposition == 8) || (steinposition == 12)))
    {
        return 1;
    }
    if ((spielstein == 8) && ((steinposition == 5) || (steinposition == 7) || (steinposition == 9)))
    {
        return 1;
    }
    if ((spielstein == 9) && ((steinposition == 8) || (steinposition == 13)))
    {
        return 1;
    }
    if ((spielstein == 10) && ((steinposition == 1) || (steinposition == 11) || (steinposition == 22)))
    {
        return 1;
    }
    if ((spielstein == 11) && ((steinposition == 4) || (steinposition == 10) || (steinposition == 12) || (steinposition == 19)))
    {
        return 1;
    }
    if ((spielstein == 12) && ((steinposition == 7) || (steinposition == 11) || (steinposition == 16)))
    {
        return 1;
    }
    if ((spielstein == 13) && ((steinposition == 9) || (steinposition == 14) || (steinposition == 18)))
    {
        return 1;
    }
    if ((spielstein == 14) && ((steinposition == 6) || (steinposition == 13) || (steinposition == 15) || (steinposition == 21)))
    {
        return 1;
    }
    if ((spielstein == 15) && ((steinposition == 3) || (steinposition == 14) || (steinposition == 24)))
    {
        return 1;
    }
    if ((spielstein == 16) && ((steinposition == 12) || (steinposition == 17)))
    {
        return 1;
    }
    if ((spielstein == 17) && ((steinposition == 16) || (steinposition == 18) || (steinposition == 20)))
    {
        return 1;
    }
    if ((spielstein == 18) && ((steinposition == 13) || (steinposition == 17)))
    {
        return 1;
    }
    if ((spielstein == 19) && ((steinposition == 11) || (steinposition == 20)))
    {
        return 1;
    }
    if ((spielstein == 20) && ((steinposition == 17) || (steinposition == 19) || (steinposition == 21) || (steinposition == 23)))
    {
        return 1;
    }
    if ((spielstein == 21) && ((steinposition == 14) || (steinposition == 20)))
    {
        return 1;
    }
    if ((spielstein == 22) && ((steinposition == 10) || (steinposition == 23)))
    {
        return 1;
    }
    if ((spielstein == 23) && ((steinposition == 20) || (steinposition == 22) || (steinposition == 24)))
    {
        return 1;
    }
    if ((spielstein == 24) && ((steinposition == 15) || (steinposition == 23)))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int allesteineinmuehle(int spielfeld[24], int spieler)
{
    /*Diese Funktion prueft, ob alle Steine des Spielers in Muehlen liegen
* Rueckgabewert: 1 = Alle Steine liegen in Muehlen; 2 = Nicht alle Steine liegen in Muehlen
*/

    int spielerwert = 0;
    //Spielerwert
    if (spieler == 1)
    {
        spielerwert = 111;
    }
    if (spieler == 2)
    {
        spielerwert = 222;
    }

    for (int i = 1; i <= 24; i++)
    {

        //Im Array wird nach einem Spielerstein gesucht
        if (spielfeld[i - 1] == spielerwert)
        {

            //Wenn ein Stein nicht in einer Muehle liegt 2 Ausgeben
            if (muehleschliessen(i, spielfeld, spieler) == 2)
            {
                return 2;
            }
        }
    }

    //Alle Steine liegen in Muehlen
    return 1;
}

int spielereingebaut(int spielfeld[24], int position)
{
    /*Diese Funktion prueft ob der Spieler an der Position einen Zug machen kann
* Rueckgabewert: 1 = Zug moeglich; 2 = Zug nicht moeglich
*/

    if ((position == 1) && (spielfeld[1] != 2) && (spielfeld[9] != 10))
    {
        return 2;
    }
    if ((position == 2) && (spielfeld[0] != 1) && (spielfeld[2] != 3) && (spielfeld[4] != 5))
    {
        return 2;
    }
    if ((position == 3) && (spielfeld[1] != 2) && (spielfeld[14] != 15))
    {
        return 2;
    }
    if ((position == 4) && (spielfeld[10] != 11) && (spielfeld[4] != 5))
    {
        return 2;
    }
    if ((position == 5) && (spielfeld[1] != 2) && (spielfeld[3] != 4) && (spielfeld[5] != 6) && (spielfeld[7] != 8))
    {
        return 2;
    }
    if ((position == 6) && (spielfeld[4] != 5) && (spielfeld[13] != 14))
    {
        return 2;
    }
    if ((position == 7) && (spielfeld[11] != 12) && (spielfeld[7] != 8))
    {
        return 2;
    }
    if ((position == 8) && (spielfeld[6] != 7) && (spielfeld[4] != 5) && (spielfeld[8] != 9))
    {
        return 2;
    }
    if ((position == 9) && (spielfeld[7] != 8) && (spielfeld[12] != 13))
    {
        return 2;
    }
    if ((position == 10) && (spielfeld[0] != 1) && (spielfeld[10] != 11) && (spielfeld[21] != 22))
    {
        return 2;
    }
    if ((position == 11) && (spielfeld[3] != 4) && (spielfeld[9] != 10) && (spielfeld[18] != 19) && (spielfeld[11] != 12))
    {
        return 2;
    }
    if ((position == 12) && (spielfeld[6] != 7) && (spielfeld[10] != 11) && (spielfeld[15] != 16))
    {
        return 2;
    }
    if ((position == 13) && (spielfeld[8] != 9) && (spielfeld[13] != 14) && (spielfeld[17] != 18))
    {
        return 2;
    }
    if ((position == 14) && (spielfeld[5] != 6) && (spielfeld[12] != 13) && (spielfeld[20] != 21) && (spielfeld[14] != 15))
    {
        return 2;
    }
    if ((position == 15) && (spielfeld[2] != 3) && (spielfeld[13] != 14) && (spielfeld[23] != 24))
    {
        return 2;
    }
    if ((position == 16) && (spielfeld[11] != 12) && (spielfeld[16] != 17))
    {
        return 2;
    }
    if ((position == 17) && (spielfeld[15] != 16) && (spielfeld[19] != 20) && (spielfeld[17] != 18))
    {
        return 2;
    }
    if ((position == 18) && (spielfeld[16] != 17) && (spielfeld[12] != 13))
    {
        return 2;
    }
    if ((position == 19) && (spielfeld[10] != 11) && (spielfeld[19] != 20))
    {
        return 2;
    }
    if ((position == 20) && (spielfeld[16] != 17) && (spielfeld[18] != 19) && (spielfeld[22] != 23) && (spielfeld[20] != 21))
    {
        return 2;
    }
    if ((position == 21) && (spielfeld[19] != 20) && (spielfeld[13] != 14))
    {
        return 2;
    }
    if ((position == 22) && (spielfeld[9] != 10) && (spielfeld[22] != 23))
    {
        return 2;
    }
    if ((position == 23) && (spielfeld[19] != 20) && (spielfeld[21] != 22) && (spielfeld[23] != 24))
    {
        return 2;
    }
    if ((position == 24) && (spielfeld[22] != 23) && (spielfeld[14] != 15))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int zugmoeglich(int spieler, int feld[24])
{
    //Diese Funktion gibt 1 zurueck, wenn der spieler einen zug taetigen kann, wenn nicht wird 2 ausgegeben

    //Variablen
    int spielerwert = 0;
    //Spielerwert
    if (spieler == 1)
    {
        spielerwert = 111;
    }
    if (spieler == 2)
    {
        spielerwert = 222;
    }

    for (int i = 1; i <= 24; i++)
    {
        if (feld[i - 1] == spielerwert)
        {
            if ((spielereingebaut(feld, i) == 1))
            {
                return 1;
            }
        }
    }
    return 2;
}