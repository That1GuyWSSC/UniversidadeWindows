'''
d = {"0" | "1" | "..." | "9"}
expressao regular = -?d\.ddE-?d+
'''
# ----
# O que foi mudado nesta versao
# o automato agora aceita todos os digitos a seguir ao "."
#  portanto nao esta limitado a receber so 2 digitos tal como na outra versao

simbolos = { "-", ".", "E"}
V = { str(x) for x in range(0,10) } | simbolos
Q = { "q0", "q1", "q2", "q3", "q4", "q5", "q6" }
F = { "q6" }
q0 = "q0"

delta = {
    "q0": { "-" : "q1" , "digito" : "q2" },
    "q1": { "digito" : "q2" },
    "q2": { ".": "q3" },
    "q3": { "digito": "q3", "E": "q4" },
    "q4": { "digito": "q6", "-": "q5"},
    "q5": { "digito": "q6" },
    "q6": { "digito": "q6" },
}

print(V)

def edigito(c):
    return c in (V - simbolos)

# -----
# especificação da função para avaliar se uma dada
# palavra é reconhecida reconhecida no Autómato AF
def reconhece(palavra: str):
    estado_atual = q0
    tam = len(palavra)
    i = 0
    while (i < tam) and (estado_atual != "Erro"):
        simbolo_atual = palavra[i]

       
        # verificar se é digito
        if (edigito(simbolo_atual)) and ("digito" in delta[estado_atual]):
            estado_atual = delta[estado_atual]["digito"]

        # verificar se é um simbolo (., -, E)
        elif (simbolo_atual in simbolos) and (simbolo_atual in delta[estado_atual]):
            estado_atual = delta[estado_atual][simbolo_atual]

        else:
            estado_atual = "Erro"

        #print(estado_atual)
        i+=1

    return (estado_atual in F) and (i==tam)

# -----
# Exemplos de utilização da função reconhece
for exemplo in [
    "7.58E-10",
    "7.583213123213E10",
    "7.5E1",
    "4.E7",
    "7.58E",
    "-7.58E17",
    "4E-1",
        
]:
    print(f"'{exemplo}'\t{reconhece(exemplo)}")
