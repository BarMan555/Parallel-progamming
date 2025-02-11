import numpy as np

rows1, cols1 = 10, 5  # Размер матрицы (4x5)
matrix1 = np.random.randint(0, 10, size=(rows1, cols1))

rows2, cols2 = 5, 15  # Размер матрицы (4x5)
matrix2 = np.random.randint(0, 10, size=(rows2, cols2))

if cols1 != rows2:
    print("!!! COLS 1 != ROWS2 !!!")
    exit

with open("matrix1.txt", "w") as file:
    file.write(f"{rows1} {cols1}\n")  # Записываем размер матрицы
    np.savetxt(file, matrix1, fmt="%d", delimiter=" ")  # Записываем саму матрицу

with open("matrix2.txt", "w") as file:
    file.write(f"{rows2} {cols2}\n")  # Записываем размер матрицы
    np.savetxt(file, matrix2, fmt="%d", delimiter=" ")  # Записываем саму матрицу