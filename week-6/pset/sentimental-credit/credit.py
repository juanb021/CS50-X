def main():

    # Pido input al usuario.
    ccn = int(input("Number: "))
    # Verifico la cantidad de digitos.
    cant = digitos(ccn)
    match cant:
        case 13 | 15 | 16:
            # Verifico los primeros digitos.
            first = firstdigit(ccn, cant)
            match first:
                case 'VISA' | 'AMEX' | 'MASTERCARD':
                    if vality(ccn, cant):
                        print(first)
                    else:
                        print("INVALID")
                case _:
                    print("INVALID")

        case _:
            print("INVALID")

# Necesito el numero de la tarjeta.


def digitos(i):
    c = 0
    while i != 0:

        i = int(i/10)
        c += 1
    return c
# Necesito el numero de la tarjeta y la cantidad de digitos.


def firstdigit(i, o):
    # Consigo los primeros 2 digitos.
    first = int(i/(10 ** (o-2)))
    # Asigno un valor dependiendo del resultado
    if (40 <= first <= 49) and (o == 13 or o == 16):
        return 'VISA'
    elif (first == 34 or first == 37) and o == 15:
        return 'AMEX'
    elif (51 <= first <= 55) and o == 16:
        return 'MASTERCARD'
    else:
        return False

# Necesito el numero de la tarjeta y la cantidad de digitos.


def vality(i, o):
    impar = 0
    suma_par = 0
    tmp = 0

    # Hago un ciclo para evaluar numero por numero.
    while o > 0:
        # Consigo el primer digito.
        impar = (i % 10) + impar
        # Actualizo el valor de la tarjeta.
        i = int(i/10)
        # Creo una variable temporal que se actualice en cada ciclo.
        tmp = (i % 10) * 2
        # Valido que hacer con la variable para el ciclo actual.
        tmp = calc(tmp)
        # Actualizo el valor de la suma de los digitos pares.
        suma_par += tmp
        # Actualizo el valor de la tarjeta.
        i = int(i/10)
        o -= 2

    total = suma_par + impar
    if total % 10 == 0:
        return True

    else:
        return False


def calc(j):
    # Si J es mayor que 10 sumo sus digitos.
    if j >= 10:
        a = j % 10
        j = int(j/10)
        b = j % 10
        return a + b

    # Si J es mayor que 0 Y menor que 10 lo devuelvo sin hacer nada.
    elif j > 0 and j < 10:
        return j

    # En otro caso devuelvo cero.
    else:
        return 0


main()