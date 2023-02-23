Considere o alfabeto V = {a,b,c,d}.

#exercicios 
1.7. todas palavras iniciadas por zero ou mais símbolos a, seguidos por um ou mais símbolos b;

		a* b+ (a|b|c|d)*

1.8. todas as palavras em que ocorrem no máximo três símbolos c;

		0c: c0 - (a|b|d)*
		1c: c1 - (a|b|d)* c (a|b|d)* 
		2c: c2 - (a|b|d)* c (a|b|d)* c (a|b|d)*
		3c: c3 - (a|b|d)* c (a|b|d)* c (a|b|d)* c (a|b|d)*
		4c: {}
		R: c0|c1|c2|c3
		R: (a|b|d)* (c|E) (a|b|d)* (c|E) (a|b|d)* (c|E) (a|b|d)*

1.9. todas as palavras com um número ímpar de símbolos c;

		0c:{}_
		1c:(a|b|d)* c (a|b|d)*
		2c:{}
		3c:(a|b|d)* c (a|b|d)* (a|b|d)* c (a|b|d)* (a|b|d)* c (a|b|d)*
		4c:{}
		5c: (a|b|d)* c (a|b|d)* (a|b|d)* c (a|b|d)* (a|b|d)* c (a|b|d)* (a|b|d)* c (a|b|d)*(a|b|d)* c (a|b|d)*		
		R: (a|b|d)* c (a|b|d)* (c (a|b|d)* c (a|b|d)* )*

	Exercicio 2:
	
![[Pasted image 20230223214355.png]]

2.1. Descreva por palavras suas a linguagem gerada por cada uma das expressões regulares;

		
   