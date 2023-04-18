import ply.lex as plex
from my_lib import slurp
tokens = ("I", "V", "IV", "NL", "OTHER")

t_ignore=" \t\n"

def t_IV(t):
    r"IV"
    t.value = 4  
    return t


def t_I(t):
    r"I{1,3}"
    t.value = len(t.value)
    return t


def t_V(t):
    r"V"
    t.value = 5 
    return t


def t_OTHER(t):
    r".|\n"    
    return t
    # pass

def t_error(t):
    print("Token not recognized: {t.value[:10]}")
    exit(1)


lexer = plex.lex()
#lexer.input("IV")
#lexer.token()


lexer.input("I  V IV\nII\tIII\tIIII")
total = 0
for t in iter(lexer.token, None):
    total += t.value
    print(t)
    # todo: completar com o tipo de toke devolvido!!
     
    

print(f"value: {total}")