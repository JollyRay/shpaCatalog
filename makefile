SOURCES=$(wildcard src/**/*.cpp src/*.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))
TARGET = server
BUILD_DIR = dst

all: $(TARGET)
$(TARGET): $(OBJECTS)
	@g++ -o $@ $(patsubst %.o,$(BUILD_DIR)/%.o,$(OBJECTS))
	@./$(TARGET)

%.o: %.cpp
	@mkdir -p "$$(dirname $(BUILD_DIR)/$@)"
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/$@

clear:
	rm -rf build $(TARGET)
