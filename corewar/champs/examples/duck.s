.name "duck"
.comment "QUARKKKKK"

store:	sti r1, %:live, %1
		ldi %:live, %0, r2
		ldi %:live, %4, r3
		ldi %:live, %8, r4
		ldi %:live, %12, r5
		ldi %:live, %16, r6
		ldi %:live, %20, r7
		ldi %:live, %24, r8

live:	live %1
		st r2, 135
		st r3, 134
		st r4, 133
		fork %6
		zjmp %-23
		st r5, 133
		st r6, 132
		st r7, 131
		st r8, 130
		and r9, %0, r9
		fork %6
		zjmp %-45
