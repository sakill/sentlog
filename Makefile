src = FileTool.cpp FileTool.h Sentlog.cpp Sentlog.h Out.cpp Out.h Tool.cpp Tool.h base64.cpp base64.h
Sentlog : FileTool.o Sentlog.o Out.o Tool.o base64.o
	g++ -o Sentlog FileTool.o Sentlog.o Out.o Tool.o base64.o ./lib/hiredis/libhiredis.a
FileTool.o : FileTool.cpp FileTool.h
	g++ -c FileTool.cpp -std=c++11 -I ./
Sentlog.o : Sentlog.h Sentlog.cpp
	g++ -c Sentlog.cpp -std=c++11 -I ./
Out.o : Out.cpp Out.h
	g++ -c Out.cpp ./lib/hiredis/libhiredis.a -std=c++11 -I ./
Tool.o : Tool.cpp Tool.h
	g++ -c Tool.cpp -std=c++11 -I ./
base64.o : base64.cpp base64.h
	g++ -c base64.cpp -std=c++11 -I ./
.PHONY : clean  
clean :  
	\rm *.o
