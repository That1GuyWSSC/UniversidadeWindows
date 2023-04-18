"""
Trabalho 2
"""
import ply.lex as plex
import json

tokens = (
    "QUANTIA",
    "PRODUTO",
    "MOEDA",
    "IGUAL",
    "VIRGULA",
    "PONTO",
    "NOME"
    "CANCELAR",
    "OTHER",
    "NL"
)
states = (("COMPRA","exclusive", ), ("INSERIR", "exclusive"), )

saldo = 0.0
estado_maquina = None

conversor_moeda = {
    "c5": 5,
    "c10": 10,
    "c20": 20,
    "c50": 50,
    "e1": 100,
    "e2": 200,
}

def slurp(filename):
    with open(filename, "r") as fh:
        contents = fh.read()
    return contents

def t_CANCELAR(t): # token: "CANCELAR"
    r"CANCELAR"
    devolver_troco(saldo)
    print(f"Valor devolvido: {saldo / 100}€")
    t.lexer.begin("INITIAL")
    pass

def t_PRODUTO(t):   # token: "PRODUTO"
    r"PRODUTO"
    t.lexer.begin("COMPRA")
    pass

def t_QUANTIA(t): # token: "QUANTIA"
    r"QUANTIA"
    t.lexer.begin("INSERIR")
    pass

def t_INSERIR_MOEDA(t):   # token: "MOEDA"
    r"(c|e)\d\d?"
    global saldo
    global estado_maquina
    valor = t.value
    if valor in conversor_moeda:
        saldo += conversor_moeda[valor]
        estado_maquina["moedeiro"][valor] += 1
    else:
        print(f"Moeda {valor} não aceite!")
    pass

def t_INSERIR_VIRGULA(t):   # token: "VIRGULA"
    r","
    pass

def t_INSERIR_PONTO(t):   # token: "PONTO"
    r"\."
    global saldo
    valor_decimal = saldo / 100
    print(f"SALDO: {valor_decimal}€")
    t.lexer.begin("INITIAL")
    pass

def t_COMPRA_EQ(t):   # token: "EQ" = EQUALS
    r"="
    pass

def t_COMPRA_PONTO(t):   # token: "EQ" = EQUALS
    r"\."
    t.lexer.begin("INITIAL")
    pass

def t_COMPRA_NOME(t):   # token: "NOME"
    r"[a-z|A-Z]+"
    global saldo
    global estado_maquina
    nome_produto = t.value
    if nome_produto in estado_maquina["produtos"]:
        preco = estado_maquina["produtos"][nome_produto]["preco"]
        quantidade = estado_maquina["produtos"][nome_produto]["quantidade"]

        if quantidade == 0:
            print(f"Não há artigos do produto {nome_produto}.")
            return

        if saldo < preco:
           print("Não tens dinheiro suficiente.")
        else:
            troco = saldo - preco
            print(f"Compra efetuada. Troco : {troco / 100}€")
            estado_maquina["produtos"][nome_produto]["quantidade"] -= 1
            devolver_troco(troco)
            saldo = 0
    else:
        print(f"Produto {nome_produto} nao existe.")
    pass

def t_ANY_OTHER(t): # token: "OTHER"
    r"."
    pass

def t_ANY_NL(t):   # toke: "NL"
    r"\n"
    pass

def t_error(t):
    print(f"Token not recognized at INITIAL state: {t.value[:10]}")
    exit(1)

def t_COMPRA_error(t):
    print(f"Token not recognized at COMPRA state: {t.value[:10]}")
    exit(1)

def t_INSERIR_error(t):
    print(f"Token not recognized at INSERIR state: {t.value[:10]}")
    exit(1)

def devolver_troco(troco):
    global estado_maquina

    if troco != 0:
        for moeada in sorted(estado_maquina["moedeiro"], key=lambda e: conversor_moeda[e], reverse=True):
            valor_moeada = conversor_moeda[moeada]
            quantidade_moedas = int(troco / valor_moeada)
            if estado_maquina["moedeiro"][moeada] >= quantidade_moedas and troco >= valor_moeada:
                estado_maquina["moedeiro"][moeada] -= quantidade_moedas
                troco -= quantidade_moedas * valor_moeada

            if troco == 0:
                break

def ler_estado_maquina(filename):
    global estado_maquina
    print("Carregar estado da maquina.")
    with open(filename, "r") as fh:
        estado_maquina = json.load(fh)

def gravar_estado_maquina(filename):
    global estado_maquina

    with open(filename, "w") as fh:
        json.dump(estado_maquina, fh)

# carrega o estado inicial da maquina a partir de um ficheiro
ler_estado_maquina("estado_maquina.json")

lexer = plex.lex()
#lexer.input(slurp("exemplo.txt"))
# lexer.token()

for line in iter(lambda: input(">> "), ""):
    lexer.input(line)
    for token in iter(lexer.token, None):
        print(token)
        
gravar_estado_maquina("estado_maquina.json")