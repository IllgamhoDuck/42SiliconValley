#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex01/main_intmax';
						my $output;
						my $expected;
						die "ex01/main_intmax failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '2147483647';

						


						if ($output eq $expected) {
							say 'work/ex01/main_intmax good!';
						} else {
							say "!!!! ERROR in work/ex01/main_intmax: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					