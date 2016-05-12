#zad

Protok� komunikacyjny obs�uguj�cy kamer�.

Warto�ci mog� by� wpisywane zar�wno w heksach jak i systemie dziesi�tnym. Przy wpisywaniu heks�w nale�y je poprzedzi� "0x".

Do dyspozycji mamy:
4 kamery o adresach : 1(0x01) 2(0x02) 3(0x03) 4(0x04)

Funkcje wyst�puj�ce to:
*POWER ON/OFF (kod funkcji to 0xA lub 10)- funkcja przyjmuje argumenty 0 dla off i 1 dla on
*ZOOM LEVEL(1-5)(kod funkcji to 0xB lub 11)- - funkcja przyjmuje argumenty od 0 do 5 dla poszczeg�lnych poziom�w zbli�enia
*LIGHT ON/OFF/FLASH (kod funkcji to 0xC lub 12)-- funkcja przyjmuje argumenty 0 dla off 1 dla on i 2 b�ysku

Instrukcja obs�ugi: 
1. W oknie podajesz komende dla jednej z trzech funkcji (dla POWER jest to POW, dla ZOOM jest to ZOO a dla LIGHT LGH).
2. W wyniku wpisania komendy np. zad.exe POW otrzymujesz: komend� wpisan�, informacj� o poprawno�ci (0x01 gdy poprawna, 0x11 gdy b��dna),
    ilo�� argument�w jak� przyjmuje funkcja np. 0x02, oraz sum� kontroln�.
3. W trybie odczytu mo�esz sprawdzi� poprawno�� wpisanych warto�ci np. zad.exe -r 1 10 1 lub te� zad.exe -r 0x01 0x0A 0x01. W wyniku wpisania funkcji otrzymasz:
    0x01 0x0A 0x01 0xF3 0x00
	
Budowa ramki:[komenda_funkcji]
Przyk�ad: zad.exe LGH
Czyli: Funkcja LIGHT
Wynik:LGH 0x01 0x03 0xF3
Czyli:[komenda_funkcji] [kod_b��du] [ilo��_argument�w] [suma_kontrolna]

Budowa ramki:[-r] [adres_urz�dzenia] [adres_funkcji] [argument_funkcji]
Przyk�ad: zad.exe -r 1 10 1
Czyli: tryb odczytu, kamera nr 1,  funkcja power, w��czona
Wynik: 0x01 0x0A 0x01 0xF3 0x00
Czyli:[adres_urz�dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna] [kod_b��du]

KODY BLEDOW:
0x00 EVERYTHING_OK
0x01 WRONG_CAMERA_ADDRESS
0x02 WRONG_FUNCTION_CODE
0x03 WRONG_ARGUMENT
0x04 WRONG_CHECKSUM
0x05 WRONG_FUNCTION_COMMAND