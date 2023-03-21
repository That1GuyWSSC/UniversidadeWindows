"""
ESI pós-laboral (Processamento de Linguagens)
Aula 10 -   16/março quarta-feira, 20:30-22:30
"""

# -----
# definição do Autómato Finito 
#    AF=(V,Q,delta,q0,F) tal que:
V = {"a", "b"}
Q = { "q0", "q1", "q2"}
# delta = {   "q0": { "a":"q1", "b":"Erro"},
# 	        "q1": { "a":"Erro", "b":"q2"},
# 	        "q2": { "a":"q2", "b":"q2"},
#             #"q3": { "a":"q3", "b":"q3"},#
#         	}

delta = {   "q0": { "a":"q1"},
	        "q1": { "b":"q2"},
	        "q2": { "a":"q2", "b":"q2"},
            #"q3": { "a":"q3", "b":"q3"},#
        	}
q0 = "q0"
F = {"q2"}

# -----
# especificação da função para avaliar se uma dada 
# palavra é reconhecida reconhecida no Autómato AF 
def reconhece(palavra:str): # aba
	estado_atual = q0
	tam = len(palavra)
	i = 0
	while (i<tam) and (estado_atual != "Errro"):
		simbolo_atual = palavra[i] 
		#if (simbolo_atual in V) and (simbolo_atual in delta[estado_atual1]):
		if (simbolo_atual in delta[estado_atual]):
            estado_atual = delta[estado_atual][simbolo_atual]
		else:
		    estado_atual = "Erro"
		i+=1
	return (estado_atual in F)	and (i==tam)

# -----
# Exemplos de utilização da função reconhece 
for exemplo in ["ab", "aba", "abb", "a", "aa", "ba","abc"]:
	print(f"'{exemplo}'\t{reconhece(exemplo)}")

# ----- 
# como utilizar 
#  >python3 aula09.py
# resultado apresentado 
#  'ab'    True
#  'aba'   True
#  'abb'   True
#  'a'     False
#  'aa'    False
#  'ba'    False