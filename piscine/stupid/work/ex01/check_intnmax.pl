#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex01/main_intnmax';
						my $output;
						my $expected;
						die "ex01/main_intnmax failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '-2147483648';

						


						if ($output eq $expected) {
							say 'work/ex01/main_intnmax good!';
						} else {
							say "!!!! ERROR in work/ex01/main_intnmax: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					