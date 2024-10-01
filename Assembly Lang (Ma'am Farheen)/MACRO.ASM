print macro p1
mov dx,offset p1
mov ah,9
int 21h
endm

dosseg
.model small
.stack 100h
.data
str1 db 'Assalam_o_Alikum.$'
str2 db 'EID MUBARAK.$'
str3 db 'In Advance.$'
.code
main proc
mov ax,@data
mov ds,ax
print str1
call enterkey
print str2
call enterkey
print str3
mov ah,4ch
int 21h

main endp

enterkey proc
mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h
ret
enterkey endp

end main
