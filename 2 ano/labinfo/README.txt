## Scripts essenciais para um SysAdmin ##

Neste projeto desenvolvi vários scripts que podem ser usados por um sysadmin, para automatizar as suas tarefas diárias. Eles foram feitos em powershell, portanto o único sistema operativo que funciona é o Windows.

## Copias de segurança + Email ##

Este script fáz uma cópia de segurança na primeira parte para o PATH indicado e manda um email a pessoa destinada, com a informação indicada. Se for preciso enviar um ficheiro em conjunto, tirar o commentario do parametro no final da codigo e colocar o PATH do ficheiro.

Para este script funcionar, precisa de colocar os PATH certos nas variaveis apropriadas.

Na segunda parte do script, subsitituir também as variaveis pelas suas informações corretas.

## Informacao do computador ##

Este script recollhe Informacao do computador local e aloca a informação num outro ficheiro.

Para funcionar, mudar o ficheiro de output e o resto dos "Add-Content"

## Progamador de tarefas ##

Este script agenda duas tarefas para executarem num certo tempo na maquina local.

Para este funcionar, mudar o PATH das duas variaveis "$acao" e "$cao2".

Mudar a hora das tarefas também é facil, basta mudar na variavel "$trigger".

Alterar o userid da script para o respetivo do seu computador, e se quiser mudar o nome da tarefa, muda no comando "Register-ScheduledTask" entre as aspas.

