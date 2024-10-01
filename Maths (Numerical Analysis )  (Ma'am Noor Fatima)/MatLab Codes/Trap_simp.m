m = menu('choose any rule:','trapezoidal' ,'simpson 1/3 ','simpson 3/8');
% func = 
% i = integral(func,0,6)

x = [0 1 2 3 4 5 6];
y =[1 1/2 1/5 1/10 1/17 1/26 1/37];

h = 1;
n = length(x) - h;

switch m
    case 1
         I = (h/2)*((y(1)+y(7))+2*(y(2)+y(3)+y(4)+y(5)+y(6)));
         disp('Trapezoidal Rule');
         disp(I);
    case 2
        u = (h/3)*((y(1)+y(7))+4*(y(2)+y(4)+y(6))+2*(y(3)+y(5)));
        disp('Simpsons 1/3 Rule');
        disp(u);
    case 3
        l = ((3*h)/8)*((y(1)+y(7)+3*(y(2)+y(3)+y(5)+y(6))+2*(y(4)+y(7))));
        disp('Simpsons 3/8 Rule');
        disp(l);
    otherwise
        disp('try again!');
end