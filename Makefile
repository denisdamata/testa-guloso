# Makefile
CXX := g++
CXXFLAGS := -std=c++17 -Wall
INCLUDE := -I include

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
TARGET := $(BIN_DIR)/tp2

# Configurando a regra padrão
all: $(TARGET)
	@echo "=== Executando ajuda: ==="
	./$(TARGET) -h
	@echo "=== Executando exemplos: ==="
#	./$(TARGET) <exemplo1_input.txt>
#	./$(TARGET) <exemplo2_input.txt>
	@echo "=== Fim dos exemplos ==="

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	@echo "=== Linkando objetos para criar o executável $@ ==="
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@
	@echo "=== Compilação concluída com sucesso. Executável $@ ==="

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "=== Compilando $< ==="
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean

clean:
	@echo "=== Realizando limpeza... ==="
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "=== Limpeza concluída ==="
