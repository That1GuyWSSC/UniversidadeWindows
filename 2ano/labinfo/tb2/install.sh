#!/bin/bash

# My first script

#Variaveis
NOW=$(date +"%d/%m/%Y")
DIR=/home/$USER/


#Inicio da videoteca
mkdir videoteca
chmod 777 videoteca
cd videoteca
touch informacao
echo "Bem vindo a tua propria videoteca.
A videoteca foi criada a $NOW, mas a informacao dos filmes e ficheiros foi retirada antes de dezemebro de 2021. " >> informacao
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
Release date: October 14, 1994 (United States)
Country of origin: United States
Language: English
Filming locations: 127A Smithfield Road, Frederiksted, Virgin Islands
Production company: Castle Rock Entertainment   
Genero do filme : Drama" >> detalhes

echo "Chronicles the experiences of a formerly successful banker as a prisoner in the gloomy jailhouse of Shawshank after being found guilty of a crime he did not commit. The film portrays the man's unique way of dealing with his new, torturous life; along the way he befriends a number of fellow prisoners, most notably a wise long-term inmate named Red." >> resumo

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
Genero do filme : Drama e Crime
" >> detalhes

echo "The Godfather "Don" Vito Corleone is the head of the Corleone mafia family in New York. He is at the event of his daughter's wedding. Michael, Vito's youngest son and a decorated WW II Marine is also present at the wedding. Michael seems to be uninterested in being a part of the family business. Vito is a powerful man, and is kind to all those who give him respect but is ruthless against those who do not. But when a powerful and treacherous rival wants to sell drugs and needs the Don's influence for the same, Vito refuses to do it. What follows is a clash between Vito's fading old values and the new ways which may cause Michael to do the thing he was most reluctant in doing and wage a mob war against all the other mafia families which could tear the Corleone family apart." >> resumo

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

echo "The continuing saga of the Corleone crime family tells the story of a young Vito Corleone growing up in Sicily and in 1910s New York; and follows Michael Corleone in the 1950s as he attempts to expand the family business into Las Vegas, Hollywood and Cuba." >> resumo

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

echo "Set within a year after the events of Batman Begins (2005), Batman, Lieutenant James Gordon, and new District Attorney Harvey Dent successfully begin to round up the criminals that plague Gotham City, until a mysterious and sadistic criminal mastermind known only as The Joker appears in Gotham, creating a new wave of chaos. Batman's struggle against The Joker becomes deeply personal, forcing him to confront everything he believes and improve his technology to stop him. A love triangle develops between Bruce Wayne, Dent, and Rachel Dawes." >> resumo

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

echo "The defense and the prosecution have rested, and the jury is filing into the jury room to decide if a young man is guilty or innocent of murdering his father. What begins as an open-and-shut case of murder soon becomes a detective story that presents a succession of clues creating doubt, and a mini-drama of each of the jurors' prejudices and preconceptions about the trial, the accused, AND each other. Based on the play, all of the action takes place on the stage of the jury room." >> resumo

#fim da parte do 12 angry men

#comeco da parte de Schindler's List (1993)

cd ..
mkdir Schindlers_List
cd Schindlers_List
echo "Liam Neeson     Oskar Schindler
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

echo "Oskar Schindler is a vain and greedy German businessman who becomes an unlikely humanitarian amid the barbaric German Nazi reign when he feels compelled to turn his factory into a refuge for Jews. Based on the true story of Oskar Schindler who managed to save about 1100 Jews from being gassed at the Auschwitz concentration camp, it is a testament to the good in all of us." >> resumo


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

echo "The final confrontation between the forces of good and evil fighting for control of the future of Middle-earth. Frodo and Sam reach Mordor in their quest to destroy the One Ring, while Aragorn leads the forces of good against Sauron's evil army at the stone city of Minas Tirith." >> resumo


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
Amanda Plummer  Harvey Keitel 
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

echo "Jules Winnfield (Samuel L. Jackson) and Vincent Vega (John Travolta) are two hit men who are out to retrieve a suitcase stolen from their employer, mob boss Marsellus Wallace (Ving Rhames). Wallace has also asked Vincent to take his wife Mia (Uma Thurman) out a few days later when Wallace himself will be out of town. Butch Coolidge (Bruce Willis) is an aging boxer who is paid by Wallace to lose his fight. The lives of these seemingly unrelated people are woven together comprising of a series of funny, bizarre and uncalled-for incidents" >> resumo


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

echo "Blondie, The Good (Clint Eastwood), is a professional gunslinger who is out trying to earn a few dollars. Angel Eyes, The Bad (Lee Van Cleef), is a hitman who always commits to a task and sees it through--as long as he's paid to do so. And Tuco, The Ugly (Eli Wallach), is a wanted outlaw trying to take care of his own hide. Tuco and Blondie share a partnership making money off of Tuco's bounty, but when Blondie unties the partnership, Tuco tries to hunt down Blondie. When Blondie and Tuco come across a horse carriage loaded with dead bodies, they soon learn from the only survivor, Bill Carson (Antonio Casale), that he and a few other men have buried a stash of gold in a cemetery. Unfortunately, Carson dies and Tuco only finds out the name of the cemetery, while Blondie finds out the name on the grave. Now the two must keep each other alive in order to find the gold. Angel Eyes (who had been looking for Bill Carson) discovers that Tuco and Blondie met with Carson and knows they know where the gold is; now he needs them to lead him to it. Now The Good, the Bad, and the Ugly must all battle it out to get their hands on $200,000.00 worth of gold. " >> resumo 

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

echo "An ancient Ring thought lost for centuries has been found, and through a strange twist of fate has been given to a small Hobbit named Frodo. When Gandalf discovers the Ring is in fact the One Ring of the Dark Lord Sauron, Frodo must make an epic quest to the Cracks of Doom in order to destroy it. However, he does not go alone. He is joined by Gandalf, Legolas the elf, Gimli the Dwarf, Aragorn, Boromir, and his three Hobbit friends Merry, Pippin, and Samwise. Through mountains, snow, darkness, forests, rivers and plains, facing evil and danger at every corner the Fellowship of the Ring must go. Their quest to destroy the One Ring is the only hope for the end of the Dark Lords reign." >> resumo

#Fim da parte The Lord of the Rings: The Fellowship of the Ring

#Fim da parte dos filmes

#Outros scripts

# Genero dos filmes
cd $HOME/videoteca
echo " grep -r -h "Genero" ~/videoteca/filmes/* " >> genero_filmes.sh 
chmod +x genero_filmes.sh

#Linguas dos filmes
echo " grep -r -h "Languages" ~/videoteca/* " >>  linguas_filmes.sh 
chmod +x linguas_filmes.sh

#Top cast dos filmes
echo "head -n 2 filmes/12_Angry_Men/castinfo filmes/Schindlers_List/castinfo filmes/Lord_of_the_rings_Return_of_the_King/castinfo filmes/The_Good_The_Bad_and_The_Ugly/castinfo filmes/Pulp_Fiction/castinfo filmes/The_Dark_Knight/castinfo filmes/The_Godfather_Part_II/castinfo filmes/The_Godfather/castinfo filmes/The_Lord_of_the_Rings_The_Fellowship_of_the_Ring/castinfo filmes/The_Shawshank_Redemption/castinfo" >> top_cast.sh
chmod +x top_cast.sh


#Apagar a video todo os ficheiros da videoteca incluinda a propria diretoria
cd $HOME/videoteca
touch apagar.sh
echo "#!/bin/bash
      cd ..
      rm -rf videoteca/
      rm -r unzip.sh " > apagar.sh
      chmod +x apagar.sh


# zips videoteca e remove a pasta 
cd $HOME
zip -q -r videoteca.zip videoteca
rm -rf videoteca/

#Script para fazer unzip a videoteca
touch unzip.sh
echo "unzip videoteca.zip
rm -rf videoteca.zip" > unzip.sh
chmod +x unzip.sh

#Final message
echo "Videoteca foi criada, corra a script unzip.sh para fazer unzip a pasta zip."