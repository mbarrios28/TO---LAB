# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -pthread -Wall -Wextra -O2

# Nombres de archivos
SOURCES = main.cpp LoggerModificado.cpp FuncionesPrueba.cpp
HEADERS = LoggerModificado.h FuncionesPrueba.h
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = logger_app

# Regla principal
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Reglas para objetos
main.o: main.cpp LoggerModificado.h FuncionesPrueba.h
	$(CXX) $(CXXFLAGS) -c main.cpp

LoggerModificado.o: LoggerModificado.cpp LoggerModificado.h
	$(CXX) $(CXXFLAGS) -c LoggerModificado.cpp

FuncionesPrueba.o: FuncionesPrueba.cpp FuncionesPrueba.h LoggerModificado.h
	$(CXX) $(CXXFLAGS) -c FuncionesPrueba.cpp

# Limpiar archivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET) bitacora.log

# Ejecutar la aplicación
run: $(TARGET)
	./$(TARGET)

# Compilar y ejecutar
all: $(TARGET) run

.PHONY: clean run all