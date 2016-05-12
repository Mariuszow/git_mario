#zad

Protokó³ komunikacyjny obs³uguj¹cy kamerê.

Wartoœci mog¹ byæ wpisywane zarówno w heksach jak i systemie dziesiêtnym. Przy wpisywaniu heksów nale¿y je poprzedziæ "0x".

Do dyspozycji mamy:
4 kamery o adresach : 1(0x01) 2(0x02) 3(0x03) 4(0x04)

Funkcje wystêpuj¹ce to:
*POWER ON/OFF (kod funkcji to 0xA lub 10)- funkcja przyjmuje argumenty 0 dla off i 1 dla on
*ZOOM LEVEL(1-5)(kod funkcji to 0xB lub 11)- - funkcja przyjmuje argumenty od 0 do 5 dla poszczególnych poziomów zbli¿enia
*LIGHT ON/OFF/FLASH (kod funkcji to 0xC lub 12)-- funkcja przyjmuje argumenty 0 dla off 1 dla on i 2 b³ysku

Instrukcja obs³ugi: 
1. W oknie podajesz komende dla jednej z trzech funkcji (dla POWER jest to POW, dla ZOOM jest to ZOO a dla LIGHT LGH).
2. W wyniku wpisania komendy np. zad.exe POW otrzymujesz: komendê wpisan¹, informacjê o poprawnoœci (0x01 gdy poprawna, 0x11 gdy b³êdna),
    iloœæ argumentów jak¹ przyjmuje funkcja np. 0x02, oraz sumê kontroln¹.
3. W trybie odczytu mo¿esz sprawdziæ poprawnoœæ wpisanych wartoœci np. zad.exe -r 1 10 1 lub te¿ zad.exe -r 0x01 0x0A 0x01. W wyniku wpisania funkcji otrzymasz:
    0x01 0x0A 0x01 0xF3 0x00
	
Budowa ramki:[komenda_funkcji]
Przyk³ad: zad.exe LGH
Czyli: Funkcja LIGHT
Wynik:LGH 0x01 0x03 0xF3
Czyli:[komenda_funkcji] [kod_b³êdu] [iloœæ_argumentów] [suma_kontrolna]

Budowa ramki:[-r] [adres_urz¹dzenia] [adres_funkcji] [argument_funkcji]
Przyk³ad: zad.exe -r 1 10 1
Czyli: tryb odczytu, kamera nr 1,  funkcja power, w³¹czona
Wynik: 0x01 0x0A 0x01 0xF3 0x00
Czyli:[adres_urz¹dzenia] [adres_funkcji] [argument_funkcji] [suma_kontrolna] [kod_b³êdu]

KODY BLEDOW:
0x00 EVERYTHING_OK
0x01 WRONG_CAMERA_ADDRESS
0x02 WRONG_FUNCTION_CODE
0x03 WRONG_ARGUMENT
0x04 WRONG_CHECKSUM
0x05 WRONG_FUNCTION_COMMAND