#include <iostream>
using namespace std;
class complexNumber {
    private:
        int real;
        int imaginary;

    public :
        complexNumber(int real, int imaginary){
            this ->real = real;
            this ->imaginary = imaginary;
        }

        void plus(complexNumber const &c2){
            real = real + c2.real;
            imaginary = imaginary + c2.imaginary;
        }

        void multiply(complexNumber const &c2){
            int real1 = real;
            real = real * c2.real - imaginary*c2.imaginary;
            imaginary = real1 * c2.imaginary + imaginary * c2.real;
        }

        void print(){
            cout<<real<<" + "<<"i"<<imaginary<<endl;
        }
};
int main(){
    int real1,imaginary1,real2,imaginary2;
    cin>>real1>>imaginary1;
    cin>>real2>>imaginary2;

    complexNumber c1(real1,imaginary1);
    complexNumber c2(real2,imaginary2);

    int choice;
    cin>>choice;
    if(choice == 1){
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2){
        c1.multiply(c2);
        c1.print();
    }
    else{
        return 0;
    }
}