#include "ECC.hpp"
using namespace big;

int main(int argc, char **argv) {
	/*
	for (int i = 0; i < argc; i++) { std::cout << i << " " << argv[i] << std::endl; }
	blc::blockchain b("start");
	b.print_chain();
	*/
	//uint256_t* a = new uint256_t("00f24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824", 64);
    //uint256_t* b = new uint256_t("ffffffffffffffffffff", 20);
	uint256_t* a = new uint256_t("0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 64);
	uint256_t* b = new uint256_t("efffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", 64);
	uint256_t* c = new uint256_t("12345", 5);
	PRINT("c " << *c);
	PRINT("OPERATION");
	*c = *a + *b;
	PRINT("a " << *a);
	PRINT("b " << *b);
	PRINT("c " << *c);
	delete a, delete b, delete c;
	return 0;
}
