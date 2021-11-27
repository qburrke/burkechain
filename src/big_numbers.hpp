#ifndef BIG_NUBMERS_H
#define BIG_NUBMERS_H

#include <iostream>
#include <bitset>

#define ERROR(x) throw std::runtime_error(x)
#define PRINT(x) std::cout << x << std::endl

namespace big {
    class uint256_t {
        public:
            /* uint256_t func
            default class constructor
            */
            uint256_t();

            /* uint256_t func
            an overloader for this classes constructor 
            @param s string of hex we wish to store
            @param len length of s
            */
            uint256_t(const char* s, int len) {
                if (len > 64){ this->creation_error(0); }
                data_str = new char[len];
                for (byte_index = 0; byte_index < len; byte_index++) {
                    data_str[byte_index] = s[byte_index];
                    *data <<= 4;
                    switch(data_str[byte_index]){
                        case '0': *data|=0x0; break;
                        case '1': *data|=0x1; break;
                        case '2': *data|=0x2; break;
                        case '3': *data|=0x3; break;
                        case '4': *data|=0x4; break;
                        case '5': *data|=0x5; break;
                        case '6': *data|=0x6; break;
                        case '7': *data|=0x7; break;
                        case '8': *data|=0x8; break;
                        case '9': *data|=0x9; break;
                        case 'a': *data|=0xA; break;
                        case 'b': *data|=0xB; break;
                        case 'c': *data|=0xC; break;
                        case 'd': *data|=0xD; break;
                        case 'e': *data|=0xE; break; 
                        case 'f': *data|=0xF; break;
                        default: this->creation_error(1);
                    }
                }
            }
            // declare class deconstructor
            ~uint256_t(){ delete data_str, delete data; }

            // little func for printing the binary of the uint256_t, might comment out this
            void print_bin(){ PRINT(*data); }

            // define << operator for this class so we can print through std::cout
            friend std::ostream& operator<<(std::ostream& os, const uint256_t& num){
                os << "0x" << num.data_str;
                return os;
            }
            /* + operator for this class so we can add this to other data types
             * maybe just other uint256_t will work, currently in progress
            friend std::bitset<256> operator+(something, const uint256_t& num){
                return sol
            }
            */
        private:
            std::bitset<256>* data = new std::bitset<256>;
            char* data_str = nullptr;
            int byte_index;
            void creation_error(int e){
                this->~uint256_t();
                switch(e){ 
                    case 0: ERROR("Error, hex provied exceeds __uint256_t limit");
                    case 1: ERROR("Invaild hex to __uint256_t assignment");
                    default:ERROR("unknown error occured while creating __uint256_t");
                }
            }
    };
}
#endif
