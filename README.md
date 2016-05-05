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
1. W oknie podajesz adres urz¹dzenia, funkcji i argument. Np. zad.exe 0x01 0xA 0x1 .
2. W wyniku dzia³ania programu otrzymujemy: Adres kamery, rodzaj funkcji, argument wykonywany, sume kontroln¹ , kod b³êdu.

KODY BLEDOW:
0x00 EVERYTHING_OK
0x01 WRONG_CAMERA_ADDRESS
0x02 WRONG_FUNCTION_CODE
0x03 WRONG_ARGUMENT
0x04 WRONG_CHECKSUM