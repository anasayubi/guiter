tests: libs/helper.cpp libs/helper.hpp op.cpp
	g++ -o op op.cpp libs/helper.cpp -I libs/

main: op.cpp
	g++ -o op op.cpp -I ./libs -lboost_system-mt
