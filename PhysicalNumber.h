#include "Unit.h"

#include <iostream>

using namespace std;



namespace ariel {



    class PhysicalNumber{

    

        double value;

        Unit unit;



    public:

   

        PhysicalNumber (double value,Unit unit);

			const PhysicalNumber operator+();

			const PhysicalNumber operator-();
			

			const PhysicalNumber operator-(const PhysicalNumber& a);

			const PhysicalNumber operator+(const PhysicalNumber& a);

			PhysicalNumber& operator+=(const PhysicalNumber& a);

			PhysicalNumber& operator-=(const PhysicalNumber& a);

			PhysicalNumber& operator=(const PhysicalNumber& a);

			
			PhysicalNumber& operator++();

			PhysicalNumber& operator--();
			
			PhysicalNumber operator++(int a);

		    PhysicalNumber operator--(int a);
			
			
			bool operator<(const PhysicalNumber& a);

			bool operator<=(const PhysicalNumber& a);

			bool operator>(const PhysicalNumber& a);

			bool operator>=(const PhysicalNumber& a);

			bool operator==(const PhysicalNumber& a);

			bool operator!=(const PhysicalNumber& a);
			
			
			friend ostream& operator<< (ostream& os, const PhysicalNumber& a);
			
			friend istream& operator>> (istream&  is, const PhysicalNumber& a);


    };









}