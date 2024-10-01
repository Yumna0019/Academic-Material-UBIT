dosseg
.model small
.stack 100h
.data
v1 db 17 dup('$')
.code
main proc
mov ax,@data
mov ds,ax
mov si,offset v1

l1:
mov ah,1
int 21h
cmp al,13       ;13 ascii code of enter key.
je l2
mov [si],al
inc si
jmp l1

l2:
mov si,offset v1
mov cx,17

l3:
mov bx,[si]
push bx
inc si
loop l3

mov cx,17
l4:
pop dx
mov ah,2
int 21h
loop l4

mov ah,4ch
int 21h
main endp
end main 

