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
		  
		string unit[]={"cm","m","km","sec","min","hour","g","kg","ton"}; 
		
		
		if (this->unitN == a.unitN)	
		{
				return a;
		}
		
		else{
		switch ( this->unitN ) {
			
				// CM ,M ,KM 
				
				case Unit::CM: 
				{
					// Process for CM
						if(a.unitN!=Unit::M && a.unitN!=Unit::KM)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [cm]");
						}
						else{
							if(a.unitN==Unit::M) //M to CM
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
				case Unit::M :
				{				
					// Process for M
						if(a.unitN!=Unit::CM && a.unitN!=Unit::KM)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [m]");
						}
						else{
							if(a.unitN==Unit::CM) //CM to M
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
				case Unit::KM : 
					// Process for KM
					{
						if(a.unitN!=Unit::CM && a.unitN!=Unit::M)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [km]");
						}
						else{
							if(a.unitN==Unit::CM
							) //CM to KM
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
					
			
				
				// SEC ,MIN ,HOUR 
				
				case Unit::SEC : 
				{
					// Process for SEC
						if(a.unitN!=Unit::MIN && a.unitN!=Unit::HOUR)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [sec]");
						}
						else{
							if(a.unitN==Unit::MIN) //MIN to SEC
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
				case Unit::MIN : 
					// Process for MIN
				{
						if(a.unitN!=Unit::SEC && a.unitN!=Unit::HOUR)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [min]");
						}
						else{
							if(a.unitN==Unit::SEC) //SEC to MIN
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
				case Unit::HOUR : 
				{
					// Process for HOUR
						if(a.unitN!=Unit::SEC && a.unitN!=Unit::MIN)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [hour]");
						}
						else{
							if(a.unitN==Unit::SEC) //SEC to HOUR
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
				
				// G ,KG ,TON 
				
				case Unit::G : 
					// Process for G
					{
						if(a.unitN!=Unit::KG && a.unitN!=Unit::TON)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [g]");
						}
						else{
							if(a.unitN==Unit::KG) //KG to G
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
						
				case Unit::KG : 
					// Process for KG
					{
						if(a.unitN!=Unit::G && a.unitN!=Unit::TON)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [kg]");
						}
						else{
							if(a.unitN==Unit::G) //G to KG
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
						
				case Unit::TON: 
					// Process for TON
					{
						if(a.unitN!=Unit::G && a.unitN!=Unit::KG)
						{
							std::string tokenA =unitInString(a);
							throw std::invalid_argument( "Units do not match -"+tokenA+" cannot be converted to [ton]");
						}
						else{
							if(a.unitN==Unit::G) //G to TON
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
			
			return a;
			
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
		PhysicalNumber ans;
		ans.value=this->value;
		ans.unitN=this->unitN;
		this->value++;
			return ans;
	}

	PhysicalNumber PhysicalNumber::operator--(int a){
		//this - a	
		PhysicalNumber ans;
		ans.value=this->value;
		ans.unitN=this->unitN;
		this->value--;
			return ans;
	}

    PhysicalNumber& PhysicalNumber::operator++(){
		//this++
		value=value +1;
        return *this;


    }

    PhysicalNumber& PhysicalNumber::operator--(){
		//this--
       value=value -1;
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
	std::string PhysicalNumber::unitInString(const PhysicalNumber& a) {
    switch (a.unitN)

    {

    case Unit::CM:
			{
				return "[cm]";
			}
			
			case Unit::M:
			{
				return "[m]";
			}
			case Unit::KM:
			{
				return "[km]";
			}
			case Unit::SEC:
			{
				return "[sec]";
			}
			case Unit::MIN:
			{
				return "[min]";
			}
			case Unit::HOUR:
			{
				return "[hour]";
			}
			case Unit::G:
			{
				return "[g]";
			}
			case Unit::KG:
			{
				return "[kg]";
			}
			case Unit::TON:
			{
				return "[ton]";
			}

    }

}
	//Input output operators
	ostream& ariel::operator<< (ostream& os, const PhysicalNumber& a) {
		//Output of physical number
		switch(a.unitN)
		{
			case Unit::CM:
			{
				return os << a.value<< "[cm]";
			}
			
			case Unit::M:
			{
				return os << a.value<< "[m]";
			}
			case Unit::KM:
			{
				return os << a.value<< "[km]";
			}
			case Unit::SEC:
			{
				return os << a.value<< "[sec]";
			}
			case Unit::MIN:
			{
				return os << a.value<< "[min]";
			}
			case Unit::HOUR:
			{
				return os << a.value<< "[hour]";
			}
			case Unit::G:
			{
				return os << a.value<< "[g]";
			}
			case Unit::KG:
			{
				return os << a.value<< "[kg]";
			}
			case Unit::TON:
			{
				return os << a.value<< "[ton]";
			}
		}
		
	}
	
	istream& ariel::operator>> (istream&  is, PhysicalNumber& a) {
		//Input of physical number
		std::string s;
		
		
		is >> s;

		int size = s.length();
		
		int i = s.find("[");
		std::string token = s.substr(0, i); 
		
		
		int i2 = s.find("]");
		std::string token2 = s.substr(i+1, i2-(i+1));
		if(i < i2 && (i2+1) == size && i > 0 && i>0){
			double v = stod(token);
		if(token2 == "cm" || token2 == "CM"){
		a.unitN = Unit::CM;
		a.value = v;
		}
		else if(token2 == "m" || token2 == "M"){
		a.unitN = Unit::M;
		a.value = v;
		}
		else if(token2 == "km" || token2 == "KM"){
		a.unitN = Unit::KM;
		a.value = v;
		}
		else if(token2 == "sec" || token2 == "SEC"){
		a.unitN = Unit::SEC;
		a.value = v;
		}
		else if(token2 == "min" || token2 == "MIN"){
		a.unitN = Unit::MIN;
		a.value = v;
		}
		else if(token2 == "hour" || token2 == "HOUR"){
		a.unitN = Unit::HOUR;
		a.value = v;
		}
		else if(token2 == "g"|| token2 =="G"){
		a.unitN = Unit::G;
		a.value = v;
		}
		else if(token2 == "kg"|| token2 == "KG"){
		a.unitN = Unit::KG;
		a.value = v;
		}
		else if(token2 == "ton"|| token2 =="TON"){
		a.unitN = Unit::TON;
		a.value = v;
		}
		else
		{
			is.setstate(std::ios::badbit);
		}}
		else{
			is.setstate(std::ios::badbit);
		}
		
		
		return is;
	}


