main: libs/helper.cpp libs/helper.hpp op.cpp
	g++ -o op op.cpp libs/helper.cpp -I libs/

comp-tests: tests/test_get_token_from_str.cpp libs/helper.cpp
	g++ -o test ./tests/test_get_token_from_str.cpp ./libs/helper.cpp -I libs/
