dosseg
.model small
.stack 100h
.data
m1 db'Can I skip a line in code?$'
m2 db'Yes u can.$'
m3 db' $'
.code
main proc
mov ax,@data
mov ds,ax

mov dx,offset m1
mov ah,9
int 21h

mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h

mov dx,offset m3
mov ah,9
int 21h

mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h

mov dx,offset m2
mov ah,9
int 21h
main endp
end main
