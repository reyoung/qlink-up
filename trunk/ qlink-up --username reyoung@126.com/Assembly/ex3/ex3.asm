DATSEG segment
		DATAX 　 db ｀ABCDEFGHIJKLMNOPQRST¨　　　　       
		DATAY 　 db 20 DUP(?)
DATSEG ends

CODSEG 　SEGMENT
　       ASSUME CS:CODSEG,DS:DATSEG,ES:DATSEG
START: MOV 　　 AX,DATSEG
 　　   MOV 　　 DS,AX 　　　
  　 　 MOV 　　 ES,AX 　　　
   　　 CLD 　　　　　　　　 
       MOV 　　SI,OFFSET DATAX 　
	   MOV　　 DI,OFFSET DATAY 　
	   MOV 　　 CX,20 
	   REP 　　   MOVSB 
	   MOV　　AX,4C00H　
	   INT 　　 21H
	   CODSEG ENDS
	   END 　　 START
