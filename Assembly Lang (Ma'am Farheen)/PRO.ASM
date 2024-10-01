dosseg
print macro p1
mov dx,offset p1
mov ah,9
int 21h
endm

.model small
.stack 100h
.data
msg1 db 'Enter Your Guess Please: $'
msg2 db 'Rules Of Game: $'
msg3 db '1) To Play Press Enter Key.$'
msg4 db '2) To Exit Press 0.$'

m1 db 'C _ _ $'
m2 db '_ A _ $'
m3 db '_ _ T $'

.code
main proc
mov ax,@data
mov ds,ax
print msg2
call new
print msg3
call new
print msg4
call new
mov ah,1
int 21h
mov dl,al
cmp al,10
je start
cmp al,48
je exit

start:
print msg1
call new
mov ah,1
int 21h
mov dl,al
cmp al,'c'
je l1
cmp al,'a'
je l2
cmp al,'t'
je l3

l1:
call new
print m1
mov ah,4ch
int 21h

l2:
call new
print m2
mov ah,4ch
int 21h

l3:
call new
print m3
mov ah,4ch
int 21h

exit:
mov ah,4ch
int 21h
main endp

new proc
mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h
ret
new endp
end main 





