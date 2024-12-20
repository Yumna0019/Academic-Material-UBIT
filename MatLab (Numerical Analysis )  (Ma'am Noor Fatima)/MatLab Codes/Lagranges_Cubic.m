function [g] = Lagranges_Cubic(X,Y,x)
    v1 = ((x-X(2))*(x-X(3))*(x-X(4)))/((X(1)-X(2))*(X(1)-X(3))*(X(1)-X(4)));
    v2 = ((x-X(1))*(x-X(3))*(x-X(4)))/((X(2)-X(1))*(X(2)-X(3))*(X(2)-X(4)));
    v3 = ((x-X(1))*(x-X(2))*(x-X(4)))/((X(3)-X(1))*(X(3)-X(2))*(X(3)-X(4)));
    v4 = ((x-X(1))*(x-X(2))*(x-X(3)))/((X(4)-X(1))*(X(4)-X(2))*(X(4)-X(3)));
    g = (v1*Y(1))+(v2*Y(2))+(v3*Y(3))+(v4*Y(4))
end