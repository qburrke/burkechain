#include "big_numbers.hpp"
using namespace big;

int main(int argc, char **argv) {
	/*
	for (int i = 0; i < argc; i++) { std::cout << i << " " << argv[i] << std::endl; }
	blc::blockchain b("start");
	b.print_chain();
	*/
	uint256_t* a = new uint256_t("ffffffffffffffffffff", 20);
    uint256_t* b = new uint256_t("ffffffffffffffffffff", 20);
	uint256_t* c = new uint256_t("12345", 5);
	PRINT("a " << *a);
	PRINT("b " << *b);
	PRINT("c " << *c);
	PRINT("OPERATION");
	*c = *a + *b;
	PRINT("a " << *a);
	PRINT("b " << *b);
	PRINT("c " << *c);
	PRINT("c(bin) ");
	c->print_bin();
	delete a, delete b, delete c;
	return 0;
}
