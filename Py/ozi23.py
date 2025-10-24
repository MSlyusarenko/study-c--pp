def gamma_cipher(text_bin, key_bin):
    """
    Шифрование методом гаммирования.
    text_bin — исходный текст в двоичном виде (строка из 0 и 1)
    key_bin  — секретный ключ (гамма), строка из 0 и 1
    Возвращает: зашифрованный текст (строку из 0 и 1)
    """
    # --- аудит входных данных ---
    if not set(text_bin) <= {"0", "1"}:
        raise ValueError("Исходный текст должен содержать только символы 0 и 1.")
    if not set(key_bin) <= {"0", "1"}:
        raise ValueError("Ключ должен содержать только символы 0 и 1.")
    if len(text_bin) > 40:
        raise ValueError("Исходный текст не должен превышать 40 двоичных символов.")
    if len(key_bin) > 16:
        raise ValueError("Ключ не должен превышать 16 двоичных символов.")
    if len(key_bin) == 0:
        raise ValueError("Ключ не может быть пустым.")

    cipher = ""
    key_len = len(key_bin)

    # --- шифрование по модулю 2 (XOR) ---
    for i in range(len(text_bin)):
        x = int(text_bin[i])
        k = int(key_bin[i % key_len])  # циклическое использование ключа
        y = (x + k) % 2
        cipher += str(y)

    return cipher


# --- пример использования ---
text_bin = "01001000011001010110110001101100"   # пример двоичного текста (до 40 бит)
key_bin = "0110"                   # пример гаммы (до 16 бит)

cipher = gamma_cipher(text_bin, key_bin)

print("Исходный текст:")
print(text_bin)
print("\nКлюч:")
print(key_bin)
print("\nЗашифрованный текст:")
print(cipher)
