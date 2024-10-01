;Your Code As Discussed In Today Class(Practice Code):
dosseg
.model small
.stack 100h
.data
q db ?
.code
main proc
mov ax,@data
mov ds,ax
mov cx,2
mov ax,26
mov bl,5
div bl

t1:
mov dl,q
mov dl,48
mov ah,2
int 21h
mov bl,q
div bl
mov ah,2
int 21h
loop t1

mov ah,4ch
int 21h
main endp
end main
