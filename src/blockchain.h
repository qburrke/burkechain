#pragma once

#include <iostream>

namespace blc {
	class Block {
		public:
			// Declare Block constructor
			Block();

			// Declare Block destructor
			~Block() {};
	}
	Block::Block(){
		std::cout << 
	}
	
	// template<typename T>
	class Blockchain {
		public:
			// Declare class constructor
			Blockchain(const char* s);

			// Declare class destructor (denoted by ~symbol)
			~Blockchain() { std::cout << "[CHAIN] closing..." << std::endl; };
			
			// Class public function
			void print_chain (){
				std::cout << "[CHAIN] printing" << std::endl;
			}
	};
	Blockchain::Blockchain(const char* s) {
		std::cout << s << std::endl;
		std::cout << "[CHAIN] creating blockchain" << std::endl;
	}
}
