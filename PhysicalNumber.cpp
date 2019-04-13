/**
 * Physical numbers class for number and unitN
 *
 * @author Israel Buskila and Moran Oshia
 * @since 04-2019
 */
#include "PhysicalNumber.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace ariel;


	PhysicalNumber::PhysicalNumber (){
		//Constructor

    }  

    PhysicalNumber::PhysicalNumber (double value,Unit unit){
		//Constructor

        this->value = value;

        this->unitN = unit;

    }  
	
	  PhysicalNumber PhysicalNumber::convert( PhysicalNumber& a){
		if (this->unitN == a.unitN)	
		{
				return a;
		}
		
		else{
		switch ( this->unitN ) {
			
				// CM ,M ,KM 
				case 0 : 
				{
					// Process for CM
						if(a.unitN!=1 && a.unitN!=2)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==1) //M to CM
							{
								
								a.value=a.value*100;
								return a;
							}
							
							else //KM to CM
							{
								a.value=a.value*100000;
								return a;
							}
						}
						 
				}						
				case 1 :
				{				
					// Process for M
						if(a.unitN!=0 && a.unitN!=2)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==0) //CM to M
							{
								
								a.value=a.value/100;
								return a;
							}
							
							else //KM to M
							{
								a.value=a.value*1000;
								return a;
							}
						}
						 
				}
				case 2 : 
					// Process for KM
					{
						if(a.unitN!=0 && a.unitN!=1)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==0) //CM to KM
							{
								
								a.value=a.value/100000;
								return a;
							}
							
							else //M to KM
							{
								a.value=a.value/1000;
								return a;
							}
						}
						
						}
					
			
				
				// SEC ,MIN ,HOUR \\
				
				case 3 : 
				{
					// Process for SEC
						if(a.unitN!=4 && a.unitN!=5)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==4) //MIN to SEC
							{
								
								a.value=a.value*60;
								return a;
							}
							
							else //HOUR to SEC
							{
								a.value=a.value*60*60;
								return a;
							}
						}
						
				}
				case 4 : 
					// Process for MIN
				{
						if(a.unitN!=3 && a.unitN!=5)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==3) //SEC to MIN
							{
								
								a.value=a.value/60;
								return a;
							}
							
							else //HOUR to MIN
							{
								a.value=a.value*60;
								return a;
							}
						}
						
				}
				case 5 : 
				{
					// Process for HOUR
						if(a.unitN!=3 && a.unitN!=4)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==3) //SEC to HOUR
							{
								
								a.value=a.value/(60*60);
								return a;
							}
							
							else //MIN to HOUR
							{
								a.value=a.value/60;
								return a;
							}
						}
						
				}
				
				// G ,KG ,TON \\
				
				case 6 : 
					// Process for G
					{
						if(a.unitN!=7 && a.unitN!=8)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==7) //KG to G
							{
								
								a.value=a.value*1000;
								return a;
							}
							
							else //TON to G
							{
								a.value=a.value*1000000;
								return a;
							}
						}
						
					}
						
				case 7 : 
					// Process for KG
					{
						if(a.unitN!=6 && a.unitN!=8)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==6) //G to KG
							{
								
								a.value=a.value/1000;
								return a;
							}
							
							else //TON to KG
							{
								a.value=a.value*1000;
								return a;
							}
						}
						
					}
						
				case 8 : 
					// Process for TON
					{
						if(a.unitN!=6 && a.unitN!=7)
						{
							throw std::invalid_argument( "Not possible to convert");
						}
						else{
							if(a.unitN==6) //G to TON
							{
								
								a.value=a.value/1000000;
								return a;
							}
							
							else //KG to TON
							{
								a.value=a.value/1000;
								return a;
							}
						}
							
					}						
				

			}
			
		}
			
		

	}
		
		
	//arithmetic operators
     PhysicalNumber PhysicalNumber::operator+() {
		//+this onry plus
	 	return *this;

    }

     PhysicalNumber PhysicalNumber::operator-() {
		//-this onry minus
		PhysicalNumber ans;
		ans.value=(-1)*this->value;
		ans.unitN=this->unitN;
        return ans;

    }

     PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& a){
		//(this+a) - sum of two Physical Numbers
		PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		ans.value=this->value+ans.value;
		ans.unitN=this->unitN;
		return ans;

    }

     PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& a){
		//(this-a) - subtraction of two Physical Numbers
		PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		ans.value=this->value-ans.value;
		ans.unitN=this->unitN;
        return ans;


    }

    PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber& a){
		//this+=a
		PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		this->value = this->value + ans.value;
        return *this;
    }

    PhysicalNumber& PhysicalNumber::operator-=(const  PhysicalNumber& a){
		//this-=a
        PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		this->value = this->value - ans.value;
        return *this;

    }

	PhysicalNumber PhysicalNumber::operator++(int a){
		//this + a
		this->value = this->value + a;
        return *this;
	}

	PhysicalNumber PhysicalNumber::operator--(int a){
		//this - a	
		this->value = this->value - a;
			return *this;
	}

    PhysicalNumber& PhysicalNumber::operator++(){
		//this++
		this->value++;
        return *this;


    }

    PhysicalNumber& PhysicalNumber::operator--(){
		//this--
        this->value--;
        return *this;

    } 
	
	//Comparison operators
	bool PhysicalNumber::operator<(const PhysicalNumber& a){
		//this<a
        
		PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		
		if (this->value < ans.value)
		{
			return true;
		}
		return false;

    }
	
	bool PhysicalNumber::operator<=(const PhysicalNumber& a){
		//this<=a
        PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		
		if (this->value <= ans.value)
		{
			return true;
		}
		return false;

    }
	
	bool PhysicalNumber::operator>(const PhysicalNumber& a){
		//this>a
        PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		
		if (this->value > ans.value)
		{
			return true;
		}
		return false;
    }
	
	bool PhysicalNumber::operator>=(const PhysicalNumber& a){
		//this>=a
		PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		
		if (this->value >= ans.value)
		{
			return true;
		}
		return false;

    }
	
	bool PhysicalNumber::operator==(const PhysicalNumber& a){
		//this==a
		 
        PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		
		if (this->value == ans.value)
		{
			return true;
		}
		return false;
    }
	
	bool PhysicalNumber::operator!=(const PhysicalNumber& a){
		//this!=a
        PhysicalNumber ans;
		ans.value=a.value;
		ans.unitN=a.unitN;
		ans=convert(ans);
		
		if (this->value != ans.value)
		{
			return true;
		}
		return false;

    }

	//Input output operators
	ostream& ariel::operator<< (ostream& os, const PhysicalNumber& a) {
		//Output of physical number
		switch(a.unitN)
		{
			case 0:
			{
				return os << a.value<< "[cm]";
			}
			
			case 1:
			{
				return os << a.value<< "[m]";
			}
			case 2:
			{
				return os << a.value<< "[km]";
			}
			case 3:
			{
				return os << a.value<< "[sec]";
			}
			case 4:
			{
				return os << a.value<< "[min]";
			}
			case 5:
			{
				return os << a.value<< "[hour]";
			}
			case 6:
			{
				return os << a.value<< "[g]";
			}
			case 7:
			{
				return os << a.value<< "[kg]";
			}
			case 8:
			{
				return os << a.value<< "[ton]";
			}
		}
		
	}
	
	istream& ariel::operator>> (istream&  is, PhysicalNumber& a) {
		//Input of physical number
		std::string s;
		is >> s;
		std::string delimiter = "[";
		int i = s.find(delimiter);
		std::string token = s.substr(0, i); 
		double v = stod(token);
		a.value = v;
		std::string token2 = s.substr(i+1, s.find("]")-(i+1));

		if(token2 == "cm")
		a.unitN = Unit::CM;
		if(token2 == "m")
		a.unitN = Unit::M;
		if(token2 == "km")
		a.unitN = Unit::KM;
		if(token2 == "sec")
		a.unitN = Unit::SEC;
		if(token2 == "min")
		a.unitN = Unit::MIN;
		if(token2 == "hour")
		a.unitN = Unit::HOUR;
		if(token2 == "g")
		a.unitN = Unit::G;
		if(token2 == "kg")
		a.unitN = Unit::KG;
		if(token2 == "ton")
		a.unitN = Unit::TON;
		
		return is;
	}



