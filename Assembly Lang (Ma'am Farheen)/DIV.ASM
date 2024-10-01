;Practice Code Of DIV:
dosseg
.model small
.stack 100h
.data
quo db ?
rem db ?
.code
main proc
mov ax,@data
mov ds,ax

mov ax,25
mov bl,5
div bl

mov quo,al
mov rem,ah

mov dl,quo
add dl,48
mov ah,2
int 21h

mov dl,rem
add dl,48
mov ah,2
int 21h

mov ah,4ch
int 21h
main endp
end main

