#include "moviebook.h"
using namespace std;

class PricingStrategy {
public:
    virtual double getPrice() const = 0;
    virtual ~PricingStrategy() = default;
};

class NormalRate : public PricingStrategy {
public:
    explicit NormalRate(double price) : price(price) {}

    double getPrice() const override {
        return price;
    }
private:
    double price;
};

class PremiumRate : public PricingStrategy {
public:
    explicit PremiumRate(double price) : price(price) {}

    double getPrice() const override {
        return price;
    }
private:
    double price;
};

class VIPRate : public PricingStrategy {
public:
    explicit VIPRate(double price) : price(price) {}
    
    double getPrice() const override {
        return price;
    }
private:
    double price;
};