dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,'9'
push ax
mov bx,'5'
push bx
pop ax
pop bx

mov dx,ax
mov ah,2
int 21h

mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h

mov dx,bx
mov ah,2
int 21h
mov ah,4ch
int 21h
main endp
end main
