% NEWTON BACKWARD DIFFERENCE INTERPOLATION:

x = input('Enter x-values:');
y = input('Enter y-values:');
po = input('Enter point of approximation:');
n = length(x); % length of x
h = x(2) - x(1); % step size
mat = zeros(n,n);
mat(:,1) = y;
for j=2:n
    for i=1:n-j+1
        mat(i,j) = mat(i+1,j-1) - mat(i,j-1);
    end
end
disp(mat);
C = mat(1,n);
for k = n-1 : -1 : 1
    p = poly(x(n))/h;
    p(2) = p(2) + (k-1);
    C = conv(C,p)/k; 
    L = length(C);
    C(L) = C(L) + mat(n-k+1,k);
end
disp('polynomial is:');
fx = poly2sym(C);
disp(fx);