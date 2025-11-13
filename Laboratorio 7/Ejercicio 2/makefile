CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = testLogger.exe
SOURCES = main.cpp Logger.cpp FuncionesPrueba.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) bitacora.log

.PHONY: clean