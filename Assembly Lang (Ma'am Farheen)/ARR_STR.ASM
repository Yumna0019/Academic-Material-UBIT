dosseg
.model small
.stack 100h
.data
arr db 5 dup(?)
array db 'Enter 5 numbers in array:$'
str db 100 dup('$')
string db 'Enter a string:$'
.code
main proc
mov ax,@data
mov ds,ax
              ;array
mov dx,offset array
mov ah,9
int 21h
mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h

mov si,offset arr
mov cx,5

l1:
mov ah,1
int 21h
mov [si],al
inc si 
loop l1

mov dl,[si]
mov ah,2
int 21h

mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h

              ;string

mov dx,offset string
mov ah,9
int 21h
mov dx,10
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h

mov si,offset str
l2:
mov ah,1
int 21h
cmp al,13
je print
mov [si],al
inc si
jmp l2

print:
mov dx,offset str
mov ah,9
int 21h

mov ah,4ch
int 21h

main endp
end main
