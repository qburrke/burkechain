#ifndef BIG_NUBMERS_H
#define BIG_NUBMERS_H

#include <iostream>
#include <bitset>

#define ERROR(x) throw std::runtime_error(x)
#define PRINT(x) std::cout << x << std::endl

namespace big {
    class uint256_t {
        public:
            // default class constructor, sets all bits to 0 as a base case
            uint256_t(){
                for(int i = 0; i < 256; i++){ 
                    data[0][i] = 0; 
                }
            }

            uint256_t(const uint256_t& num){ *this->data = *num.data; }
            
            // this is a scary func, I will add in checks in the future
            template<typename T>
            uint256_t(T set){ *data = set; }

            /* uint256_t func
            an overloader for this classes constructor 
            @param s string of hex we wish to store
            @param len length of s
            */
            uint256_t(const char* s, int len) {
                if (len > 64){ this->_error(0); }
                for (byte_index = 0; byte_index < len; byte_index++) {
                    *data <<= 4;
                    switch(s[byte_index]){
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
                        default: this->_error(1);
                    }
                }
            }
            // declare class deconstructor
            ~uint256_t(){ delete data; }

            // little func for printing the binary of the uint256_t, might comment out this
            void print_bin(){ PRINT(*data); }

            // define << operator for this class so we can print through std::cout
            friend std::ostream& operator<<(std::ostream& os, const uint256_t& num){
                os << "0x" << std::hex << num.data->to_ulong();
                return os;
            }
            
            void operator=(const uint256_t& num){
                /* 
                Please note the num's destructor will be called
                once we exit this scope, which is why we copy 
                the data in num and not move (move is alot faster
                than copying). Im commenting this because It took me 
                AWHILE to figure this out omg I finally did it and I didnt 
                need stackoverflow or any help.
                */
                *this->data = *num.data;
            }

            uint256_t operator+(const uint256_t& num){
                uint256_t temp(*this);
                *temp.data = temp.data->to_ulong() + num.data->to_ulong();
                // PRINT("[OP+] " << temp.data->to_ulong());
                // PRINT("[OP+] " << num.data->to_ulong());
                // PRINT("[OP+] " << temp);
                return temp;
            }

        private:
            std::bitset<256>* data = new std::bitset<256>;
            int byte_index;
            void _error(int e){
                this->~uint256_t();
                switch(e){ 
                    case 0: ERROR("Error, hex provied exceeds __uint256_t limit");
                    case 1: ERROR("Invaild hex to __uint256_t assignment");
                    case 2: ERROR("Overflow error while adding two uint256_t objects");
                    default:ERROR("unknown error occured while creating __uint256_t");
                }
            }
    };
}
#endif
