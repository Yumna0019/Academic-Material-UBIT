; *******
;  *****
;   ***
;    *

dosseg
.model small
.stack 100h
.data
str dw 7        ; for star
space dw 1      ; for space var
.code
main proc
mov ax,@data
mov ds,ax

mov cx,4
l1:
push cx

mov cx,space    ; loop for space
l2:
mov dl,' '
mov ah,2
int 21h
loop l2

inc space       ; increment in space var

mov cx,str
l3:             ; loop for str
mov dl,'*'
mov ah,2
int 21h
loop l3

mov dx,10       ; newline
mov ah,2
int 21h
mov dx,13       ; carriage return
mov ah,2
int 21h

mov bx,2
sub str,bx      ; decrement 2 in str

pop cx
loop l1

mov ah,4ch
int 21h

main endp
end main 
















