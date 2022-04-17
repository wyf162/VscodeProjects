#include<iostream>

#include<ql/quantlib.hpp>
using namespace QuantLib;

void testingMacros1(){
    double x=0.0;
    QL_REQUIRE(x!=0,"zero number");
}

void testingMacros(){
    QL_FAIL("FAILED");
}

void testingDate(){
    Date myDate(12,Aug,2009);
    std::cout<<myDate<<std::endl;
    myDate++;
    std::cout<<myDate<<std::endl;
    myDate += 12*Days;
    std::cout<<myDate<<std::endl;
    Period myP(10, Weeks);
    myDate += myP;
    std::cout<<myDate<<std::endl;
}



int main(){
    // try{
    //     testingMacros1();
    // }catch(std::exception& e){
    //     std::cout<<e.what()<<std::endl;
    //     return 1;
    // }catch(...){
    //     std::cout<<"unknown error"<<std::endl;
    //     return 1;
    // }
    testingDate();
}