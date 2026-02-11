# Переменные
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = test
OBJ = test.o

# 1. Главная цель
all: $(TARGET)

# 2. Линковка: создание исполняемого файла из объектных файлов
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# 3. Компиляция: создание объектного файла из исходного кода (.c -> .o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all run clean