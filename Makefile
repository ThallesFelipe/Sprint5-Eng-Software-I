dll:
	g++ -c ./src/*.cpp -fpic
	g++ *.o -shared -o ./bin/lib_simulate.so -fpic 
	rm *.o

functional:
	g++ -c ./test/functional/*.cpp 
	g++ *.o -o ./bin/funcexe -L./bin -l_simulate
	rm *.o

unit:
	g++ -c ./test/unit/*.cpp 
	g++ *.o -o ./bin/unitexe -L./bin -l_simulate
	rm *.o

run_functional: 
	./bin/funcexe

run_unit:
	./bin/unitexe
	
clean: 
	rm -f *.o main

run:
	./main

# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:C:\Users\thall\Documents\Sprint5Thalles\bin