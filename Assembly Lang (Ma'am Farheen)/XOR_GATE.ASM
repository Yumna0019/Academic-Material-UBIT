;Practice Code Of XOR-GATE:
dosseg
.model small
.stack 100h
.data
.code
main proc
mov bl,101b
xor bl,110b
add bl,48
mov dl,bl
mov ah,2
int 21h
mov ah,4ch
int 21h
main endp
end main
