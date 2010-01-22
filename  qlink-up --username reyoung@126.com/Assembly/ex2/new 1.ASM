DATA SEGMENT
string DB 'HAPPY NEW YEAR!',0DH,0AH,'$'
count DW 17
DATA ENDS

CODE SEGMENT
main    proc far
start:
	mov cx,count
	mov si,0
next:	mov dl,string[si]
	mov ah,2
	int 21h
	inc si
	loop next
	cmp cx,si
	ret
main   endp
code   ends
          end   start