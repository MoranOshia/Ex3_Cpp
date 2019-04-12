/**
 * Header file for the PhysicalNumber class. 
 * @author Israel Buskila and Moran Oshia
 * @since 04-2019
 */
 
#include "Unit.h"

#include <iostream>

using namespace std;



namespace ariel {



    class PhysicalNumber{

    

    public:
        double value;

        Unit unitN;




    PhysicalNumber ();

        PhysicalNumber (double value,Unit unit);

			 PhysicalNumber operator+();

			 PhysicalNumber operator-();
			
			PhysicalNumber convert(PhysicalNumber& a);

			 PhysicalNumber operator-(const PhysicalNumber& a);

			 PhysicalNumber operator+(const PhysicalNumber& a);

			PhysicalNumber &operator+=(const PhysicalNumber& a);

			PhysicalNumber& operator-=(const PhysicalNumber& a);


			
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
			
			friend istream& operator>> (istream&  is, PhysicalNumber& a);


    };









}
