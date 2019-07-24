#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex05/main';
						my $output;
						my $expected;
						die "ex05/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "werty\nwerty qwerty\n(null)\n(null)\n(null)\nasdf qwerty\n";

						


						if ($output eq $expected) {
							say 'work/ex05/main good!';
						} else {
							say "!!!! ERROR in work/ex05/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					