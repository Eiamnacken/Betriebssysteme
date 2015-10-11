#!/bin/sh


#.--    .-""-.
#.   ) (     )
#.  (   )   (
#.     /     )
#.    (_    _)                     0_,-.__
#.      (_  )_                     |_.-._/
#.       (    )                    |lulz..\
#.        (__)                     |__--_/
#.     |''   ``\                   |
#.     | [Lulz] \                  |      /b/
#.     |         \  ,,,---===?A`\  |  ,==y'
#.   ___,,,,,---==""\        |M] \ | ;|\ |>
#.           _   _   \   ___,|H,,---==""""bno,
#.    o  O  (_) (_)   \ /          _     AWAW/
#.                     /         _(+)_  dMM/
#.      \@_,,,,,,---=="   \      \\|//  MW/
#.--''''"                         ===  d/
#.                                    //   SET SAIL FOR FAIL!
#.                                    ,'_________________________
#.   \    \    \     \               ,/~~~~~~~~~~~~~~~~~~~~~~~~~~~
#.                         _____    ,'  ~~~   .-""-.~~~~~~  .-""-.
#.      .-""-.           ///==---   /`-._ ..-'      -.__..-'
#.            `-.__..-' =====\\\\\\ V/  .---\.
#.                     ~~~~~~~~~~~~, _',--/_.\  .-""-.
#.                            .-""-.___` --  \|         -.__..-


# Dieses Programm erstellt einen Porjekt ordner für ein C projekt mit dem dazugehörigen makefile um das erstellen zu erleichtern
# Es wird wie folgt erstellt
# Es wird einen Großen Ordner geben der den Projekt namen erhält
# Dort wird sich ein Header Ordern so wie ein source ordner finden in dem sich der Quellcode befindet
# Im lib ordner finden sich dann die Objekt dateien z.B. beispiel.o
# Im root ordner findet sich das Makefile und das ausführbare Programm
# Die erste Quell datei wird dabei immer quelle.c benannt




echo "Bitte geben sie an ob sie selber angeben wollen,\ wo ihr Porjekt ordner erstellt werden soll oder ob sie ihn \in diesem ordner erstellt haben wollen?\n"
echo "1 für hier erstellen\n"
echo "2 für auswählen wo erstellt werden soll\n"
echo "Default ist 1\n"



ceckDir() {
  true
  }
