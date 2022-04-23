all : bin/HighLight.exe
	@echo done.

bin/HighLight.exe : bin/main.o bin/zeta.res
	@echo MAKE Terminal.exe
	@g++ bin/main.o bin/zeta.res -o bin/HighLight.exe


bin/main.o : src/main.cpp
	@echo MAKE main.o
	@g++ -I include src/main.cpp -c -o bin/main.o

	
bin/zeta.res : res/zeta.rc
	@echo MAKE zeta.res
	@windres -I include res/zeta.rc -O coff -o bin/zeta.res
.PHONY : clean # Windows
clean:
	del bin\* /q

.PHONY : clear # Linux
clear:
	rm bin/*
