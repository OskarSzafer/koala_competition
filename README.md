# koala competition

## decryption
Napiszcie program, który odszyfruje dany szyfrogram uzyskany metodą kolumnowego szyfru przestawieniowego, dla którego zastosowano dany klucz. Program powinien wypisać odszyfrowany tekst jako jeden scalony
ciąg znaków.

Uwaga: Przyjmijcie, że tekst szyfrogramu nie zawiera polskich znaków diakrytycznych oraz, że liczby tworzące klucz
szyfrowania są wprowadzane do programu jako ciąg liczb oddzielonych pojedynczą spacją.

metoda szyfrowania:
- Tekst jawny należy odpowiednio przygotować, tj. cały tekst należy zapisać używając wyłącznie drukowanych wielkich liter, usuwając przy tym wszelkie odstępy i znaki niebędące literami bądź cyframi.
- Należy przygotować tzw. klucz i tabelę – liczbę kolumn w tabeli określa długość klucza. Klucz jest ciągiem liczb złożonym z n niepowtarzających się dodatnich liczb naturalnych, mniejszych lub równych n. Liczba n jest większa od 1 i mniejsza lub równa długości tekstu jawnego.
- Tekst jawny wprowadzany jest znak po znaku do kolejnych wierszy tabeli, w kierunku od lewej do prawej.
- Należy przeczytać kolumnami tekst z tabeli, przy czym klucz określa kolejność odczytywania kolumn.

## expansion
Napiszcie program, który dla zadanej liczby naturalnej 2 <= k <= 16 wyznacza najmniejszą potęgę liczby k (program powinien zwracać potęgę, a nie wykładnik), która nie występuje w ciągu zdefiniowanym poniżej:
- Pierwszy wyraz ciągu jest równy 1.
- Aby wyznaczyć kolejny wyraz, należy zapisać najpierw wszystkie poprzednie wyrazy ciągu w systemie liczbowym o podstawie k. Liczba cyfr potrzebnych do ich zapisania to kolejny wyraz ciągu.

## gutter system
Rysunek poniżej ukazuje projekt ściany wodnej, umieszczony w układzie współrzędnych OXY . Ze szczytu
ściany na długości 15 m wypływa ze stałą szybkością 15 l wody w ciągu sekundy, rozłożone równomiernie.
Znaczna część wody trafia do pochyłych rynien, które na rysunku są przedstawione jako odcinki. Woda
spływa rynnami i dalej spada pionowo w dół, aż do napotkania kolejnej rynny lub osiągnięcia ziemi, w której
znajduje się odpływ.

![gutter_system](https://github.com/OskarSzafer/koala_competition/blob/main/images/gutter_system_explanation.png?raw=true)

Ze szczytu ściany na długości 15 m wypływa ze stałą szybkością 15 l
wody w ciągu sekundy, rozłożone równomiernie. Dana jest dodatnia liczba całkowita n ¬ 10, oznaczająca
liczbę rynien oraz 2n par liczb całkowitych, z zakresu od 1 do 14, określających położenie rynien. Każde
kolejne dwie pary liczb dotyczą jednej rynny: pierwsza para określa współrzędne (x, y) początku rynny, a
druga para – współrzędne (x, y) końca tej rynny.
Napiszcie program, który wyznacza liczbę litrów wody, która spływa z poszczególnych rynien w ciągu sekundy.
Przyjmijcie, że wśród rynien nie ma dwóch takich, które mają jakikolwiek punkt wspólny. Nie ma dwóch takich, które
miałyby tę samą odciętą (współrzędną x) początku rynny, ani nie ma dwóch takich rynien, które miałyby tę samą odciętą
końca rynny.
