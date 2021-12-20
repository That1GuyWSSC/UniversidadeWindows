#!/bin/bash

# My first script

NOW=$(date +"%d/%m/%Y")
DIR=/home/$USER/

mkdir videoteca
cd videoteca
touch informacao
echo "Bem vindo a tua propria videoteca.
A videoteca foi criada a $NOW , mas a informacao dos filmes e ficheiros foi retirada antes de dezemebro de 2021. " >> informacao
mkdir filmes
cd filmes

#Inicio da parte de Shawshank

mkdir The_Shawshank_Redemption
cd The_Shawshank_Redemption
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


echo " 

Release date
    October 14, 1994 (United States)

Country of origin

    United States

Language

    English

Filming locations

    127A Smithfield Road, Frederiksted, Virgin Islands

Production company

    Castle Rock Entertainment   
	
Genero do filme : Drama" >> detalhes

#Fim De Shawshank

#Inicio da parte do The Godfather

cd ..
mkdir The_Godfather
cd The_Godfather

echo "    Marlon Brando (Don Vito Corleone)
    Al Pacino (Michael Corleone)
    James Caan (Sonny Corleone)
    Robert Duvall (Tom Hagen)
    Diane Keaton (Kay Adams)
    Talia Shire (Connie)
    John Cazale (Fredo)
    Abe Vigoda (Tessio)

										" >> castinfo

echo "Release date: March 24, 1972 (United States)
Country of origin: United States
Languages: English Italian Latin
Also known as: Mario Puzo's The Godfather
Filming locations: Forza d'Agrò, Messina, Sicily, Italy

Box office
Budget: $6,000,000 (estimated)
Gross US & Canada: $134,966,411
Opening weekend US & Canada: $302,393Mar 19, 1972
Gross worldwide: $246,120,986
Genero do filme : Drama e Crime
" >> detalhes


#Fim da parte do GodFather

#Incio da parte do The Godfather: Part II

cd ..
mkdir The_Godfather_Part_II
cd The_Godfather_Part_II

echo "    Al Pacino (Michael Corleone)
    Robert De Niro (Vito Corleone)
    Robert Duvall (Tom Hagen)
    Diane Keaton (Kay Corleone)
    John Cazale (Fredo Corleone)
    Talia Shire (Connie Corleone)
    Lee Strasberg (Hyman Roth)
    Michael V. Gazzo (Frankie Pentangeli)

" >> castinfo

echo "Release date: December 18, 1974 (United States)
Country of origin: United States
Languages: English Italian Spanish Latin Sicilian
Also known as: Son of Godfather
Filming locations: Kaiser Estate, 4000 W Lake Blvd, Homewood, Lake Tahoe, California, USA
Production companies: Paramount Pictures The Coppola Company American Zoetrope
Genero do filme : Drama e Crime
" >> detalhes

#Fim da parte do Godfather part II

#inicio da parte do the dark night


cd ..
mkdir The_Dark_Knight
cd The_Dark_Knight
echo "Christian Bale    ...     Bruce Wayne
Heath Ledger    ...     Joker
Aaron Eckhart   ...     Harvey Dent
Michael Caine   ...     Alfred
Maggie Gyllenhaal   ...     Rachel
Gary Oldman     ...     Gordon
Morgan Freeman  ...     Lucius Fox
Monique Gabriela Curnen     ...     Ramirez
Ron Dean    ...     Wuertz
Cillian Murphy  ...     Scarecrow
Chin Han    ...     Lau
Nestor Carbonell    ...     Mayor
Eric Roberts    ...     Maroni
Ritchie Coster  ...     Chechen
Anthony Michael Hall    ...     Engel
Keith Szarabajka    ...     Stephens" >> castinfo

echo "Release date: July 18, 2008 (United States)
Countries of origin: United StatesUnited Kingdom
Languages: English Mandarin
Also known as: Batman Begins 2
Filming locations: Chicago, Illinois, USA
Production companies: Warner Bros Legendary Entertainment Syncopy
Genero do filme: Drama Crime Acao Thriller
" >> detalhes

#fim da parte do the dark night

# comeco da parte de 12 angry men

cd ..
mkdir 12_Angry_Men
cd 12_Angry_Men
echo "    Henry Fonda (Davis/Juror #8)
    Martin Balsam (Juror #1)
    John Fiedler (Juror #2)
    Lee J. Cobb (Juror #3)
    E.G. Marshall (Juror #4)
    Jack Klugman (Juror #5)
    Ed Begley (Juror #10)

" >> castinfo

echo "Release date: April 10, 1957 (United States)
Country of origin: United States
Also known as: Twelve Angry Men
Filming locations: New York County Courthouse - 60 Centre Street, New York City, New York, USA
Production company: Orion-Nova Productions
Genero do filme: Crime e drama" >> detalhes

#fim da parte do 12 angry men

#comeco da parte de Schindler's List (1993)

cd ..
mkdir Schindlers_List
cd Schindlers_List
echo "
Liam Neeson     Oskar Schindler
Ralph Fiennes   Amon Goeth
Andrzej Seweryn     Julian Scherner
Béatrice Macola     Ingrid
Ben Kingsley    Itzhak Stern
Caroline Goodall    Emilie Schindler
Embeth Davidtz  Helen Hirsch
Friedrich von Thun  Rolf Czurda
Harry Nehring   Leo John
Jonathan Sagall     Poldek Pfefferberg
Krzysztof Luft  Herman Toffel
Malgoscha Gebel     Wiktoria Klonowska
Mark Ivanir     Marcel Goldberg
Norbert Weisser     Albert Hujar
Shmuel Levy     Wilek Chilowicz " >> castinfo

echo "Release date: February 4, 1994 (United States)
Country of origin: United States
Languages: English Hebrew German Polish Latin
Also known as: La lista de Schindler
Filming locations: Auschwitz-Birkenau Concentration Camp, Oswiecim, Malopolskie, Poland
Production companies: Universal Pictures Amblin Entertainment
Genero do filme: Biografia Drama e Historia" >> detalhes


#fim da parte da schindler list


#comeco da parte de Lord of the rings return of the king


cd ..
mkdir Lord_of_the_rings_Return_of_the_King
cd Lord_of_the_rings_Return_of_the_King
echo "Elijah Wood    Frodo Baggins 
Ian McKellen    Gandalf 
Viggo Mortensen     Aragorn 
Sean Astin      Samwise Gamgee 
Orlando Bloom   Legolas 
Andy Serkis     Gollum/Sméagol 
Billy Boyd      Pippin 
Dominic Monaghan    Merry 
John Rhys-Davies    Gimli 
Liv Tyler   Arwen 
Bernard Hill    King Théoden 
Miranda Otto    Éowyn 
Hugo Weaving    Elrond 
Cate Blanchett  Galadriel 
David Wenham    Faramir 
Karl Urban  Éomer 
John Noble  Denethor " >> castinfo

echo "Release date: December 17, 2003 (United States)
Countries of origin: New Zealand United States
Languages: English Quenya Old English Sindarin
Also known as: The Return of the King
Filming locations: Hinuera Valley, Matamata, Waikato, New Zealand
Production companies: New Line CinemaWingNut FilmsThe Saul Zaentz Company
Genero do filme: Acao Aventura Drama e Fantasia" >> detalhes


#fim da parte do lotrrotk

# comeco da parte de Pulp fiction

cd ..
mkdir Pulp_Fiction
cd Pulp_Fiction
echo "  
John Travolta 
 
Bruce Willis 
 
Samuel L. Jackson 

Uma Thurman 
 
Christopher Walken 

Ving Rhames Ca

Tim Roth 
 
Amanda Plummer 
 
Harvey Keitel 

Eric Stoltz 
 
Maria de Medeiros

Rosanna Arquette 
 
Peter Greene 

Frank Whaley 

Burr Steers 

Duane Whitaker 
"  >> castinfo

echo "Release date: October 14, 1994 (United States)
Country of origin: United States
Languages: English Spanish French
Also known as: Black Mask
Filming locations: 1435 Flower Street, Glendale, California, USA
Production companies: MiramaxA Band ApartJersey Films
Genero do filme: Crime e Drama " >> detalhes


#fim da parte da pulp fiction



#comeco da parte de the good the bad and the ugly

cd ..
mkdir The_Good_The_Bad_and_The_Ugly
cd The_Good_The_Bad_and_The_Ugly
echo "
Clint Eastwood 
Lee Van Cleef 
Eli Wallach 
Aldo Giuffrè 
Chelo Alonso 
Luigi Pistilli 
Antonio Molino Rojo 
Enzo Petito 
Rada Rassimov 
Claudio Scarchilli 
John Bartha 
Livio Lorenzon 
Antonio Casale 
Sandro Scarchilli 
Benito Stefanelli 
Angelo Novi " >> castinfo

echo "Release date: October 14, 1994 (United States)
Country of origin: United States
Languages: English Spanish French
Also known as: Black Mask
Filming locations: 1435 Flower Street, Glendale, California, USA
Production companies: MiramaxA Band ApartJersey Films
Genero do filme: Aventura Western" >> detalhes

#fim da part the good the bad etc

# comeco da parte de The Lord of the Rings: The Fellowship of the Ring

cd ..
mkdir The_Lord_of_the_Rings_The_Fellowship_of_the_Ring
cd The_Lord_of_the_Rings_The_Fellowship_of_the_Ring
echo "Frodo Baggins Elijah Wood
Gandalf the Grey    Ian McKellen
Arwen Undómiel  Liv Tyler
Aragorn / Strider   Viggo Mortensen
Samwise  Gamgee    Sean Astin
Galadriel   Cate Blanchett
Elrond  Hugo Weaving
Boromir Sean Bean
Bilbo Baggins   Ian Holm
Saruman the White   Christopher Lee
Gimli   John Rhys-Davies" >> castinfo

echo "Release date: December 19, 2001 (United States)
Countries of origin: New Zealand United States
Languages: English Sindarin
Also known as: The Lord of the Rings: The Fellowship of the Ring: The Motion Picture
Filming locations: Wellington, New Zealand
Production companies: New Line Cinema Wing Nut Films The Saul Zaentz Company
Genero do filme: Acao Aventura Drama e Fantasia" >> detalhes


#Outros scripts

# Genero dos filmes
cd $HOME/videoteca
echo " grep -r -h "Genero do filme" videoteca/* " >> genero_filmes.sh 
chmod +x genero_filmes.sh
echo " grep -r "Languages" videoteca/* " >>  linguas_filmes.sh 
chmod +x linguas_filmes.sh
echo " head -n 2 $(find filmes -name "castinfo") " >> top_cast.sh 
chmod +x top_cast.sh







#Apagar a video todo os ficheiros da videoteca incluinda a propria diretoria
cd $HOME/videoteca
touch apagar.sh
echo "#!/bin/bash
      cd ..
      rm -rf videoteca/" >> apagar.sh
      chmod +x apagar.sh


# zips videoteca
zip -r videoteca.zip videoteca
rm -rf videoteca/

echo "Videoteca foi criada."