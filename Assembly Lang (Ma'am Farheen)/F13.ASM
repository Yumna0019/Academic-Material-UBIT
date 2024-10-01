dosseg
.model small
.stack 100h
.data
a1 db 'Rectangle$'
.code
main proc
mov ax,@data
mov ds,ax
mov ah,6h
mov al,10
mov bh,00111000b
mov ch,3
mov cl,0
mov dh,30
mov dl,40
int 10h
mov dx,offset a1
mov ah,9
int 21h

mov cx,3
lop:
mov ch,2
mov cl,0
mov dh,20
mov dl,40
int 10h

inc bh
dec ch
dec dh
loop lop


mov ah,4ch
int 21h 
main endp
end main
