file_name = "42_with_nl"
content = "a" * 41  # Substitua 'a' por qualquer outro caractere se desejar

with open(file_name, "w", newline="") as f:
    f.write(content)
