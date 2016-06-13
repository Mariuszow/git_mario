#zad

Protok� komunikacyjny obs�uguj�cy kamer�.

Warto�ci mog� by� wpisywane za pomoc� komend lub w trybie odczytu szesnastkowo. Przy wpisywaniu heks�w nale�y je poprzedzi� "0x".

Do dyspozycji mamy:
4 kamery o adresach : 1(0x01) 2(0x02) 3(0x03) 4(0x04)

Funkcje wyst�puj�ce to:
*POWER ON/OFF (kod funkcji to POW a adres funkcji to 0x0A )- funkcja przyjmuje argumenty 0 dla off i 1 dla on
*LIGHT ON/OFF/FLASH (kod funkcji to LGH a adres funkcji to 0x0B )-- funkcja przyjmuje argumenty 0 dla off 1 dla on i 2 b�ysku

Instrukcja obs�ugi: 
1. W oknie podajesz komende dla jednej z czterech kamer: CAM1 - CAM4.
2. Po spacji wpisujemy komend� jednej z funkcji: POW lub LGH. 
3. Nast�pnie argument funkcji ON lub OFF lub te� dodarkowo FLASH dla funkcji LGH.
4. W trybie odczytu wpisujemy warto�ci kt�re wyrzuci nam konsola. Poprzedzamy to -r .
	
Budowa ramki:[komenda_kamery] [komenda_funkcji] [argument_funkcji]
Przyk�ad: zad.exe CAM1 POW ON
Czyli: Kamera nr 1, funkcja POWER, argument ON
Wynik:0x01 0x0A 0x01 0xF3
Czyli:[adres_urz�dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna1]

Budowa ramki:[-r] [adres_urz�dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna1]
Przyk�ad: zad.exe -r 0x01 0x0A 0x01 0xF3
Czyli: tryb odczytu, kamera nr 1,  funkcja power, w��czona, suma kontrolna1
Wynik: 0x01 0x0A 0x01 0xF3 0xE7 0x00
Czyli:[adres_urz�dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna1] [suma_kontrolna2] [kod_b��du]

KODY BLEDOW:
0x00 EVERYTHING_OK
0x01 WRONG_CAMERA_ADDRESS
0x02 WRONG_FUNCTION_CODE
0x03 WRONG_ARGUMENT
0x04 WRONG_CHECKSUM
0x05 WRONG_FUNCTION_COMMAND