# Путь к папке с консольным проектом
CONSOLE_DIR = console

# Цель по умолчанию — запускает 'all' внутри папки console
all:
	$(MAKE) -C $(CONSOLE_DIR)

# Запуск программы через вложенный Makefile
run:
	$(MAKE) -C $(CONSOLE_DIR) run

# Очистка через вложенный Makefile
clean:
	$(MAKE) -C $(CONSOLE_DIR) clean

.PHONY: all run clean