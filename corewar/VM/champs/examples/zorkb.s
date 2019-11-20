.name "zorkB"
.comment "I'M DEAAADD"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		st r1 35
		zjmp %:live
