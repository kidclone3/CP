#include<iostream>
#include<vector>
#include<math.h>
#include<random>
#include<iomanip>
using namespace std;

void print(vector<double> a) {for (auto x : a) cout << x << " "; cout << "\n";}

vector<double> linspace (double start, double end, int n) {
    vector<double> ans(n);
    double sep = (end - start) / (n);
    for(int i = 0; i < n; ++i) {
        ans[i] = start + i * sep;
    }
    return ans;
}

const double pi = 2*acos(0);
double riemann(int n) {
    vector<double> rho = linspace(1.0, 2.0, n);
    vector<double> phi = linspace(0.0, pi/4, n);
    vector<double> theta = linspace(0, 2*pi, n);
    double dr = (2.0-1.0) / n;
    double dp = (pi/4 - 0.0) / n;
    double dt = (2*pi - 0.0) / n;
    double dV = dr * dp * dt;
    auto f = [&](double r, double p, double t) -> double {
        return r*r*r*sin(p);
    };
    
    double sum = 0.0;
    for (auto i : rho) {
        double rr = i + rand()*1.0/RAND_MAX * dr;
        for(auto j : phi) {
            double pp = j + rand()*1.0/RAND_MAX * dp;
            for(auto k : theta) {
                double tt = k + rand()*1.0/RAND_MAX * dt;
                sum += f(rr, pp, tt) * dV;
            }
        }
    }
    return sum;
}

int main() {
    // Kết quả của n = 50:
    cout << setprecision(10) << riemann(50) << "\n";
    freopen("out.txt", "w", stdout);
    for (int n = 10; n <= 500; n+=10) {
        cout << setprecision(10) << riemann(n) << " ";
    }
}