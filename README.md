#zad

Protokó³ komunikacyjny obs³uguj¹cy kamerê.

Wartoœci mog¹ byæ wpisywane za pomoc¹ komend lub w trybie odczytu szesnastkowo. Przy wpisywaniu heksów nale¿y je poprzedziæ "0x".

Do dyspozycji mamy:
4 kamery o adresach : 1(0x01) 2(0x02) 3(0x03) 4(0x04)

Funkcje wystêpuj¹ce to:
*POWER ON/OFF (kod funkcji to POW a adres funkcji to 0x0A )- funkcja przyjmuje argumenty 0 dla off i 1 dla on
*LIGHT ON/OFF/FLASH (kod funkcji to LGH a adres funkcji to 0x0B )-- funkcja przyjmuje argumenty 0 dla off 1 dla on i 2 b³ysku

Instrukcja obs³ugi: 
1. W oknie podajesz komende dla jednej z czterech kamer: CAM1 - CAM4.
2. Po spacji wpisujemy komendê jednej z funkcji: POW lub LGH. 
3. Nastêpnie argument funkcji ON lub OFF lub te¿ dodarkowo FLASH dla funkcji LGH.
4. W trybie odczytu wpisujemy wartoœci które wyrzuci nam konsola. Poprzedzamy to -r .
	
Budowa ramki:[komenda_kamery] [komenda_funkcji] [argument_funkcji]
Przyk³ad: zad.exe CAM1 POW ON
Czyli: Kamera nr 1, funkcja POWER, argument ON
Wynik:0x01 0x0A 0x01 0xF3
Czyli:[adres_urz¹dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna1]

Budowa ramki:[-r] [adres_urz¹dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna1]
Przyk³ad: zad.exe -r 0x01 0x0A 0x01 0xF3
Czyli: tryb odczytu, kamera nr 1,  funkcja power, w³¹czona, suma kontrolna1
Wynik: 0x01 0x0A 0x01 0xF3 0xE7 0x00
Czyli:[adres_urz¹dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna1] [suma_kontrolna2] [kod_b³êdu]

KODY BLEDOW:
0x00 EVERYTHING_OK
0x01 WRONG_CAMERA_ADDRESS
0x02 WRONG_FUNCTION_CODE
0x03 WRONG_ARGUMENT
0x04 WRONG_CHECKSUM
0x05 WRONG_FUNCTION_COMMAND