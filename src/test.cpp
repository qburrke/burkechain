#include <iostream>

#define P(x) std::cout << x << std::endl

class X {
   public:
      std::string name;
      X(const char* name, int num)
         : name(name)
      {
         P("Constructing instance of X " << name);
         *x = num;
      };

      // copy constructor
      X(const char* name, const X& x)
         : name(name)
      {
         P("Copy constructor");
         *this->x = *x.x;
         P("x addr on heap (this) \t\t" << this->x);
         P("x addr on heap (copyied x) \t" << x.x);
      }

      ~X(){
         P("Deleting instance of " << name);
         delete x; 
      }

      friend std::ostream& operator<<(std::ostream& os, const X& x){
         os << x.name << " " << *x.x;
         return os;
      }

      void operator=(const X& x){
         P("[OP=] calling");
         P("[OP=] " << x);
         P("[OP=] " << *this);
         *this->x = *x.x;
      }
      
      X operator+(const X& x){
         P("[OP+] calling");
         X temp("temp", x);
         P("[OP+] temp addr " << temp.x);
         P("[OP+] x addr \t" << x.x);
         *temp.x += *this->x;
         return temp;
      }

   private:
      int* x = new int;
};

int main (int argc, char** argv){
   X num1("num1", 123);
   X num2("num2", 456);
   P("1. " << num1);
   P("2. " << num2);
   num1 = num1 + num2;
   P("3. " << num1);
   P("4. " << num2);
   return 0;
}