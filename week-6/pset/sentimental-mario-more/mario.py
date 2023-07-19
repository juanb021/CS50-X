def main():
    h = get_height()
    printm(h)


def get_height():
    # Creo un ciclo infinito.
    while True:
        # Pido la altura de la piramide al usuario.
        try:
            n = int(input("Height "))
            # Si la altura esta entre 1 y 8 salgo del ciclo infinito.
            if n > 0 and n <= 8:
                break
        except:
            print("Height should be greater than 0 and less than 9")
    return n


def printm(a):
    # Creo un ciclo para pasar a la siguiente linea de texto.
    for linea in range(a):
        # Creo un ciclo que imprima los espacios en blanco.
        for espacio in range(a - linea - 1):
            print(" ", end='')
        # Imprimo un ciclo que imprima los hash
        for columna in range(linea + 1):
            print("#", end='')
        # Imprimo los 2 espacios.
        print("  ", end='')
        # Creo un ciclo que imprima los hash del otro lado.
        for columna in range(linea + 1):
            print("#", end='')
        # Paso a la siguiente linea.
        print('')


main()

