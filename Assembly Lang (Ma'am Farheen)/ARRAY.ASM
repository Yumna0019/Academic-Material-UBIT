dosseg
.model small
.stack 100h
.data
array db 'Y','U','M','N','A'
.code
main proc
mov ax,@data
mov ds,ax
mov si,offset array
mov cx,5

L1:
mov dx,[si]
mov ah,2
int 21h
inc si
loop L1
mov ah,4ch
int 21h
main endp
end main
