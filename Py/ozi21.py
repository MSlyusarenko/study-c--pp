def permutation_cipher(text, key):
    """
    Шифрование методом перестановки.
    text — исходный текст (строка)
    key  — строка с перестановкой, например "31024"
    """
    block_size = len(key)

    # --- аудит ключа ---
    if not key.isdigit():
        raise ValueError("Ключ должен содержать только цифры.")
    
    if max(int(k) for k in key) >= block_size:
        raise ValueError(f"Ключ содержит индекс {max(int(k) for k in key)}, "
                         f"который больше или равен размеру блока ({block_size}).")

    cipher = ""

    # если длина текста не кратна размеру блока — дополним пробелами
    while len(text) % block_size != 0:
        text += " "

    # --- основное шифрование ---
    for i in range(0, len(text), block_size):
        block = text[i:i + block_size]
        new_block = ""
        for k in key:
            idx = int(k)
            new_block += block[idx]
        cipher += new_block

    return cipher


# --- пример использования ---
text = "ВАСИЛЬЕВИЧ"
key = "43021"

cipher = permutation_cipher(text, key)

print("Исходный текст:")
print(text)
print("\nЗашифрованный текст:")
print(cipher)
