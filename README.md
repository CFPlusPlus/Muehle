# Muehle
The Game Muehle coded in C

Allgemein

Ziele	
2 Spieler Modus	
Konsolenausgabe (Text/Zeichen)	
Spielregelkonform	

Nicht Ziele
KI/Computer
grafische Oberfläche

Spielregeln
Setzphase
•	Spieler 1 & 2 setzten nacheinander ihre Steine
•	Weiß beginnt 
•	Erstellt ein Spieler eine Mühle (3 Steine in einer Reihe) darf er einen gegnerischen Stein entfernen

Zugphase
Die Spielsteine werden gezogen, das heißt, pro Runde darf jeder Spieler einen Stein auf einen angrenzenden, freien Punkt bewegen. Kann ein Spieler keinen Stein bewegen, so hat er verloren.
Endphase (Springphase)
Sobald ein Spieler nur noch drei Steine hat, darf er mit seinen Steinen springen, das heißt, er darf nun pro Runde mit einem Stein an einen beliebigen freien Punkt springen. Sobald ihm ein weiterer Stein abgenommen wird, hat er das Spiel verloren.

C-Programm
Spielfarben
•	Spieler 1: Rot
•	Spieler 2: Blau
Spielfeld
•	Wird in ein Array gespeichert (1 oder 2 Dimensional?)
Spielfeldanzeige
Ausgabe auf Konsole (Farbige Spielsteine)
