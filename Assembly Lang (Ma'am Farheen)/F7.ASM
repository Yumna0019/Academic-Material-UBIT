dosseg
.model small
.stack 100h
.data
n1 db'NAME:YUMNA MUBEEN$'
n2 db'STUDING IN UBIT$'
.code
main proc
mov ax,@data
mov ds,ax
mov dx, offset n1
mov ah,9
int 21h
mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h
mov dx, offset n2
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main


