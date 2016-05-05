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
1. W oknie podajesz adres urz�dzenia, funkcji i argument. Np. zad.exe 0x01 0xA 0x1 .
2. W wyniku dzia�ania programu otrzymujemy: Adres kamery, rodzaj funkcji, argument wykonywany, sume kontroln� , kod b��du.

KODY BLEDOW:
0x00 EVERYTHING_OK
0x01 WRONG_CAMERA_ADDRESS
0x02 WRONG_FUNCTION_CODE
0x03 WRONG_ARGUMENT
0x04 WRONG_CHECKSUM