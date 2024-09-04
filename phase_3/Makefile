CXX = g++ -g -std=c++20

a4S = build/main.o build/system.o build/person.o build/channel.o build/course.o build/generalfunctions.o build/IO.o build/major.o
BUILD_DIR = build
TEMPLATE_DIR = .template
OUT_EXE = utms.out

ifeq ($(OS),Windows_NT)
	LDLIBS += -l Ws2_32
endif

all: $(BUILD_DIR) $(OUT_EXE)

$(OUT_EXE): $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/strutils.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o  $(BUILD_DIR)/system.o $(BUILD_DIR)/person.o $(BUILD_DIR)/channel.o $(BUILD_DIR)/course.o $(BUILD_DIR)/generalfunctions.o $(BUILD_DIR)/IO.o $(BUILD_DIR)/major.o
	$(CXX) $^ $(LDLIBS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp utils/strutils.hpp utils/strutils.cpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp utils/strutils.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/strutils.o: utils/strutils.cpp utils/strutils.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/strutils.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/handlers.o: examples/handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/system.o: src/system.cpp src/system.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/person.o: src/person.cpp src/person.hpp
	$(CXX) -c $< -o $@
$(BUILD_DIR)/channel.o: src/channel.cpp src/channel.hpp
	$(CXX) -c $< -o $@
$(BUILD_DIR)/course.o: src/course.cpp src/course.hpp
	$(CXX) -c $< -o $@
$(BUILD_DIR)/generalfunctions.o: src/generalfunctions.cpp src/generalfunctions.hpp
	$(CXX) -c $< -o $@
$(BUILD_DIR)/IO.o: src/IO.cpp src/IO.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/major.o: src/major.cpp src/major.hpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/main.o: examples/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp src/system.hpp src/person.hpp src/channel.hpp src/course.hpp src/generalfunctions.hpp src/IO.hpp src/major.hpp
	$(CXX) -c $< -o $@

.PHONY: all clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null