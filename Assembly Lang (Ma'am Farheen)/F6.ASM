;Input Two Number And ADD Them:
dosseg
.model small
.stack 100h
.data
.code
main proc
mov ah,1
INT 21h
mov bl,al
mov ah,1
INT 21h
add bl,al
sub bl,48
mov dl,bl
mov ah,2
INT 21h
mov ah,4ch
INT 21h
main endp
end main 



