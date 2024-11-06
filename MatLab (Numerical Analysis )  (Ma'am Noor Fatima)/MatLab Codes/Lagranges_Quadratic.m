function [g] = Lagranges_Quadratic(X,Y,x)
    a = (((x-X(2))*(x-X(3)))/((X(1)-X(2))*(X(1)-X(3))))*Y(1);
    b = (((x-X(1))*(x-X(3)))/((X(2)-X(1))*(X(2)-X(3))))*Y(2);
    c = (((x-X(1))*(x-X(2)))/((X(3)-X(1))*(X(3)-X(2))))*Y(3);
    g=a+b+c
end