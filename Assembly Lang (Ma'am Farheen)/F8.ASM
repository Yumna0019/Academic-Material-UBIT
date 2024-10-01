;Program Using Conditional Jump:
dosseg
.model small
.stack 100h
.data
v1 db ' Number is greater or equal.$'
v2 db ' Number is less or equal.$'
.code
main proc
mov ax,@data
mov ds,ax
mov dl,'5'
mov ah,1
int 21h
cmp al,dl
jge L1
mov dx,offset v2
mov ah,9
int 21h
mov ah,4ch
int 21h

L1:
mov ah,1
int 21h
mov dx,offset v1
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main 






