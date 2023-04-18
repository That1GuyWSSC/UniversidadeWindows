"""
Trabalho 2
"""
import ply.lex as plex

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

saldo = 0

estado_maquina = {
    "produtos": {
        "twix": {"preco": 2.3, "quantidade": 10 },
        "mars": {"preco": 2.1, "quantidade": 10 },
    },
    "moedeiro": {
        "c5": 10,
        "c10": 10,
        "c20": 10,
        "c50": 20,
        "e1": 10,
        "e2": 10,
    },
}

conversor_moeda = {
    "c5": 0.05,
    "c10": 0.1,
    "c20": 0.2,
    "c50": 0.5,
    "e1": 1.0,
    "e2": 2.0,
}

def slurp(filename):
    with open(filename, "r") as fh:
        contents = fh.read()
    return contents

def t_CANCELAR(t): # token: "CANCELAR"
    r"CANCELAR"
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
    r"(c(1|2|5)0?|e(1|2))"
    global saldo
    saldo += conversor_moeda[t.value]
    pass

def t_INSERIR_VIRGULA(t):   # token: "VIRGULA"
    r","
    pass

def t_INSERIR_PONTO(t):   # token: "PONTO"
    r"\."
    global saldo
    print(f"SALDO: {saldo}")
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
    nome_produto = t.value
    if nome_produto in estado_maquina["produtos"]:
       print("Existe")
       if saldo < estado_maquina["produtos"][nome_produto]["preco"]:
           print("nao tens dinheiro sufficiente")
       else:
           print("Compra efetuada")
        # TODO: adicinar logica para atualizar estado da maquina
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
    
lexer = plex.lex()
lexer.input(slurp("exemplo.txt"))

lexer.token()


# print(f"soma: {somatorio}")