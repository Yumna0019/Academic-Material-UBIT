% Linear Square Approximation For Straight Line.
y = [12 15 21 25];
x = [50 70 100 120];
n = numel(y); % to find the number of elements in y
Ey = sum(y);
Ex = sum(x);
Exy = sum(y.*x);
Exsqr = sum(x.^2);
a = ((Exsqr.*Ey) - (Ex.*Exy)) / ((n.*Exsqr) - (Ex.^2))
b = ((n.*Exy) - (Ey.*Ex)) / ((n.*Exsqr) - (Ex.^2))
vec = [a b];
poly2sym(vec)


%Tradezoidal Numerical Integration:
X = [0 1 2 3 4 5 6];
Y = [1 0.5 0.2 0.1 0.058 0.038 0.027];
trapz(X,Y)

% Quadrature:
% Function to integrate
fx = @(x) x.^2;
% Integration limits
a = 0; % upper
b = 1; % lower
quad(fx, a, b)


%Linear Square Approximation For Parabola.
X = [-3 -2 -1 0 1 2 3];
Y = [4.63 2.11 0.67 0.09 0.63 2.15 4.58];
% Use polyfit to find the coefficients of the quadratic polynomial
co = polyfit(X, Y, 2);
a = co(1)
b = co(2)
c = co(3)




