dosseg
print macro p1      ;macro for printing strings
mov dx,offset p1
mov ah,9
int 21h
endm
.model small
.stack 100h
.data
msg1 db 'Enter your guess please $'
msg2 db '           *******************Rules of game*****************$'
msg3 db '                         1.To exit game press 0.$'
msg4 db '                         2.To play press enter key.$'
msg5 db 'Guess Again$'
msg6 db '      +++++++++++++++++CONGRATULATIONS!!!!!You Won++++++++++++++ $'
m1 db 'C - - $'
m2 db '- A - $'
m3 db '- - T $'
m4 db 'C A - $'
m5 db 'C - T $'
m6 db '- A T $'
m7 db 'C A T $'
m8 db '                            WORD:  - - - $'
msg7 db 'OOPS!! It is a wrong guess$'
msg8 db '             ++++++++++++++++Game Over+++++++++++++++++ $'   
msg9 db '============================================================================$'
msg10 db 'You Guess It all Right$'
msg11 db '                         Hint:It is a pet animal$'
hint db 'CHANCES:  $'
msg12 db '================================WORD GUESS GAME =============================$'

.code
main proc
mov ax,@data                    
mov ds,ax

mov ah,00              ;set mode option
mov al,03              ;CGA color mode
int 10h                ;print graphics
mov ah,09              ;display option
mov bh,00              ;page 0
mov al,20h             ;ASCII code for space
mov cx,900h            ;repeat it
mov bl,01100000b       ;color
int 10h               ;print graphics

call new
print msg12            ;print game name
call new
print msg2             ;rules of game
call new
print msg3             ;rule 1
call new
print msg4             ;rule 2
call new
print msg11
call new
print msg9
call new
call inp               ;take input from user that 0 or enter 
cmp al,10
je start               ;if enter jump to start loop
cmp al,48
je exit                ;if 0 then exit 
print m8               ;print number of place holder
call new

mov cx,5               ;counter loop to guess only five wrong guesses
start:
call new
print hint             ;print hint left
mov dx,cx
add dl,48
mov ah,2
int 21h
call new
print msg1             ;print enter the guess
call new
call inp               ;call input procedure define in last
mov dl,al              ;move input to data register
cmp al,'C'              
je l1
cmp al,'c'
je l1
cmp al,'A'
je l2
cmp al,'a'
je l2
cmp al,'T'
je l3
cmp al,'t'
je l3
call new
print msg7         ;print it is a wrong guess
call new
print msg11
call new
loop start            ;loop call
print msg8            ;print you loss

exit:                 ;exit loop
mov ah,4ch
int 21h

l1:                   ;IF GUESS IS C
call new
print m1
call msg
call cmp1             ;cmp with t and jmp to l5
call cmp2             ;cmp with a and jmp to l4
jmp l0                ;jump to l0 loop if the input is neither A,a nor T,t

l2:                   ;IF GUESS IS A
call new
print m2
call msg
call cmp3             ;cmp with c and jmp to l4
call cmp4             ;cmp with t and jmp to l7
jmp l                 ;jump to l loop if input is neither C,c nor T,t

l3:                   ; IF GUESS IS T
call new
print m3
call msg
call cmp5             ;cmp with c and jmp to l5
call cmp6             ;cmp with a and jmp to l7
jmp l10               ;jump to l10 loop if the input is neither C,c nor A,a

l0:                   ;if guess is not a nor t after c
call loss             ;print it is a wrong guess
call inp              ;take input again
call cmp2             ;cmp with a and jmp to l4
call cmp1             ;cmp with t and jmp to l5
loop l0               ;jump back to loop if the input is neither T,t nor A,a

l:
call loss
call inp
call cmp3            ;cmp with c and jmp to l4
call cmp4            ;cmp with t and jmp to l7
loop l               ;jump back to loop if the input is neither C,c nor T,t

l10:
call loss
call inp
call cmp5            ;cmp with c and jmp to l5
call cmp6            ;cmp with a and jmp to l7
loop l10             ;jump back to loop if the input is neither C,c nor A,a
                     
l11:                 ;loop execute when you won the game
call new    
print m7
call new
print msg10
call new
print msg6
call exit

l4:                  ;GUESS A AFTER C or guess c after a
call new
print m4
call msg
cmp al,'T'
je l11
cmp al,'t'
je l11
call loss            ;print it is a wrong guess
jmp l4

l5:                  ;GUESS T AFTER C or guess c after t
call new
print m5
call msg
cmp al,'A'
je l11
cmp al,'a'
je l11
call loss            ;print it is a wrong guess
jmp l5

l7:                  ;GUESS T AFTER A or guess a after t
call new
print m6
call msg
cmp al,'C'
je l11
cmp al,'c'
je l11
call loss            ;print it is a wrong guess
jmp l7

mov ah,4ch
int 21h
main endp

cmp3 proc             ;procedure to cmp c if yes then jump to l4
cmp al,'C'
je l4
cmp al,'c'
je l4
ret
cmp3 endp

cmp2 proc             ;procedure to cmp a if yes then jump to l4
cmp al,'A'
je l4
cmp al,'a'
je l4
ret
cmp2 endp

cmp1 proc             ;procedure to cmp t if yes then jump to l5
cmp al,'T'
je l5
cmp al,'t'
je l5
ret
cmp1 endp

cmp5 proc             ;procedure to cmp c if yes then jump to l5
cmp al,'C'
je l5
cmp al,'c'
je l5
ret
cmp5 endp

cmp4 proc             ;procedure to cmp t if yes then jump to l7
cmp al,'T'
je l7
cmp al,'t'
je l7
ret
cmp4 endp

cmp6 proc             ;procedure to cmp a if yes then jump to l7
cmp al,'A'
je l7
cmp al,'a'
je l7
ret
cmp6 endp


loss proc             ;procedure to print that you loss
call new
print msg7
call new
print msg1
call new
ret
loss endp

msg proc              ;procedure to print input guess
call new
print msg1
call new
call inp              ;call procedure in procedure which takes input
ret
msg endp

inp proc              ;procedure to take input
mov ah,1
int 21h
mov dl,al
ret
inp endp

new proc              ;procedure to give space in a line
mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h
ret
new endp
end main
