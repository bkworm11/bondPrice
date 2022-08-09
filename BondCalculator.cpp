#include "BondCalculator.h"
#include "iostream"

BondCalculator::BondCalculator(const std::string issueEntity, int periods, double principalAmount, double couponValue):
m_issueEntity(issueEntity), m_periods(periods), m_principalAmount(principalAmount), m_coupon(couponValue) {
}

BondCalculator::BondCalculator(const BondCalculator &v): 
m_issueEntity(v.m_issueEntity), m_periods(v.m_periods), m_principalAmount(v.m_principalAmount), m_coupon(v.m_coupon) {
}

BondCalculator::~BondCalculator() {

}

BondCalculator& BondCalculator::operator=(const BondCalculator &v) {
    if(this != &v) {
        std::cout<<"operator"<<std::endl;
        this->m_issueEntity = v.m_issueEntity;
        this->m_principalAmount = v.m_principalAmount;
        this->m_periods = v.m_periods;
        this->m_coupon = v.m_coupon;
    }
    return *this;
}

double BondCalculator::interestRate() {
    std::cout<<"interest"<<std::endl;
    return m_coupon / m_principalAmount;
}

int main(int argCount, const char* argParams[]) {
    if(argCount != 4) {
        std::cout<< "Need to input exactly 4 parameters: company, principalAmount, coupon and years" << std::endl;
        return 1;
    }

    std::string issueEntity = argParams[1];
    double principalAmountAmount = atof(argParams[2]);
    double couponValue = atof(argParams[3]);
    int periods = atoi(argParams[4]);

    BondCalculator bc(issueEntity, principalAmountAmount, couponValue, periods);
    std::cout << "Issuing entity is: "<< issueEntity << std::endl;
    std::cout<< "the interest rate is " << bc.interestRate() <<std::endl;

    return 0;

}