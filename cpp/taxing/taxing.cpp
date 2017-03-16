#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    int b;
    scanf("%d", &b);
    vector<pair<double, double>> bands;
    for (int i = 0; i < b; ++i) {
        double band_amount, tax_rate;
        scanf("%lf %lf", &band_amount, &tax_rate);
        bands.push_back({band_amount, tax_rate/100.0});
    }
    double upper_band;
    scanf("%lf", &upper_band);
    bands.push_back({numeric_limits<double>::infinity(), upper_band/100.0});
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; ++i) {
        double earned, gift_after_tax;
        scanf("%lf %lf", &earned, &gift_after_tax);
        double payed = 0;
        for (auto band : bands) {
            double band_amount = band.first;
            double tax_rate = band.second;
            double pay_at_band = min(max(0.0, band_amount - earned), gift_after_tax / (1 - tax_rate));
            gift_after_tax -= pay_at_band * (1 - tax_rate);
            earned = max(0.0, earned - band_amount);
            payed += pay_at_band;
        }
        printf("%.6lf\n", payed);
    }
}
