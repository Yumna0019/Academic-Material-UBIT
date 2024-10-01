function [g] = Lagranges_Linear(X,Y,x)
    a = (((x-X(2))/(X(1)-X(2)))*Y(1));
    b = (((x-X(1))/(X(2)-X(1)))*Y(2));
    g=a+b
end