def DT():
    print("String accepted as Data type")

def K1():
    print("String accepted as keyword")

def K2():
    print("String accepted as keyword")

def dead_state():
    print("String rejected!")

def CS():
    print("String accepted as Conditional Statement.")

def LO():
    print("String accepted as Logical Operator.")
    
def Loop():
    print("String accepted as Loop.")
    
def id(input_value):
    if len(input_value) > 2:
        print("String accepted as identifier")
    else:
        i2(input_value)

def i3(input_value,i):
    count= input_value.count('_')
    if '_' in input_value and input_value[-1] != '_' and count==1 and input_value[0]!='_':
        index=input_value.index('_')
        if (input_value[index+1: ].isalnum() ):
            print("String accepted")        
    elif input_value[i:].isalnum():
        print("String accepted as identifier")           
    else:
        dead_state()

def i2(input_value):
    i3(input_value, 2)

def i1(input_value):
    if input_value[1].isalpha() and len(input_value) == 1:
        id(input_value)
    elif input_value[1].isalpha() and len(input_value) > 1:
        i3(input_value, 1)
    else:
        dead_state()

def d1(input_value):
    if (input_value[1].isdigit()):
        d2(input_value)
    else:
        dead_state()

def d2(input_value):
    if '.' not in input_value:
        print("It is a digit")
    elif '.' in input_value :
            index=input_value.index('.')
            d3(input_value,index)
        
def d3(input_value,index):
    if (input_value.endswith('.')):
        dead_state()
    elif(index>1):
        d4(input_value)
    
def d4(input_value):
    if 'e' in input_value :
        index=input_value.index('e')
        d5(input_value,index)
    elif 'E' in input_value :
        index=input_value.index('E')
        d5(input_value,index)  
    elif 'e' and 'E' not in input_value:
        print("It is a digit") 
    else:
        dead_state()    

def d5(input_value,index):
    if(input_value.endswith('e') or input_value.endswith('E') ):
        dead_state()
    elif (input_value[index+1]=='+' or input_value[index+1]=='-'):
        d6(input_value,index+2)
    else:
        d7(input_value)

def d6(input_value,index):
    if(input_value[index:].isdigit()):
        d7(input_value)
    else:
        dead_state()

def d7(input_value):
    print("It is a digit")

def f35(input_value):
    if len(input_value) >= 5 and input_value[4] == 't':
        K1()
    else:
        dead_state()

def f34(input_value):
    if len(input_value) >= 4 and input_value[3] == 'u':
        f35(input_value)
    else:
        dead_state()

def f33(input_value):
    if len(input_value) >= 3 and input_value[2] == 'p':
        f34(input_value)
    else:
        dead_state()

def f32(input_value):
    if len(input_value) >= 4 and input_value[3] == 'r':
        Loop()
    else:
        dead_state()

def f31(input_value):
    if len(input_value) >= 3 and input_value[2] == 'e':
        f32(input_value)
    else:
        dead_state()

def f30(input_value):
    if len(input_value) >= 2 and input_value[1] == 't':
        f31(input_value)
    elif len(input_value) >= 2 and input_value[1] == 'n':
        f33(input_value)
    elif len(input_value) >= 2 and input_value[1] == 'f':
        CS()
    else:
        dead_state()

def f27(input_value):
    if(len(input_value) > 1 and input_value[1] == 'r'):
        LO()
    else:
        dead_state()
        
def f29(input_value):
    if(len(input_value) > 2 and input_value[2] == 'd'):
        LO()
    else:
        dead_state()
        
def f28(input_value):
    if(len(input_value) > 1 and input_value[1] == 'n'):
        f29(input_value)
    else:
        dead_state()

def f26(input_value):
    if(len(input_value) > 3 and input_value[3] == 'f'):
        CS()
    else:
        dead_state()
    
def f25(input_value):
    if(len(input_value) > 3 and input_value[3] == 'e'):
        CS()
    else:
        dead_state()
        
def f24(input_value):
    if(len(input_value) > 2 and input_value[2] == 's'):
        f25(input_value)
    elif(len(input_value) > 2 and input_value[2] == 'i'):
        f26(input_value)
    else:
        dead_state()
    
def f23(input_value):
    if(len(input_value) > 1 and input_value[1] == 'l'):
        f24(input_value)
    else:
        dead_state()

def f22(input_value):
    if(len(input_value) > 4 and input_value[4] == 't'):
        K2()
    else:
        dead_state()

def f21(input_value):
    if(len(input_value) > 3 and input_value[3] == 'n'):
        f22(input_value)
    else:
        dead_state()

def f20(input_value):
    if(len(input_value) > 2 and input_value[2] == 'i'):
        f21(input_value)
    else:
        dead_state()

def f19(input_value):
    if(len(input_value) > 1 and input_value[1] == 'r'):
        f20(input_value)
    else:
        dead_state()

def f5(input_value):
    print(input_value)

def f6(input_value):
    print(input_value)

def f7(input_value):
    print(input_value)

def f8(input_value):
    print(input_value)

def f9(input_value):
    print(input_value)

def f10(input_value):
    print(input_value)

def f11(input_value):
    print(input_value)

def f12(input_value):
    print(input_value)

def f13(input_value):
    print(input_value)

def f14(input_value):
    print(input_value)

def f15(input_value):
    print(input_value)

def f16(input_value):
    print(input_value)

def f17(input_value):
    print(input_value)

def f18(input_value):
    print(input_value)

def f4(input_value):
    if(input_value[2] == 't'):
        K1()
    else:
        dead_state()
        
def f3(input_value):
    if ( len(input_value) > 3 and input_value[3] == ' '):
        DT()
    else:
        dead_state()
        
def f2(input_value):
    if(len(input_value) > 3 and input_value[2] == 'm'):
        f3(input_value)
    else:
        dead_state()
        
def f1(input_value):
    if (len(input_value) > 1 and input_value[1]=='u'):
        f2(input_value)
    elif (len(input_value) > 1 and input_value[1]=='o'):
        f4(input_value)
    else:
        dead_state()

def start():
    user_input = input("Enter the string: ")
    if len(user_input) < 1:
        dead_state()
    elif (user_input[0] == 'n'):
        f1(user_input)
    elif user_input.startswith('#'):
        i1(user_input)
    elif (user_input[0] == 'p'):
        f19(user_input)
    elif (user_input[0] == 'e'):
        f23(user_input)
    elif(user_input[0] == 'o'):
        f27(user_input)
    elif(user_input[0] == 'a'):
        f28(user_input) 
    elif(user_input[0] == 'i'):
        f30(user_input)
    elif (user_input[0] == '+' or user_input[0] == '-'):
        d1(user_input)
    elif (user_input[0].isdigit()):
        d2(user_input)
    elif (user_input=='*'):
        f5(user_input)
    elif (user_input=='+'):
        f6(user_input)
    elif (user_input=='-'):
        f7(user_input)
    elif (user_input=='/'):
        f8(user_input)
    elif (user_input==';'):
        f9(user_input)
    elif (user_input=='{'):
        f10(user_input)
    elif (user_input=='}'):
        f11(user_input)
    elif (user_input=='('):
        f12(user_input)
    elif (user_input=='['):
        f13(user_input)
    elif (user_input==']'):
        f14(user_input)
    elif (user_input==')'):
        f15(user_input)
    elif (user_input=='^'):
        f16(user_input)
    elif (user_input=='>'):
        f17(user_input)
    elif (user_input=='<'):
        f18(user_input)
    else:
        dead_state()

start()

