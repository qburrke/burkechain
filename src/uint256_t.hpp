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
                for (int i = 0; i < len; i++) {
                    *data <<= 4;
                    switch(s[i]){
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
            
            void clear(){ (*this->data).reset(); }

            bool empty(){ return this->empty; }

            // little func for printing the binary of the uint256_t, might comment out this
            void print_bin(){ PRINT(*data); }

            // define << operator for this class so we can print through std::cout
            friend std::ostream& operator<<(std::ostream& os, const uint256_t& num){
                os << "0x";
                std::bitset<4> hex_char;
                for (int i = 255; i > -1; i-=4){
                    for (int j = 0; j < 4; j++){
                        hex_char[3 - j] = (*num.data)[i - j];
                    }
                    os << std::hex << hex_char.to_ulong();
                    hex_char.reset();
                }
                return os;
            }
            
            void operator=(const uint256_t& num){
                /* 
                Please note the num's destructor will be called
                once we exit this scope, which is why we copy 
                the data in num and not move 
                (moving data is faster than copying data, but we cant more here).
                */
                *this->data = *num.data;
            }

            uint256_t operator+(const uint256_t& num){
                uint256_t temp;
                char a = 0, b = 0, carry = 0;
                for (int i = 0; i < 256; i++){
                    a = (*this->data)[i];
                    b = (*num.data)[i];
                    if (carry && a && b){
                        (*temp.data)[i] = 1;
                    }
                    else if (carry && (a || b)){
                        (*temp.data)[i] = 0;
                    }
                    else if (!carry && a && b){
                        (*temp.data)[i] = 0;
                        carry = 1;
                    }
                    else if (!carry && (a || b)){
                        (*temp.data)[i] = 1;
                    }
                    else if(carry && !(a || b)){
                        (*temp.data)[i] = 1;
                        carry = 0;
                    }
                    else {
                        (*temp.data)[i] = 0;
                        carry = 0;    
                    }
                }
                if (carry) { this->_error(2); }
                return temp;
            }

            uint256_t operator+=(const uint256_t& num){
                uint256_t temp = *this + num; 
                return temp;
            }
            
            uint256_t operator-(const uint256_t& num){
                uint256_t temp;
                return temp;
            }

            uint256_t operator-=(const uint256_t& num){
                uint256_t temp = *this - num;
                return temp;
            }
        private:
            std::bitset<256>* data = new std::bitset<256>;
            bool infinity = false;
            bool empty = false;
            void _error(int e){
                this->~uint256_t();
                switch(e){ 
                    case 0: ERROR("Error, hex provied exceeds uint256_t limit");
                    case 1: ERROR("Invaild hex to uint256_t assignment");
                    case 2: ERROR("Overflow error while adding two uint256_t objects");
                    case 3: ERROR("Error, attempting to do math with infinity point");
                    default:ERROR("unknown error occured while creating uint256_t");
                }
            }
    };
    
    uint256_t* pow(const uint256_t& a, const uint256_t& b, const uint256_t& c);
}
#endif
