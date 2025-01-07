# MOVING WINDOW
```
Program do uśredniania różnego rodzaju danych z pliku .csv, jako seprator powinien być użyty średnik.

Rezultatem jest plik .csv z 4 kolumnami:
 - Pierwsza – powielone wejście
 - Druga    – wynik średniej kroczącej dla danej próbki.
 - Trzecia  – wynik kroczącego maximum dla danej próbki.
 - Czwarta  – wynik kroczącego minimum dla danej próbki.
```

# Budowanie na Linux Ubuntu
1. W terminalu wpisc komende "cmake -S . -B build", ktora spowoduje utworzenie pliku "MakeFile" w folderze "build:
2. Wpisać "make -C build", w folderze powstanie plik wykonywalny "MovingWindow"
3. W celu uruchomienia programu nalezy wpisac w terminal nazwe pliku wykonywalnego i po spacji dane do przefiltrowania oraz rozmiar okna np. "MovingWindow TestData 10"
4. Jesli podano poprawna nazwe pliku w folderze powinien powstac plik z przefiltrowanymi danymi

# Budowanie na Windows
1. W terminalu wpisc komende "cmake -S . -B build -G "Unix Makefiles"", ktora spowoduje utworzenie pliku "MakeFile"
2. Reszta czynnosci analogicznie jak w przypadku systemu Linux