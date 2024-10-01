dosseg
.model small
.stack 100h
.data
v1 db ' Number is equal to 20.$'
v2 db ' Number is not equal to 20$.'
.code
main proc
mov al,5
mov bl,4
mul bl
AAM
mov ch,ah
mov cl,al
mov dl,ch
add dl,48
mov ah,2
int 21h
mov dl,cl
add dl,48
mov ah,2
int 21h

mov ax,@data
mov ds,ax
mov dl,al
cmp al,dl
je L1
mov dx,offset v2
mov ah,9
int 21h
mov ah,4ch
int 21h
L1:
mov dx,offset v1
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main
