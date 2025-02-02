#include"header.h"



int pruefen_ob_zahl(char eingabe[GROESSE]) {		// ein string wurde �bergeben. ein integer wert wird �bergeben
	int laenge = 0, fehler = 0, index = 0;	// initialisierungen
	laenge = strlen(eingabe);		// um herauszufinden wie gro� der string ist
	if (eingabe[0] == '+') {		// �berpr�ft ob ein + am anfang steht um es abzufangen
		laenge -= 2;		// wenn ja dann dekrementiert er die l�nge um 2
		for (index = 0; index < laenge; index++) {		// dient dazu um den + weg zu machen und um die zahlen zu vertauschen
			eingabe[index] = eingabe[index + 1];		// tauscht den ersten wert des arrays mit dem n�chsten
			eingabe[index + 1] = 0;		// setzt den n�chsten wert des arrays auf 0
		}
	}
	else {		// wenn die obige bedingung nicht erf�llt wurde dann f�hrt er das aus
		laenge -= 1;	// l�nge wird um 1 dekrementiert. (l�nge--)
	}
	for (index = 0; index < laenge; index++) {		// dient dazu um alle string- zeichen zu �berpr�fen ob auch alle zahlen sind
		if (isdigit(eingabe[index]) == 0) {	// wenn eine 0 zur�ckgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
			fehler++;		// die variable fehler wird incrementiert
		}
	}
	index = 0;		// index wird auf 0 gesetzt
	if (fehler == 0) {		// wenn fehler = 0 ist dann f�hrt er die schleife aus
		index = atoi(eingabe);		// wandelt den string in einen integer wert um und setzt es mit index gleich
	}
	fehler = 0;	// setzt fehler = 0
	return index;	// gibt index wieder zur�ck
}			// ende........

int pruefen_ob_zeichen(char eingabe[GROESSE]) {		// ein string wurde �bergeben. ein integer wert wird �bergeben
	int laenge = 0, fehler = 0, index = 0;	// initialisierungen
	laenge = strlen(eingabe);		// um herauszufinden wie gro� der string ist
	laenge -= 1;	// l�nge wird um 1 dekrementiert. (l�nge--)
	for (index = 0; index < laenge; index++) {		// dient dazu um alle string- zeichen zu �berpr�fen ob auch alle zahlen sind
		if (isdigit(eingabe[index]) != 0) {	// wenn eine 1 zur�ckgegeben wurde(also true) dann ist die stelle des arrays EINE zahl und
			fehler++;		// die variable fehler wird incrementiert
		}
	}
	index = 0;		// index wird auf 0 gesetzt
	if (fehler == 0) {		// wenn fehler = 0 ist dann f�hrt er die schleife aus
		index = 1;		// wandelt den string in einen integer wert um und setzt es mit index gleich
	}
	fehler = 0;	// setzt fehler = 0
	return index;	// gibt index wieder zur�ck
}			// ende........

int pruefen_gueltig(char eingabe[GROESSE]) {	// Funktion
	int i = 0, laenge = 0, fehler = 0, punkt = 0, wert2 = 0, minus = 0;
	int wert = 0;
	laenge = strlen(eingabe);		// laenge von der Anzahl des Strings ausrechnen bzw herausfinden

	if (eingabe[0] == '+') {
		laenge = laenge - 2;		// laenge um 2 Stellen k�rzen wegen dem + am Anfang und \0 ganz zum Schluss
		for (i = 0; i < laenge; i++) {	// Damit man das + weg bekommt
			eingabe[i] = eingabe[i + 1];	// ersetzt die "i.te" stelle mit der "i+1.te stelle
			eingabe[i + 1] = 0;		// setzt die i+1 stelle auf 0
		}
	}
	else {
		laenge--;		// laenge um 1 Stelle k�rzen wegen \0 ganz zum Schluss
	}
	if (eingabe[0] == '-')
	{
		minus++;
	}
	for (i = 0; i < laenge; i++) {
		if (isdigit(eingabe[i]) == 0) {		// kontrolliert ob die "i.te" Stelle von dem String die Werte von 0-9 besitzt,
											// indem es eine "0" also "false" oder eine "1" also "true" als r�ckgabeparameter zur�ck gibt.
			fehler++;			// wenn der rueckgabeparameter von der Funktion isDigit eine 1 ist, setzt er die Variable fehler auf 1.
			if (eingabe[i] == '.') {	// �berpr�ft ob ein '.' also eine Komma vorhanden ist. Bzw mehrere Kommas vorhanden sind
				fehler--;
				punkt++;	// F�r die Fehlerabfange falls mehrere Komams vorhanden sind
			}
		}
	}
	if (minus == 1)
	{
		fehler--;
	}
	if (fehler == 0 && punkt == 0) {		// Falls der User einen Integer Wert eingegeben hat
		wert = 1;
	}
	else if (fehler == 0 && punkt == 1) {		// wenn fehler = 0 ist und punkt = 0 ist f�hrt er das aus
		wert = 1;		// Den String Wert in einen Double Wert umwandeln
									// printf("eingabe:\t%lf\n\n", wert);	// Verwendungszweck: Kontrolle
	}
	else {		// wenn fehler auf 1 gesetzt wurde dann f�hrt er das aus
		printf("Ungueltig.\n\n");
		fehler = 0;		// setzt den fehler Wert wieder auf 0
		wert = 0;
	}
	return wert;	// Gibt eine 0 als 'False' zur�ck
}