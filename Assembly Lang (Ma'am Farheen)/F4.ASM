;2. Progarm To ADD Two Numbers:
dosseg
.model small
.stack 100h
.data
.code
main proc

mov al,5
mov dl,4
add dl,al
add dl,48
mov ah,2
INT 21h

mov ah,4ch
INT 21h

main endp
end main
