#include "big_numbers.hpp"
using namespace big;

int main(int argc, char **argv) {
	/*
	for (int i = 0; i < argc; i++) { std::cout << i << " " << argv[i] << std::endl; }
	blc::blockchain b("start");
	b.print_chain();
	*/
	uint256_t* a = new uint256_t("ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb", 64);
    std::cout << *a << std::endl;
    a->print_bin();
    delete a;
	return 0;
}
