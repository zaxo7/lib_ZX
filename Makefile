#ARG 				:=
ifeq ($(OS),Windows_NT)
	ARG0 := echo I am Windows
	ARG := g++ -o main.exe main.cpp functions.cpp 
	ARG2:=main.exe
else
	ARG0 := echo I am Linux
	ARG :=g++ -o main main.cpp functions.cpp 
	ARG2:=./main
endif
#ARG2:=gnome-terminal -- ./main g#

all:
	@echo start compling
	@$(ARG)
	@echo Compiled succesfully ;D 
	@$(ARG2)