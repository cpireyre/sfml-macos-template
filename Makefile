sfml_dir := ./SFML-2.6.2
sfml_lib := $(sfml_dir)/lib
CPPFLAGS := -I$(sfml_dir)/include -std=c++17
LDFLAGS  := -L$(sfml_lib) -Wl,-rpath,$(sfml_lib)
LIBS 		 := -lsfml-graphics -lsfml-window -lsfml-system
.DEFAULT_GOAL := all

.sfml:
	@echo "Configuring & compiling SFML from source"
	cd $(sfml_dir) && cmake -B . && make -j4
	touch .sfml

name := a.out
$(name): .sfml main.cpp
	clang++ $(CPPFLAGS) $(LDFLAGS) main.cpp $(LIBS) -o $(name)

.PHONY: all
all: $(name)
	./$(name)

.PHONY: clean
clean:
	$(RM) .sfml $(sfml_dir)/CMakeCache.txt
	make -C $(sfml_dir) clean

.PHONY: fclean
fclean: clean
	$(RM) $(name)

.PHONY: re
re: fclean $(name)
