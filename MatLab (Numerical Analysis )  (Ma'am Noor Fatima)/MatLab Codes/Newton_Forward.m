%NEWTON FORWARD DIFFERENCE INTERPOLATION:

x = input('Enter x-values:');
y = input('Enter y-values:');
po = input('Enter point of approximation:');
n = length(x); % length of x
h = x(2) - x(1); % step size
mat = zeros(n,n);
mat(:,1) = y; % first column will be of all y values.
for j=2:n
    for i=j:n
        mat(i,j) = mat(i,j-1) - mat(i-1,j-1);
    end
end
disp(mat); 
C = mat(n,n);
for k = n-1 : -1 : 1
    p = poly(x(1))/h;
    p(2) = p(2) - (k-1);
    C = conv(C,p)/k; %multipliv
    L = length(C);
    C(L) = C(L) + mat(k,k);
end
a=poly2sym(C)
