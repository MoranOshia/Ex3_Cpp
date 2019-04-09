/**
 * Physical numbers class for number and unit
 *
 * @author Israel Buskila and Moran Oshia
 * @since 04-2019
 */
#include "PhysicalNumber.h"
#include <iostream>

using namespace ariel;




    PhysicalNumber::PhysicalNumber (double value,Unit unit){
		//Constructor

        this->value = value;

        this->unit = unit;

    }   

	//arithmetic operators
    const PhysicalNumber PhysicalNumber::operator+() {
		//+a onry plus
       return *this;

    }

    const PhysicalNumber PhysicalNumber::operator-() {
		//-a onry minus
        return *this;

    }

    const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& a){
		//(a+b) - sum of two Physical Numbers
        return *this;

    }

    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& a){
		//(a-b) - subtraction of two Physical Numbers
        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& a){
		//a+=b
        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& a){
		//a-=b
        return *this;

    }

	PhysicalNumber PhysicalNumber::operator++(int a){
		//a++
		 return *this;
	}

	PhysicalNumber PhysicalNumber::operator--(int a){
		//a--	
			return *this;
	}

    PhysicalNumber& PhysicalNumber::operator++(){
		//a++
        return *this;

    }

    PhysicalNumber& PhysicalNumber::operator--(){
		//a--
        return *this;

    } 
	
	//Comparison operators
	bool PhysicalNumber::operator<(const PhysicalNumber& a){
		//a<b
        return true;

    }
	
	bool PhysicalNumber::operator<=(const PhysicalNumber& a){
		//a<=b
        return true;

    }
	
	bool PhysicalNumber::operator>(const PhysicalNumber& a){
		//a>b
        return true;

    }
	
	bool PhysicalNumber::operator>=(const PhysicalNumber& a){
		//a>=b
        return true;

    }
	
	bool PhysicalNumber::operator==(const PhysicalNumber& a){
		//a==b
        return true;

    }
	
	bool PhysicalNumber::operator!=(const PhysicalNumber& a){
		//a!=b
        return true;

    }

	//Input output operators
	ostream& ariel::operator<< (ostream& os, const PhysicalNumber& a) {
		//Output of physical number

		return os;
	}
	
	istream& ariel::operator>> (istream&  is, const PhysicalNumber& a) {
		//Input of physical number
		return is;
	}



