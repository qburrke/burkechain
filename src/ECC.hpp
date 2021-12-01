#include "uint256_t.hpp"

namespace ecc {
    class p224 {
        public:
            // p224 class constructor
            p224(){}

            // p224 class deconstructor
            ~p224(){
                delete p;
                delete b;
                delete Gx;
                delete Gy;
                delete n;
            }

            void elip_addition(const big::uint256_t& p1, const big::uint256_t& p2){
            
            }

            void elip_multiple(const big::uint256_t& k){
                
            }
            
            void is_point_on_curve(){

            }
            
            big::uint256_t* reduce_modp(const big::uint256_t& x){
                return x % *this->p;
            }

            bool equal_modp(const big::uint256_t& x, const big::uint256_t& y){
                return this->reduce_modp(x - y) == 0;
            }

            big::uint256_t* inverse_modp(const big::uint256_t& x){
                if (this->reduce_modp(x) == 0){
                    return nullptr;
                }
                return big::pow(x, this->p - 2, this->p);
            }
            
            big::uint256_t* inverse_mod(const big::uint256_t& x, int order){
                if (this->reduce_modp(x) == 0){
                    return nullptr;
                }
                return big::pow(x, order - 2, order);
            }
            
            void create_keys(){

            }
            
            void sign(){

            }
            
            void verify(){

            }
        protected:
            /*
            Predefined variables for the P224 curve, derived from
            https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-186-draft.pdf 
            */
            int a = -3;
            big::uint256_t* p = new big::uint256_t("ffffffffffffffffffffffffffffffff000000000000000000000001", 56);
            big::uint256_t* b = new big::uint256_t("b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4", 56);
            big::uint256_t* Gx = new big::uint256_t("b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21", 56);
            big::uint256_t* Gy = new big::uint256_t("bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34", 56);
            big::uint256_t* n = new big::uint256_t("ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d", 56);
    };
}
