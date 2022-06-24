#include <iostream>
using namespace std;
class polynomial{
    public:
        int *degCoeff;
        int capacity;

        // Default Constructor
        polynomial(){
            capacity = 5;
            degCoeff = new int[5];
            for(int i=0;i<capacity;i++){
                degCoeff[i] = 0;
            }
        }

        // Copy Constructor 
        // Copy Assignment Operator
        polynomial(polynomial const & p2){
            capacity = p2.capacity;
            degCoeff = new int[capacity];
            for(int i=0;i<capacity;i++){
                degCoeff[i] = p2.degCoeff[i];
            }
        }

        // Set Coefficient
        void setCoefficient(int degree, int coefficient){
            while(degree>=capacity){
                int* newDegCoeff = new int[2*capacity];
                for(int i=0;i<2*capacity;i++){
                    if(i<capacity){
                        newDegCoeff[i] = degCoeff[i];
                    }
                    else{
                        newDegCoeff[i] = 0;
                    }      
                }
                capacity *= 2;
                delete [] degCoeff;
                degCoeff = newDegCoeff;
            }
            degCoeff[degree] = coefficient;
        }

        // Operator Overloading +
        polynomial operator+(polynomial& p2){
            int newCapacity = max(capacity,p2.capacity);
            if(newCapacity == capacity){
                for(int i=p2.capacity;i<newCapacity;i++){
                    p2.setCoefficient(i,0);
                }
            }
            else{
                for(int i=capacity;i<newCapacity;i++){
                    setCoefficient(i,0);
                }
            }
            polynomial p3;
            for(int i=0;i<newCapacity;i++){
                p3.setCoefficient(i,degCoeff[i] + p2.degCoeff[i]);
            }
            return p3;
        }

        // Operator Overloading -
        polynomial operator-(polynomial & p2){
            int newCapacity = max(capacity,p2.capacity);
            if(capacity == newCapacity){
                for(int i=p2.capacity;i<newCapacity;i++){
                    p2.setCoefficient(i,0);
                }
            }else{
                for(int i=capacity;i<newCapacity;i++){
                    setCoefficient(i,0);
                }
            }
            polynomial p3;
            for(int i=0;i<newCapacity;i++){
                p3.setCoefficient(i,degCoeff[i] - p2.degCoeff[i]);
            }
            return p3;
        }

        // Operator Overlaoding *
        polynomial operator*(polynomial& p2){
            polynomial p3;
            for(int i=0;i<capacity;i++){
                polynomial p;
                for(int j=0;j<p2.capacity;j++){
                    p.setCoefficient(i+j,degCoeff[i]*p2.degCoeff[j]);
                }
                p3 = p3 + p;
            }
            return p3;
        }

        // Print function
        void print()const{
            for(int i=0;i<capacity;i++){
                if(degCoeff[i] != 0){
                    cout<<degCoeff[i]<<"x"<<i<<" ";
                }
            }
            cout<<endl;
        }
};
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}