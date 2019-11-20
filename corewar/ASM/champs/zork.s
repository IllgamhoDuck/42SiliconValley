.name "zork"
.comment "I'M ALIIIIVE"

		sti r1, %:lives, %1
		and r1, %0, r1

lives: live %1
		zjmp %:lives
