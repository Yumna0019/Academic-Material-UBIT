%ROOTS :
q = [2 8 0 -7 -1];
roots(q)

%POLYFIT :
p = [-1 0 1 3];
w = [0.89 0.19 5.54 3.38];
z = polyfit(p,w,2);
poly2sym(z)

% INTERPOLATION OF DEGREEE 1 :
x = [1 7];
y = [1.3 4.9];
interp1(x,y,2.5)