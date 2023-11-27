def generar_clave(indice):
    if indice == 0:
        return 0  # Valor inicial
    elif indice == 1:
        return 1  # Segundo valor en la serie de Fibonacci

    # Generar la serie de Fibonacci
    a, b = 0, 1
    for _ in range(2, indice + 1):
        a, b = b, a + b

    return b  # Devolver el valor correspondiente en la serie de Fibonacci

def descifrar_cesar_avanzado(mensaje):
    resultado = ""
    for i, char in enumerate(mensaje):
        if char.isalpha():
            ascii_offset = ord('A') if char.isupper() else ord('a')
            clave_actual = generar_clave(i)
            resultado += chr((ord(char) - ascii_offset - clave_actual) % 26 + ascii_offset)
        else:
            resultado += char
    return resultado

# Entrada del usuario
mensaje_cifrado = input("Ingrese el mensaje cifrado: ")

# Descifrado utilizando la serie de Fibonacci para la clave
mensaje_descifrado = descifrar_cesar_avanzado(mensaje_cifrado)

# Mostrar resultados
print("\nMensaje cifrado:", mensaje_cifrado)
print("Mensaje descifrado:", mensaje_descifrado)

