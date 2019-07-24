#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex02/main';
						my $output;
						my $expected;
						die "ex02/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = 'is_null? 0
size is 5
5,6,7,8,9,
is_null? 0
size is 3
-20,-19,-18,
is_null? 1
size is 0
';

						


						if ($output eq $expected) {
							say 'work/ex02/main good!';
						} else {
							say "!!!! ERROR in work/ex02/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					