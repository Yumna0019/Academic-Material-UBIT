;3. Program To SUB Two Numbers:
dosseg
.model small
.stack 100h
.data
.code
main proc

mov bl,3
mov dl,1
sub bl,dl
add dl,48
mov ah,2
INT 21h

mov ah,4ch
INT 21h

main endp
end main
