CC = gcc
CFLAGS = -Wall -Wextra -g -I$(INC_DIR)

INC_DIR = ./include
SRC_DIR = ./src
LIB_DIR = ./lib
BUILD_BASE_DIR = ./build

PROBLEM ?=

PROBLEM_MAIN_C = $(SRC_DIR)/$(PROBLEM)/index.c

BUILD_DIR = $(BUILD_BASE_DIR)/$(PROBLEM)

TARGET = $(BUILD_DIR)/$(PROBLEM)

SRCS = $(PROBLEM_MAIN_C) \
       $(LIB_DIR)/graph.c \

OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

.PHONY: all clean

all: $(TARGET)
	@echo "Construção do projeto '$(PROBLEM)' concluída em $(TARGET)!"

$(TARGET): $(OBJ)
	@if [ -z "$(PROBLEM)" ]; then \
		echo "ERRO: Você deve especificar um problema. Ex: make PROBLEM=problema_a"; \
		exit 1; \
	fi
	@mkdir -p $(@D)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/index.o: $(PROBLEM_MAIN_C)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	@if [ -z "$(PROBLEM)" ]; then \
		echo "ERRO: Você deve especificar um problema para rodar. Ex: make run PROBLEM=problema_a"; \
		exit 1; \
	fi
	@echo "Executando $(PROBLEM)..."
	@cd $(BUILD_DIR) && ./$(PROBLEM)
	@echo "Execução de $(PROBLEM) concluída."

clean:
	@echo "Limpando arquivos gerados..."
	@if [ -n "$(PROBLEM)" ]; then \
		rm -f $(OBJ) $(TARGET); \
		echo "Limpeza de arquivos de '$(PROBLEM)' concluída."; \
	else \
		find $(BUILD_BASE_DIR) -type f -name "*.o" -delete; \
		find $(BUILD_BASE_DIR) -type f -exec rm {} +; \
		echo "Limpeza de todos os executáveis e .o concluída."; \
	fi