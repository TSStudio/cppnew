#ifndef FRAC_H
#define FRAC_H
#include<cstdio>
#include<cstring>
#include<string>
struct fraction{
    bool sig;
    unsigned long long numerator,denominator;
    fraction(int a,int b){
        if(a*b<0){this->sig=0;}
        else{this->sig=1;}
        this->numerator=a<0?-a:a;
        this->denominator=b<0?-b:b;
        this->hj();
    }
    bool operator ==(const fraction l){
        if(sig==l.sig&&numerator==l.numerator&&denominator==l.denominator) return true;
        return false;
    }
    bool operator !=(const fraction l){
        if(sig==l.sig&&numerator==l.numerator&&denominator==l.denominator) return false;
        return true;
    }
    bool operator <(const fraction l){
        if(sig==0&&l.sig==1)return true;
        if(sig==1&&l.sig==0)return false;
        if(sig==1) return numerator*l.denominator<denominator*l.numerator;
        return numerator*l.denominator>denominator*l.numerator;
    }
    bool operator >(const fraction l){
        if(sig==0&&l.sig==1)return false;
        if(sig==1&&l.sig==0)return true;
        if(sig==1) return numerator*l.denominator>denominator*l.numerator;
        return numerator*l.denominator<denominator*l.numerator;
    }
    bool operator <=(const fraction l){
        if(sig==l.sig&&numerator==l.numerator&&denominator==l.denominator) return true;
        if(sig==0&&l.sig==1)return true;
        if(sig==1&&l.sig==0)return false;
        if(sig==1) return numerator*l.denominator<denominator*l.numerator;
        return numerator*l.denominator>denominator*l.numerator;
    }
    bool operator >=(const fraction l){
        if(sig==l.sig&&numerator==l.numerator&&denominator==l.denominator) return true;
        if(sig==0&&l.sig==1)return false;
        if(sig==1&&l.sig==0)return true;
        if(sig==1) return numerator*l.denominator>denominator*l.numerator;
        return numerator*l.denominator<denominator*l.numerator;
        
    }
    unsigned long long gcd(unsigned long long a,unsigned long long b){
        while(b^=a^=b^=a%=b);
	    return a;
    }
    void hj(){
        unsigned long long h=gcd(numerator,denominator);
        numerator/=h,denominator/=h;
    }
    fraction operator +(fraction l){
        fraction temp(0,1);
        temp.denominator=denominator*l.denominator;
        if(sig==l.sig){
            temp.sig=sig;
            temp.numerator=(denominator*l.numerator)+(numerator*l.denominator);
            temp.hj();
            return temp;
        }else{
            if(sig==0){
                if((denominator*l.numerator)>(numerator*l.denominator))
                    temp.numerator=(denominator*l.numerator)-(numerator*l.denominator);
                else{
                    temp.numerator=(numerator*l.denominator)-(denominator*l.numerator);
                    temp.sig=0;
                }
                temp.hj();
                return temp;
            }else{
                if((denominator*l.numerator)<(numerator*l.denominator))
                    temp.numerator=(numerator*l.denominator)-(denominator*l.numerator);
                else{
                    temp.numerator=(denominator*l.numerator)-(numerator*l.denominator);
                    temp.sig=0;
                }
                temp.hj();
                return temp;
            }
        }
        
    }
    fraction operator -(fraction l){
        l.sig^=1;
        return fraction((sig-1)*numerator,denominator)+l;
    }
    fraction operator *(fraction l){
        fraction x(numerator*l.numerator,denominator*l.denominator);
        x.sig=sig^l.sig;
        return x;
    }
    fraction operator /(fraction l){
        fraction x(numerator*l.denominator,denominator*l.numerator);
        x.sig=sig^l.sig;
        return x;
    }
    char* getsig(){
        static char* ne="-";
        static char* po="";
        return sig?po:ne;
    }
};
#endif