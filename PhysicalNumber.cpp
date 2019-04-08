#include "PhysicalNumber.h"

#include <iostream>

using namespace ariel;




    PhysicalNumber::PhysicalNumber (double value,Unit unit){

        this->value = value;

        this->unit = unit;

    }   


    const PhysicalNumber PhysicalNumber::operator+() {

       return *this;

    }

    const PhysicalNumber PhysicalNumber::operator-() {

        return *this;

    }

    const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& a){

        return *this;

    }

    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& a){

        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& a){

        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& a){

        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& a){

        return *this;

    }
	const PhysicalNumber PhysicalNumber::operator++(int a){
		
		 return *this;
	}

			const PhysicalNumber PhysicalNumber::operator--(int a){
				 return *this;
			}

    PhysicalNumber& PhysicalNumber::operator++(){

        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator--(){

        return *this;

    } 
	
	bool PhysicalNumber::operator<(const PhysicalNumber& a){

        return true;

    }
	
	bool PhysicalNumber::operator<=(const PhysicalNumber& a){

        return true;

    }
	
	bool PhysicalNumber::operator>(const PhysicalNumber& a){

        return true;

    }
	
	bool PhysicalNumber::operator>=(const PhysicalNumber& a){

        return true;

    }
	
	bool PhysicalNumber::operator==(const PhysicalNumber& a){

        return true;

    }
	
	bool PhysicalNumber::operator!=(const PhysicalNumber& a){

        return true;

    }

	 ostream& ariel::operator<< (ostream& os, const PhysicalNumber& a) {
		

		return os;
	}
	
	 istream& ariel::operator>> (istream&  is, const PhysicalNumber& a) {

		return is;
	}



