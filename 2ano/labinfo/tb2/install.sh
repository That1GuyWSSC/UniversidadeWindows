#!/bin/bash

# My first script

echo "Hello World!"
mkdir videoteca
cd videoteca
touch informacao
echo "Bem vindo a tua propria videoteca." >> informacao
echo "Que tipo de filmes gostas?"
read tipo
echo "eu tmb gosto de $tipo"
mkdir top10
cd top10

#Inicio da parte de Shawshank

mkdir "The Shawshank Redemption"
cd "The Shawshank Redemption"
echo "Tim Robbins 	... 	Andy Dufresne
Morgan Freeman 	... 	Ellis Boyd 'Red' Redding
Bob Gunton 	... 	Warden Norton
William Sadler 	... 	Heywood
Clancy Brown 	... 	Captain Hadley
Gil Bellows 	... 	Tommy
Mark Rolston 	... 	Bogs Diamond
James Whitmore 	... 	Brooks Hatlen
Jeffrey DeMunn 	... 	1946 D.A.
Larry Brandenburg 	... 	Skeet
Neil Giuntoli 	... 	Jigger
Brian Libby 	... 	Floyd
David Proval 	... 	Snooze
Joseph Ragno 	... 	Ernie
Jude Ciccolella 	... 	Guard Mert
Paul McCrane 	... 	Guard Trout" >> castinfo

#Fim De Shawshank

#Inicio da parte do The Godfather

cd ..
mkdir "The Godfather"
cd "The Godfather"

echo "    Marlon Brando (Don Vito Corleone)
    Al Pacino (Michael Corleone)
    James Caan (Sonny Corleone)
    Robert Duvall (Tom Hagen)
    Diane Keaton (Kay Adams)
    Talia Shire (Connie)
    John Cazale (Fredo)
    Abe Vigoda (Tessio)

										" >> castinfo


#Fim da parte do GodFather

#Incio da parte do The Godfather: Part II

cd ..
mkdir "The Godfather: Part II"
cd "The Godfather: Part II"

echo "    Al Pacino (Michael Corleone)
    Robert De Niro (Vito Corleone)
    Robert Duvall (Tom Hagen)
    Diane Keaton (Kay Corleone)
    John Cazale (Fredo Corleone)
    Talia Shire (Connie Corleone)
    Lee Strasberg (Hyman Roth)
    Michael V. Gazzo (Frankie Pentangeli)

" >> castinfo

#Fim da parte do Godfather part II










#Apagar a video todo os ficheiros da videoteca incluinda a propria diretoria
cd ..
touch apagar.sh
echo "#!/bin/bash
      cd ..
      rm -rf videoteca/" >> apagar.sh
      chmod +x apagar.sh