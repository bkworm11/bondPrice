#include<string>

#ifndef __FinancialSamples__BondCalculator__
#define __FinancialSamples__BondCalculator__

class BondCalculator {
    public:
    BondCalculator (const std::string issueEntity, int periods, double principalAmount, double couponValue);
    BondCalculator (const BondCalculator &v);
    BondCalculator &operator = (const BondCalculator &v);
    ~BondCalculator();
    double interestRate();

    private:
    std::string m_issueEntity;
    double m_principalAmount;
    double m_coupon;
    double m_periods;
};

#endif /*define(__FinancialSamples__BondCalculator__) */