alphabet = "АБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ "
text = "СЛЮСАРЕНКО"
shift = 20

N = len(alphabet)
cipher = ""

print(f"Алфавит ({N} символов): {alphabet}")
print()
print(f"{'i':>2}  {'char':^5} {'pos':>3} -> {'new':>3} -> {'mapped':^6}")
print("-"*32)

for i, ch in enumerate(text):
    pos = alphabet.find(ch)
    newpos = (pos + shift) % N
    mapped = alphabet[newpos]
    newpos_str = str(newpos)
    print(f"{i:2}  {ch!r:5} {pos:3} -> {newpos_str:>3} -> {mapped!r:6}")
    cipher += mapped

print("\nЗашифрованный текст:\n" + cipher)

vpos = alphabet.find('В')
vnew = (vpos + shift) % N
print(f"\nПроверка: 'В' -> pos = {vpos} -> (pos+{shift})%{N} = {vnew} -> символ = '{alphabet[vnew]}'")