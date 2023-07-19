def main():
    # Pido el input al usuario.
    texto = input("Text: ")

    # Verifico cuantas letras tiene el texto.
    l = cuenta_letras(texto)
    l = float(l)

    # Verifico cuantas palabras tiene el texto.
    p = cuenta_palabras(texto)

    # Verifico cuantas sentencias tiene el texto.
    s = cuenta_sentencias(texto)

    # Calculo y muestro el index.
    pindex(l, p, s)


# Calculo cuantas letras hay, necesito el texto.
def cuenta_letras(i):
    letras = 0
    j = 0
    while j < len(i):
        if i[j].isalpha():
            letras += 1
        j += 1
    return letras


# Calculo cuantas palabras hay, necesito el texto.
def cuenta_palabras(a):
    palabras = 1
    j = 0
    while j < len(a):
        if a[j] == ' ':
            palabras += 1
        j += 1
    return palabras


# Calculo cuantas sentencias hay, necesito el texto.
def cuenta_sentencias(a):
    sentencias = 0
    j = 0
    while j < len(a):
        match a[j]:
            case '.' | '!' | '?':
                sentencias += 1
        j += 1
    return sentencias


# Calculo el index y lo imprimo, necesito letras, palabras y sentencias.
def pindex(i, j, k):
    l = (i / j) * 100
    s = (k / j) * 100
    index = round(0.0588 * l - 0.296 * s - 15.8)
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()
